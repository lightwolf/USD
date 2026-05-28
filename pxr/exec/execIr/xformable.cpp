//
// Copyright 2026 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/pxr.h"

#include "pxr/exec/execIr/controllerBuilder.h"
#include "pxr/exec/execIr/tokens.h"
#include "pxr/exec/execIr/utils.h"

#include "pxr/base/gf/matrix4d.h"
#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"
#include "pxr/exec/exec/registerSchema.h"
#include "pxr/exec/execGeom/tokens.h"
#include "pxr/exec/vdf/context.h"
#include "pxr/usd/usdGeom/xformable.h"

PXR_NAMESPACE_USING_DIRECTIVE

namespace {

// Builder used to register computations for input and output attributes.
//
// TODO: When the OpenExec core provides builtin support for attribute
// connection data flow and for inversion, we won't need to define any of the
// plugin computations defined by this builder.
// 
class _Builder : ExecIr_ControllerBuilderBase {
public:
    _Builder(ExecComputationBuilder &self)
        : ExecIr_ControllerBuilderBase(self)
    {}

    // Defines the computations needed for an attribute that provides input
    // values for an invertible controller, via an attribute connection, when
    // performing a forward computation.
    //
    template <typename ValueType>
    void InputAttribute(const TfToken &attributeName);

    // Defines the computations needed for an attribute that receives values
    // values from an invertible controller output, via an attribute connection,
    // when performing a forward computation.
    //
    template <typename ValueType>
    void OutputAttribute(const TfToken &attributeName);

    // Defines a computation named \p computationName that computes a
    // transformation inherited from a namespace ancestor.
    //
    // Finds the nearest namespace ancestor that is either IrXformable or
    // Xformable:
    // - If the ancestor is IrXformable, yields the value of the attribute named
    //   \p spaceAttributeName.
    // - If the ancestor is Xformable, yields the value of the ancestor's
    //   computeLocalToWorldTransform computation.
    //
    // This is done by defining (for IrXformable prims) and dispatching (for
    // Xformable prims) a computation named \p ancestorComputationName.
    //
    void
    InheritedTransformationComputation(
        const TfToken &computationName,
        const TfToken &ancestorComputationName,
        const TfToken &spaceAttributeName);
};

} // anonymous namespace

TF_DEFINE_PRIVATE_TOKENS(
    _tokens,

    (computedDefaultSpace)
    (computedRestSpace)
    (defaultTransRotOffsetXf)
    (localRestXf)
    (parentDefaultSpace)
    (parentRestSpace)
    (restTransRotOffsetXf)
);

