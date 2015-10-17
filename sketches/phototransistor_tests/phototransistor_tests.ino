#include <LineFollower.h>

void test_phototransistor(const int, const int);
void phototransistor_tracking_test(const int, const int);

void setup() {
  LineFollower::reset();
}

void loop() {
  test_phototransistor(LEFT_COLOR_PIN, LEFT_MOTOR_PIN);
  test_phototransistor(RIGHT_COLOR_PIN, RIGHT_MOTOR_PIN);
}

void test_phototransistor(const int phototransistor_pin, const int motor_speed_pin) {
  phototransistor_tracking_test(phototransistor_pin, motor_speed_pin);
}

void phototransistor_tracking_test(const int phototransistor_pin, const int motor_speed_pin) {
  const int brightness = analogRead(phototransistor_pin);
  const int motor_speed = map(brightness, 512, 1023, 0, 255);
  analogWrite(motor_speed_pin, motor_speed);
}

