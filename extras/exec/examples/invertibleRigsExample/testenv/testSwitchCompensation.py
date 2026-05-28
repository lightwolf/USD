#!/pxrpythonsubst
#
# Copyright 2026 Pixar
#
# Licensed under the terms set forth in the LICENSE.txt file available at
# https://openusd.org/license.

from pxr import Gf, Sdf, Ts, Usd, InvertibleRigsExample
import unittest

def _SetSplineKnot(attr, time, value):
    """
    Sets a value on an attribute at a specified time by writing a knot to
    the attribute's spline. If no knot exists at that time, creates a new
    knot with curve interpolation for the segment that follows it.
    """
    valueType = attr.GetTypeName().type

    frame = time.GetValue()
    spline = attr.GetSpline()
    knot = spline.GetKnot(frame)
    if knot:
        knot.SetValue(value)
    else:
        knot = Ts.Knot(
            typeName=valueType.typeName, time=frame, value=value,
            nextInterp=Ts.InterpCurve)
    spline.SetKnot(knot)
    attr.SetSpline(spline)

def _AssertAvarValues(time, avars, expectedValues):
    """
    Asserts that the values of the given avars at the given time are close
    to the given expected values.
    """

    for avar, expectedValue in zip(avars, expectedValues):
        actualValue = avar.Get(time)
        assert Gf.IsClose(actualValue, expectedValue, 1e-6), \
            f"For avar <{avar.GetPath()} {actualValue} != {expectedValue}"

class TestSwitchCompensation(unittest.TestCase):

    def test_CompensateSwitch(self):
        """
        Test compensation on a switch controller.
        """

        layer = Sdf.Layer.FindOrOpen("shot.usda")
        stage = Usd.Stage.Open(layer)

        switch = stage.GetAttributeAtPath('/Root/Control/Switch.switch')
        assert switch

        joint1 = stage.GetPrimAtPath('/Root/Anim/Joint1')
        joint2 = stage.GetPrimAtPath('/Root/Anim/Joint1/Joint2')
        assert joint1 and joint2

        ry1 = joint1.GetAttribute("avars:ry")
        ry2 = joint2.GetAttribute("avars:ry")
        assert ry1 and ry2

        inputAvarNames = (
            "avars:tx", "avars:ty", "avars:tz", 
            "avars:rx", "avars:ry", "avars:rz", "avars:rspin")
        inputAvars = [prim.GetAttribute(name)
                      for prim in (joint1, joint2)
                      for name in inputAvarNames]

        authoring = InvertibleRigsExample.Authoring(stage)

        # Start at time 0 by switching to 'rig1'. This is the fallback value, so
        # this doesn't change the selected rig, but it breaks down the default
        # values into splines for all input avars.
        currentTime = Usd.TimeCode(0.0)
        authoring.CompensateSwitch(switch, currentTime, 'rig1')

        _AssertAvarValues(
            currentTime, inputAvars,
            (0, 0, 0, 0, 0, 0, 0,
             0, 0, 0, 0, 0, 0, 0))

        # Author animation on rotation avars and a series of compensated changes
        # to the switch attribute that make the rig tumble by alternately
        # pivoting about one end or the other.

        currentTime = Usd.TimeCode(10.0)
        _SetSplineKnot(ry1, currentTime, 90.0)
        authoring.CompensateSwitch(switch, currentTime, 'rig2')

        _AssertAvarValues(
            currentTime, inputAvars,
            (0, 0, 0, 0, 0, 0, 0,
             10, 0, -10, 0, 90, 0, 0))

        currentTime = Usd.TimeCode(30.0)
        _SetSplineKnot(ry2, currentTime, 270.0)
        authoring.CompensateSwitch(switch, currentTime, 'rig1')

        _AssertAvarValues(
            currentTime, inputAvars,
            (20, 0, 0, 0, -90, 0, 0,
             0, 0, 0, 0, 0, 0, 0))

        currentTime = Usd.TimeCode(50.0)
        _SetSplineKnot(ry1, currentTime, 90.0)
        authoring.CompensateSwitch(switch, currentTime, 'rig2')
    
        _AssertAvarValues(
            currentTime, inputAvars,
            (0, 0, 0, 0, 0, 0, 0,
             30, 0, -10, 0, 90, 0, 0))

        currentTime = Usd.TimeCode(60.0)
        _SetSplineKnot(ry2, currentTime, 180.0)

        layer.Export("result.usda")
        
if __name__ == "__main__":
    unittest.main()
