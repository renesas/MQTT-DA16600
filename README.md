# RS Periodic MQTT Publisher

The Periodic MQTT Publisher Project showcases communication between a Renesas RA MCU and the DA16600 Wi-Fi module.
The system connects to a configured Wi-Fi network and establishes access to the internet.  It then creates a connection to an MQTT broker using the MQTT protocol.  The application periodically publishes messages to predefined MQTT topics.  These messages can represent device status, telemetry, or diagnostic information.  Published data is received and displayed on the MQTT broker for verification.  The project demonstrates reliable device-to-cloud communication.  It serves as a reference design for IoT connectivity solutions.  


# Project Structure

```
.
├── README.md
│   └── High-level overview of the project directory structure
│
├── docs
│   └── RS_Periodic_MQTT_Publisher.md
│      └── Documentation for the RS Periodic MQTT Publisher
│   
│        
├── Examples
│   │── e2studio
│   │   │   
│   │   └── Periodic_MQTT_Publisher_FPB_RA6E2
│   │       └── e²studio project for FPB-RA6E2 demonstrating Periodic MQTT Publisher
│   └── VSCode
│       │   
│       └── Periodic_MQTT_Publisher_FPB_RA6E2
│           └── VSCode project for FPB-RA6E2 demonstrating Periodic MQTT Publisher
├── src
│   │── config   
│   │    └── Module configuration generation and checking functions
│   │       
│   │   
│   │── rs_periodic_mqtt_publisher.c
│   │        └── Periodic MQTT Publisher module main source code
│   │   
│   └── rs_periodic_mqtt_publisher.h
│           └── Periodic MQTT Publisher module header file
│  
├── srec
│   └── Demonstration application executable in S-RECORD format   
│  

```
