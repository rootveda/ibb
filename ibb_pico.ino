#include <Servo.h>
#include <PubSubClient.h>
#include "StringSplitter.h"
#include <WiFi.h>

//Network Config 
const char* ssid = "SSID";    
const char* password = "SSID-PWD";
const char* mqtt_server = "192.168.1.141";
const char* mqttUser = "botx";
const char* mqttPassword = "xoxoxoxo";
int mqtt_port = 1773; //"MQTT_Broker_Port"
WiFiClient espClient; //ESP BOARD Config
PubSubClient client(espClient); //ESP BOARD Config

//Topic Subscription: botID & subID
const char* botID = "IBB_bot/1"; //Staic (Subscription) ID/SerialNo. (DO NOT CHANGE): **Sync This With ID/SN File/record
String subID = "alpha"; //Varialble (Subscription) ID: May Change in Play)

//I/O Pins
int ch1; // To Read pulseIn
int ch2; // To Read pulseIn
int ch3; // To Read pulseIn
const int ch1in = 2; // Input Pin - Rx wire
const int ch2in = 3; // Input Pin - Rx wire
const int ch3in = 4; // Input Pin - Rx wire
const int ch1out = 16; // Output Pin - ESC/Servo CH1 wire
const int ch2out = 17; // Output Pin - ESC/Servo CH2 wire
const int ch3out = 18; // Output Pin - ESC/Servo CH3 wire
int minrxval = 1900;
int maxrxval = 1050;


//3CH Controls
int escoutval1; //Output value for: ch1out = 4; // Output Pin - ESC/Servo CH1 wire
int escoutval2; //Output value for: ch2out = 5; // Output Pin - ESC/Servo CH2 wire
int escoutval3; //Output value for: ch3out = 16; // Output Pin - ESC/Servo CH3 wire
Servo esc1; //for: ch1out = 4; // Output Pin - ESC/Servo CH1 wire
Servo esc2; //for: ch2out = 5; // Output Pin - ESC/Servo CH2 wire
Servo esc3; //for: ch3out = 16; // Output Pin - ESC/Servo CH3 wire

//Initial escoutval (CH 1,2 & 3) For "ESC/Servo" (May Chnage in Play)
int esc1min = 93;
int esc1max = 94;
int esc2min = 93;
int esc2max = 94;
int esc3min = 10;
int esc3max = 20;
int ch1nerf;
int ch2nerf;
int ch3nerf;

char publish_value[180];
char ch1v1[5];
char ch2v2[5];
char ch3v3[5];
char escv1[5];
char escv2[5];
char escv3[5];
char xxesc1min [5];
char xxesc1max [5];
char xxesc2min [5];
char xxesc2max [5];
char xxesc3min [5];
char xxesc3max [5];

//pulsein-interrupt var 3ch
volatile long StartTimeFWD = 0;
volatile long CurrentTimeFWD = 0;
volatile long PulsesFWD = 0;
int PulseWidthFWD = 0;

volatile long StartTimeSide = 0;
volatile long CurrentTimeSide = 0;
volatile long PulsesSide = 0;
int PulseWidthSide = 0;

volatile long StartTimeSpin = 0;
volatile long CurrentTimeSpin = 0;
volatile long PulsesSpin = 0;
int PulseWidthSpin = 0;

void PulseTimerFWD(){
  CurrentTimeFWD = micros();
  if (CurrentTimeFWD > StartTimeFWD){
    PulsesFWD = CurrentTimeFWD - StartTimeFWD;
    StartTimeFWD = CurrentTimeFWD;
  }
}
void PulseTimerSide(){
  CurrentTimeSide = micros();
  if (CurrentTimeSide > StartTimeSide){
    PulsesSide = CurrentTimeSide - StartTimeSide;
    StartTimeSide = CurrentTimeSide;
  }
}
void PulseTimerSpin(){
  CurrentTimeSpin = micros();
  if (CurrentTimeSpin > StartTimeSpin){
    PulsesSpin = CurrentTimeSpin - StartTimeSpin;
    StartTimeSpin = CurrentTimeSpin;
  }
}

//Wifi Config: Bot to Server/Hotspot

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//Data Processing: Bot & Server Communication

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String payload_value;
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    payload_value += (char)payload[i];
  }
  Serial.println();
  String strTest = payload_value;
  Serial.println("Test String: " + strTest);
  StringSplitter *splitter = new StringSplitter(strTest, ',', 10);
  int itemCount = splitter->getItemCount();
  Serial.println("Item count: " + String(itemCount));
  String data[80];

  for(int i = 0; i < itemCount; i++){
    String item = splitter->getItemAtIndex(i);
    Serial.println("Item @ index " + String(i) + ": " + String(item));    
    data[i] = item;
  }  

if(data[0] == "botmove")
  {
    String xesc1min = data[1];
    String xesc1max = data[2];
    String xesc2min = data[3];
    String xesc2max = data[4];
    esc1min = xesc1min.toInt();
    esc1max = xesc1max.toInt();
    esc2min = xesc2min.toInt();
    esc2max = xesc2max.toInt();
    Serial.println(esc1min);
    Serial.println(esc1max);
    Serial.println(esc2min);
    Serial.println(esc2max);
  }

