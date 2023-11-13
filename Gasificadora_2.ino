float Pres;
float P=Pres;
float alpha=0.05;
float prom=0;
float sum=0;
const int botton=10;
const int verde=3;
const int rojo=4;
const int valv=11;
const int agitador=12;
const int buzzer=13;

void setup() {

Serial.begin(9600);
pinMode(botton, INPUT);
pinMode(verde,OUTPUT);
pinMode(rojo,OUTPUT);
pinMode(valv,OUTPUT);
pinMode(buzzer, OUTPUT);
pinMode(agitador, OUTPUT);
digitalWrite(buzzer,HIGH);
digitalWrite(valv, HIGH);
digitalWrite(rojo, LOW);
digitalWrite(verde, LOW);
digitalWrite(agitador, HIGH);
}

void loop() {
  
  for(int i=0;i<5;i++){
         Pres = analogRead(A5);
         sum=sum+Pres;
         delay(20);
      }
  prom=sum/5;
  sum=0;
  P=(alpha*prom)+((1-alpha)*P);
  Serial.print(prom);
  Serial.print("   ");
  Serial.println(P);
  if(digitalRead(botton) == HIGH){
      digitalWrite(verde, LOW);
      digitalWrite(rojo, LOW);
      digitalWrite(agitador, LOW);
      delay(1800);
      if(P>165){
          delay(10000);
          goto p165;
      }
      if(P>130){
          delay(10000);
          goto p130;
      }
      digitalWrite(valv, LOW);
      for(int j=0;j<500;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      }
  digitalWrite(valv, HIGH);
  for(int j=0;j<800;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
  }     
  p110:
  
  while( P < 110){
      digitalWrite(valv, LOW);
      for(int j=0;j<450;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      } 
  digitalWrite(valv, HIGH);  
      for(int j=0;j<800;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      }
  }


   p130:
  
  while( P < 130){
      digitalWrite(valv, LOW);
      for(int j=0;j<300;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      } 
  digitalWrite(valv, HIGH);  
      for(int j=0;j<800;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      }
  }

  p145:

  while( P < 145){
      digitalWrite(valv, LOW);
      for(int j=0;j<150;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      } 
  digitalWrite(valv, HIGH);  
      for(int j=0;j<800;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      }
  }
    
    p165:
    
    while( P < 165){
      digitalWrite(valv, LOW);
      for(int j=0;j<80;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      } 
  digitalWrite(valv, HIGH);  
      for(int j=0;j<900;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
      }
  }
        for(int j=0;j<1500;j++){
        for(int i=0;i<5;i++){
          Pres = analogRead(A5);
          sum=sum+Pres;
          delay(20);
        }
        prom=sum/5;
        sum=0;
        P=(alpha*prom)+((1-alpha)*P);
        Serial.print(prom);
        Serial.print("   ");
        Serial.println(P);
        if(P < 165){
        goto p165;
      }
      }
  if (P < 185 && P > 165){
    digitalWrite(verde, HIGH);            
  }
  if(P > 185){
    digitalWrite(rojo, HIGH);
  }
  if(P<165){
    digitalWrite(verde, HIGH);
    digitalWrite(rojo, HIGH);  
  }
  digitalWrite(agitador, HIGH);
  for(int k=0; k<4 ; k++){
    digitalWrite(buzzer, LOW);
    delay(1500);
    digitalWrite(buzzer, HIGH);
    delay(800);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(buzzer, HIGH);
    
  }
  
  
  }
}
