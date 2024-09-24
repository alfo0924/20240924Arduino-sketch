void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
  pinMode(LED_BUILTIN,OUTPUT); //set port
  digitalWrite(LED_BUILTIN,LOW); //close LED
}

void loop() {
  // put your main code here, to run repeatedly:
      char command = Serial.read();
      if(command == 'N'){ //IF RECIVED WITH LETTER 'N' OR WORDS THAT CONTAINS 'N' IT WILL LIGHT THE LED FOR 1 SEC
        Serial.println("LED ON");
        digitalWrite(LED_BUILTIN,HIGH);
        delay(1000);
      }
      else{
        digitalWrite(LED_BUILTIN,LOW);
      }
}


