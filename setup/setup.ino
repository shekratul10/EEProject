
#define USE_WIFI_NINA false    
#define USE_WIFI101           true
#include <WiFiWebServer.h>
int l_en = 12;
int l_dir = 13;
int r_en = 8;
int r_dir = 9; //for motor controls
const int modRead = 1;
const int irRead = 3;
const int usRead = 4;
const char ssid[] = "HUAWEI nova 5T";
const char pass[] = "password";

//const char ssid[] = "Anthony's iPhone 11 Pro iOS 16";
//const char pass[] = "ejesjcoc43&/;pkndbs";
const int groupNumber = 5; // Set your group number to make the IP address constant - only do this on the EEERover network

//

float freq, period;
int ontime, offtime;
bool ir353 = false, ir571 = false, acoustic = false, mod151=false, mod239=false, magsouth=false, magnorth=false, car89=false;

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
  freq = floor(1000000/period); // determines the period of the signal by meausring the time the signal is HIGH and LOW. This functionality is reused in other signals
  
  if(offtime != 0) { // high signal when no input
    if(freq > 340.91 && freq < 366.78) {
       server.sendHeader("Access-Control-Allow-Origin", "*");
       server.send(200, F("text/plain"), (String(round(freq))+" Hz"));
       ir353 = true;
    }
    else if(freq > 564.97 && freq < 585.28) {
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, F("text/plain"), (String(round(freq))+" Hz"));
      ir571 = true;
    }
    else {
      // undefined pulse behaviour at 100 Hz needs to produce a "none" for pulses detected
      server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("None"));
    }
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("None"));
  }
}

void magUpdate(){
  int val = analogRead(A1);
  Serial.print("Mag");
  Serial.println(val);
  if(val<500){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("South"));
    magsouth = true;
  }
  else if(val>609){
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("North"));
    magnorth = true;
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("None"));
  }
}

void rModUpdate(){
  ontime = pulseIn(1, HIGH);
  offtime = pulseIn(1, LOW);
  period = ontime + offtime;
  freq = 1000000/period;

  if(ontime != 0){   
    if(freq < 152.18 && freq > 149.11){
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, F("text/plain"), (String(round(freq))+" Hz"));
      mod151 = true;
      Serial.println("151 modulating");
    }
    else if(freq < 243.84 && freq > 237.47)
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, F("text/plain"), (String(round(freq))+" Hz"));
      mod239 = true;
      Serial.println("239 modulating");
    }
    else {
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, F("text/plain"), F("None"));
    }
}

void rCarUpdate(){
  int tmp = analogRead(A0);
  int maxRead=0;
  for(int i=0;i<10;i++){
   tmp = analogRead(A0);
   if(abs(tmp)>maxRead){
    
      maxRead=abs(tmp);
    }
  
   }
  Serial.println(maxRead);
  //float amplitude = tmp * (5000/1024);
  if(maxRead > 150) { // this analogue value may not be accurate
    // 89 kHz carrier frequency only
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("89 kHz"));
    Serial.println("carrier");
    car89 = true;
  }
  else {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("None"));
  }
}

void usUpdate(){

  ontime = pulseIn(4, HIGH);
  offtime = pulseIn(4, LOW);
  period = offtime + ontime;
  freq = floor(1000/period); // reports frequency in kHz
  if(ontime != 0) {
    if(freq > 38.46154 && freq < 43.47826) {
      server.sendHeader("Access-Control-Allow-Origin", "*");
      server.send(200, F("text/plain"), (String(round(freq))+" kHz"));
      acoustic = true;
    }
    }
  else {
    server.sendHeader("Access-Control-Allow-Origin", "*");
   server.send(200, F("text/plain"), F("None"));
 }
}

void identifyrock(){
  if(ir353 == true) {
    // Thiotimoline
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("Thiotimoline"));
  }
  else if(ir571 == true) {
    // Netherite
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("Netherite"));
  }
  else if(mod151 == true && (acoustic == true || (magsouth == false && magnorth == false))){
    // Gaborium
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("Gaborium"));
  }
  else if(magnorth == true || mod151 == true && car89 == true){
    // Adamantine
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("Adamantine"));
  }
  else if((mod239 == true && car89 == true) || magsouth == true){
    // Xirang
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("Xirang"));
  }
  else if(mod239 == true && ((magsouth == false && magnorth == false)||acoustic == false)){
    // Lathwaite
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("Lathwaite"));
  }
  else{
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(200, F("text/plain"), F("None"));
  }
  ir353 = false, ir571 = false, mod151 = false, mod239 = false, acoustic = false, magnorth = false, magsouth = false, car89 = false;
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

void motion(float l_in, float r_in) {
 
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
  pinMode(A1, INPUT); // analogue for magnetic
  pinMode(irRead, INPUT); // digital pin 3 for ir pulse
  pinMode(modRead, INPUT); // digital pin 1 for modulating radio wave
  pinMode(A0, INPUT); // analogue for carrier radio wave
  pinMode(usRead, INPUT); // digital pin 4 for ultrasonic signals
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
  //EERover IP
  //WiFi.config(IPAddress(192,168,0,groupNumber+1));

  //Damani Hotspot IP
  WiFi.config(IPAddress(192,168,43,groupNumber+1));

  // iphone hotspot 172.20.10.2
  //WiFi.config(IPAddress(172,20,10,groupNumber+1));

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
  server.on(F("/radM"), rModUpdate);
  server.on(F("/radC"), rCarUpdate);
  server.on(F("/identify"), identifyrock);
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