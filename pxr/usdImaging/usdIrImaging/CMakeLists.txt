set(PXR_PREFIX pxr/usdIrImaging)
set(PXR_PACKAGE usdIrImaging)

pxr_library(usdIfImaging
    LIBRARIES
        execIr
        gf
        hd
        tf
        usd
        usdGeom
        usdImaging

    PUBLIC_CLASSES
        jointScopeAdapter
        tokens

    PUBLIC_HEADERS
        api.h

    RESOURCE_FILES
        plugInfo.json
)
