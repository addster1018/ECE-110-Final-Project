/*
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 
int trigPin = 11;    //Trig - green Jumper
int echoPin = 12;    //Echo - yellow Jumper
long duration, cm;
int buttonPin = 10;  // pushbutton pin
int ledLock = 9; //On when locked, off when not
int ledUnlock = 8; //On when unlocked, off when not

int code1 = 10;
int code2 = 15;
int code3 = 20;
int code4 = 15;

int flagCounter = 0;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set up the pushbutton pin to be an input:
  pinMode(buttonPin, INPUT);

  //set LED output pins
  pinMode(ledLock, OUTPUT);
  pinMode(ledUnlock, OUTPUT);

  //Start with ledLock = HIGH
  digitalWrite(ledLock, HIGH);
}
 
void loop()
{
  int buttonState = digitalRead(buttonPin);
  if(buttonState == 1){ //pressed
    flagCounter++;  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
   
  // convert the time into a distance
  cm = (duration/2) / 29.1;  

  //blink green LED if you got it right
  if(flagCounter == 1){
      if(cm > code1 - 2 && cm < code1 + 2){
        //blink LED
        digitalWrite(ledUnlock, LOW);
        delay(10);
        digitalWrite(ledUnlock, HIGH);
        delay(100);
        digitalWrite(ledUnlock, LOW);
      }
      else{
        flagCounter = 0;
        Serial.print("WRONG!");
        Serial.println();
      }
  }
  else if(flagCounter == 2){
      if(cm > code2 - 2 && cm < code2 + 2){
        //blink LED
        digitalWrite(ledUnlock, LOW);
        delay(10);
        digitalWrite(ledUnlock, HIGH);
        delay(100);
        digitalWrite(ledUnlock, LOW);
      }
      else{
        flagCounter = 0;
        Serial.print("WRONG!");
        Serial.println();
      }
  }
    else if(flagCounter == 3){
      if(cm > code3 - 2 && cm < code3 + 2){
        //blink LED
        digitalWrite(ledUnlock, LOW);
        delay(10);
        digitalWrite(ledUnlock, HIGH);
        delay(100);
        digitalWrite(ledUnlock, LOW);
      }
      else{
        flagCounter = 0;
        Serial.print("WRONG!");
        Serial.println();
      }
    }
    else if(flagCounter == 4){
      if(cm > code4 - 2 && cm < code4 + 2){
        //blink LED
        digitalWrite(ledUnlock, LOW);
        digitalWrite(ledLock, LOW);
        delay(10);
        digitalWrite(ledUnlock, HIGH);
        Serial.print("Unlocked!!");
        Serial.println();
        delay(2000);
        digitalWrite(ledUnlock, LOW);
        delay(10);
        digitalWrite(ledLock, HIGH);
        flagCounter = 0; //reset the lock
        Serial.print("Lock Reset");
        Serial.println();
        
      }
      else{
        flagCounter = 0;
        Serial.print("WRONG!");
        Serial.println();
      }
    }
    else{
      flagCounter = 0;
    }
  
  Serial.print(cm);
  Serial.print("cm, flag = ");
  Serial.print(flagCounter);
  Serial.println();
    
  delay(150);
  }
}
