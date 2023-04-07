#include <gtest/gtest.h>

#include "Tests/Monitors/curve_sensor_monitor_test.cpp"
#include "Tests/Monitors/threshold_sensor_monitor_test.cpp"

#include "Tests/UI/set_ac_on_threshold_screen_test.cpp"
#include "Tests/UI/set_screen_timeout_screen_test.cpp"
#include "Tests/UI/set_temperature_curve_screen_test.cpp"

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