#define FALSE_TRESHOLD 160
#define TRUE_TRESHOLD 800
#define FALSE_DELAY 5
#define TRUE_DELAY 1

void buzzTrue(void) {
  for(int i = 0; i < TRUE_TRESHOLD; i++) {

    digitalWrite(PIN_BUZZ, HIGH);
    delay(TRUE_DELAY);
    digitalWrite(PIN_BUZZ, LOW);
    delay(TRUE_DELAY);

  }
}

void buzzFalse(void) {
  for(int i = 0; i < FALSE_TRESHOLD; i++) {

    digitalWrite(PIN_BUZZ, HIGH);
    delay(FALSE_DELAY);
    digitalWrite(PIN_BUZZ, LOW);
    delay(FALSE_DELAY);

  }
}
