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

#ifndef PXR_IMAGING_HD_EXT_COMPUTATION_SCHEMA_H
#define PXR_IMAGING_HD_EXT_COMPUTATION_SCHEMA_H

/// \file

#include "pxr/imaging/hd/api.h"
#include "pxr/imaging/hd/schemaTypeDefs.h"

#include "pxr/imaging/hd/schema.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

// --(BEGIN CUSTOM CODE: Declares)--

using HdExtComputationCpuCallbackSharedPtr =
    std::shared_ptr<class HdExtComputationCpuCallback>;
using HdExtComputationCpuCallbackDataSource =
    HdTypedSampledDataSource<HdExtComputationCpuCallbackSharedPtr>;
using HdExtComputationCpuCallbackDataSourceHandle =
    HdExtComputationCpuCallbackDataSource::Handle;

// --(END CUSTOM CODE: Declares)--

#define HD_EXT_COMPUTATION_SCHEMA_TOKENS \
    (extComputation) \
    (inputValues) \
    (inputComputations) \
    (outputs) \
    (glslKernel) \
    (cpuCallback) \
    (dispatchCount) \
    (elementCount) \

TF_DECLARE_PUBLIC_TOKENS(HdExtComputationSchemaTokens, HD_API,
    HD_EXT_COMPUTATION_SCHEMA_TOKENS);

//-----------------------------------------------------------------------------


class HdExtComputationSchema : public HdSchema
{
public:
    /// \name Schema retrieval
    /// @{

    HdExtComputationSchema(HdContainerDataSourceHandle container)
      : HdSchema(container) {}

    /// Retrieves a container data source with the schema's default name token
    /// "extComputation" from the parent container and constructs a
    /// HdExtComputationSchema instance.
    /// Because the requested container data source may not exist, the result
    /// should be checked with IsDefined() or a bool comparison before use.
    HD_API
    static HdExtComputationSchema GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer);

    /// @}

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

    /// \name Member accessor
    /// @{

    HD_API
    HdSampledDataSourceContainerSchema GetInputValues() const;

    HD_API
    HdExtComputationInputComputationContainerSchema GetInputComputations() const;

    HD_API
    HdExtComputationOutputContainerSchema GetOutputs() const;

    HD_API
    HdStringDataSourceHandle GetGlslKernel() const;

    HD_API
    HdExtComputationCpuCallbackDataSourceHandle GetCpuCallback() const;

    HD_API
    HdSizetDataSourceHandle GetDispatchCount() const;

    HD_API
    HdSizetDataSourceHandle GetElementCount() const; 

    /// @}

    /// \name Schema location
    /// @{

    /// Returns a token where the container representing this schema is found in
    /// a container by default.
    HD_API
    static const TfToken &GetSchemaToken();

    /// Returns an HdDataSourceLocator (relative to the prim-level data source)
    /// where the container representing this schema is found by default.
    HD_API
    static const HdDataSourceLocator &GetDefaultLocator();

    /// @}

    /// \name Data source locators for members
    ///
    /// The following methods return an HdDataSourceLocator (relative to the
    /// prim-level data source) where the data source for a member can be found.
    ///
    /// This is often useful for checking intersection against the
    /// HdDataSourceLocatorSet sent with HdDataSourceObserver::PrimsDirtied.
    /// @{

    /// Prim-level relative data source locator to locate inputValues.
    HD_API
    static const HdDataSourceLocator &GetInputValuesLocator();

    /// Prim-level relative data source locator to locate inputComputations.
    HD_API
    static const HdDataSourceLocator &GetInputComputationsLocator();

    /// Prim-level relative data source locator to locate outputs.
    HD_API
    static const HdDataSourceLocator &GetOutputsLocator();

    /// Prim-level relative data source locator to locate glslKernel.
    HD_API
    static const HdDataSourceLocator &GetGlslKernelLocator();

    /// Prim-level relative data source locator to locate cpuCallback.
    HD_API
    static const HdDataSourceLocator &GetCpuCallbackLocator();

    /// Prim-level relative data source locator to locate dispatchCount.
    HD_API
    static const HdDataSourceLocator &GetDispatchCountLocator();

    /// Prim-level relative data source locator to locate elementCount.
    HD_API
    static const HdDataSourceLocator &GetElementCountLocator();
    /// @} 

    /// \name Schema construction
    /// @{

    /// \deprecated Use Builder instead.
    ///
    /// Builds a container data source which includes the provided child data
    /// sources. Parameters with nullptr values are excluded. This is a
    /// low-level interface. For cases in which it's desired to define
    /// the container with a sparse set of child fields, the Builder class
    /// is often more convenient and readable.
    HD_API
    static HdContainerDataSourceHandle
    BuildRetained(
        const HdContainerDataSourceHandle &inputValues,
        const HdContainerDataSourceHandle &inputComputations,
        const HdContainerDataSourceHandle &outputs,
        const HdStringDataSourceHandle &glslKernel,
        const HdExtComputationCpuCallbackDataSourceHandle &cpuCallback,
        const HdSizetDataSourceHandle &dispatchCount,
        const HdSizetDataSourceHandle &elementCount
    );

    /// \class HdExtComputationSchema::Builder
    /// 
    /// Utility class for setting sparse sets of child data source fields to be
    /// filled as arguments into BuildRetained. Because all setter methods
    /// return a reference to the instance, this can be used in the "builder
    /// pattern" form.
    class Builder
    {
    public:
        HD_API
        Builder &SetInputValues(
            const HdContainerDataSourceHandle &inputValues);
        HD_API
        Builder &SetInputComputations(
            const HdContainerDataSourceHandle &inputComputations);
        HD_API
        Builder &SetOutputs(
            const HdContainerDataSourceHandle &outputs);
        HD_API
        Builder &SetGlslKernel(
            const HdStringDataSourceHandle &glslKernel);
        HD_API
        Builder &SetCpuCallback(
            const HdExtComputationCpuCallbackDataSourceHandle &cpuCallback);
        HD_API
        Builder &SetDispatchCount(
            const HdSizetDataSourceHandle &dispatchCount);
        HD_API
        Builder &SetElementCount(
            const HdSizetDataSourceHandle &elementCount);

        /// Returns a container data source containing the members set thus far.
        HD_API
        HdContainerDataSourceHandle Build();

    private:
        HdContainerDataSourceHandle _inputValues;
        HdContainerDataSourceHandle _inputComputations;
        HdContainerDataSourceHandle _outputs;
        HdStringDataSourceHandle _glslKernel;
        HdExtComputationCpuCallbackDataSourceHandle _cpuCallback;
        HdSizetDataSourceHandle _dispatchCount;
        HdSizetDataSourceHandle _elementCount;

    };

    /// @}
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif