/**
 * Cassaforte.ino
 */

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

#define NUM_PASSWORD 4
char user_password[NUM_PASSWORD] = {49, 50, 51, 52};
char input_password[NUM_PASSWORD];

uint8_t flg = 0;

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
#define PIN_BUZZ 12

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {

  Serial.begin(9600);
  pinMode(PIN_BUZZ, OUTPUT);

  // for(int i = 0; i < NUM_PASSWORD; i++) {
  //
  //   while(user_password[i] == 0) {
  //
  //     user_password[i] = customKeypad.getKey();
  //   }
  // }
}

void loop() {

  inputData();

  Serial.println("Bravo, hai inserito tutti i numeri, ora controlliamo");

  if(testData()) {
    /**
     * Attivare l'attuatore per sbloccare la porta
     */
    buzzTrue();
  } else {
    buzzFalse();
  }

  resetData();

}
