# IBB

Interactive UI design to control the bots and monitor data stream on dashboard.

## Description

This builds includes below modules:

[1] Nodejs Server: Configured to deploy the admin and user controls.

[2] MonoDB Database: Services linked to node services.

[3] Mirocontroller {Raspberry Pi Pico}: client side (bot brain) module written in C++.


## Getting Started

### Dependencies

* For module [1] & [2]:
  OS: Ubuntu:latest/8GB
  Docker
* For module [3]:
  Raspberry Pi Pico Wh
* Make sure below ports are NOT IN USE:
  - MONGODB [29017 & 27017]
  - Nodejs Application & cluster [1575-1600, 1773]

### Installing

1. Clone this repository

2. Install Docker on Ubuntu from here - https://docs.docker.com/engine/install/ubuntu/
   
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
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