EXEC_REGISTER_COMPUTATIONS_FOR_SCHEMA(ExecIrXformable)
{
    _Builder builder(self);

    builder.InputAttribute<double>(ExecIrXformableTokens->avarsTx);
    builder.InputAttribute<double>(ExecIrXformableTokens->avarsTy);
    builder.InputAttribute<double>(ExecIrXformableTokens->avarsTz);
    builder.InputAttribute<double>(ExecIrXformableTokens->avarsRx);
    builder.InputAttribute<double>(ExecIrXformableTokens->avarsRy);
    builder.InputAttribute<double>(ExecIrXformableTokens->avarsRz);
    builder.InputAttribute<double>(ExecIrXformableTokens->avarsRspin);
    builder.InputAttribute<TfToken>(
        ExecIrXformableTokens->avarsRotationOrder);
    builder.InputAttribute<GfMatrix4d>(
        ExecIrXformableTokens->avarsDefaultSpace);

    // avars:defaultSpace has an expression that simply returns the value of
    // default:space.
    self.AttributeExpression(ExecIrXformableTokens->avarsDefaultSpace)
        .Inputs(Prim().AttributeValue<GfMatrix4d>(
                    ExecIrXformableTokens->defaultSpace))
        .Callback(+[](const VdfContext &ctx) -> GfMatrix4d {
            return ctx.GetInputValue<GfMatrix4d>(
                ExecIrXformableTokens->defaultSpace);
        });

    builder.InputAttribute<double>(
        ExecIrXformableTokens->avarsUnitScaleFactor);

    builder.InputAttribute<double>(ExecIrXformableTokens->restTx);
    builder.InputAttribute<double>(ExecIrXformableTokens->restTy);
    builder.InputAttribute<double>(ExecIrXformableTokens->restTz);
    builder.InputAttribute<double>(ExecIrXformableTokens->restRx);
    builder.InputAttribute<double>(ExecIrXformableTokens->restRy);
    builder.InputAttribute<double>(ExecIrXformableTokens->restRz);
    builder.InputAttribute<GfMatrix4d>(ExecIrXformableTokens->restSpace);

    builder.InputAttribute<double>(ExecIrXformableTokens->defaultTx);
    builder.InputAttribute<double>(ExecIrXformableTokens->defaultTy);
    builder.InputAttribute<double>(ExecIrXformableTokens->defaultTz);
    builder.InputAttribute<double>(ExecIrXformableTokens->defaultRx);
    builder.InputAttribute<double>(ExecIrXformableTokens->defaultRy);
    builder.InputAttribute<double>(ExecIrXformableTokens->defaultRz);
    builder.InputAttribute<GfMatrix4d>(ExecIrXformableTokens->defaultSpace);

    // Compute default:space by taking the offsets defined by the default
    // scalars and combining them with the parent default space.
    // 
    // Default space is a world space transform representing the 'zero' position
    // for posing. This may be different from the rest pose in order to provide
    // default scaling for a character, to make variants, or to set a more
    // natural starting place for animation controls. Default space combines the
    // effect of that local transform with the rest space offset.
    self.AttributeExpression(ExecIrXformableTokens->defaultSpace)
        .Inputs(
            Prim().Computation<GfMatrix4d>(_tokens->defaultTransRotOffsetXf),
            Prim().Computation<GfMatrix4d>(_tokens->localRestXf),
            Prim().AttributeValue<GfMatrix4d>(
                ExecIrXformableTokens->parentDefaultSpace))
        .Callback(+[](const VdfContext &ctx) -> GfMatrix4d {
            return ExecIr_ComputeDefaultSpace(
                ctx.GetInputValue<GfMatrix4d>(_tokens->defaultTransRotOffsetXf),
                GfMatrix4d(1), // defaultScaleXf
                ctx.GetInputValue<GfMatrix4d>(_tokens->localRestXf),
                ctx.GetInputValue<GfMatrix4d>(
                    ExecIrXformableTokens->parentDefaultSpace));
        });

    // The defaultTransRotOffsetXf computation represents the local authored
    // offset from where defaultSpace would normally be relative to the
    // parent. Note that we don't pass in handedness here, because this offset
    // will be applied to rest space, which already incorporates handedness.
    self.PrimComputation(_tokens->defaultTransRotOffsetXf)
        .Inputs(
            AttributeValue<double>(ExecIrXformableTokens->defaultTx),
            AttributeValue<double>(ExecIrXformableTokens->defaultTy),
            AttributeValue<double>(ExecIrXformableTokens->defaultTz),
            AttributeValue<double>(ExecIrXformableTokens->defaultRx),
            AttributeValue<double>(ExecIrXformableTokens->defaultRy),
            AttributeValue<double>(ExecIrXformableTokens->defaultRz))
        .Callback(+[](const VdfContext &ctx) {
            return ExecIr_ComputeLocalXf(
                ctx.GetInputValue<double>(ExecIrXformableTokens->defaultTx),
                ctx.GetInputValue<double>(ExecIrXformableTokens->defaultTy),
                ctx.GetInputValue<double>(ExecIrXformableTokens->defaultTz),
                0.0, // rSpin
                ctx.GetInputValue<double>(ExecIrXformableTokens->defaultRx),
                ctx.GetInputValue<double>(ExecIrXformableTokens->defaultRy),
                ctx.GetInputValue<double>(ExecIrXformableTokens->defaultRz),
                ExecIrRotationOrderTokens->XYZ,
                ctx);
        });

    // rest:space is the value of the restTransRotOffsetXf computation relative
    // to the parentRestSpace.
    // 
    // Rest space is a world space transform representing the position of this
    // transformable object before any posing has happened. The fallback value
    // combines the effect of the restTx/y/z/... attributes to yield a local
    // transform. restSpace inherits from the transform parent. The connected
    // value is orthonormalized.
    self.AttributeExpression(ExecIrXformableTokens->restSpace)
        .Inputs(
            Prim().Computation<GfMatrix4d>(_tokens->restTransRotOffsetXf),
            Prim().Computation<GfMatrix4d>(_tokens->parentRestSpace))
        .Callback(+[](const VdfContext &ctx) {
            return
                ctx.GetInputValue<GfMatrix4d>(_tokens->restTransRotOffsetXf) *
                ctx.GetInputValue<GfMatrix4d>(_tokens->parentRestSpace);
        });

    // Compute the local transform that is the result of combining the authored
    // values of the rest space scalars.
    self.PrimComputation(_tokens->restTransRotOffsetXf)
        .Inputs(
            AttributeValue<double>(ExecIrXformableTokens->restTx),
            AttributeValue<double>(ExecIrXformableTokens->restTy),
            AttributeValue<double>(ExecIrXformableTokens->restTz),
            AttributeValue<double>(ExecIrXformableTokens->restRx),
            AttributeValue<double>(ExecIrXformableTokens->restRy),
            AttributeValue<double>(ExecIrXformableTokens->restRz))
        .Callback(+[](const VdfContext &ctx) {
            return ExecIr_ComputeLocalXf(
                ctx.GetInputValue<double>(ExecIrXformableTokens->restTx),
                ctx.GetInputValue<double>(ExecIrXformableTokens->restTy),
                ctx.GetInputValue<double>(ExecIrXformableTokens->restTz),
                0.0, // rSpin
                ctx.GetInputValue<double>(ExecIrXformableTokens->restRx),
                ctx.GetInputValue<double>(ExecIrXformableTokens->restRy),
                ctx.GetInputValue<double>(ExecIrXformableTokens->restRz),
                ExecIrRotationOrderTokens->XYZ,
                ctx);
        });

    // Compute local transform that defines the delta from the parent.
    self.PrimComputation(_tokens->localRestXf)
        .Inputs(
            AttributeValue<GfMatrix4d>(ExecIrXformableTokens->restSpace),
            Computation<GfMatrix4d>(_tokens->parentRestSpace))
        .Callback(+[](const VdfContext &ctx) {
            return
                ctx.GetInputValue<GfMatrix4d>(
                    ExecIrXformableTokens->restSpace) *
                ctx.GetInputValue<GfMatrix4d>(
                    _tokens->parentRestSpace).GetInverse();
        });

    // Define the parentRestSpace computation, which computes the parent rest
    // space.
    builder.InheritedTransformationComputation(
        _tokens->parentRestSpace,
        _tokens->computedRestSpace,
        ExecIrXformableTokens->restSpace);

    builder.OutputAttribute<GfMatrix4d>(ExecIrXformableTokens->posedSpace);
    builder.OutputAttribute<GfMatrix4d>(
        ExecIrXformableTokens->posedDefaultSpace);
    
    builder.InputAttribute<GfMatrix4d>(ExecIrXformableTokens->parentSpace);
    builder.InputAttribute<GfMatrix4d>(
        ExecIrXformableTokens->parentDefaultSpace);

    self.AttributeExpression(ExecIrXformableTokens->parentDefaultSpace)
        .Inputs(Prim().Computation<GfMatrix4d>(_tokens->parentDefaultSpace))
        .Callback(+[](const VdfContext &ctx) -> GfMatrix4d {
            return ctx.GetInputValue<GfMatrix4d>(_tokens->parentDefaultSpace);
        });

    // Define the parentDefaultSpace computation, which computes the parent
    // default space.
    builder.InheritedTransformationComputation(
        _tokens->parentDefaultSpace,
        _tokens->computedDefaultSpace,
        ExecIrXformableTokens->defaultSpace);
}

