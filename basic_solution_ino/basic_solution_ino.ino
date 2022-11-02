#include <Arduino.h>
#include <LiquidCrystal.h>
#include <IRremote.hpp>
#include <RotaryEncoder.h>
#include <FanController.h>

#define FTDI_RX_PIN 0
#define FTDI_TX_PIN 1
#define IR_RECEIVER_PIN 2
#define IR_EMITTER_PIN 3
#define DEVICE_LED_PIN 4
#define FAN_CONTROL_PIN 5
#define FAN_SENSOR_PIN 6
#define ENCODER_PIN_1 7
#define ENCODER_PIN_2 8
#define LCD_RS_PIN 9
#define LCD_EN_PIN 10
#define LCD_BACKLIGHT_PIN 11
#define LCD_D4_PIN 12
#define LCD_D5_PIN 13

#define LCD_D6_PIN A0
#define LCD_D7_PIN A1
#define BUTTON_1_PIN A2
#define BUTTON_2_PIN A3
#define CURRENT_SENSOR_PIN A4
#define TEMPERATURE_SENSOR_PIN A5

#define FAN_SENSOR_THRESHOLD 1000

#define IR_ON_OFF_ADDRESS 0x6CD2
#define IR_ON_OFF_CMD 0xCB
#define NUMBER_OF_REPEATS_TO_SEND 1

/*
   This solution's only objective is to turn on the FAN when the system is on.
*/

LiquidCrystal *lcd;
RotaryEncoder *encoder;
FanController *fan;

IRData *irData;
boolean isDeviceOn = false;
boolean prevIsDeviceOn = false;

void configure_pins()
{
  // pinMode(FTDI_RX_PIN, OUTPUT); NOT NEEDED
  // pinMode(FTDI_TX_PIN, OUTPUT); NOT NEEDED
  // pinMode(IR_RECEIVER_PIN, INPUT); NOT NEEDED - IR
  // pinMode(IR_EMITTER_PIN, INPUT); NOT NEEDED - IR
  pinMode(DEVICE_LED_PIN, OUTPUT);
  // pinMode(FAN_CONTROL_PIN, OUTPUT); NOT NEEDED - FAN
  // pinMode(FAN_SENSOR_PIN, INPUT); NOT NEEDED - FAN
  // pinMode(ENCODER_PIN_1, INPUT); NOT NEEDED - ENCODER
  // pinMode(ENCODER_PIN_2, INPUT); NOT NEEDED - ENCODER
  // pinMode(LCD_RS_PIN, INPUT); NOT NEEDED - LCD
  // pinMode(LCD_EN_PIN, INPUT); NOT NEEDED - LCD
  pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
  // pinMode(LCD_D4_PIN, INPUT); NOT NEEDED - LCD
  // pinMode(LCD_D5_PIN, INPUT); NOT NEEDED - LCD

  // pinMode(LCD_D6_PIN, INPUT); NOT NEEDED - LCD
  // pinMode(LCD_D7_PIN, INPUT);  NOT NEEDED - LCD
  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  // pinMode(CURRENT_SENSOR_PIN, INPUT); ANALOG INPUT
  // pinMode(TEMPERATURE_SENSOR_PIN, INPUT); ANALOG INPUT
}

void init_lcd()
{
  lcd = new LiquidCrystal(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

  lcd->begin(16, 2);
  digitalWrite(LCD_BACKLIGHT_PIN, HIGH);
}

void init_ir_comms()
{
  IrReceiver.begin(IR_RECEIVER_PIN, DISABLE_LED_FEEDBACK);
  IrSender.begin(IR_EMITTER_PIN, DISABLE_LED_FEEDBACK);
}

void init_encoder()
{
  encoder = new RotaryEncoder(ENCODER_PIN_1, ENCODER_PIN_2, RotaryEncoder::LatchMode::TWO03);
}

void init_fan()
{
  //  Change D5 & D6 PWM frenquency to 62.5kHz
  // TCCR0B &= B11111000 | B00000011; // D5 & D6 DEFAULT   (00976.56 Hz)
  // TCCR0B &= B11111000 | B00000001; // D5 & D6 MAX FREQ  (62500.00 Hz)
  // TCCR2B &= B11111000 | B00000100; // D3 & D11 DEFAULT  (00490.20 Hz)
  // TCCR2B &= B11111000 | B00000001; // D3 & D11 MAX FREQ (31372.55 Hz)
  // TCCR1B &= B11111000 | B00000100; // D9 & D10 DEFAULT  (00490.20 Hz)
  // TCCR1B &= B11111000 | B00000001; // D9 & D10 MAX FREQ (31372.55 Hz) <- BEST OPTION

  fan = new FanController(FAN_SENSOR_PIN, FAN_SENSOR_THRESHOLD, FAN_CONTROL_PIN);
}

void setup()
{
  configure_pins();

  init_lcd();
  init_ir_comms();
  init_encoder();
  init_fan();
}

void ir_loop()
{
  if (IrReceiver.available())
  {
    irData = IrReceiver.read();

    if (irData->address == IR_ON_OFF_ADDRESS)
    {
      if (irData->command == IR_ON_OFF_CMD)
      {
        isDeviceOn = !isDeviceOn;
      }
    }

    IrSender.write(irData, NUMBER_OF_REPEATS_TO_SEND);

    IrReceiver.resume();
  }
}

int encoderPosition = 0;
bool button1LastState = LOW;
int dutyCycle = 50;

void loop()
{
  ir_loop();

  encoder->tick();
  int newEncoderPosition = encoder->getPosition();
  if (encoderPosition != newEncoderPosition)
  {
    encoderPosition = newEncoderPosition;

    if (encoder->getDirection() == RotaryEncoder::Direction::CLOCKWISE)
    {
      if (++dutyCycle > 100)
      {
        dutyCycle = 100;
      }
    }
    else if (--dutyCycle < 0)
    {
      dutyCycle = 0;
    }

    fan->setDutyCycle(isDeviceOn ? dutyCycle : 0);
  }

  if (prevIsDeviceOn != isDeviceOn)
  {
    prevIsDeviceOn = isDeviceOn;
    fan->setDutyCycle(isDeviceOn ? dutyCycle : 0);
  }

  if (digitalRead(BUTTON_1_PIN) != button1LastState)
  {
    button1LastState = !button1LastState;
    isDeviceOn = !isDeviceOn;
  }

  if (digitalRead(BUTTON_2_PIN))
  {
    digitalWrite(FAN_CONTROL_PIN, 0);
  }

  // digitalWrite(DEVICE_LED_PIN, digitalRead(BUTTON_1_PIN));
  // digitalWrite(IR_EMITTER_PIN, digitalRead(BUTTON_2_PIN));

  lcd->setCursor(0, 0);
  lcd->print(String(millis() / 1000, DEC) + " | " + (isDeviceOn ? "ON " : "OFF"));

  lcd->setCursor(0, 1);
  lcd->print(String(dutyCycle, DEC) + " | " + String(fan->getSpeed(), DEC));

  digitalWrite(DEVICE_LED_PIN, isDeviceOn);
}
