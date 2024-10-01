void setup(){
  Serial.begin(9600);
}

void loop() {
  int servoinput, motorinput;

  servoinput = analogRead(A1);
  motorinput = analogRead(A5);
  byte servosend, motorsend;
  motorsend = motorinput/4;
  servosend = servoinput/4;

  if(servosend == 10 || servosend == 13){
    servosend = 12;
  }
  if(motorsend == 10 || motorsend == 13){
    motorsend = 12;
  }
  
  Serial.write(servosend);
  Serial.write(motorsend);
  Serial.println();

  delay(20);

}
