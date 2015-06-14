// constants won't change. They're used here to 
// set pin numbers
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin =  8;      // the number of the LED pin


boolean closed=true; // true = closed , false = open

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. pressed 
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH); 
    Serial.println("button state high; closed");
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
    Serial.println("button state low; open");
  }
}
