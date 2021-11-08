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
<<<<<<< HEAD:pxr/usd/usdLux/meshLightAPI.h
#ifndef USDLUX_GENERATED_MESHLIGHTAPI_H
#define USDLUX_GENERATED_MESHLIGHTAPI_H

/// \file usdLux/meshLightAPI.h

#include "pxr/pxr.h"
#include "pxr/usd/usdLux/api.h"
#include "pxr/usd/usd/apiSchemaBase.h"
=======
#ifndef USDCONTRIVED_GENERATED_DERIVEDNONAPPLIEDAPI_H
#define USDCONTRIVED_GENERATED_DERIVEDNONAPPLIEDAPI_H

/// \file usdContrived/derivedNonAppliedAPI.h

#include "pxr/pxr.h"
#include "pxr/usd/usdContrived/api.h"
#include "pxr/usd/usdContrived/nonAppliedAPI.h"
>>>>>>> upstream/dev:pxr/usd/usd/testenv/testUsdSchemaGen/baseline/headerTerminatorString/derivedNonAppliedAPI.h
#include "pxr/usd/usd/prim.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/usd/usdLux/tokens.h"

#include "pxr/base/vt/value.h"

#include "pxr/base/gf/vec3d.h"
#include "pxr/base/gf/vec3f.h"
#include "pxr/base/gf/matrix4d.h"

#include "pxr/base/tf/token.h"
#include "pxr/base/tf/type.h"

PXR_NAMESPACE_OPEN_SCOPE

class SdfAssetPath;

// -------------------------------------------------------------------------- //
<<<<<<< HEAD:pxr/usd/usdLux/meshLightAPI.h
// MESHLIGHTAPI                                                               //
// -------------------------------------------------------------------------- //

/// \class UsdLuxMeshLightAPI
///
/// This is the preferred API schema to apply to 
/// \ref UsdGeomMesh "Mesh" type prims when adding light behaviors to a mesh. 
/// At its base, this API schema has the built-in behavior of applying LightAPI 
/// to the mesh and overriding the default materialSyncMode to allow the 
/// emission/glow of the bound material to affect the color of the light. 
/// But, it additionally serves as a hook for plugins to attach additional 
/// properties to "mesh lights" through the creation of API schemas which are 
/// authored to auto-apply to MeshLightAPI.
/// \see \ref Usd_AutoAppliedAPISchemas
/// 
///
/// For any described attribute \em Fallback \em Value or \em Allowed \em Values below
/// that are text/tokens, the actual token is published and defined in \ref UsdLuxTokens.
/// So to set an attribute to the value "rightHanded", use UsdLuxTokens->rightHanded
/// as the value.
///
class UsdLuxMeshLightAPI : public UsdAPISchemaBase
=======
// DERIVEDNONAPPLIEDAPI                                                       //
// -------------------------------------------------------------------------- //

