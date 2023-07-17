int toggle_pin = PIN_D0;
int button_pin = PIN_B7;
int key_pressed = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(toggle_pin, INPUT_PULLUP); // Toggle switch
  pinMode(button_pin, INPUT_PULLUP); // Pushbutton
}
void loop() {
  if (digitalRead(toggle_pin)) {
    // D0 pin is high due to pullup resistor plus switch in "off" position
    digitalWrite(LED_BUILTIN, LOW);   // LED on
    delay(400);                       // Slow blink
    digitalWrite(LED_BUILTIN, HIGH);  // LED off
    delay(400);
    if (key_pressed == 1) {
      // Reset as if key wasn't pressed
      key_pressed = 0;
    }
  } else {
    // D0 pin is low due to switch in "on" position
    digitalWrite(LED_BUILTIN, LOW);   // LED on
    delay(50);                        // Fast blink
    digitalWrite(LED_BUILTIN, HIGH);  // LED off
    delay(50);
    // Check state of big red button pin
    if (!digitalRead(button_pin)) {
      // Big red button has been pressed

      // If we haven't already pressed the key
      if (key_pressed == 0) {
        // Send an enter
        // Keyboard.println();
        // Alternatively, hit Ctrl-V to paste a command:
        Keyboard.press(MODIFIERKEY_CTRL);
        delay(100);
        Keyboard.press(KEY_V);
        delay(100);
        Keyboard.release(KEY_V);
        Keyboard.release(MODIFIERKEY_CTRL);
        // Record that we've pressed the key
        key_pressed = 1;
      }
    }
  }
}
