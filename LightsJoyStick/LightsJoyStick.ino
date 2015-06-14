
int got[4];
int pos=0;
int want[4];
boolean unlock=false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  randomSeed(analogRead(0));
  want[0]=random(1,5);
  want[1]=random(1,5);
  want[2]=random(1,5);
  want[3]=random(1,5);
  
  for(int i=0; i<4; i++){
    if(want[i]==1){
      digitalWrite(3, HIGH);
      delay(250);
      digitalWrite(3,LOW);
      delay(50);
    }
    else if(want[i]==2){
      digitalWrite(6, HIGH);
      delay(250);
      digitalWrite(6,LOW);
      delay(50);
    }
    else if(want[i]==3){
      digitalWrite(5, HIGH);
      delay(250);
      digitalWrite(5,LOW);
      delay(50);
    }
    else{ //want[i]==4
      digitalWrite(4, HIGH);
      delay(250);
      digitalWrite(4,LOW);
      delay(50);
    }
  }
}

void loop() {
  
  for(int i=0;i<4;i++){
    Serial.print(want[i]);
    
  }
  Serial.println("WANT");
  
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(250);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(200);

  // put your main code here, to run repeatedly:
  //joystick coordinate 
  int sensorValue1 = analogRead(A0);
  int sensorValue2 = analogRead(A1); 
  //delay(250);

 //checking joystick - up down left right, priority on up down- add value into got[]
  if(sensorValue1<500 && sensorValue1>400){
    /*digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW); */
    
    got[pos]=3;
    pos++;
  }
  else if(sensorValue1<200){
    /*digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(3, LOW); */

    got[pos]=1;
    pos++;
  }
  else if(sensorValue2<500 && sensorValue2>400){
    /*digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW); */

    got[pos]=2;
    pos++;
  }
  else if(sensorValue2<200){
    /*digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW); */

    got[pos]=4;
    pos++;
  }
  
  for(int i=0; i<4; i++){
    Serial.print(got[i]);
  }
  Serial.println("**");
  if(got[0]==want[0] && got[1]==want[1] && got[2]==want[2] && got[3]==want[3]){
    unlock=true;
    //****
    Serial.println(unlock);
  }
  Serial.println(unlock);
  if(pos==4){
    pos=0;
    got[0]=0;
    got[1]=0;
    got[2]=0;
    got[3]=0;
    delay(500);
    if(unlock==false){
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
    unlock=false;
    want[0]=random(1,5);
    want[1]=random(1,5);
    want[2]=random(1,5);
    want[3]=random(1,5);
  }
 

  
}
