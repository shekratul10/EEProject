/**************************************************************************************************************************************
  EEERover Starter Example
  
  Based on AdvancedWebServer.ino - Simple Arduino web server sample for SAMD21 running WiFiNINA shield
  For any WiFi shields, such as WiFiNINA W101, W102, W13x, or custom, such as ESP8266/ESP32-AT, Ethernet, etc
  
  WiFiWebServer is a library for the ESP32-based WiFi shields to run WebServer
  Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Forked and modified from Arduino WiFiNINA library https://www.arduino.cc/en/Reference/WiFiNINA
  Built by Khoi Hoang https://github.com/khoih-prog/WiFiWebServer
  Licensed under MIT license
  
  Copyright (c) 2015, Majenko Technologies
  All rights reserved.
  
  Redistribution and use in source and binary forms, with or without modification,
  are permitted provided that the following conditions are met:
  
  Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
  
  Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
  
  Neither the name of Majenko Technologies nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.
  
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ***************************************************************************************************************************************/
#define USE_WIFI_NINA         false
#define USE_WIFI101           true
#include <WiFiWebServer.h>
const int leftwheel = 12;
const int irRead = 13;
//10 and 11 are broken it seems
const int magRead = 9;
const int radRead = 8;
const char ssid[] = "EEERover";
const char pass[] = "exhibition";
const int groupNumber = 5; // Set your group number to make the IP address constant - only do this on the EEERover network

//Webpage to return when root is requested
//const char webpage[] = 
//R"=====(<html><head><style>
//.btn {background-color: inherit;padding: 14px 28px;font-size: 16px;}
//.btn:hover {background: #eee;}
//.h1:{color:#1a1a1a;}
//</style></head>
//<body>
//<h1>EEE Rover Controls</h1>
//<button class="btn" onclick="update()">Update</button>
//<button class="btn" onclick="forward()">Forward</button>
//<button class="btn" onclick="brakes()">Stop</button>
//<br>IR Detected: <span id="state">False</span>
//</body>
//<script>
//var xhttp = new XMLHttpRequest();
//xhttp.onreadystatechange = function() {if (this.readyState == 4 && this.status == 200) {document.getElementById("state").innerHTML = this.responseText;}};
//function update() {xhttp.open("GET", "/update"); xhttp.send();}
//function forward(){xhttp.open("GET", "/fwd"); xhttp.send();}
//function brakes(){xhttp.open("GET", "/static"); xhttp.send();}
//</script></html>)=====";

WiFiWebServer server(80);
void irUpdate(){
  int val = digitalRead(irRead);
  if(val==HIGH){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("True"));
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("False"));
  }
}
void magUpdate(){
  int val = analogRead(magRead);
  
  Serial.println(val);
  if(val>270){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("South"));
  }
  else if(val<230){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("North"));
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("False"));
  }
}
void radUpdate(){
  int val = digitalRead(radRead);
  if(val==HIGH){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("True"));
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("False"));
  }
}
//Return the web page
void handleRoot()
{
  
  server.send(200, F("text/html"), webpage);
}



void forward(){
  
  
  digitalWrite(leftwheel,1);
}
void wheeloff(){
 
  digitalWrite(leftwheel,0); 
}

//Generate a 404 response with details of the failed request
void handleNotFound()
{
  String message = F("File Not Foundnn"); 
  message += F("URI: ");
  message += server.uri();
  message += F("nMethod: ");
  message += (server.method() == HTTP_GET) ? F("GET") : F("POST");
  message += F("nArguments: ");
  message += server.args();
  message += F("n");
  for (uint8_t i = 0; i < server.args(); i++)
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "n";
  }
  server.send(404, F("text/plain"), message);
}

void setup()
{
  
  pinMode(leftwheel, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(magRead, INPUT);
  pinMode(radRead, INPUT);
  pinMode(irRead, INPUT);
  digitalWrite(leftwheel,0);
  digitalWrite(LED_BUILTIN, 0);
  
  Serial.begin(9600);

  //Wait 10s for the serial connection before proceeding
  //This ensures you can see messages from startup() on the monitor
  //Remove this for faster startup when the USB host isn't attached
  while (!Serial && millis() < 10000);  

  Serial.println(F("nStarting Web Server"));

  //Check WiFi shield is present
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println(F("WiFi shield not present"));
    while (true);
  }

  //Configure the static IP address if group number is set
  if (groupNumber)
    WiFi.config(IPAddress(192,168,0,groupNumber+1));

  // attempt to connect to WiFi network
  Serial.print(F("Connecting to WPA SSID: "));
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED)
  {
    delay(500);
    Serial.print('.');
  }

  //Register the callbacks to respond to HTTP requests
  server.on(F("/"), handleRoot);
  server.on(F("/ir"), irUpdate);
  server.on(F("/mag"), magUpdate);
  server.on(F("/rad"), radUpdate);
  server.on(F("/fwd"), forward);
  server.on(F("/static"), wheeloff);
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.print(F("HTTP server started @ "));
  Serial.println(static_cast<IPAddress>(WiFi.localIP()));
}

//Call the server polling function in the main loop
void loop()
{
  
  server.handleClient();
}
