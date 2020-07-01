int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int LED1 = 13;


void setup() {
Serial.begin(9600);
 pinMode(LED1, OUTPUT);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 

  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" F"); 
  Serial.print("Voltage: "); 
  Serial.print(Vo);
  Serial.println();

  if (T>75){
    digitalWrite(LED1, HIGH);
    delay(2000);
    //tone(12, 20, 5000);
    }
  else{
    digitalWrite(LED1, LOW);
    }
   

  delay(2000);
}

