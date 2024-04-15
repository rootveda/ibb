# IBB

Interactive UI design to control the bots and monitor data stream on dashboard.

## Description

This builds includes below modules:

[1] Nodejs Server: Configured to deploy the admin and user controls.

[2] MongoDB Database: Linked to node application services.

[3] Mirocontroller {Raspberry Pi Pico}: client side (bot brain) module written in C++.


## Getting Started

### Dependencies

* For module [1] & [2]:
  - OS: Ubuntu:latest/8GB (min.)
  - Docker
* For module [3]:
  - Need 10 x Raspberry Pi Pico Wh
  - Arduino IDE
* Make sure below ports are NOT IN USE:
  - For MongoDB [29017 & 27017]
  - For Nodejs Application & cluster [1575-1600, 1773]

### Installing

1. Clone this repository

2. Install Docker on Ubuntu: https://docs.docker.com/engine/install/ubuntu/
   
3. Assign this IP/static {192.168.1.141} to your ubuntu host ~ next version will replace this with a hostname "ibb".


### Executing program

* Pull MongoDB docker image and configure: [DO NOT PULL LATEST MONGODB IMAGE]
```
docker pull mongo:bionic
docker run --name mongodb -p 29017:27017 -d mongo:bionic
```
* Now build docker IBB cluster image: [RUN THIS FROM IBB FOLDER ]
```
cd ibb
docker build -t ibb .
docker run -p 1575-1600:1575-1600 -p 1773:1773 -v ${PWD}/etc/supervisor:/etc/supervisor -v ${PWD}/var/log/supervisor:/var/log/supervisor -v ${PWD}/rules:/rules --name IBB ibb
docker stats
```

## URLs In Play

* Admin Controls: http://192.168.1.141:1575/ui
* Landing page for user: http://192.168.1.141:1580/ui
* User CTBF (capture the bot flag) port range [1581-1590]: e.g. http://192.168.1.141:1581/ui

## Pico: Bot Code

Use Arduino IDE or other to burn the code.
* Download the code from folder {ibb/ibb_pico.ino}
* Change below wi-fi config parameters to your wi-fi: [line:7 & line:8]
``` 
const char* ssid = "your_SSID";    
const char* password = "your_SSID-PWD";
```