template <typename ValueType>
void
_Builder::InputAttribute(const TfToken &attributeName)
{
    using namespace exec_registration;

    // The 'computeDesiredValue' computation gets its value from the
    // 'computeDesiredValue' computation via incoming connections--but only if
    // there is exactly one desired value present. Otherwise, no value is
    // returned. An error is emitted if more than one desired value is present.
    _self.AttributeComputation(
        attributeName, ExecIrComputationTokens->computeDesiredValue)
        .Callback<ValueType>(&_GetExactlyOneDesiredValue<ValueType>)
        .Inputs(
            IncomingConnections<ValueType>(
                ExecIrComputationTokens->computeDesiredValue));
}

template <typename ValueType>
void
_Builder::OutputAttribute(const TfToken &attributeName)
{
    // Output attributes support dataflow across connections.
    _ConnectionDataflowExpression<ValueType>(attributeName);

    // Output attributes support computing desired values, for inversion.
    _DesiredValueComputations<ValueType>(attributeName);
}

void
_Builder::InheritedTransformationComputation(
    const TfToken &computationName,
    const TfToken &ancestorComputationName,
    const TfToken &spaceAttributeName)
{
    using namespace exec_registration;

    // This computation finds the ancestorComputationName computation on the
    // nearest namespace ancestor that defines it.
    _self.PrimComputation(computationName)
        .Inputs(
            NamespaceAncestor<GfMatrix4d>(ancestorComputationName)
                .FallsBackToDispatched())
        .Callback<GfMatrix4d>([ancestorComputationName](const VdfContext &ctx) {
            const GfMatrix4d *const valuePtr =
                ctx.GetInputValuePtr<GfMatrix4d>(ancestorComputationName);
            ctx.SetOutput(valuePtr ? *valuePtr : GfMatrix4d(1));
        });

    // Define an ancestorComputationName computation for all IrXformable prims
    // that returns the value of the attribute with the name given by
    // spaceAttributeName.
    _self.PrimComputation(ancestorComputationName)
        .Inputs(AttributeValue<GfMatrix4d>(spaceAttributeName))
        .Callback<GfMatrix4d>([spaceAttributeName](const VdfContext &ctx) {
            ctx.SetOutputToReferenceInput(spaceAttributeName);
        });

    // Dispatch an ancestorComputationName computation onto all Xformable prims
    // that returns the value of the 'computeLocalToWorldTransform' computation.
    _self.DispatchedPrimComputation(
        ancestorComputationName,
        TfType::Find<UsdGeomXformable>())
        .Inputs(Computation<GfMatrix4d>(
                    ExecGeomXformableTokens->computeLocalToWorldTransform))
        .Callback<GfMatrix4d>(+[](const VdfContext &ctx) {
            ctx.SetOutputToReferenceInput(
                ExecGeomXformableTokens->computeLocalToWorldTransform);
        });
}
