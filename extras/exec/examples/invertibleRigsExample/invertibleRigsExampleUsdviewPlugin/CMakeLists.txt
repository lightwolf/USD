set(PXR_PREFIX pxr/exec)
set(PXR_PACKAGE invertibleRigsExampleUsdviewPlugin)

pxr_plugin(${PXR_PACKAGE}
    PYMODULE_FILES
        __init__.py
        openExec.py
        plugInfo.json
)