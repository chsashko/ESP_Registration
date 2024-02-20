#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>



ESP8266WebServer server(80);
const char* ssid = "Redmi6pro";
const char* password = "12345678";
const int ledPin = D3;
String userData[4];

void handleRootPath(){

    String html ="<html><head><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"><style>";
    html +="body { font-family: Arial, sans-serif; background-color:#9dc8e7; } ";
    html +="input[type=text] {width: 100%; padding: 12px 20px; margin: 8px 0; display: inline-block; border: 1px solid #ccc; border-radius: 4px; box-sizing: border-box; }";
    html +="button { width: 100%; background-color: #4CAF50; color: white; padding: 14px 20px; margin: 8px 0;border: none; border-radius: 4px; cursor: pointer; }" ;
    html +="</style></head><body>";

    html +="<h1> ДАПРОС </h1>";
    html +="</br>";

    html +="<form action=\"/submit\" method=\"get\">";
    html +="Surname<input type=\"text\" name=\"surname\"><br>";
    html +="Name:<input type=\"text\" name=\"name\"><br>";
    html +="Email: <input type=\"text\" name=\"email\"><br>";
    html +="Date of Birth: <input type=\"date\", name = \"data\"><br>";
    html +="<button type=\"submit\" value=\"Submit\">Send</button>";
    html +="</form> ";
    html +="<form action=\"/show\" method=\"get\">";
    html +="<button>Show Data</button>";
    html +="</form>";
    html +="</body></html>";

    server.send(200,"text/html",html);
}

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