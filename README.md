# RS Periodic MQTT Publisher

The Periodic MQTT Publisher Project showcases communication between a Renesas RA MCU and the DA16600 Wi-Fi module.
The system connects to a configured Wi-Fi network and establishes access to the internet.  It then creates a connection to an MQTT broker using the MQTT protocol.  The application periodically publishes messages to predefined MQTT topics. Published data is received and displayed on the MQTT broker for verification.  The project demonstrates reliable device-to-cloud communication.  It serves as a reference design for IoT connectivity solutions.  


# Project Directory Structure

```
.
├── README.md/index.html
│   └── High-level overview of the project directory structure
│
├── docs
│   └── RS_Periodic_MQTT_Publisher.md/RS_Periodic_MQTT_Publisher.html
│      └── Documentation for the RS Periodic MQTT Publisher
│        
├── Examples
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
## Contents

- [Documentation](#documentation)
- [Example projects](#example-projects)
- [Application entry points](#application-entry-points)
- [Periodic MQTT Publisher module](#periodic-mqtt-publisher-module)
- [Configuration sources](#configuration-sources)
- [Demo sources](#demo-sources)
- [Console support](#console-support)
- [Prebuilt firmware](#prebuilt-firmware)

## Documentation

- [RS Periodic MQTT Publisher User Manual](docs/RS_Periodic_MQTT_Publisher.md) — architecture, configuration, usage, APIs, validation, error handling, and functional flow.

## Example projects

- [Visual Studio Code project](Examples/VSCode/Periodic_MQTT_Publisher_FPB_RA6E2/) — complete FPB-RA6E2 project for VS Code.

## Application entry points

- [`main_thread_entry.c`](src/main_thread_entry.c) — FreeRTOS main-thread entry point.

## Periodic MQTT Publisher module

- [`rs_periodic_mqtt_publisher.c`](src/rs_periodic_mqtt_publisher/rs_periodic_mqtt_publisher.c) — module implementation.
- [`rs_periodic_mqtt_publisher.h`](src/rs_periodic_mqtt_publisher/rs_periodic_mqtt_publisher.h) — public API, types, and declarations.

## Configuration sources

- [`rs_periodic_mqtt_publisher_config.c`](src/rs_periodic_mqtt_publisher/config/rs_periodic_mqtt_publisher_config.c) — configuration generation and validation.
- [`rs_periodic_mqtt_publisher_data.h`](src/rs_periodic_mqtt_publisher/config/rs_periodic_mqtt_publisher_data.h) — common configuration data declarations.
- [`rs_periodic_mqtt_publisher_data_fpb_ra6e2.c`](src/rs_periodic_mqtt_publisher/config/rs_periodic_mqtt_publisher_data_fpb_ra6e2.c) — FPB-RA6E2 configuration data.
- [`rs_periodic_mqtt_publisher_data_fpb_ra6e2.h`](src/rs_periodic_mqtt_publisher/config/rs_periodic_mqtt_publisher_data_fpb_ra6e2.h) — FPB-RA6E2 configuration declarations.

## Demo sources

- [`rs_periodic_mqtt_publisher_demo.c`](src/rs_periodic_mqtt_publisher/demo/rs_periodic_mqtt_publisher_demo.c) — demonstration application and periodic publishing flow.
- [`user.h`](src/rs_periodic_mqtt_publisher/demo/user.h) — user-configurable settings.
- [`mqtt_cert.h`](src/rs_periodic_mqtt_publisher/demo/mqtt_cert.h) — MQTT certificate configuration.

## Console support

- [`r_byteq.c`](src/console/r_byteq.c) and [`r_byteq.h`](src/console/r_byteq.h) — byte-queue implementation and interface.
- [`syscalls_picolib_stdio_to_uart.c`](src/console/syscalls_picolib_stdio_to_uart.c) — redirects standard I/O to UART.

## Prebuilt firmware

- [FPB-RA6E2 S-record image](srec/MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.srec)
