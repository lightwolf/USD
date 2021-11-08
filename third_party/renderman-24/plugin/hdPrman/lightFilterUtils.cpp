//
// Copyright 2019 Pixar
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

#include "hdPrman/lightFilterUtils.h"

<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
#include "hdPrman/context.h"
#include "hdPrman/debugCodes.h"
#include "hdPrman/light.h"
#include "hdPrman/material.h"
#include "hdPrman/renderParam.h"
=======
#include "hdPrman/renderParam.h"
#include "hdPrman/debugCodes.h"
#include "hdPrman/light.h"
#include "hdPrman/material.h"
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
#include "hdPrman/rixStrings.h"

#include "pxr/imaging/hd/material.h"
#include "pxr/imaging/hd/sceneDelegate.h"
#include "pxr/imaging/hd/tokens.h"

#include "pxr/base/gf/vec3f.h"
#include "pxr/base/tf/debug.h"
#include "pxr/base/tf/envSetting.h"
#include "pxr/base/tf/staticTokens.h"

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PRIVATE_TOKENS(
    _tokens,

    // tokens for RenderMan-specific light filter parameters
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
    ((analyticApex, "inputs:analytic:apex"))
    ((analyticDensityExponent, "inputs:analytic:density:exponent"))
    ((analyticDensityFarDistance, "inputs:analytic:density:farDistance"))
    ((analyticDensityFarValue, "inputs:analytic:density:farValue"))
    ((analyticDensityNearDistance, "inputs:analytic:density:nearDistance"))
    ((analyticDensityNearValue, "inputs:analytic:density:nearValue"))
    ((analyticDirectional, "inputs:analytic:directional"))
    ((analyticShearX, "inputs:analytic:shearX"))
    ((analyticShearY, "inputs:analytic:shearY"))
    ((analyticUseLightDirection, "inputs:analytic:useLightDirection"))
    ((barnMode, "inputs:barnMode"))
    ((colorRampColors, "inputs:colorRamp:colors"))
    ((colorRampInterpolation, "inputs:colorRamp:interpolation"))
    ((colorRampKnots, "inputs:colorRamp:knots"))
    ((colorSaturation, "inputs:color:saturation"))
    ((depth, "inputs:depth"))
    ((edgeScaleBack, "inputs:edgeScale:back"))
    ((edgeScaleBottom, "inputs:edgeScale:bottom"))
    ((edgeScaleFront, "inputs:edgeScale:front"))
    ((edgeScaleLeft, "inputs:edgeScale:left"))
    ((edgeScaleRight, "inputs:edgeScale:right"))
    ((edgeScaleTop, "inputs:edgeScale:top"))
    ((edgeThickness, "inputs:edgeThickness"))
    ((falloffFloats, "inputs:falloff:floats"))
    ((falloffInterpolation, "inputs:falloff:interpolation"))
    ((falloffKnots, "inputs:falloff:knots"))
    ((height, "inputs:height"))
    ((preBarnEffect, "inputs:preBarnEffect"))
    ((radius, "inputs:radius"))
    ((refineBack, "inputs:refine:back"))
    ((refineBottom, "inputs:refine:bottom"))
    ((refineFront, "inputs:refine:front"))
    ((refineLeft, "inputs:refine:left"))
    ((refineRight, "inputs:refine:right"))
    ((refineTop, "inputs:refine:top"))
    ((riCombineMode, "inputs:ri:combineMode"))
    ((riDensity, "inputs:ri:density"))
    ((riDiffuse, "inputs:ri:diffuse"))
    ((riExposure, "inputs:ri:exposure"))
    ((riIntensity, "inputs:ri:intensity"))
    ((riInvert, "inputs:ri:invert"))
    ((riSpecular, "inputs:ri:specular"))
    ((scaleDepth, "inputs:scale:depth"))
    ((scaleHeight, "inputs:scale:height"))
    ((scaleWidth, "inputs:scale:width"))
    ((width, "inputs:width"))
=======
    ((analyticApex, "inputs:ri:lightFilter:apex"))
    ((analyticDensityExponent, "inputs:ri:lightFilter:densityPow"))
    ((analyticDensityFarDistance, "inputs:ri:lightFilter:densityFarDist"))
    ((analyticDensityFarValue, "inputs:ri:lightFilter:densityFarVal"))
    ((analyticDensityNearDistance, "inputs:ri:lightFilter:densityNearDist"))
    ((analyticDensityNearValue, "inputs:ri:lightFilter:densityNearVal"))
    ((analyticDirectional, "inputs:ri:lightFilter:directional"))
    ((analyticShearX, "inputs:ri:lightFilter:shearX"))
    ((analyticShearY, "inputs:ri:lightFilter:shearY"))
    ((analyticUseLightDirection, "inputs:ri:lightFilter:useLightDirection"))
    ((barnMode, "inputs:ri:lightFilter:barnMode"))
    ((colorRampColors, "inputs:ri:lightFilter:colorRamp_Colors"))
    ((colorRampInterpolation, "inputs:ri:lightFilter:colorRamp_Interpolation"))
    ((colorRampKnots, "inputs:ri:lightFilter:colorRamp_Knots"))
    ((colorSaturation, "inputs:ri:lightFilter:saturation"))
    ((depth, "inputs:ri:lightFilter:depth"))
    ((edgeScaleBack, "inputs:ri:lightFilter:backEdge"))
    ((edgeScaleBottom, "inputs:ri:lightFilter:bottomEdge"))
    ((edgeScaleFront, "inputs:ri:lightFilter:frontEdge"))
    ((edgeScaleLeft, "inputs:ri:lightFilter:leftEdge"))
    ((edgeScaleRight, "inputs:ri:lightFilter:rightEdge"))
    ((edgeScaleTop, "inputs:ri:lightFilter:topEdge"))
    ((edgeThickness, "inputs:ri:lightFilter:edge"))
    ((falloffFloats, "inputs:ri:lightFilter:falloff_Floats"))
    ((falloffInterpolation, "inputs:ri:lightFilter:falloff_Interpolation"))
    ((falloffKnots, "inputs:ri:lightFilter:falloff_Knots"))
    ((height, "inputs:ri:lightFilter:height"))
    ((preBarnEffect, "inputs:ri:lightFilter:preBarn"))
    ((radius, "inputs:ri:lightFilter:radius"))
    ((refineBack, "inputs:ri:lightFilter:back"))
    ((refineBottom, "inputs:ri:lightFilter:bottom"))
    ((refineFront, "inputs:ri:lightFilter:front"))
    ((refineLeft, "inputs:ri:lightFilter:left"))
    ((refineRight, "inputs:ri:lightFilter:right"))
    ((refineTop, "inputs:ri:lightFilter:top"))
    ((combineMode, "inputs:ri:lightFilter:combineMode"))
    ((density, "inputs:ri:lightFilter:density"))
    ((diffuse, "inputs:ri:lightFilter:diffuse"))
    ((exposure, "inputs:ri:lightFilter:exposure"))
    ((intensity, "inputs:ri:lightFilter:intensity"))
    ((invert, "inputs:ri:lightFilter:invert"))
    ((specular, "inputs:ri:lightFilter:specular"))
    ((scaleDepth, "inputs:ri:lightFilter:scaleDepth"))
    ((scaleHeight, "inputs:ri:lightFilter:scaleHeight"))
    ((scaleWidth, "inputs:ri:lightFilter:scaleWidth"))
    ((width, "inputs:ri:lightFilter:width"))
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp

    (analytic)
    (cone)
    (noEffect)
    (noLight)
    (physical)

    (PxrIntMultLightFilter)
    (PxrBarnLightFilter)
    (PxrRodLightFilter)
);

