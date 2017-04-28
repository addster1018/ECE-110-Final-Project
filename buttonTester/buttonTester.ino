int buttonPin = 10;

void setup() {
  //Serial Port begin
  Serial.begin (9600);
  
  // Set up the pushbutton pin to be an input:
  pinMode(buttonPin, INPUT);

}

void loop() {

  int buttonState = digitalRead(buttonPin);
  if(buttonState == 0){ //default
    Serial.print("Unpressed"); //buttonState = 0
  }
  else{ //button press
    Serial.print("Pressed"); // buttonState = 1
  }
  Serial.println();
  delay(150);

}
