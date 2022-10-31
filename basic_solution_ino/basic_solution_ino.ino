#define FTDI_RX_PIN               0
#define FTDI_TX_PIN               1
#define IR_RECEIVER_PIN           2
#define IR_EMITTER_PIN            3
#define DEVICE_LED_PIN            4
#define FAN_CONTROL_PIN           5
#define FAN_SENSOR_PIN            6
#define ENCODER_PIN_1             7
#define ENCODER_PIN_2             8
#define LCD_RS_PIN                9
#define LCD_EN_PIN                10
#define LCD_BACKLIGHT_PIN         11
#define LCD_D4_PIN                12
#define LCD_D5_PIN                13

#define LCD_D6_PIN                A0
#define LCD_D7_PIN                A1
#define BUTTON_1_PIN              A2
#define BUTTON_2_PIN              A3
#define CURRENT_SENSOR_PIN        A4
#define TEMPERATURE_SENSOR_PIN    A5

#define FAN_SENSOR_THRESHOLD      1000

#define IR_ON_OFF_ADDRESS         0x6CD2
#define IR_ON_OFF_CMD             0xCB
#define NUMBER_OF_REPEATS_TO_SEND 1

#include <LiquidCrystal.h>
#include <IRremote.hpp>
#include <RotaryEncoder.h>
#include <FanController.h>

LiquidCrystal *lcd;
RotaryEncoder *encoder;
FanController *fan;

IRData *ir_data;
boolean is_device_on = false;

void configure_pins() {
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

void init_lcd() {
  lcd = new LiquidCrystal(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

  lcd->begin(16, 2);
  digitalWrite(LCD_BACKLIGHT_PIN, HIGH);
}

void init_ir_comms() {
  IrReceiver.begin(IR_RECEIVER_PIN, DISABLE_LED_FEEDBACK);
  IrSender.begin(IR_EMITTER_PIN, DISABLE_LED_FEEDBACK);
}

void init_encoder() {
  encoder = new RotaryEncoder(ENCODER_PIN_1, ENCODER_PIN_2, RotaryEncoder::LatchMode::TWO03);
}

void init_fan() {
  fan = new FanController(FAN_SENSOR_PIN, FAN_SENSOR_THRESHOLD, FAN_CONTROL_PIN);
}

void setup() {
  configure_pins();

  init_lcd();
  init_ir_comms();
  init_encoder();
  init_fan();

  lcd->print("hello, world!");
}

void ir_loop() {
  if (IrReceiver.available()) {
    ir_data = IrReceiver.read();

    if (ir_data->address == IR_ON_OFF_ADDRESS) {
      if (ir_data->command == IR_ON_OFF_CMD) {
        is_device_on = !is_device_on;
      }
    }

    IrSender.write(ir_data, NUMBER_OF_REPEATS_TO_SEND);

    IrReceiver.resume();
  }
}

int pos = 0;

void loop() {
  ir_loop();

  encoder->tick();
  int newPos = encoder->getPosition();
  if (pos != newPos) {
    pos = newPos;
  }

  digitalWrite(DEVICE_LED_PIN, digitalRead(BUTTON_1_PIN));
  digitalWrite(IR_EMITTER_PIN, digitalRead(BUTTON_2_PIN));

  lcd->setCursor(0, 1);
  lcd->print(String(millis() / 1000,DEC) + " | " + String(pos));

  digitalWrite(DEVICE_LED_PIN, is_device_on);
}
