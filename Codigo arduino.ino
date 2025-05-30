#include <DHT.h>

#define DHTPIN 4       
#define DHTTYPE DHT11  

#define LED1 7         
#define LED2 8        

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop()
 {

  float temp = dht.readTemperature();
  if (!isnan(temp)) {
    Serial.print("TEMP:");
    Serial.println(temp);
  }

  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim(); 

    if (cmd == "LED1_ON") 
    {
      digitalWrite(LED1, HIGH);
    }
    else if (cmd == "LED1_OFF") 
    {
      digitalWrite(LED1, LOW);
    }
    else if (cmd == "LED2_ON") 
    {
      digitalWrite(LED2, HIGH);
    }
    else if (cmd == "LED2_OFF") 
    {
      digitalWrite(LED2, LOW);
    }
  }

  delay(1000); 
}