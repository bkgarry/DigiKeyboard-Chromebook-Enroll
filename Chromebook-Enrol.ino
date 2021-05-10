#include <DigiKeyboard.h>
#define KEY_TAB 43
#define KEY_DOWN_ARROW  0x51

String ssid = "SSIDHERE";
String ssid_password = "PASSPHRASEHERE";
String email = "USERNAME\"DOMAIN"; //the /" inserts the @ symbol in the UK
String email_password = "PASSWORD";
int keyWait = 275;

void setup() {

  //Welcome Screen
  DigiKeyboard.sendKeyStroke(0);
  wait(1);
  pressKey(KEY_TAB, 2);
  pressKey(KEY_ENTER, 1);

  wait(1);

  //Wireless Setup Screen
  pressKey(KEY_TAB, 3);
  pressKey(KEY_SPACE, 2);

  //pressKey(KEY_TAB, 4);
  //pressKey(KEY_ENTER, 1);

  pressKey(KEY_TAB, 3);
  pressKey(KEY_ENTER, 1);

  wait(2);

  DigiKeyboard.print(ssid);

  pressKey(KEY_TAB, 1);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_DOWN_ARROW, 2);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_TAB, 1);

  DigiKeyboard.print(ssid_password);

  pressKey(KEY_ENTER, 1);

  wait(10); //Wait to connect to wireless

  pressKey(KEY_TAB, 3);
  pressKey(KEY_ENTER, 1);
  wait(3);
  pressKey(KEY_ENTER, 1); 

  wait(4);//Wait for OS Terms to load

  //Google Chrome OS Terms
  DigiKeyboard.sendKeyStroke(KEY_TAB,MOD_SHIFT_LEFT);
  pressKey(KEY_TAB, 3);
  pressKey(KEY_SPACE, 1); //Turn off feedback
  pressKey(KEY_TAB, 3);
  pressKey(KEY_ENTER, 1);

  wait(15);//Updates

  //Enterprise Enrollment
  pressKey(KEY_TAB, 3);
  pressKey(KEY_ENTER, 1);
  wait(5);
  pressKey(KEY_TAB, 6); 


  DigiKeyboard.print(email);
  pressKey(KEY_ENTER, 1);

  wait(4);

  DigiKeyboard.print(email_password);

  pressKey(KEY_ENTER, 1);

  
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);

}

void loop() {

}

uint8_t pressKey(uint8_t key, int times) {
  for (int i = 1; i <= times; i++) {
    DigiKeyboard.delay(50);
    DigiKeyboard.sendKeyStroke(key);
    DigiKeyboard.delay(keyWait);
  }
}

int wait(int seconds) {
  for (int i = 0; i < seconds; i++) {
    DigiKeyboard.delay(1000);
  }
}
