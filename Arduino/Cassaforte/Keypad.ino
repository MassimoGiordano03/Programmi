/**
 * Keypad.ino
 */

void inputData() {

  for(int i = 0; i < NUM_PASSWORD; i++) {

    int n = i + 1;

    Serial.print("Inserire il numero "); Serial.println(n);

    while(input_password[i] == 0) {

      input_password[i] = customKeypad.getKey();
    }
    Serial.println(input_password[i]);
  }
}

uint8_t testData(void) { //l'input che gli do è in esadecimale

  if(input_password[0] == user_password[0]) {

    if(input_password[1] == user_password[1]) {

      if(input_password[2] == user_password[2]) {

        if(input_password[3] == user_password[3]) {

          return 1;

        }
        else {
          return 0;
        }
      }
      else {
        return 0;
      }
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

void resetData() {

  for(int i = 0; i < NUM_PASSWORD; i++) {

    input_password[i] = 0;
    flg = 0;

  }
}
