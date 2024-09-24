void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  
  // pinMode(LED_BUILTIN,OUTPUT); //set port
  pinMode(4,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  // digitalWrite(LED_BUILTIN,LOW); //close LED
  digitalWrite(4,LOW);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  // // // put your main code here, to run repeatedly:
  //     char command = Serial.read();
  //     if(command == 'O'){ //IF RECIVED WITH LETTER 'N' OR WORDS THAT CONTAINS 'N' IT WILL LIGHT THE LED FOR 1 SEC
  //       Serial.println("LED ON");
  //       // digitalWrite(LED_BUILTIN,HIGH);
  //       digitalWrite(4,HIGH);
  //       // delay(1000);

      
  //     }
  //     else if(command == 'X'){
  //       Serial.println("LED OFF");
  //       // digitalWrite(LED_BUILTIN,LOW);
  //       digitalWrite(4,LOW);
  //       // delay(1000);
  //     }
  //     // else{
  //     //   digitalWrite(LED_BUILTIN,LOW);
  //     // }




  // put your main code here, to run repeatedly:
      // char command = Serial.read();
      int x = Serial.parseInt();
 
    
      for ( int i=0 ; i<x;i++)
      { Serial.println("LED ON" );
        digitalWrite(4,HIGH);
        digitalWrite(LED_BUILTIN,LOW);
        delay(500);
        digitalWrite(4,LOW);
        digitalWrite(LED_BUILTIN,HIGH);
         Serial.println("LED OFF");
        delay(500);
        digitalWrite(4,HIGH);
        digitalWrite(LED_BUILTIN,LOW);
        digitalWrite(4,LOW);
        digitalWrite(LED_BUILTIN,HIGH);
      }
      
       
}


 