bool HdPrmanLightFilterPopulateNodesFromLightParams(
    std::vector<riley::ShadingNode> *filterNodes,
    SdfPath &filterPath,
    HdSceneDelegate *sceneDelegate)
{
    HD_TRACE_FUNCTION();

    VtValue tval = sceneDelegate->GetLightParamValue(filterPath,
                                TfToken("lightFilterType"));
    if (!tval.IsHolding<TfToken>()) {
        TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
            .Msg("  filter type unknown\n");
        return false;
    }
    TfToken filterType = tval.UncheckedGet<TfToken>();

    riley::ShadingNode filter({
        riley::ShadingNode::Type::k_LightFilter,
        RtUString(filterType.GetText()),
        RtUString(filterPath.GetName().c_str()),
        RtParamList()});

    VtValue pval;

    pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->intensity);
    if (pval.IsHolding<float>()) {
        float intensity = pval.UncheckedGet<float>();
        TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
            .Msg("      ri:intensity %f\n", intensity);
=======
            .Msg("      %s %f\n", _tokens->intensity.GetText(), intensity);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
        filter.params.SetFloat(RtUString("intensity"), intensity);
    }
    if (filterType == _tokens->PxrIntMultLightFilter) {
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                                 _tokens->exposure);
        if (pval.IsHolding<float>()) {
            float exposure = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      ri:exposure %f\n", exposure);
=======
                .Msg("      %s %f\n", _tokens->exposure.GetText(), 
                        exposure);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("exposure"), exposure);
        }
    }
    if (filterType != _tokens->PxrIntMultLightFilter) {
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                                 _tokens->density);
        if (pval.IsHolding<float>()) {
            float density = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      ri:density %f\n", density);
=======
                .Msg("      %s %f\n", _tokens->density.GetText(), density);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("density"), density);
        }
    }
    pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->invert);
    if (pval.IsHolding<bool>()) {
        bool invert = pval.UncheckedGet<bool>();
        TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
            .Msg("      ri:invert %d\n", invert);
=======
            .Msg("      %s %d\n", _tokens->invert.GetText(), invert);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
        filter.params.SetInteger(RtUString("invert"), invert);
    }
    pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->diffuse);
    if (pval.IsHolding<float>()) {
        float diffuse = pval.UncheckedGet<float>();
        TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
            .Msg("      ri:diffuse %f\n", diffuse);
=======
            .Msg("      %s %f\n", _tokens->diffuse.GetText(), diffuse);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
        filter.params.SetFloat(RtUString("diffuse"), diffuse);
    }
    pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->specular);
    if (pval.IsHolding<float>()) {
        float specular = pval.UncheckedGet<float>();
        TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
            .Msg("      ri:specular %f\n", specular);
=======
            .Msg("      %s %f\n", _tokens->specular.GetText(), specular);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
        filter.params.SetFloat(RtUString("specular"), specular);
    }
    pval = sceneDelegate->GetLightParamValue(filterPath,
                                             _tokens->combineMode);
    if (pval.IsHolding<TfToken>()) {
        TfToken combineMode = pval.UncheckedGet<TfToken>();
        TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
            .Msg("      %s %s\n", _tokens->combineMode.GetText(), 
                    combineMode.GetText());
        // XXX -- what to do with this
        //filter.params.SetFloat(RtUString("combineMode"), combineMode);
        // XXX -- what to do with this
    }

    // XX -- not sure how to handle this param
    //filter.params.SetString(RtUString("linkingGroups"), RtUString(""));
    // XX -- not sure how to handle this param

    if (filterType == _tokens->PxrIntMultLightFilter) {
        filter.name = RtUString("PxrIntMultLightFilter");

        // XXX -- note this token is not color:saturation so be specific
        pval = sceneDelegate->GetLightParamValue(filterPath,
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                                                 TfToken("inputs:colorSaturation"));
        if (pval.IsHolding<float>()) {
            float saturation = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                .Msg("      colorSaturation %f\n", saturation);
=======
                                                 _tokens->colorSaturation);
        if (pval.IsHolding<float>()) {
            float saturation = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                .Msg("      %s %f\n", _tokens->colorSaturation.GetText(), 
                        saturation);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("saturation"), saturation);
        }

    } else if (filterType == _tokens->PxrBarnLightFilter) {
        filter.name = RtUString("PxrBarnLightFilter");

        TfToken barnMode = _tokens->physical;
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->barnMode);
        if (pval.IsHolding<TfToken>()) {
            barnMode = pval.UncheckedGet<TfToken>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                .Msg("      %s %s\n", _tokens->barnMode.GetText(), 
                        barnMode.GetText());
            int bm = -1;
            if (barnMode == _tokens->physical)
                bm = 0;
            else if (barnMode == _tokens->analytic)
                bm = 1;
            if (bm >= 0)
                filter.params.SetInteger(RtUString("barnMode"), bm);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->width);
        if (pval.IsHolding<float>()) {
            float width = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      width %f\n", width);
=======
                .Msg("      %s %f\n", _tokens->width.GetText(), width);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("width"), width);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->height);
        if (pval.IsHolding<float>()) {
            float height = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      height %f\n", height);
=======
                .Msg("      %s %f\n", _tokens->height.GetText(), height);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("height"), height);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->radius);
        if (pval.IsHolding<float>()) {
            float radius = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      radius %f\n", radius);
=======
                .Msg("      %s %f\n", _tokens->radius.GetText(), radius);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("radius"), radius);
        }
        if (barnMode == _tokens->analytic) {
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticDirectional);
            if (pval.IsHolding<bool>()) {
                bool directional = pval.UncheckedGet<bool>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:directional %d\n", directional);
=======
                    .Msg("      %s %d\n", 
                            _tokens->analyticDirectional.GetText(), 
                            directional);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetInteger(RtUString("directional"),
                                          directional);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticShearX);
            if (pval.IsHolding<float>()) {
                float shearX = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:shearX %f\n", shearX);
=======
                    .Msg("      %s %f\n", _tokens->analyticShearX.GetText(),
                            shearX);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("shearX"), shearX);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticShearY);
            if (pval.IsHolding<float>()) {
                float shearY = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:shearY %f\n", shearY);
=======
                    .Msg("      %s %f\n", _tokens->analyticShearY.GetText(), 
                            shearY);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("shearY"), shearY);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticApex);
            if (pval.IsHolding<float>()) {
                float apex = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:apex %f\n", apex);
=======
                    .Msg("      %s %f\n", _tokens->analyticApex.GetText(), 
                            apex);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("apex"), apex);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticUseLightDirection);
            if (pval.IsHolding<bool>()) {
                bool useLightDirection = pval.UncheckedGet<bool>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s %d\n", 
                            _tokens->analyticUseLightDirection.GetText(),
                                            useLightDirection);
                filter.params.SetInteger(RtUString("useLightDirection"),
                                        useLightDirection);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticDensityNearDistance);
            if (pval.IsHolding<float>()) {
                float nearDistance = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s %f\n",
                            _tokens->analyticDensityNearDistance.GetText(),
                                        nearDistance);
                filter.params.SetFloat(RtUString("densityNear"), nearDistance);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticDensityFarDistance);
            if (pval.IsHolding<float>()) {
                float farDistance = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s %f\n",
                            _tokens->analyticDensityFarDistance.GetText(),
                                        farDistance);
                filter.params.SetFloat(RtUString("densityFar"), farDistance);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticDensityNearValue);
            if (pval.IsHolding<float>()) {
                float nearValue = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:density:nearValue %f\n", nearValue);
=======
                    .Msg("      %s %f\n", 
                            _tokens->analyticDensityNearValue.GetText(),
                            nearValue);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("densityNearVal"), nearValue);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticDensityFarValue);
            if (pval.IsHolding<float>()) {
                float farValue = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:density:farValue %f\n", farValue);
=======
                    .Msg("      %s %f\n", 
                            _tokens->analyticDensityFarValue.GetText(),
                            farValue);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("densityFarVal"), farValue);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->analyticDensityExponent);
            if (pval.IsHolding<float>()) {
                float exponent = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      analytic:density:exponent %f\n", exponent);
=======
                    .Msg("      %s %f\n", 
                            _tokens->analyticDensityExponent.GetText(),
                            exponent);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("densityPow"), exponent);
            }
        }
        float edgeThickness = 0.0;
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->edgeThickness);
        if (pval.IsHolding<float>()) {
            edgeThickness = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      edgeThickness %f\n", edgeThickness);
=======
                .Msg("      %s %f\n", 
                        _tokens->edgeThickness.GetText(), 
                        edgeThickness);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("edge"), edgeThickness);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->preBarnEffect);
        if (pval.IsHolding<TfToken>()) {
            TfToken preBarnEffect = pval.UncheckedGet<TfToken>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                .Msg("      %s %s\n", 
                        _tokens->preBarnEffect.GetText(),
                        preBarnEffect.GetText());
            int preBarn = -1;
            if (preBarnEffect == _tokens->noEffect)
                preBarn = 0;
            else if (preBarnEffect == _tokens->cone)
                preBarn = 1;
            else if (preBarnEffect == _tokens->noLight)
                preBarn = 1;
            if (preBarn >= 0)
                filter.params.SetInteger(RtUString("preBarn"), preBarn);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->scaleWidth);
        if (pval.IsHolding<float>()) {
            float width = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      scaleWidth %f\n", width);
=======
                .Msg("      %s %f\n", 
                        _tokens->scaleWidth.GetText(), width);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("scaleWidth"), width);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->scaleHeight);
        if (pval.IsHolding<float>()) {
            float height = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      scaleHeight %f\n", height);
=======
                .Msg("      %s %f\n", 
                        _tokens->scaleHeight.GetText(), height);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("scaleHeight"), height);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineTop);
        if (pval.IsHolding<float>()) {
            float top = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:top %f\n", top);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineTop.GetText(), top);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("top"), top);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineBottom);
        if (pval.IsHolding<float>()) {
            float bottom = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:bottom %f\n", bottom);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineBottom.GetText(), bottom);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("bottom"), bottom);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineLeft);
        if (pval.IsHolding<float>()) {
            float left = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:left %f\n", left);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineLeft.GetText(), left);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("left"), left);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineRight);
        if (pval.IsHolding<float>()) {
            float right = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:right %f\n", right);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineRight.GetText(), right);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("right"), right);
        }
        if (edgeThickness > 0.0) {
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleTop);
            if (pval.IsHolding<float>()) {
                float top = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:top %f\n", top);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleTop.GetText(), top);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("topEdge"), top);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleBottom);
            if (pval.IsHolding<float>()) {
                float bottom = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:bottom %f\n", bottom);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleBottom.GetText(), bottom);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("bottomEdge"), bottom);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleLeft);
            if (pval.IsHolding<float>()) {
                float left = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:left %f\n", left);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleLeft.GetText(), left);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("leftEdge"), left);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleRight);
            if (pval.IsHolding<float>()) {
                float right = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:right %f\n", right);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleRight.GetText(), right);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("rightEdge"), right);
            }
        }

    } else if (filterType == _tokens->PxrRodLightFilter) {
        filter.name = RtUString("PxrRodLightFilter");

        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->width);
        if (pval.IsHolding<float>()) {
            float width = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      width %f\n", width);
=======
                .Msg("      %s %f\n", 
                        _tokens->width.GetText(), width);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("width"), width);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->height);
        if (pval.IsHolding<float>()) {
            float height = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      height %f\n", height);
=======
                .Msg("      %s %f\n", 
                        _tokens->height.GetText(), height);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("height"), height);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->depth);
        if (pval.IsHolding<float>()) {
            float depth = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      depth %f\n", depth);
=======
                .Msg("      %s %f\n", 
                        _tokens->depth.GetText(), depth);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("depth"), depth);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath, _tokens->radius);
        if (pval.IsHolding<float>()) {
            float radius = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      radius %f\n", radius);
=======
                .Msg("      %s %f\n", 
                        _tokens->radius.GetText(), radius);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("radius"), radius);
        }
        float edgeThickness = 0.0;
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->edgeThickness);
        if (pval.IsHolding<float>()) {
            edgeThickness = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      edgeThickness %f\n", edgeThickness);
=======
                .Msg("      %s %f\n", 
                        _tokens->edgeThickness.GetText(), edgeThickness);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("edge"), edgeThickness);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->scaleWidth);
        if (pval.IsHolding<float>()) {
            float width = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      scaleWidth %f\n", width);
=======
                .Msg("      %s %f\n", 
                        _tokens->scaleWidth.GetText(), width);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("scaleWidth"), width);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->scaleHeight);
        if (pval.IsHolding<float>()) {
            float height = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      scaleHeight %f\n", height);
=======
                .Msg("      %s %f\n", 
                        _tokens->scaleHeight.GetText(), height);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("scaleHeight"), height);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->scaleDepth);
        if (pval.IsHolding<float>()) {
            float depth = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      scaleDepth %f\n", depth);
=======
                .Msg("      %s %f\n", 
                        _tokens->scaleDepth.GetText(), depth);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("scaleDepth"), depth);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineTop);
        if (pval.IsHolding<float>()) {
            float top = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:top %f\n", top);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineTop.GetText(), top);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("top"), top);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineBottom);
        if (pval.IsHolding<float>()) {
            float bottom = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:bottom %f\n", bottom);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineBottom.GetText(), bottom);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("bottom"), bottom);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineLeft);
        if (pval.IsHolding<float>()) {
            float left = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:left %f\n", left);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineLeft.GetText(), left);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("left"), left);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineRight);
        if (pval.IsHolding<float>()) {
            float right = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:right %f\n", right);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineRight.GetText(), right);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("right"), right);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineFront);
        if (pval.IsHolding<float>()) {
            float front = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:front %f\n", front);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineFront.GetText(), front);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("front"), front);
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->refineBack);
        if (pval.IsHolding<float>()) {
            float back = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      refine:back %f\n", back);
=======
                .Msg("      %s %f\n", 
                        _tokens->refineBack.GetText(), back);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("back"), back);
        }
        if (edgeThickness > 0.0) {
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleTop);
            if (pval.IsHolding<float>()) {
                float top = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:top %f\n", top);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleTop.GetText(), top);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("topEdge"), top);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleBottom);
            if (pval.IsHolding<float>()) {
                float bottom = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:bottom %f\n", bottom);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleBottom.GetText(), bottom);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("bottomEdge"), bottom);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleLeft);
            if (pval.IsHolding<float>()) {
                float left = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:left %f\n", left);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleLeft.GetText(), left);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("leftEdge"), left);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleRight);
            if (pval.IsHolding<float>()) {
                float right = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:right %f\n", right);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleRight.GetText(), right);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("rightEdge"), right);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleFront);
            if (pval.IsHolding<float>()) {
                float front = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:front %f\n", front);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleFront.GetText(), front);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("frontEdge"), front);
            }
            pval = sceneDelegate->GetLightParamValue(filterPath,
                                            _tokens->edgeScaleBack);
            if (pval.IsHolding<float>()) {
                float back = pval.UncheckedGet<float>();
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                    .Msg("      edgeScale:back %f\n", back);
=======
                    .Msg("      %s %f\n", 
                            _tokens->edgeScaleBack.GetText(), back);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
                filter.params.SetFloat(RtUString("backEdge"), back);
            }
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->colorSaturation);
        if (pval.IsHolding<float>()) {
            float saturation = pval.UncheckedGet<float>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      color:saturation %f\n", saturation);
=======
                .Msg("      %s %f\n", 
                        _tokens->colorSaturation.GetText(), saturation);
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetFloat(RtUString("saturation"), saturation);
        }

        // XXX -- handle the falloff spline
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->falloffKnots);
        if (pval.IsHolding<std::vector<float>>()) {
            const std::vector<float>& v =
                                pval.UncheckedGet<std::vector<float>>();
            if (TfDebug::IsEnabled(HDPRMAN_LIGHT_FILTER_LINKING)) {
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s size %d\n", 
                            _tokens->falloffKnots.GetText(), (int)(v.size()));
                for(size_t ii = 0; ii < v.size(); ii++)
                    TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                        .Msg("        %2zu: %f\n", ii, v[ii]);
            }
            filter.params.SetFloatArray(RtUString("falloff_Knots"),
                                         &v[0], v.size());
            // XXX -- extra param to hold the size of the spline
            filter.params.SetInteger(RtUString("falloff"), v.size());
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->falloffFloats);
        if (pval.IsHolding<std::vector<float>>()) {
            const std::vector<float>& v =
                                pval.UncheckedGet<std::vector<float>>();
            if (TfDebug::IsEnabled(HDPRMAN_LIGHT_FILTER_LINKING)) {
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s size %d\n", 
                            _tokens->falloffFloats.GetText(), (int)(v.size()));
                for(size_t ii = 0; ii < v.size(); ii++)
                    TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                        .Msg("        %2zu: %f\n", ii, v[ii]);
            }
            filter.params.SetFloatArray(RtUString("falloff_Floats"),
                                         &v[0], v.size());
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->falloffInterpolation);
        if (pval.IsHolding<TfToken>()) {
            TfToken interpolation = pval.UncheckedGet<TfToken>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      falloff:interpolation %s\n", interpolation.GetText());
=======
                .Msg("      %s %s\n", 
                        _tokens->falloffInterpolation.GetText(), 
                        interpolation.GetText());
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetString(RtUString("falloff_Interpolation"),
                                     RtUString(interpolation.GetText()));
        }
        // XXX -- handle the colorRamp spline
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->colorRampKnots);
        if (pval.IsHolding<std::vector<float>>()) {
            const std::vector<float>& v =
                                pval.UncheckedGet<std::vector<float>>();
            if (TfDebug::IsEnabled(HDPRMAN_LIGHT_FILTER_LINKING)) {
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s size %d\n", 
                            _tokens->colorRampKnots.GetText(), (int)(v.size()));
                for(size_t ii = 0; ii < v.size(); ii++)
                    TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                        .Msg("        %2zu: %f\n", ii, v[ii]);
            }
            filter.params.SetFloatArray(RtUString("colorRamp_Knots"),
                                         &v[0], v.size());
            // XXX -- extra param to hold the size of the spline
            filter.params.SetInteger(RtUString("colorRamp"), v.size());
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->colorRampColors);
        if (pval.IsHolding<std::vector<GfVec3f>>()) {
            const std::vector<GfVec3f>& v =
                                pval.UncheckedGet<std::vector<GfVec3f>>();
            if (TfDebug::IsEnabled(HDPRMAN_LIGHT_FILTER_LINKING)) {
                TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                    .Msg("      %s size %d\n", 
                            _tokens->colorRampColors.GetText(), 
                            (int)(v.size()));
                for(size_t ii = 0; ii < v.size(); ii++)
                    TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
                        .Msg("      %2zu: %f %f %f\n",
                                            ii, v[ii][0], v[ii][1], v[ii][2]);
            }
            filter.params.SetColorArray(RtUString("colorRamp_Colors"), 
                    reinterpret_cast<const RtColorRGB*>(&v[0]), v.size());
        }
        pval = sceneDelegate->GetLightParamValue(filterPath,
                                        _tokens->colorRampInterpolation);
        if (pval.IsHolding<TfToken>()) {
            TfToken interpolation = pval.UncheckedGet<TfToken>();
            TF_DEBUG(HDPRMAN_LIGHT_FILTER_LINKING)
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
                .Msg("      colorRamp:spline:interpolation %s\n",
                                        interpolation.GetText());
=======
                .Msg("      %s %s\n",
                        _tokens->colorRampInterpolation.GetText(), 
                        interpolation.GetText());
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
            filter.params.SetString(RtUString("colorRamp_Interpolation"),
                                     RtUString(interpolation.GetText()));
        }

    } else {
        // bail 
        TF_WARN("Light filter type %s not implemented\n", filterType.GetText());
        return false;
    }

    filterNodes->emplace_back(std::move(filter));
    return true;
}