/// \class UsdContrivedDerivedNonAppliedAPI
///
///
class UsdContrivedDerivedNonAppliedAPI : public UsdContrivedNonAppliedAPI
>>>>>>> upstream/dev:pxr/usd/usd/testenv/testUsdSchemaGen/baseline/headerTerminatorString/derivedNonAppliedAPI.h
{
public:
    /// Compile time constant representing what kind of schema this class is.
    ///
    /// \sa UsdSchemaKind
<<<<<<< HEAD:pxr/usd/usdLux/meshLightAPI.h
    static const UsdSchemaKind schemaKind = UsdSchemaKind::SingleApplyAPI;

    /// Construct a UsdLuxMeshLightAPI on UsdPrim \p prim .
    /// Equivalent to UsdLuxMeshLightAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdLuxMeshLightAPI(const UsdPrim& prim=UsdPrim())
        : UsdAPISchemaBase(prim)
    {
    }

    /// Construct a UsdLuxMeshLightAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdLuxMeshLightAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdLuxMeshLightAPI(const UsdSchemaBase& schemaObj)
        : UsdAPISchemaBase(schemaObj)
=======
    static const UsdSchemaKind schemaKind = UsdSchemaKind::NonAppliedAPI;

    /// Construct a UsdContrivedDerivedNonAppliedAPI on UsdPrim \p prim .
    /// Equivalent to UsdContrivedDerivedNonAppliedAPI::Get(prim.GetStage(), prim.GetPath())
    /// for a \em valid \p prim, but will not immediately throw an error for
    /// an invalid \p prim
    explicit UsdContrivedDerivedNonAppliedAPI(const UsdPrim& prim=UsdPrim())
        : UsdContrivedNonAppliedAPI(prim)
    {
    }

    /// Construct a UsdContrivedDerivedNonAppliedAPI on the prim held by \p schemaObj .
    /// Should be preferred over UsdContrivedDerivedNonAppliedAPI(schemaObj.GetPrim()),
    /// as it preserves SchemaBase state.
    explicit UsdContrivedDerivedNonAppliedAPI(const UsdSchemaBase& schemaObj)
        : UsdContrivedNonAppliedAPI(schemaObj)
>>>>>>> upstream/dev:pxr/usd/usd/testenv/testUsdSchemaGen/baseline/headerTerminatorString/derivedNonAppliedAPI.h
    {
    }

    /// Destructor.
<<<<<<< HEAD:pxr/usd/usdLux/meshLightAPI.h
    USDLUX_API
    virtual ~UsdLuxMeshLightAPI();
=======
    USDCONTRIVED_API
    virtual ~UsdContrivedDerivedNonAppliedAPI();
>>>>>>> upstream/dev:pxr/usd/usd/testenv/testUsdSchemaGen/baseline/headerTerminatorString/derivedNonAppliedAPI.h

    /// Return a vector of names of all pre-declared attributes for this schema
    /// class and all its ancestor classes.  Does not include attributes that
    /// may be authored by custom/extended methods of the schemas involved.
    USDCONTRIVED_API
    static const TfTokenVector &
    GetSchemaAttributeNames(bool includeInherited=true);

<<<<<<< HEAD:pxr/usd/usdLux/meshLightAPI.h
    /// Return a UsdLuxMeshLightAPI holding the prim adhering to this
=======
    /// Return a UsdContrivedDerivedNonAppliedAPI holding the prim adhering to this
>>>>>>> upstream/dev:pxr/usd/usd/testenv/testUsdSchemaGen/baseline/headerTerminatorString/derivedNonAppliedAPI.h
    /// schema at \p path on \p stage.  If no prim exists at \p path on
    /// \p stage, or if the prim at that path does not adhere to this schema,
    /// return an invalid schema object.  This is shorthand for the following:
    ///
    /// \code
<<<<<<< HEAD:pxr/usd/usdLux/meshLightAPI.h
    /// UsdLuxMeshLightAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDLUX_API
    static UsdLuxMeshLightAPI
    Get(const UsdStagePtr &stage, const SdfPath &path);


    /// Returns true if this <b>single-apply</b> API schema can be applied to 
    /// the given \p prim. If this schema can not be a applied to the prim, 
    /// this returns false and, if provided, populates \p whyNot with the 
    /// reason it can not be applied.
    /// 
    /// Note that if CanApply returns false, that does not necessarily imply
    /// that calling Apply will fail. Callers are expected to call CanApply
    /// before calling Apply if they want to ensure that it is valid to 
    /// apply a schema.
    /// 
    /// \sa UsdPrim::GetAppliedSchemas()
    /// \sa UsdPrim::HasAPI()
    /// \sa UsdPrim::CanApplyAPI()
    /// \sa UsdPrim::ApplyAPI()
    /// \sa UsdPrim::RemoveAPI()
    ///
    USDLUX_API
    static bool 
    CanApply(const UsdPrim &prim, std::string *whyNot=nullptr);

    /// Applies this <b>single-apply</b> API schema to the given \p prim.
    /// This information is stored by adding "MeshLightAPI" to the 
    /// token-valued, listOp metadata \em apiSchemas on the prim.
    /// 
    /// \return A valid UsdLuxMeshLightAPI object is returned upon success. 
    /// An invalid (or empty) UsdLuxMeshLightAPI object is returned upon 
    /// failure. See \ref UsdPrim::ApplyAPI() for conditions 
    /// resulting in failure. 
    /// 
    /// \sa UsdPrim::GetAppliedSchemas()
    /// \sa UsdPrim::HasAPI()
    /// \sa UsdPrim::CanApplyAPI()
    /// \sa UsdPrim::ApplyAPI()
    /// \sa UsdPrim::RemoveAPI()
    ///
    USDLUX_API
    static UsdLuxMeshLightAPI 
    Apply(const UsdPrim &prim);
=======
    /// UsdContrivedDerivedNonAppliedAPI(stage->GetPrimAtPath(path));
    /// \endcode
    ///
    USDCONTRIVED_API
    static UsdContrivedDerivedNonAppliedAPI
    Get(const UsdStagePtr &stage, const SdfPath &path);

>>>>>>> upstream/dev:pxr/usd/usd/testenv/testUsdSchemaGen/baseline/headerTerminatorString/derivedNonAppliedAPI.h

protected:
    /// Returns the kind of schema this class belongs to.
    ///
    /// \sa UsdSchemaKind
    USDCONTRIVED_API
    UsdSchemaKind _GetSchemaKind() const override;

private:
    // needs to invoke _GetStaticTfType.
    friend class UsdSchemaRegistry;
    USDCONTRIVED_API
    static const TfType &_GetStaticTfType();

    static bool _IsTypedSchema();

    // override SchemaBase virtuals.
    USDCONTRIVED_API
    const TfType &_GetTfType() const override;

public:
    // ===================================================================== //
    // Feel free to add custom code below this line, it will be preserved by 
    // the code generator. 
    //
    // Just remember to: 
    //  - Close the class declaration with }; 
    //  - Close the namespace with PXR_NAMESPACE_CLOSE_SCOPE
    //  - Close the include guard with #endif
    // ===================================================================== //
    // --(BEGIN CUSTOM CODE)--
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // custom terminator string
