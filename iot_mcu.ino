#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#define BLYNK_TEMPLATE_ID "TMPLfeOwwuBv"
#define BLYNK_DEVICE_NAME "Air Analyzer"
#define BLYNK_AUTH_TOKEN "s6V5AEG3i5I3XRseTxoOmQ7PfVlKf0Lm"
char auth[] = "s6V5AEG3i5I3XRseTxoOmQ7PfVlKf0Lm"; //Enter Authentication code sent by Blynk
 

char ssid[] = "Surya Don"; //Enter WIFI Name
char pass[] = "relaxboys"; //Enter WIFI Password
 
SimpleTimer timer;
 
int mq135 = A0; // 
int data = 0;
void getSendData()
{
data = analogRead(mq135); 
  Blynk.virtualWrite(V1, data); // Blynk INPUT Connect V2 Pin
 
  
 
} 
void setup() 
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
  Serial.print(data);
}
 