void HdPrmanLightFilterGenerateCoordSysAndLinks(
    riley::ShadingNode *filter,
    SdfPath &filterPath,
    std::vector<riley::CoordinateSystemId> *coordsysIds,
    std::vector<TfToken> *filterLinks,
    HdSceneDelegate *sceneDelegate,
<<<<<<< HEAD:third_party/renderman-24/plugin/hdPrman/lightFilterUtils.cpp
    HdPrman_Context *context,
=======
    HdPrman_RenderParam *renderParam,
>>>>>>> upstream/dev:third_party/renderman-23/plugin/hdPrman/lightFilterUtils.cpp
    riley::Riley *riley,
    const riley::ShadingNode &lightNode)
{
    static const RtUString us_PxrRodLightFilter("PxrRodLightFilter");
    static const RtUString us_PxrBarnLightFilter("PxrBarnLightFilter");

    if (filter->name == us_PxrRodLightFilter ||
        filter->name == us_PxrBarnLightFilter) {
        // Sample filter transform
        HdTimeSampleArray<GfMatrix4d, HDPRMAN_MAX_TIME_SAMPLES> xf;
        sceneDelegate->SampleTransform(filterPath, &xf);
        TfSmallVector<RtMatrix4x4, HDPRMAN_MAX_TIME_SAMPLES> 
            xf_rt_values(xf.count);
        for (size_t i=0; i < xf.count; ++i) {
            xf_rt_values[i] = HdPrman_GfMatrixToRtMatrix(xf.values[i]);
        }
        const riley::Transform xform = {
            unsigned(xf.count), xf_rt_values.data(), xf.times.data()};

        // The coordSys name is the final component of the id,
        // after stripping namespaces.
        RtParamList attrs;
        const char *csName =
                    SdfPath::StripNamespace(filterPath.GetName()).c_str();
        attrs.SetString(RixStr.k_name, RtUString(csName));

        riley::CoordinateSystemId csId;
        csId = riley->CreateCoordinateSystem(riley::UserId::DefaultId(),
                                             xform, attrs);

        (*coordsysIds).push_back(csId);

        filter->params.SetString(RtUString("coordsys"),
                                 RtUString(csName));

        if (filter->name == us_PxrBarnLightFilter) {
            filter->params.SetString(RtUString("__lightFilterParentShader"),
                                     lightNode.name);
        }
    }

    // Light filter linking
    VtValue val = sceneDelegate->GetLightParamValue(filterPath,
                                    HdTokens->lightFilterLink);
    TfToken lightFilterLink = TfToken();
    if (val.IsHolding<TfToken>()) {
        lightFilterLink = val.UncheckedGet<TfToken>();
    }
    
    if (!lightFilterLink.IsEmpty()) {
        renderParam->IncrementLightFilterCount(lightFilterLink);
        (*filterLinks).push_back(lightFilterLink);
        // For light filters to link geometry, the light filters must
        // be assigned a grouping membership, and the
        // geometry must subscribe to that grouping.
        filter->params.SetString(RtUString("linkingGroups"),
                            RtUString(lightFilterLink.GetText()));
        TF_DEBUG(HDPRMAN_LIGHT_LINKING)
            .Msg("HdPrman: Light filter <%s> linkingGroups \"%s\"\n",
                    filterPath.GetText(), lightFilterLink.GetText());
    }
}

PXR_NAMESPACE_CLOSE_SCOPE
