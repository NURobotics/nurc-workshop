#include <Arduino.h>
#include <LineFollower.h>

namespace LineFollower {

LineFollowerState state;
Color left_color;
Color right_color;

MAF threshold_value;
MAF left_color_value;
MAF right_color_value;

void motion_update() {
  switch(state) {
    case ON_COURSE: {
      // Keep the robot on course as long as you can
      analogWrite(LEFT_MOTOR_PIN, 255);
      analogWrite(RIGHT_MOTOR_PIN, 255);
    }
    case FAR_LEFT: {
      // Move the robot back on course
      analogWrite(LEFT_MOTOR_PIN, 255);
      analogWrite(RIGHT_MOTOR_PIN, 127);
    }
    case FAR_RIGHT: {
      // Move the robot back on course
      analogWrite(LEFT_MOTOR_PIN, 127);
      analogWrite(RIGHT_MOTOR_PIN, 255);
    }
    case OFF_COURSE: {
      // Find the course course
      analogWrite(LEFT_MOTOR_PIN, 0);
      analogWrite(RIGHT_MOTOR_PIN, 0);
    }
  }
}

void state_update() {
  switch(state) {
    case ON_COURSE: {
      if(left_color == DARK && right_color == LIGHT)
        state = FAR_RIGHT;
      else if(left_color == LIGHT && right_color == DARK)
        state = FAR_LEFT;
    }
    case FAR_LEFT: {
      if(right_color == LIGHT)
        state = OFF_COURSE;
    }
    case FAR_RIGHT: {
      if(left_color == LIGHT)
        state = OFF_COURSE;
    }
    case OFF_COURSE: {
      if(left_color == DARK && right_color == LIGHT)
        state = FAR_RIGHT;
      else if(left_color == LIGHT && right_color == DARK)
        state = FAR_LEFT;
    }
  }
}

void sensor_update() {
  double threshold = threshold_value.filter(analogRead(THRESHOLD_PIN));
  double lc_value = left_color_value.filter(analogRead(LEFT_COLOR_PIN));
  double rc_value = right_color_value.filter(analogRead(RIGHT_COLOR_PIN));

  left_color = color(lc_value, threshold);
  right_color = color(rc_value, threshold);
}

void update() {
  sensor_update();
  state_update();
  motion_update();
}

void reset() {
  // Initial state
  state = ON_COURSE;

  // Configure modes
  pinMode(THRESHOLD_PIN, INPUT);
  pinMode(LEFT_COLOR_PIN, INPUT);
  pinMode(RIGHT_COLOR_PIN, INPUT);
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);

  // Initialize motors to halt
  analogWrite(LEFT_MOTOR_PIN, 0);
  analogWrite(RIGHT_MOTOR_PIN, 0);

  // Reset the filters
  threshold_value.reset();
  left_color_value.reset();
  right_color_value.reset();
  
  // Fill the filter buffers
  for(int i = 0; i < MAF_SIZE; i++) {
    threshold_value.filter(analogRead(THRESHOLD_PIN));
    left_color_value.filter(analogRead(LEFT_COLOR_PIN));
    right_color_value.filter(analogRead(RIGHT_COLOR_PIN));
  }
}

} // namespace LineFollower
