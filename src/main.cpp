#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>



ESP8266WebServer server(80);
const char* ssid = "Redmi6pro";
const char* password = "12345678";
const int ledPin = D3;
String userData[4];


void handleSubmit(){
  userData[0]=server.arg("surname");
  userData[1]=server.arg("name");
  userData[2]=server.arg("email");
  userData[3]=server.arg("data");
  server.sendHeader("Location", "/");
  server.send(302,"text/plain","Data submitted successfully!!! :3");

}

void handleShow(){
  Serial.println("-__________________________________-");
  Serial.println("User surname: "+ userData[0]);
  Serial.println("User name: "+ userData[1]);
  Serial.println("User email: "+ userData[2]);
  Serial.println("User date of birth: "+ userData[3]);
  Serial.println("-__________________________________-");
  server.sendHeader("Location", "/");
  server.send(302,"text/plain","Data submitted successfully!!! :3");

}





void setup() {
  Serial.begin(9600);
  pinMode(D3,OUTPUT);

  WiFi.mode(WIFI_STA); // AP - access point / STA-station mode
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());

  server.on("/",HTTP_GET,handleRootPath);
  server.on("/submit",HTTP_GET,handleSubmit);
  server.on("/show",HTTP_GET,handleShow);

  server.begin();
  Serial.println("Server is ready");
}

void loop() {
  server.handleClient();
}