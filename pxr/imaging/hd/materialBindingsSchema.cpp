//
// Copyright 2023 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdSchemaDefs.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "pxr/imaging/hd/materialBindingsSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdMaterialBindingsSchemaTokens,
    HD_MATERIAL_BINDINGS_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--

HdMaterialBindingSchema
HdMaterialBindingsSchema::GetMaterialBinding() const
{
    return HdMaterialBindingSchema(
        _GetTypedDataSource<HdContainerDataSource>(
            HdMaterialBindingsSchemaTokens->allPurpose));
}

HdMaterialBindingSchema
HdMaterialBindingsSchema::GetMaterialBinding(TfToken const &purpose) const
{
    if (auto b = _GetTypedDataSource<HdContainerDataSource>(purpose)) {
        return HdMaterialBindingSchema(b);
    }

    // If we can't find the purpose-specific binding, return the fallback.
    return GetMaterialBinding();
}

// --(END CUSTOM CODE: Schema Methods)--

/*static*/
HdContainerDataSourceHandle
HdMaterialBindingsSchema::BuildRetained(
    const size_t count,
    const TfToken * const names,
    const HdDataSourceBaseHandle * const values)
{
    return HdRetainedContainerDataSource::New(count, names, values);
}

/*static*/
HdMaterialBindingsSchema
HdMaterialBindingsSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdMaterialBindingsSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdMaterialBindingsSchemaTokens->materialBindings))
        : nullptr);
}

/*static*/
const TfToken &
HdMaterialBindingsSchema::GetSchemaToken()
{
    return HdMaterialBindingsSchemaTokens->materialBindings;
}

/*static*/
const HdDataSourceLocator &
HdMaterialBindingsSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
} 

PXR_NAMESPACE_CLOSE_SCOPE