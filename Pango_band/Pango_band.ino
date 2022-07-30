#include <ESP8266WiFi.h> //includes wifi modules library
const char* APssid = "Pango band"; //the acess point credentails of the device 
const char* APpassword = "life or death";
const int RSSI_MAX =-71;// maximum strength of signal in dBm 
const int RSSI_MIN =-74;// minimum strength of signal in dBm 
int LM35=A0;//output of temperature sensor
#define LED1 D0 
#define LED2 D1 
#define buz D2 
unsigned long Start=0;
unsigned long Time=1800000;
void setup()
{
    pinMode(LED2,OUTPUT); 
    pinMode(LED1,OUTPUT);
    pinMode(buz,OUTPUT); 
    Start=millis(); 
    WiFi.disconnect();
    delay(100); //this part turns off the wifi and resets it if it was already on 
    Serial.begin(115200);
    WiFi.mode(WIFI_OFF); 
    Serial.println();
    WiFi.mode(WIFI_AP_STA); //configuring the board in hybrid mode 
    Serial.print("Configuring access point...");
    WiFi.softAP(APssid, APpassword); 
    Serial.println(WiFi.softAPIP());
}
void loop()
{
    Serial.println("Wifi Scan Started");
    int n = WiFi.scanNetworks(); //assigns the scanned value to n 
    Serial.println("Wifi Scan Ended");
    if (n == 0)
    {
       Serial.println("No Networks found");
    }
    else
    {
       Serial.print(n);
       Serial.println("Networks found"); 
       for (int i = 0; i < n; ++i)
       {
          // Print SSID and RSSI for each network found 
          Serial.print(i + 1);
          Serial.print(") "); 
          Serial.print(WiFi.SSID(i));// SSID
          Serial.print(WiFi.RSSI(i));//Signal strength in dBm 
          Serial.print("dBm (");
          if(WiFi.SSID(i) == "Pango band")
          {
             if(WiFi.RSSI(i) >RSSI_MAX )//THIS -71 is the key this is the threshold value btw this value is set according to the distance of 1m
             {
                int i=1; 
                for(i=1;i<=10;i++)
                {
                    digitalWrite(LED2,HIGH); 
                    delay(1000); 
                    digitalWrite(LED2,LOW); 
                    delay(1000);
                }
                Serial.println("A BAND WAS FOUND");
                break;
              }
          }
          else
          {
             digitalWrite(LED2,LOW);
          }
       }
       delay(100);
    }
    Serial.println(""); 
    delay(100);
    WiFi.scanDelete(); 
    if((millis()-Start)>=Time)
    {
       tone(buz,1000,500); 
       Serial.println("BUZZER ON"); 
       Start+=Time; 
       Serial.println(Start);
    }
    int analogValue = analogRead(LM35);
    float millivolts = (analogValue/1024.0) * 3300; //3300 is the voltage provided by NodeMCU
    float celsius = millivolts/10; //converting into celsius
    Serial.print("Temp in celsius= "); 
    Serial.println(celsius); 
    if(celsius>37.5)
    {
        digitalWrite(LED1,HIGH); 
        Serial.println("LED ON"); 
        delay(1000);
    }
    else
    {
        digitalWrite(LED1,LOW);
        Serial.println("LED OFF");
    }
}
