//
// Copyright 2026 Pixar
//
// Licensed under the terms set forth in the LICENSE.txt file available at
// https://openusd.org/license.
//
#ifndef PXR_IMAGING_HDSI_BACK_PLATE_SCENE_INDEX_H
#define PXR_IMAGING_HDSI_BACK_PLATE_SCENE_INDEX_H
 
#include "pxr/imaging/hdsi/api.h"
#include "pxr/imaging/hd/sceneIndex.h"
#include "pxr/imaging/hd/filteringSceneIndex.h"

#include <unordered_set>

PXR_NAMESPACE_OPEN_SCOPE
 
TF_DECLARE_WEAK_AND_REF_PTRS(HdsiBackPlateSceneIndex);
 
class HdsiBackPlateSceneIndex :
    public HdSingleInputFilteringSceneIndexBase
{
public:
    HDSI_API
    static HdsiBackPlateSceneIndexRefPtr
    New(const HdSceneIndexBaseRefPtr &inputSceneIndex);
 
    HDSI_API
    HdSceneIndexPrim GetPrim(const SdfPath &primPath) const override final;
 
    HDSI_API
    SdfPathVector GetChildPrimPaths(const SdfPath &primPath) const override final;
 
protected:
    HDSI_API
    void _PrimsAdded(
        const HdSceneIndexBase &sender,
        const HdSceneIndexObserver::AddedPrimEntries &entries) override final;
 
    HDSI_API
    void _PrimsRemoved(
        const HdSceneIndexBase &sender,
        const HdSceneIndexObserver::RemovedPrimEntries &entries) override final;
 
    HDSI_API
    void _PrimsDirtied(
        const HdSceneIndexBase &sender,
        const HdSceneIndexObserver::DirtiedPrimEntries &entries) override final;
 
    HDSI_API
    HdsiBackPlateSceneIndex(
        const HdSceneIndexBaseRefPtr &inputSceneIndex);

private:
    void
    _RemoveSubtree(
        const SdfPath &primPath,
        SdfPathSet * const removedBackPlatePrims);
 
    void
    _AddBackPlateChildren(
        const SdfPath &primPath,
        SdfPathSet * const addedBackPlatePrims);
    void
    _DirtyBackPlateChildren(
        const SdfPath &primPath,
        HdSceneIndexObserver::DirtiedPrimEntries * const 
            dirtiedBackPlatePrims);

    HdSceneIndexPrim
    _GetMeshOrMaterialSiPrim(
        const SdfPath &plateInstancePath,
        const TfToken &plateChildType) const;
    
    using _ChildrenNames = std::unordered_set<TfToken,TfToken::HashFunctor>;
    using _PathToDirectChildrenMap = std::map<SdfPath, _ChildrenNames>;

    // Stores the direct descendents' names of each prim path
    _PathToDirectChildrenMap _pathToDirectChildrenMap;
};
 
PXR_NAMESPACE_CLOSE_SCOPE
 
#endif //PXR_IMAGING_HDSI_BACK_PLATE_SCENE_INDEX_H