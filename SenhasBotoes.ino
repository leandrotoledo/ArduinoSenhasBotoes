/* 
*
* Arduino com 6 botoes e 1 LED RGB para digitacao de senhas (como as de banco)
*
* @author: Leandro Toledo de Souza <leandrotoledo [at] member [dot] fsf [dot] org>
* @author: Pedro Gabriel Dela Rosa <pedrogabriel.delarosa [at] gmail [dot] com>
* @date: 15/05/2013 02:00
*/

const int BTN_1 = 6;
const int BTN_2 = 7;
const int BTN_3 = 8;
const int BTN_4 = 12;
const int BTN_5 = 13;
const int LED_R = 4;
const int LED_G = 3;
const int LED_B = 2;

int button_1State = 0;
boolean button_1StateFlag = false;

int button_2State = 0;
boolean button_2StateFlag = false;

int button_3State = 0;
boolean button_3StateFlag = false;

int button_4State = 0;
boolean button_4StateFlag = false;

int button_5State = 0;
boolean button_5StateFlag = false;

int counter = 0;
byte response = 0;

void setup() {
  pinMode(BTN_1, INPUT);
  pinMode(BTN_2, INPUT);
  pinMode(BTN_3, INPUT);
  pinMode(BTN_4, INPUT);
  pinMode(BTN_5, INPUT);
  
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  button_1State = digitalRead(BTN_1);
  if (button_1State == HIGH) {
    button_1StateFlag = true;
  } else {
    if (button_1StateFlag == true) {
      button_1StateFlag = false;
      digitalWrite(LED_B, HIGH);
      delay(100);
      digitalWrite(LED_B, LOW);
      Serial.println("BTN_1");
      counter++;
    }
  }
  
  button_2State = digitalRead(BTN_2);
  if (button_2State == HIGH) {
    button_2StateFlag = true;
  } else {
    if (button_2StateFlag == true) {
      button_2StateFlag = false;
      digitalWrite(LED_B, HIGH);
      delay(100);
      digitalWrite(LED_B, LOW);
      Serial.println("BTN_2");
      counter++;
    }
  }
  
  button_3State = digitalRead(BTN_3);
  if (button_3State == HIGH) {
    button_3StateFlag = true;
  } else {
    if (button_3StateFlag == true) {
      button_3StateFlag = false;
      digitalWrite(LED_B, HIGH);
      delay(100);
      digitalWrite(LED_B, LOW);
      Serial.println("BTN_3");
      counter++;
    }
  }
  
  button_4State = digitalRead(BTN_4);
  if (button_4State == HIGH) {
    button_4StateFlag = true;
  } else {
    if (button_4StateFlag == true) {
      button_4StateFlag = false;
      digitalWrite(LED_B, HIGH);
      delay(100);
      digitalWrite(LED_B, LOW);
      Serial.println("BTN_4");
      counter++;
    }
  }
  
  button_5State = digitalRead(BTN_5);
  if (button_5State == HIGH) {
    button_5StateFlag = true;
  } else {
    if (button_5StateFlag == true) {
      button_5StateFlag = false;
      digitalWrite(LED_B, HIGH);
      delay(100);
      digitalWrite(LED_B, LOW);
      Serial.println("BTN_5");
      counter++;
    }
  }
  
  while (counter == 6) {
    if (Serial.available() > 0) {
      response = Serial.read();
      if (response == 'T') { // True
        for (int i = 0; i <= 3; i++) {
          digitalWrite(LED_G, HIGH);
          delay(100);
          digitalWrite(LED_G, LOW);
          delay(100);
        }
        counter = 0;
      } else if (response == 'F') { // False
        for (int i = 0; i <= 3; i++) {
          digitalWrite(LED_R, HIGH);
          delay(100);
          digitalWrite(LED_R, LOW);
          delay(100);
        }
        counter = 0;
      }
    }
  }
}
