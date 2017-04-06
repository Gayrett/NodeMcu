#include <SPI.h>

#include <ESP8266WiFi.h>
/*
#define BLOCKED "00";
#define FOLLOWING "01";
#define PARKED "10";
#define MANUAL "11";
*/

int statusBit1, statusBit2;
char *status;
const char *CART_ID = "1";
const char* ssid = "Kala";
const char* password = "qwerty774";
const char* host = "192.168.43.53";
String sendString;
const int sleepTimeS = 1*10;
 
int ledPin = 13; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);  
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  POSTforUpdate();
  Serial.println("ESP8266 in sleep mode");
  ESP.deepSleep(sleepTimeS * 1000000);
}

void GET(){
  Serial.println(host);
  WiFiClient client;
  const int port = 1441;
  if(!client.connect(host, port)){
    Serial.println("connection failed");
    return;   
   }
  Serial.println("Geting");
  client.println("GET / HTTP/1.1");
  client.println("Host: 192.168.43.53");
  client.println("Content-Type: application/json");
  client.println("Connection: close");
  client.println();
  delay(500);
  
  while(client.available()){
    String res = client.readStringUntil('\r');
    Serial.print(res+"\n");  
  }
}

void POSTforUpdate(){
  Serial.println(host);
  WiFiClient client;
  const int port = 1441;
  if(!client.connect(host, port)){
    Serial.println("connection failed");
    return;   
   }
//  statusBit1 = digitalRead(digitalPIN1);
//  statusBit2 = digitalRead(digitalPIN2);
  status = "10";
  String sendString = "{\"cartID\":"+String(CART_ID)+",\"status\":"+String(status)+"}";
//  sendString = "{\"cartID\": \"ANA1\", \"status\": \"PARKED\/"}";
  String sendStringLen = String(sendString.length(), DEC);
  Serial.println("POSTing");
  client.println("POST /update HTTP/1.1");
  client.println("Host: 192.168.43.53");
  client.println("Content-Type: application/json");
  client.println("Connection: close");
  client.print("Content-Length: ");
  client.println(sendStringLen);
  client.println();
  client.print(sendString);
  client.println();
  delay(500);
  
  while(client.available()){
    String res = client.readStringUntil('\r');
    Serial.print(res+"\n");  
  }
  
}
 
void loop() {

}
 
