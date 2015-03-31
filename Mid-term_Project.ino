const int ledPin0 = 3; 
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 = 9;
const int ledPin4 = 10;
const int ledPin5 = 11;

const int pwPin = A0; 
long pulse, inches;

int fadeValue0 = 70 ;   // VITAL BREAKTHROUGH: CHANGING FADEVALUE0=0 TO FADEVALUE0=5; 
int fadeValue1 = 150;
int fadeValue2 = 230; 
int fadeValue3 = 170;
int fadeValue4 = 90;
int fadeValue5 = 10;


int fadeEffect0 = 10;
int fadeEffect1 = 10; 
int fadeEffect2 = 10; 
int fadeEffect3 = -10;
int fadeEffect4 = -10; 
int fadeEffect5 = -10; 

void setup (){
  Serial.begin(9600); 
    pinMode(pwPin, INPUT);
} 

void loop() { 


  //Used to read in the pulse that is being sent by the MaxSonar device.
  //Pulse Width representation with a scale factor of 147 uS per Inch.

  //Serial.println();

  //  if (inches >8){
  //}
  


  //Used to read in the pulse that is being sent by the MaxSonar device.
  //Pulse Width representation with a scale factor of 147 uS per Inch.



  //  if (inches >8){
  //}

  
  if (inches > 10) {
  if (fadeValue0==240 || fadeValue0<=0) {
    fadeEffect0 = -fadeEffect0;
  } 
  fadeValue0 = fadeValue0 + fadeEffect0; 
  analogWrite(ledPin0, fadeValue0);


  if (fadeValue1==240 || fadeValue1<=0) {
    fadeEffect1 = -fadeEffect1;
  } 
  fadeValue1 = fadeValue1 + fadeEffect1; 
  analogWrite(ledPin1, fadeValue1);

  if (fadeValue2==240 || fadeValue2<=0) {
    fadeEffect2 = -fadeEffect2;
  } 
  fadeValue2 = fadeValue2 + fadeEffect2; 
  analogWrite(ledPin2, fadeValue2);

  if (fadeValue3==240 || fadeValue3<=0) {
    fadeEffect3 = -fadeEffect3;
  } 
  fadeValue3 = fadeValue3 + fadeEffect3; 
  analogWrite(ledPin3, fadeValue3);


  if (fadeValue4==240 || fadeValue4<=0) {
    fadeEffect4 = -fadeEffect4;
  } 
  fadeValue4 = fadeValue4 + fadeEffect4; 
  analogWrite(ledPin4, fadeValue4);

  if (fadeValue5==240 || fadeValue5<=0) {
    fadeEffect5 = -fadeEffect5;
  } 
  fadeValue5 = fadeValue5 + fadeEffect5; 
  analogWrite(ledPin5, fadeValue5);

  }
    
  if (inches <=10 ) { 
    analogWrite(ledPin0,0); 
    analogWrite(ledPin1,0); 
    analogWrite(ledPin2,0); 
    analogWrite(ledPin3,0); 
    analogWrite(ledPin4,0); 
    analogWrite(ledPin5,0); 
  }


  pulse = pulseIn(pwPin, HIGH);
  //147uS per inch
  inches = pulse/147;
  Serial.write(inches);

}
