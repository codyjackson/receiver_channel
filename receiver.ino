#include "receiver_channel.h"
#include <Arduino.h>

ReceiverChannel channel2(5);

void setup() {
  delay(100);
  channel2.initialize();
  channel2.set_point_of_reference_as_current_signal();

  Serial.begin(9600);
}

void loop() {
  Serial.println(channel2.get_relative_signal());

  delay(100);
}