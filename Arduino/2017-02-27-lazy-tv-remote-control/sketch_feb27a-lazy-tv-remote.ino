/*
 * sketch_feb27a-lazy-tv-remote.ino
 * Date: 2017-02-27
 * 
 * CLazy TV Remote
 * 
 * Making a TV remote control with an Arduino, LCD and IR LED - it works!
 *
 * Copyright (c) 2026 Christopher Elison <chriselison.uk>
 * Licensed under the MIT License.
 */

byte me;

#include <IRremote.h>
#include <IRremoteInt.h>
#include <LiquidCrystal.h>

#define DEBUG 0

// LCD setup
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Move LCD pin 3 (on Arduino) to 8 (IR needs Pin 3)
LiquidCrystal lcd(12, 11, 5, 4, 8, 2);

// IR setup
IRsend irsend;

int currChannel = 0;
const int blueBtnPin  = 7;
const int redBtnPin   = 6;
const int digitDelay = 50; // 90

// Simple solution to prevent button bouncing
bool inputEnabled = false;

// Define TV Channel data object (well, struct) - cool though!
typedef struct {
  char* chanName;
  char* chanNum;
} TVChan;

// TV Channel name/channel array - add favourite channels
TVChan channelsTest[] = {
  {"BBC One", "1"},
  {"BBC Two", "2"},
  {"Channel Four", "4"},
  {"Dave", "12"},
  {"Quest", "37"},
  {"Pop!", "125"},
  {"BBC News", "130"},
  {"Putin Propaganda", "135"},
  {"Babestation", "172"}
};

//char* chanNums[] = {"1", "2", "4", "125", "170", "172"};
//char* chanNames[] = {"BBC One", "BBC Two", "Channel Four", "Pop!", "BBC News", "Babestation"};

void setup() {
  Serial.begin(9600);

  /* Test/Debug - Dump channel list to serial monitor */
  #if DEBUG == 1
  Serial.print("[Debug]: currChannel= ");
  Serial.println(currChannel);

  Serial.print("[Debug]: Array size: ");
  Serial.println(sizeof(channelsTest) / sizeof(channelsTest[0]));
  
  for (int i=0; i< sizeof(channelsTest) / sizeof(channelsTest[0]); i++) {
    Serial.print(channelsTest[i].chanName);
    Serial.print(": ");
    Serial.println(channelsTest[i].chanNum);
  }
  Serial.println("");
  #endif
  /* */

  // Welcome & info text
  lcd.begin(16, 2);
  lcd.write("Lazy Remote v1.0");
  lcd.setCursor(0,1);
  lcd.write("By Chris Elison");
  delay(2500);

  // Show instructions
  lcd.clear();
  lcd.write("Select: [Blue]");
  lcd.setCursor(0,1);
  lcd.write("Watch: [Red]");
  delay(1000);

  // Show first channel info
  lcd.clear();
  lcd.write("Ch ");
  lcd.write(channelsTest[currChannel].chanNum);
  lcd.write(": ");
  lcd.setCursor(0,1);
  lcd.write(channelsTest[currChannel].chanName);
  
  inputEnabled = true;
}

void loop() {
  // Check if blue button pressed (channel browse)
  if (digitalRead(blueBtnPin) && inputEnabled == true) { 
    inputEnabled = false;
    cycleChannelDisplay();
    delay(1000);
    inputEnabled = true;
  }

  // Check if red button pressed (channel select)
  if (digitalRead(redBtnPin) && inputEnabled == true) {
    inputEnabled = false;
    testSendIR(atoi(channelsTest[currChannel].chanNum));
    delay(1000);
    inputEnabled = true;
  }
}

// Cycle channels (Blue button)
void cycleChannelDisplay() {
  lcd.clear();
  lcd.setCursor(0,0);

  // If last channel in array
  if (currChannel == (sizeof(channelsTest) / sizeof(channelsTest[0]))-1 ) {
    // Loop back to first channel
    currChannel = 0;
    lcd.clear();
    lcd.write("Ch ");
    lcd.write(channelsTest[currChannel].chanNum);
    lcd.write(": ");
    lcd.setCursor(0,1);
    lcd.write(channelsTest[currChannel].chanName);
  } else {
    currChannel++;
    lcd.clear();
    lcd.write("Ch ");
    lcd.write(channelsTest[currChannel].chanNum);
    lcd.write(": ");
    lcd.setCursor(0,1);
    lcd.write(channelsTest[currChannel].chanName);
  }
}

// Test transmitting IR signal!
void testSendIR(int chan) {
  #if DEBUG == 1
  Serial.println("[Debug]: testSendIR() called");
  Serial.print("[Debug]: chan = ");
  Serial.println(chan);
  Serial.print("[Debug]: currChannel= ");
  Serial.println(currChannel);
  
  Serial.print("[Debug]: Changing channel: ");
  Serial.print(channelsTest[currChannel].chanName);
  Serial.print(" - ");
  Serial.println(channelsTest[currChannel].chanNum);
  Serial.println("");
  #endif

  // Basic IR code sending for now, improve
  switch(chan) {
    case 1:
      // BBC One
      irsend.sendNEC(0xFE708F, 32);
      delay(digitDelay);
      break;
      
    case 2:
      // BBC Two
      irsend.sendNEC(0xFE609F, 32);
      delay(digitDelay);
      break;

    case 4:
      // Channel Four
      irsend.sendNEC(0xFE48B7, 32);
      delay(digitDelay);
      break;

    case 12:
      // Dave
      irsend.sendNEC(0xFE708F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFE609F, 32);
      delay(digitDelay);
      break;

    case 37:
      // Quest
      irsend.sendNEC(0xFEF00F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFE6897, 32);
      delay(digitDelay);
      break;

    case 125:
      // Pop
      irsend.sendNEC(0xFE708F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFE609F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFEE01F, 32);
      delay(digitDelay);
      break;
      
    case 130:
      // BBC NEWS
      irsend.sendNEC(0xFE708F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFEF00F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFE58A7, 32);
      delay(digitDelay);
      break;

    case 135:
      // RT
      irsend.sendNEC(0xFE708F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFEF00F, 32);
      delay(digitDelay);
      irsend.sendNEC(0xFEE01F, 32);
      delay(digitDelay);
      break;

    case 172:
      // Babestation
      irsend.sendNEC(0xFE708F, 32);
      delayMicroseconds(digitDelay);
      irsend.sendNEC(0xFE6897, 32);
      delayMicroseconds(digitDelay);
      irsend.sendNEC(0xFE609F, 32);
      delayMicroseconds(digitDelay);
      break;

    default:
      Serial.println("Error, couldn't find chan in switch/case!");
      break;
  }
      
  //delay(20);
}
