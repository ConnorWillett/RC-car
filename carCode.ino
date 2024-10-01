#include <Servo.h>
#define enA 10
#define in1 4
#define in2 5

Servo myservo;

const unsigned int MAX_LEN = 4;
int servorecive, motorrecive;
int servo = 0;
int motor = 0;
int motorSpeed = 0;


void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  myservo.attach(2);
}
void loop() {
 // servo = 510;
 // motor = 510;


  while(Serial.available() > 0){
    static byte message[MAX_LEN];
    static int message_pos = 0;

    byte inByte = Serial.read();

    if(inByte != 10 && (message_pos < MAX_LEN -1) ){
      message[message_pos] = inByte;
      message_pos++;
    }
    else{
      message[message_pos] = '\0';
      servorecive = message[0];
      motorrecive = message[1];
      Serial.print("servo");
      Serial.println(servorecive);
      Serial.print("motor");
      Serial.println(motorrecive);
      Serial.println(message[2]);
      Serial.println(message[3]);

      message_pos = 0;
    }
  }
  
  servo = servorecive * 4;
  motor = motorrecive * 4;

  servo = map(servo, 0, 1023, 0, 180);
  myservo.write(servo);
  
  
  if(motor < 470)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    motorSpeed = map(motor, 470, 0, 0, 255); 
  //  motorSpeed = 150;
    
  }
  else if(motor > 550)
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    motorSpeed = map(motor, 550, 1020, 0, 255);  
//    motorSpeed = 150; 
    //seeing what happends when i put a valu over 255

  }
  else
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
   // motorSpeed = 0;
  }

  if(motorSpeed > 255)
  {
    motorSpeed = 255;
  }
  else if(motorSpeed < 0)
  {
    motorSpeed = 0;
  }
 
  //Serial.print(motorSpeed);
  
  analogWrite(enA, motorSpeed);

  

  delay(20);
}
