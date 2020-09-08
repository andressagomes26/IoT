#include <Ultrasonic.h>


#include <ThingSpeak.h>

#include <WiFi.h>



String apiKey = "FFM2753WQJGHY7BU";     //  <-- seu Write API key do site ThingSpeak

const char *ssid =  "ProRat";     // <-- substitua com o ssid e senha da rede Wifi
const char *pass =  "44668822";
const char* server = "api.thingspeak.com";


#define PIN_TRIGGER   4
#define PIN_ECHO      5

#define SECRET_CH_ID 1132697     // replace 0000000 with your channel number
#define SECRET_WRITE_APIKEY "FFM2753WQJGHY7BU"   // replace XYZ with your channel write API Key

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(PIN_TRIGGER, PIN_ECHO);




WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       delay(10);

       
       pinMode(INPUT,12);
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
       ThingSpeak.begin(client);
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
int distancia = 0;
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
void loop() 
{
  
   distancia = ultrasonic.read();      
   int ldr = analogRead(36);
   ThingSpeak.setField(1,distancia);
   ThingSpeak.setField(2,ldr); 
   int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
   if(x == 200){
     Serial.println("Channel update successful.");
   }
   else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
   }
     
   
   Serial.print("Distancia: ");
   Serial.println(distancia);
   Serial.print("LDR: ");
   Serial.println(ldr);
   Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates, i've set it to 20 seconds
   delay(20000);
}
