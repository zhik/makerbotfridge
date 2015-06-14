#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

int got[4];
int pos = 0;
int want[4];
int unlock = false;
boolean closed = false; // true = closed door; false = open door;
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  7;      // the number of the LED pin
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  randomSeed(analogRead(0));
  want[0] = random(1, 5);
  randomSeed(analogRead(0));
  want[1] = random(1, 5);
  randomSeed(analogRead(0));
  want[2] = random(1, 5);
  randomSeed(analogRead(0));
  want[3] = random(1, 5);

}

void loop() {

  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. pressed = high
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) { // pressed ; closed
    // turn LED off:
    digitalWrite(ledPin, LOW);
    closed = true;
  Serial.println("button state high; closed"); 
  unlock = false;
  }
   else { // not pressed ; open
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    closed = false;
    Serial.println("Button state low; open");
    unlock = true;
  }
  
  //sero 
  if (unlock == true) {
    myservo.write(0);              // tell servo to go to position in variable 'pos' 
    delay(100);                       // waits 15ms for the servo to reach the position 
  }
    else if(unlock == false) {
    myservo.write(180);              // tell servo to go to position in variable 'pos' 
    delay(100);                       // waits 15ms for the servo to reach the position 
  
  }

  
  
  Serial.println(closed);
  Serial.println("it works");
  delay(500);
  while (closed == true) {
    for (int i = 0; i < 4; i++) {
      if (want[i] == 1) {
        digitalWrite(3, HIGH);
        delay(250);
        digitalWrite(3, LOW);
        delay(50);
      }
      else if (want[i] == 2) {
        digitalWrite(6, HIGH);
        delay(250);
        digitalWrite(6, LOW);
        delay(50);
      }
      else if (want[i] == 3) {
        digitalWrite(5, HIGH);
        delay(250);
        digitalWrite(5, LOW);
        delay(50);
      }
      else { //want[i]==4
        digitalWrite(4, HIGH);
        delay(250);
        digitalWrite(4, LOW);
        delay(50);
      }
    }
    for (int i = 0; i < 4; i++) {
      Serial.print(want[i]);

    }
    Serial.println("WANT");

    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    delay(300);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);

    // put your main code here, to run repeatedly:
    //joystick coordinate
    int sensorValue1 = analogRead(A0);
    int sensorValue2 = analogRead(A1);
    delay(200);
    //checking joystick - up down left right, priority on up down- add value into got[]
    if (sensorValue1 < 500 && sensorValue1 > 400) {
      /*digitalWrite(5, HIGH);
      delay(100);
      digitalWrite(5, LOW); */

      got[pos] = 3;
      pos++;
    }
    else if (sensorValue1 < 200) {
      /*digitalWrite(3, HIGH);
      delay(100);
      digitalWrite(3, LOW); */

      got[pos] = 1;
      pos++;
    }
    else if (sensorValue2 < 500 && sensorValue2 > 400) {
      /*digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(6, LOW); */

      got[pos] = 2;
      pos++;
    }
    else if (sensorValue2 < 200) {
      /*digitalWrite(4, HIGH);
      delay(100);
      digitalWrite(4, LOW); */

      got[pos] = 4;
      pos++;
    }


    for (int i = 0; i < 4; i++) {
      Serial.print(got[i]);
    }
    Serial.println("**");
    if (got[0] == want[0] && got[1] == want[1] && got[2] == want[2] && got[3] == want[3]) {
      unlock = true;
      //****
      Serial.println(unlock);
    }
    Serial.println(unlock);
    if (pos == 4) {
      pos = 0;
      got[0] = 0;
      got[1] = 0;
      got[2] = 0;
      got[3] = 0;
      //delay(500);
      if (unlock == false) {
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        delay(100);
      }
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(100);

      
      unlock = false;
      want[0] = random(1, 5);
      want[1] = random(1, 5);
      want[2] = random(1, 5);
      want[3] = random(1, 5);
    }
   
    if(buttonState==LOW){
      closed=false;
    }

    
  }
  
  
}
