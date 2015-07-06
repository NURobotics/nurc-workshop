#include <LineFollower.h>

#define UPDATE_RATE 100.0

void setup() {
  // Perform necessary setup once
  LineFollower::reset();
}

void loop() {
  // Rate-limited update
  LineFollower::update();

  // 100 Hertz or
  // once every 10 milliseconds
  delay(0.1/UPDATE_RATE); 
}
