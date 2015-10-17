#include <LineFollower.h>

#define TEST_DELAY 1000.0

void test_motor(const int);
void motor_spin_test(const int);
void motor_speed_test(const int);

void setup() {
  LineFollower::reset();
}

void loop() {
  test_motor(LEFT_MOTOR_PIN);
  test_motor(RIGHT_MOTOR_PIN);
}

void test_motor(const int motor_speed_pin) {
  motor_spin_test(motor_speed_pin);
  delay(TEST_DELAY);
  motor_speed_test(motor_speed_pin);
  delay(TEST_DELAY);
}

void motor_spin_test(const int motor_speed_pin) {
  analogWrite(motor_speed_pin, 255);
  delay(TEST_DELAY);
  analogWrite(motor_speed_pin, 0);
}

void motor_speed_test(const int motor_speed_pin) {
  // Ramp up the motor's speed linearly from 0-100% over 1 second.
  int i = 0;
  for (i = 0; i < 256; i++) {
    analogWrite(motor_speed_pin, i);
    delay(1000.0 / 256.0);
  }
  
  // Hold the max speed for 1 second.
  delay(1000.0);

  // Reduce the motor's speed linearly from 100-0% over 1 second.
  for (i = 255; i >= 0; i--) {
    analogWrite(motor_speed_pin, i);
    delay(1000.0 / 256.0);
  }
}

