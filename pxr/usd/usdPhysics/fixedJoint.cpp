//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
#include "pxr/usd/usdPhysics/fixedJoint.h"
=======
#include "pxr/usd/usdPhysics/articulationRootAPI.h"
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"
#include "pxr/usd/usd/tokens.h"
=======
#include "pxr/usd/usdPhysics/fixedJoint.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"
>>>>>>> upstream/dev

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
=======
>>>>>>> upstream/dev
    TfType::Define<UsdPhysicsFixedJoint,
        TfType::Bases< UsdPhysicsJoint > >();
    
    // Register the usd prim typename as an alias under UsdSchemaBase. This
    // enables one to call
    // TfType::Find<UsdSchemaBase>().FindDerivedByName("PhysicsFixedJoint")
    // to find TfType<UsdPhysicsFixedJoint>, which is how IsA queries are
    // answered.
    TfType::AddAlias<UsdSchemaBase, UsdPhysicsFixedJoint>("PhysicsFixedJoint");
<<<<<<< HEAD
=======
    TfType::Define<UsdPhysicsArticulationRootAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
}

TF_DEFINE_PRIVATE_TOKENS(
    _schemaTokens,
    (PhysicsArticulationRootAPI)
);

/* virtual */
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
UsdPhysicsFixedJoint::~UsdPhysicsFixedJoint()
=======
UsdPhysicsArticulationRootAPI::~UsdPhysicsArticulationRootAPI()
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
=======
}

/* virtual */
UsdPhysicsFixedJoint::~UsdPhysicsFixedJoint()
>>>>>>> upstream/dev
{
}

/* static */
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
=======
>>>>>>> upstream/dev
UsdPhysicsFixedJoint
UsdPhysicsFixedJoint::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysicsFixedJoint();
    }
    return UsdPhysicsFixedJoint(stage->GetPrimAtPath(path));
}

/* static */
UsdPhysicsFixedJoint
UsdPhysicsFixedJoint::Define(
    const UsdStagePtr &stage, const SdfPath &path)
{
    static TfToken usdPrimTypeName("PhysicsFixedJoint");
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysicsFixedJoint();
    }
    return UsdPhysicsFixedJoint(
        stage->DefinePrim(path, usdPrimTypeName));
}

/* virtual */
UsdSchemaKind UsdPhysicsFixedJoint::_GetSchemaKind() const
{
    return UsdPhysicsFixedJoint::schemaKind;
<<<<<<< HEAD
=======
UsdPhysicsArticulationRootAPI
UsdPhysicsArticulationRootAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return UsdPhysicsArticulationRootAPI();
    }
    return UsdPhysicsArticulationRootAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind UsdPhysicsArticulationRootAPI::_GetSchemaKind() const
{
    return UsdPhysicsArticulationRootAPI::schemaKind;
}

/* static */
bool
UsdPhysicsArticulationRootAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<UsdPhysicsArticulationRootAPI>(whyNot);
}

/* static */
UsdPhysicsArticulationRootAPI
UsdPhysicsArticulationRootAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<UsdPhysicsArticulationRootAPI>()) {
        return UsdPhysicsArticulationRootAPI(prim);
    }
    return UsdPhysicsArticulationRootAPI();
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
=======
>>>>>>> upstream/dev
}

/* static */
const TfType &
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
UsdPhysicsFixedJoint::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysicsFixedJoint>();
=======
UsdPhysicsArticulationRootAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysicsArticulationRootAPI>();
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
=======
UsdPhysicsFixedJoint::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<UsdPhysicsFixedJoint>();
>>>>>>> upstream/dev
    return tfType;
}

/* static */
bool 
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
UsdPhysicsFixedJoint::_IsTypedSchema()
=======
UsdPhysicsArticulationRootAPI::_IsTypedSchema()
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
=======
UsdPhysicsFixedJoint::_IsTypedSchema()
>>>>>>> upstream/dev
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
UsdPhysicsFixedJoint::_GetTfType() const
=======
UsdPhysicsArticulationRootAPI::_GetTfType() const
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
=======
UsdPhysicsFixedJoint::_GetTfType() const
>>>>>>> upstream/dev
{
    return _GetStaticTfType();
}

/*static*/
const TfTokenVector&
<<<<<<< HEAD
<<<<<<< HEAD:pxr/usd/usdPhysics/fixedJoint.cpp
=======
>>>>>>> upstream/dev
UsdPhysicsFixedJoint::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames;
    static TfTokenVector allNames =
        UsdPhysicsJoint::GetSchemaAttributeNames(true);
<<<<<<< HEAD
=======
UsdPhysicsArticulationRootAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames;
    static TfTokenVector allNames =
        UsdAPISchemaBase::GetSchemaAttributeNames(true);
>>>>>>> upstream/dev:pxr/usd/usdPhysics/articulationRootAPI.cpp
=======
>>>>>>> upstream/dev

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--
