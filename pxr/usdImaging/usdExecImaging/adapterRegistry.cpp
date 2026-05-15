//
// Copyright 2026 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usdImaging/usdExecImaging/adapterRegistry.h"

#include "pxr/usdImaging/usdExecImaging/geomXformablePrimAdapter.h"
#include "pxr/usdImaging/usdExecImaging/irTransformablePrimAdapter.h"
#include "pxr/usdImaging/usdExecImaging/primAdapter.h"

#include "pxr/exec/execIr/tokens.h"
#include "pxr/usd/usdGeom/xformable.h"

PXR_NAMESPACE_OPEN_SCOPE

UsdExecImagingPrimAdapter *
UsdExecImaging_AdapterRegistry::GetPrimAdapter(const UsdPrim &prim)
{
    // TODO: The adapter currently has a few hard-coded adapter types. This
    // will change in the future to generically handle adapters registered in
    // plugins.

    if (prim.IsA<UsdGeomXformable>()) {
        using Adapter = UsdExecImaging_GeomXformablePrimAdapter;
        static Adapter adapter;
        return &adapter;
    }

    if (prim.IsA(ExecIrTransformableTokens->IrTransformable)) {
        using Adapter = UsdExecImaging_IrTransformablePrimAdapter;
        static Adapter adapter;
        return &adapter;
    }

    return nullptr;
}

PXR_NAMESPACE_CLOSE_SCOPE
