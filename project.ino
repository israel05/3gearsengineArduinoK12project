  const int RED= 9; // digital 11 red diode //tone disable D3 and D11
  const int ORANGE= 6; // digital 6 orange diode //tone disable D3 and D11
  const int GREEN= 5; // digital 3 green diode //tone disable D3 and D11
  const int BUZZER=12;


void setup() {
  pinMode(A0,INPUT);
  pinMode(11,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue=0; // read from a0
  int RedLedIntensity=0; // glowing red
  int OrangeLedIntensity=0; //glowing orange
  int GreenLedIntensity=0; //glowing green
  int zone=0; // 0 for red, 1 for orange, 2 for green
  potValue=analogRead(A0); // Analog0 read, from 0 to 1023
  Serial.print("Analog A0");
  Serial.println(potValue);
   delay(100);
  // check the zone
  if (potValue<300){
    zone=0; // RED ZONEE
  } else  if (potValue<660 && potValue>301){  
    zone=1; // ORANGE ZONE
  }else { // greater than 660
      zone=2; //GREEN ZONE
  }

  // SWITCH BETWEEN ZONES and map according to values
  switch (zone) {
    case 0:
      // RED ZONE
      Serial.println("RED ZONE");
     // delay(100);
      Serial.print("A0 Value ");
      Serial.println(potValue);
      RedLedIntensity=map(potValue, 0, 299, 0, 255); //  map(value, fromLow, fromHigh, toLow, toHigh)     
       Serial.print("led intensity: ");
      Serial.print(RedLedIntensity); 
      Serial.println(" ");
      // delay(100);
      analogWrite(RED,RedLedIntensity);     
      analogWrite(ORANGE,0); // if it is red, it cannot be others
      analogWrite(GREEN,0);   
      tone(BUZZER, RedLedIntensity, 100);
      break;
      
    case 1:
      // ORANGE ZONE
      Serial.println("ORANGE ZONE");
       //delay(100);
        Serial.print("A0 Value ");
      Serial.println(potValue);
      OrangeLedIntensity=map(potValue, 300, 660, 0, 255); //  map(value, fromLow, fromHigh, toLow, toHigh)
       Serial.print("led intensity: ");
      Serial.print(OrangeLedIntensity);
      Serial.println(" ");
     //  delay(100);
      analogWrite(ORANGE,OrangeLedIntensity);  
      analogWrite(GREEN,0);     
      tone(BUZZER, OrangeLedIntensity, 100);   
      break;
      
    case 2:
      // GREEN ZONE
      Serial.println("GREEN ZONE");
      // delay(100);
        Serial.print("A0 Value ");
      Serial.println(potValue);
      GreenLedIntensity=map(potValue, 661, 1024, 0, 255); //  map(value, fromLow, fromHigh, toLow, toHigh)
      Serial.print("led intensity: ");
      Serial.print(GreenLedIntensity);      
      Serial.println(" ");
      // delay(100);    
      analogWrite(GREEN,GreenLedIntensity);   
      tone(BUZZER, GreenLedIntensity, 100); 
      break;
      
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }


}
