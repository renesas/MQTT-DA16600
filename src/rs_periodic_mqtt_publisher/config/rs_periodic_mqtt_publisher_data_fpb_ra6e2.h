#if RS_PERIODIC_MQTT_PUBLISH_PRESET_CONFIG_USE
#ifndef RS_CONFIG_FPB_RA6E2_H_
#define RS_CONFIG_FPB_RA6E2_H_
#include <stdint.h>
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "event_groups.h"
#include "FreeRTOS.h"
#include "timers.h"
#include "r_dtc.h"
#include "r_transfer_api.h"
#include "r_sci_uart.h"
#include "r_uart_api.h"
#include "rm_at_transport_da16xxx_uart.h"
#include "rm_at_transport_da16xxx.h"
#include "rm_wifi_da16xxx.h"
#include "r_ioport.h"
#include "bsp_pin_cfg.h"
FSP_HEADER
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer0_preset;

/** Access the DTC instance using these structures when calling API functions directly (::p_api is not used). */
extern dtc_instance_ctrl_t g_transfer0_ctrl_preset;
extern const transfer_cfg_t g_transfer0_cfg_preset;
/** UART on SCI Instance. */
extern const uart_instance_t g_uart0_preset;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t g_uart0_ctrl_preset;
extern const uart_cfg_t g_uart0_cfg_preset;
extern const sci_uart_extended_cfg_t g_uart0_cfg_extend_preset;

#ifndef rm_at_transport_da16xxx_uart_callback
void rm_at_transport_da16xxx_uart_callback(uart_callback_args_t *p_args);
#endif
extern const char *g_at_transport_da16xxx_uart_cmd_baud_preset;
extern at_transport_da16xxx_instance_ctrl_t g_at_transport_da16xxx_ctrl_preset;
extern at_transport_da16xxx_cfg_t g_at_transport_da16xxx_cfg_preset;
extern const at_transport_da16xxx_instance_t g_at_transport_da16xxx_preset;
extern const wifi_da16xxx_cfg_t g_wifi_da16xxx_cfg_preset;


/* IOPORT control structure. */

extern EventGroupHandle_t g_periodic_event_group;
extern TimerHandle_t g_receiveTaskWakeUp;
void g_receiveTaskWakeUp_callback(TimerHandle_t xTimer);
void g_common_init(void);

#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void main_thread_entry(void * pvParameters);
                #else
extern void main_thread_entry(void *pvParameters);
#endif
#include "r_gpt.h"
#include "r_timer_api.h"
#include "rm_mqtt_onchip_da16xxx.h"

/** Timer on GPT Instance. */
extern const timer_instance_t g_timer1_preset;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_timer1_ctrl_preset;
extern const timer_cfg_t g_timer1_cfg_preset;

#ifndef g_periodic_timer_callback
void g_periodic_timer_callback(timer_callback_args_t *p_args);
#endif
extern const mqtt_onchip_da16xxx_cfg_t g_mqtt_onchip_da16xxx_cfg_preset;

#ifndef mqtt0_callback
void mqtt0_callback(mqtt_onchip_da16xxx_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* MAIN_THREAD_H_ */

#if 1  **************************************************************
#ifndef MAIN_THREAD_H_
#define MAIN_THREAD_H_
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#ifdef __cplusplus
                extern "C" void main_thread_entry(void * pvParameters);
                #else
extern void main_thread_entry(void *pvParameters);
#endif
#include "r_agt.h"
#include "r_timer_api.h"
#include "rm_mqtt_onchip_da16xxx.h"
FSP_HEADER
/** AGT Timer Instance */
extern const timer_instance_t g_timer0;

/** Access the AGT instance using these structures when calling API functions directly (::p_api is not used). */
extern agt_instance_ctrl_t g_timer0_ctrl;
extern const timer_cfg_t g_timer0_cfg;

#ifndef g_periodic_timer_callback
void g_periodic_timer_callback(timer_callback_args_t *p_args);
#endif
extern const mqtt_onchip_da16xxx_cfg_t g_mqtt_onchip_da16xxx_cfg;

#ifndef mqtt0_callback
void mqtt0_callback(mqtt_onchip_da16xxx_callback_args_t *p_args);
#endif
FSP_FOOTER
#endif /* MAIN_THREAD_H_ */


#endif


#if 1
#ifndef COMMON_DATA_H_
#define COMMON_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "FreeRTOS.h"
#include "event_groups.h"
#include "r_dtc.h"
#include "r_transfer_api.h"
#include "r_sci_uart.h"
#include "r_uart_api.h"
#include "rm_at_transport_da16xxx_uart.h"
#include "rm_at_transport_da16xxx.h"
#include "rm_wifi_da16xxx.h"
#include "r_ioport.h"
#include "bsp_pin_cfg.h"
FSP_HEADER
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer1;

/** Access the DTC instance using these structures when calling API functions directly (::p_api is not used). */
extern dtc_instance_ctrl_t g_transfer1_ctrl;
extern const transfer_cfg_t g_transfer1_cfg;
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer0;

/** Access the DTC instance using these structures when calling API functions directly (::p_api is not used). */
extern dtc_instance_ctrl_t g_transfer0_ctrl;
extern const transfer_cfg_t g_transfer0_cfg;
/** UART on SCI Instance. */
extern const uart_instance_t g_uart9;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t g_uart9_ctrl;
extern const uart_cfg_t g_uart9_cfg;
extern const sci_uart_extended_cfg_t g_uart9_cfg_extend;

#ifndef rm_at_transport_da16xxx_uart_callback
void rm_at_transport_da16xxx_uart_callback(uart_callback_args_t *p_args);
#endif
extern const char *g_at_transport_da16xxx_uart_cmd_baud;
extern at_transport_da16xxx_instance_ctrl_t g_at_transport_da16xxx_ctrl;
extern at_transport_da16xxx_cfg_t g_at_transport_da16xxx_cfg;
extern const at_transport_da16xxx_instance_t g_at_transport_da16xxx;
extern const wifi_da16xxx_cfg_t g_wifi_da16xxx_cfg;
#define IOPORT_CFG_NAME g_bsp_pin_cfg
#define IOPORT_CFG_OPEN R_IOPORT_Open
#define IOPORT_CFG_CTRL g_ioport_ctrl

/* IOPORT Instance */
extern const ioport_instance_t g_ioport;

/* IOPORT control structure. */
extern ioport_instance_ctrl_t g_ioport_ctrl;
extern EventGroupHandle_t g_periodic_event_group;
void g_common_init(void);
FSP_FOOTER
#endif /* COMMON_DATA_H_ */


#endif