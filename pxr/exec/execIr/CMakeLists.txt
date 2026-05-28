set(PXR_PREFIX pxr/exec)
set(PXR_PACKAGE execIr)

pxr_library(execIr
    INCLUDE_SCHEMA_FILES

    LIBRARIES
        execGeom
        execUsd
        gf
        tf
        
    PUBLIC_HEADERS
        api.h

    PUBLIC_CLASSES
        computations
        controllerBuilder
        types

    PRIVATE_HEADERS

    PRIVATE_CLASSES
        utils

    CPPFILES
        fkControllerComputations.cpp
        switchControllerComputations.cpp
        xformableComputations.cpp

    PYMODULE_FILES
        __init__.py

    DOXYGEN_FILES
        README.md
)

#
# Tests
#

pxr_build_test(testExecIrController
    LIBRARIES
        exec
        execIr
        execUsd
        plug
        sdf
        tf
        usd
        vdf
    CPPFILES
        testenv/testExecIrController.cpp
)

pxr_register_test(testExecIrController
    COMMAND "${CMAKE_INSTALL_PREFIX}/tests/testExecIrController"
    TESTENV testenv/testExecIrController
    EXPECTED_RETURN_CODE 0
)

pxr_build_test(testExecIrFkController
    LIBRARIES
        exec
        execIr
        execUsd
        gf
        sdf
        tf
        usd
    CPPFILES
        testenv/testExecIrFkController.cpp
)

pxr_register_test(testExecIrFkController
    COMMAND "${CMAKE_INSTALL_PREFIX}/tests/testExecIrFkController"
    EXPECTED_RETURN_CODE 0
)

pxr_build_test(testExecIrJointScope
    LIBRARIES
        exec
        execIr
        execUsd
        gf
        sdf
        tf
        usd
        usdGeom
    CPPFILES
        testenv/testExecIrJointScope.cpp
)

pxr_register_test(testExecIrJointScope
    COMMAND "${CMAKE_INSTALL_PREFIX}/tests/testExecIrJointScope"
    EXPECTED_RETURN_CODE 0
)

pxr_build_test(testExecIrSwitchController
    LIBRARIES
        exec
        execIr
        execUsd
        gf
        sdf
        tf
        usd
    CPPFILES
        testenv/testExecIrSwitchController.cpp
)

pxr_register_test(testExecIrSwitchController
    COMMAND "${CMAKE_INSTALL_PREFIX}/tests/testExecIrSwitchController"
    EXPECTED_RETURN_CODE 0
)

pxr_build_test(testExecIrSwitchCompensation
    LIBRARIES
        exec
        execIr
        execUsd
        gf
        sdf
        tf
        ts
        usd
    CPPFILES
        testenv/testExecIrSwitchCompensation.cpp
)

pxr_register_test(testExecIrSwitchCompensation
    COMMAND "${CMAKE_INSTALL_PREFIX}/tests/testExecIrSwitchCompensation"
    EXPECTED_RETURN_CODE 0
)
