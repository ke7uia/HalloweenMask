int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=250;
int lEye =6;
int rEye =7;
int headLamp =13;


byte LED1s=0X00;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(lEye, OUTPUT);
  pinMode(rEye, OUTPUT);
  pinMode(headLamp, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LED1s);
digitalWrite(latchPin,HIGH);
delay(dt);
LED1s=LED1s+1;

  if(LED1s >199){
    Serial.print("eyes on  "); digitalWrite(lEye, HIGH); digitalWrite(rEye, HIGH);
    }
    else {
      Serial.print("eyes off "); digitalWrite(lEye,LOW); digitalWrite(rEye,LOW);
    
    }
    
  Serial.print(LED1s, BIN);
  Serial.print(",  ");
  Serial.println(LED1s);
//
//  if(LED1s >=255){
//    Serial.println("The headlamp is on"); digitalWrite(headLamp, HIGH);  }
//    else {
//      Serial.print("The headlamp is off  "); digitalWrite(headLamp, LOW);
//      }
  }
