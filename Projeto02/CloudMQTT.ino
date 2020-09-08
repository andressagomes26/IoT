 /*////////////////////////////////////////////////////////////////////////////////////////////////////
 *                                                                                                   /
 * Este programa mostra como fazer uma aplicacao usando lingugem mqtt para ligar e desligar leds     /
 * Usando um ESP8266-12E                                                                             /
 * Foi utilizado o site IoT https://www.cloudmqtt.com/                                               /
 * O tutorial deste e de outras aplicações didaticas estão disponiveis no meu website                /
 * ///////////////////////////////////////////////////////////////////////////////////////////////////
 * 
 * //////////////////////////////////////////////////////////////////////////
 * Prática baseada no código disponível em www.carloskwiek.com.br        ////
 * ////////////////////////////////////////////////////////////////////////*/
 


#include <WiFi.h>
#include <PubSubClient.h> // Biblioteca usada, baixe e instale se não a tiver, link abaixo
                          //https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino
 
const char* ssid = "ProRat"; //Aqui o nome da sua rede local wi fi
const char* password =  "44668822"; // Aqui a senha da sua rede local wi fi
const char* mqttServer = "tailor.cloudmqtt.com"; // Aqui o endereço do seu servidor fornecido pelo site 
const int mqttPort = 16946; // Aqui mude para sua porta fornecida pelo site
const char* mqttUser = "jemqcgkq"; //  Aqui o nome de usuario fornecido pelo site
const char* mqttPassword = "DlPgV0Ehxagw"; //  Aqui sua senha fornecida pelo site
//char EstadoSaida = '0';  
WiFiClient espClient;
PubSubClient client(espClient);


void mqtt_callback(char* topic, byte* payload, unsigned int length);


void setup() {

    pinMode(5, OUTPUT);
  
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  
 
  client.publish("liga","desliga");
  client.subscribe("LED");
  client.subscribe("PP");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Mensagem recebida no topico: ");
  Serial.println(topic);
 
  Serial.print("Mensagem:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
       String msg;
    
 
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    }
    Serial.println(msg);
    if(msg.equals("MOV")){
       Serial.println("MOV mensagem......");
       digitalWrite(5,HIGH);
       delay(500);
       digitalWrite(5,LOW); 
       delay(500); 
    }
        
    //toma ação dependendo da string recebida:
    //verifica se deve colocar nivel alto de tensão na saída.
    //IMPORTANTE: o Led já contido na placa é acionado com lógica invertida (ou seja,
    //enviar HIGH para o output faz o Led apagar / enviar LOW faz o Led acender)
 
 
    //verifica se deve colocar nivel alto de tensão na saída se enviar L e digito, ou nivel baixo se enviar D e digito no topíco LED

    
  Serial.println();
  Serial.println("-----------------------------");
 
}
 
void loop() {
  client.loop();
}
