
#define USE_WIFI_NINA false    
#define USE_WIFI101           true
#include <WiFiWebServer.h>
int l_en = 6;//12;
int l_dir = 8; //13;
int r_en = A5;//8;
int r_dir = 3;//9; //for motor controls
const int irRead = 3;
const int magRead = A0;
const int radRead = 2;
const int usRead = 4;
const char ssid[] = "HUAWEI nova 5T";
const char pass[] = "password";
int uscount=0;
const int groupNumber = 5; // Set your group number to make the IP address constant - only do this on the EEERover network



float freq, period;
int ontime, offtime;
//Webpage to return when root is requested
const char webpage[] = 
R"=====(<html><head><style>
.btn {background-webcolor: inherit;padding: 14px 28px;font-size: 16px;}
.btn:hover {background: #eee;}
.h1:{color:#1a1a1a;}
</style></head>
<body>
<h1>EEE Rover is Online</h1>
</html>)=====";

WiFiWebServer server(80);
void irUpdate(){

  ontime = pulseIn(3, HIGH);
  offtime = pulseIn(3, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(offtime != 0) {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), (String(freq)+" Hz"));
//    if(freq > 340.91 && freq < 366.78) {
//       server.sendHeader("Access-Control-Allow-Origin", "*");
//      server.send(200, F("text/plain"), F("353 Hz"));
//    }
//    else if(freq > 564.97 && freq < 585.28) {
//      server.sendHeader("Access-Control-Allow-Origin", "*");
//      server.send(200, F("text/plain"), F("571 Hz"));
//    }
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("None"));
  }
}

//done
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
    server.send(200, F("text/plain"), F("None"));
  }
}


void usUpdate(){
  
  ontime = pulseIn(4, HIGH);
  offtime = pulseIn(4, LOW);
  period = offtime + ontime;
  freq = 1000000/period;
  if(ontime != 0) {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), (String(freq)+" Hz"));
    }
  else {
    server.sendHeader("Access-Control-Allow-Origin", "*");
   server.send(200, F("text/plain"), F("None"));
 }
}
void handleRoot()
{
  server.send(200, F("text/html"), webpage);
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

void motion(int l_in, int r_in) {
 
  if(l_in > 0){ //forward
    digitalWrite(l_dir, HIGH);
  }
  else if(l_in < 0){ //left
    digitalWrite(l_dir, LOW);
  }
  if(r_in > 0){ 
    digitalWrite(r_dir, HIGH);
  }
  else if(r_in < 0){ 
    digitalWrite(r_dir, LOW);
  }
 
  analogWrite(l_en, abs(l_in));
  analogWrite(r_en, abs(r_in));
  Serial.println(l_in);
  Serial.println(r_in);
}
void handleMotion(){
  if(server.arg("left")&& server.arg("right")){
      int right=(server.arg("right")).toInt();
      int left=(server.arg("left")).toInt();
     
     server.sendHeader("Access-Control-Allow-Origin", "*");
     motion(left,right);
     server.send(200, F("text/plain"), F("Motor Control Engaged"));
     Serial.println("Args Present");
  }
  else{
     server.send(404, F("text/plain"), F("Motor Control Error"));
     Serial.println("Arg Error");
  }
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(magRead, INPUT);
  pinMode(radRead, INPUT);
  pinMode(irRead, INPUT);
  Serial.begin(9600);
  pinMode(l_en,OUTPUT);
  pinMode(l_dir,OUTPUT);
  pinMode(r_en,OUTPUT);
  pinMode(r_dir,OUTPUT);

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
  ////EERover IP
  //WiFi.config(IPAddress(192,168,0,groupNumber+1));

  //Damani Hotspot IP
    WiFi.config(IPAddress(192,168,43,groupNumber+1));

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
  server.on(F("/us"), usUpdate);
  server.on(F("/motion"),handleMotion);
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
