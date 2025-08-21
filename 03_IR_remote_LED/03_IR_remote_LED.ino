#include <IRremote.hpp>
const int IR_RECEIVE_PIN = 2;   // your OUT→D2
const int LED_PIN = LED_BUILTIN;
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // LED on receiver board may blink
  Serial.println("IR receiver ready. Press buttons...");
}
void loop() {
  if (IrReceiver.decode()) {
    // Print the decoded info
    Serial.print("Protocol: ");
    Serial.print(IrReceiver.decodedIRData.protocol);
    Serial.print("  Address: 0x");
    Serial.print(IrReceiver.decodedIRData.address, HEX);
    Serial.print("  Command: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    // Example: blink onboard LED on any key
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    IrReceiver.resume(); // prepare for the next value
  }
}