if(data[0] == "botspin")
  {
    String xesc3min = data[1];
    String xesc3max = data[2];
    esc3min = xesc3min.toInt();
    esc3max = xesc3max.toInt();
    Serial.println(esc3min);
    Serial.println(esc3max);
  }

  if(data[0] == "reset"){
    software_reset();
  }

if(data[0] == "readval")
  {
    client.publish("botvalue", publish_value);
    //Serial.println(publish_value);
  }

if(data[0] == botID && data[1] == "subID")
  {
    client.unsubscribe(subID.c_str());
    String xsubid = data[2];
    subID = xsubid;
    //client.subscribe(subID.c_str());   
    Serial.println((String) "subID Changed To: " + subID);
  }
}

//Bot MQTT Client to MQTT Broker (Server) Connection
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect(botID,mqttUser,mqttPassword)) {
      Serial.println("connected");
      client.subscribe(botID);
      //client.subscribe(subID.c_str());
      client.publish("botconnect", botID);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      delay(2000);
    }
  }
}

//Initial Bot Pins & Mqtt Client Setup
void setup() {

  pinMode(ch1in, INPUT_PULLUP);
  pinMode(ch2in, INPUT_PULLUP);
  pinMode(ch3in, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ch1in),PulseTimerFWD,CHANGE);
  attachInterrupt(digitalPinToInterrupt(ch2in),PulseTimerSide,CHANGE);
  attachInterrupt(digitalPinToInterrupt(ch3in),PulseTimerSpin,CHANGE);

  esc1.attach(ch1out);
  esc2.attach(ch2out);
  esc3.attach(ch3out);
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server,mqtt_port);
  client.setCallback(callback);
}

void software_reset()
{
    *((volatile uint32_t*)(PPB_BASE + 0x0ED0C)) = 0x5FA0004;
}

void loop() {

//Keep Connected to MQTT Server
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

//RC(rx) Value (Input) ~Routed To~ ESC/Servo Pins (Output)
  if (PulsesFWD < 2000){
    ch1 = PulsesFWD;
  }
  if (PulsesSide < 2000){
    ch2 = PulsesSide;
  }
  if (PulsesSpin < 2000){
    ch3 = PulsesSpin;
  }

    itoa(ch1nerf, ch1v1, 10);
    itoa(ch2nerf, ch2v2, 10);
    itoa(ch3nerf, ch3v3, 10);
    itoa(escoutval1, escv1, 10);
    itoa(escoutval2, escv2, 10);
    itoa(escoutval3, escv3, 10);
    itoa(esc1min, xxesc1min, 10);
    itoa(esc1max, xxesc1max, 10);
    itoa(esc2min, xxesc2min, 10);
    itoa(esc2max, xxesc2max, 10);
    itoa(esc3min, xxesc3min, 10);
    itoa(esc3max, xxesc3max, 10);
    strcpy(publish_value,botID);
    strcat(publish_value,",");
    strcat(publish_value,subID.c_str());
    strcat(publish_value,",");
    strcat(publish_value,ch1v1);
    strcat(publish_value,",");
    strcat(publish_value,ch2v2);
    strcat(publish_value,",");
    strcat(publish_value,ch3v3);
    strcat(publish_value,",");
    strcat(publish_value,escv1);
    strcat(publish_value,",");
    strcat(publish_value,escv2);
    strcat(publish_value,",");
    strcat(publish_value,escv3);
    strcat(publish_value,",");
    strcat(publish_value,xxesc1min);
    strcat(publish_value,",");
    strcat(publish_value,xxesc1max);
    strcat(publish_value,",");
    strcat(publish_value,xxesc2min); 
    strcat(publish_value,",");
    strcat(publish_value,xxesc2max); 
    strcat(publish_value,",");
    strcat(publish_value,xxesc3min);    
    strcat(publish_value,",");
    strcat(publish_value,xxesc3max);

    if (ch1 > 950 && ch1 < 2050 && abs(ch1 - 1450) > 100) {
    escoutval1 = map(ch1, 900, 2000, esc1min, esc1max);
    esc1.write(escoutval1);
    ch1nerf = map(ch1, 900, 2000, 0, 180);
    //ch1nerf = ch1;
    //ch1nerf = ch1;
    //Serial.print("ch1: ");
    //Serial.println(ch1);
    }
    else {
      esc1.write(90);
    }

    if (ch2 > 950 && ch2 < 2050 && abs(ch2 - 1450) > 100) {
    escoutval2 = map(ch2, 900, 2000, esc2min, esc2max);
    esc2.write(escoutval2);
    ch2nerf = map(ch2, 900, 2000, 0, 180);
    //ch2nerf = ch2;
    //Serial.print("ch2: ");
    //Serial.println(ch2);
    }
    else {
      esc2.write(90);
    }

  if (ch3 > 950 && ch3 < 2050 && abs(ch3 - 1450) > 100) {
    escoutval3 = map(ch3, 900, 2000, esc3min, esc3max);
    esc3.write(escoutval3);
    ch3nerf = map(ch3, 900, 2000, 0, 180);
    //ch2nerf = ch2;
    //Serial.print("ch2: ");
    //Serial.println(ch2);
    }
    else {
      esc3.write(90);
    }

  client.publish("rcvalue", publish_value);
  Serial.println(String(publish_value));
  //Serial.println(ch1);
  delay(100);
  
}
