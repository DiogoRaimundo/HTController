#include <gtest/gtest.h>

#include "Tests/Monitors/CurveSensorMonitorTest.cpp"
#include "Tests/Monitors/ThresholdSensorMonitorTest.cpp"

#include "Tests/UI/SetCurrentThresholdScreenTest.cpp"
#include "Tests/UI/SetScreenTimeoutScreenTest.cpp"
#include "Tests/UI/SetTemperatureCurveScreenTest.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    // if you plan to use GMock, replace the line above with
    // ::testing::InitGoogleMock(&argc, argv);

    if (RUN_ALL_TESTS())
        ;

    // Always return zero-code and allow PlatformIO to parse results
    return 0;
}