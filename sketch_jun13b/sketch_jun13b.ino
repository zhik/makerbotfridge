#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
int unlock = true;
void setup() 
{ 
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  if (unlock == true) {
  //for(pos = 0; pos < 180; pos += 180)  // goes from 0 degrees to 180 degrees 
                                 // in steps of 1 degree 
    myservo.write(0);              // tell servo to go to position in variable 'pos' 
    delay(1500);                       // waits 15ms for the servo to reach the position 
  }
    else if(unlock == false) {
    // for(pos = 180; pos>=1; pos-=180)     // goes from 180 degrees to 0 degrees 
                          
    myservo.write(180);              // tell servo to go to position in variable 'pos' 
    delay(1500);                       // waits 15ms for the servo to reach the position 
  
  }
 }


