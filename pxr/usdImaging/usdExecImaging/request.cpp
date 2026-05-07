//
// Copyright 2026 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#include "pxr/usdImaging/usdExecImaging/request.h"

#include "pxr/base/tf/scopeDescription.h"
#include "pxr/base/tf/stringUtils.h"
#include "pxr/usdImaging/usdExecImaging/adapterRegistry.h"
#include "pxr/usdImaging/usdExecImaging/debugCodes.h"
#include "pxr/usdImaging/usdExecImaging/primAdapter.h"
#include "pxr/usdImaging/usdExecImaging/requestBuilderImpl.h"

#include "pxr/base/tf/diagnostic.h"
#include "pxr/base/trace/trace.h"
#include "pxr/exec/exec/systemDiagnostics.h"
#include "pxr/usd/usd/primRange.h"
#include "pxr/usd/usd/stage.h"

#include <utility>

PXR_NAMESPACE_OPEN_SCOPE

UsdExecImaging_RequestSharedPtr
UsdExecImaging_Request::New(UsdStageRefPtr stage)
{
    TF_DEBUG_MSG(USDEXECIMAGING_REQUEST, "[%s]\n", TF_FUNC_NAME().c_str());

    if (!TF_VERIFY(stage)) {
        return nullptr;
    }

    return std::shared_ptr<UsdExecImaging_Request>(
        new UsdExecImaging_Request(std::move(stage)));
}

UsdExecImaging_Request::UsdExecImaging_Request(UsdStageRefPtr stage)
    : _stage(std::move(stage))
    , _requiresRebuild(true)
    , _graphFileIndex(0)
{
    _system.emplace(_stage);
}

void
UsdExecImaging_Request::Refresh()
{
    TRACE_FUNCTION();
    TF_DEBUG_MSG(USDEXECIMAGING_REQUEST, "[%s]\n", TF_FUNC_NAME().c_str());

    if (_requiresRebuild || !_request || !_request->IsValid()) {
        _Rebuild();
    }
}

void
UsdExecImaging_Request::_Rebuild()
{
    TRACE_FUNCTION();
    TF_DEBUG_MSG(USDEXECIMAGING_REQUEST, "[%s]\n", TF_FUNC_NAME().c_str());

    // Prim adapters use this object to add value keys to the request.
    UsdExecImaging_RequestBuilderImpl requestBuilder;

    for (const UsdPrim &prim : _stage->Traverse()) {
        // Get the adpater for this prim. If there is no adapter, then skip
        // this prim.
        const UsdExecImagingPrimAdapter *const primAdapter =
            UsdExecImaging_AdapterRegistry::GetPrimAdapter(prim);
        if (!primAdapter) {
            continue;
        }

        // Add value keys for this prim.
        TF_DEBUG_MSG(USDEXECIMAGING_REQUEST,
            "[%s] Adapting prim %s\n",
            TF_FUNC_NAME().c_str(),
            prim.GetPath().GetText());
        requestBuilder.SetAdaptedPrim(prim, *primAdapter);
        primAdapter->BuildRequest(prim, requestBuilder);
    }

    // Build the exec request.
    _request = _system->BuildRequest(requestBuilder.TakeValueKeys());

    // Save the value key map gathered by the request builder.
    _valueKeyMap = requestBuilder.TakeValueKeyMap();

    // The request no longer requires rebuilding.
    _requiresRebuild = false;

    // If enabled, write the exec network to a file.
    if (TfDebug::IsEnabled(USDEXECIMAGING_GRAPH_AFTER_REBUILD)) {
        TF_DESCRIBE_SCOPE("Writing exec network to file");
        TRACE_FUNCTION_SCOPE("Write exec network to file");

        const std::string filename =
            TfStringPrintf("usdExecImaging_Request_%d.dot", _graphFileIndex++);

        TF_DEBUG_MSG(USDEXECIMAGING_GRAPH_AFTER_REBUILD,
            "[%s] Writing %s\n",
            TF_FUNC_NAME().c_str(),
            filename.c_str());
        
        // Ensure the request has been compiled or else the graph may be empty.
        _system->PrepareRequest(*_request);
        
        ExecSystem::Diagnostics diagnostics(&_system.value());
        diagnostics.GraphNetwork(filename.c_str());
    }
}

PXR_NAMESPACE_CLOSE_SCOPE
