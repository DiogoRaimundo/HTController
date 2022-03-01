#include <Arduino.h>
#include <unity.h>

using namespace fakeit;

uint8_t led_built_in_state;

void setBuiltInLedState(uint8_t pin, uint8_t state)
{
    led_built_in_state = state;
}

int getBuiltInLedState(uint8_t pin)
{
    return led_built_in_state;
}

void setUp(void)
{
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();

    When(Method(ArduinoFake(), digitalWrite)).Do(setBuiltInLedState);
    When(Method(ArduinoFake(), digitalRead).Using(LED_BUILTIN)).Do(getBuiltInLedState);

    When(Method(ArduinoFake(), delay)).AlwaysReturn();
}

// void tearDown(void) {
// // clean stuff up here
// }

void test_led_builtin_pin_number(void)
{
    TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_state_high(void)
{
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void)
{
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop()
{
    if (i < max_blinks)
    {
        RUN_TEST(test_led_state_high);
        delay(500);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    }
    else if (i == max_blinks)
    {
        UNITY_END(); // stop unit testing
    }
}

int main(int argc, char **argv)
{
    UNITY_BEGIN(); // IMPORTANT LINE!

    RUN_TEST(test_led_builtin_pin_number);

    pinMode(LED_BUILTIN, OUTPUT);

    while (i < max_blinks)
    {
        RUN_TEST(test_led_state_high);
        delay(500);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    }

    UNITY_END(); // stop unit testing
}