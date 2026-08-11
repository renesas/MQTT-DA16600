#if RS_PERIODIC_MQTT_PUBLISH_PRESET_CONFIG_USE
#ifndef RS_CONFIG_FPB_RA6E2_H_
#define RS_CONFIG_FPB_RA6E2_H_
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
#include "task.h"
#include "semphr.h"
#include "hal_data.h"
#include "r_agt.h"
#include "r_timer_api.h"
#include "rm_mqtt_onchip_da16xxx.h"

FSP_HEADER
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer1_preset;

/** Access the DTC instance using these structures when calling API functions directly (::p_api is not used). */
extern dtc_instance_ctrl_t g_transfer1_ctrl_preset;
extern const transfer_cfg_t g_transfer1_cfg_preset;
/* Transfer on DTC Instance. */
extern const transfer_instance_t g_transfer0_preset;

/** Access the DTC instance using these structures when calling API functions directly (::p_api is not used). */
extern dtc_instance_ctrl_t g_transfer0_ctrl_preset;
extern const transfer_cfg_t g_transfer0_cfg_preset;
/** UART on SCI Instance. */
extern const uart_instance_t g_uart9_preset;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t g_uart9_ctrl_preset;
extern const uart_cfg_t g_uart9_cfg_preset;
extern const sci_uart_extended_cfg_t g_uart9_cfg_extend_preset;

#ifndef rm_at_transport_da16xxx_uart_callback
void rm_at_transport_da16xxx_uart_callback(uart_callback_args_t *p_args);
#endif
extern const char *g_at_transport_da16xxx_uart_cmd_baud;
extern at_transport_da16xxx_instance_ctrl_t g_at_transport_da16xxx_ctrl_preset;
extern at_transport_da16xxx_cfg_t g_at_transport_da16xxx_cfg_preset;
extern const at_transport_da16xxx_instance_t g_at_transport_da16xxx_preset;
extern const wifi_da16xxx_cfg_t g_wifi_da16xxx_cfg_preset;

/** AGT Timer Instance */
extern const timer_instance_t g_timer0_preset;

/** Access the AGT instance using these structures when calling API functions directly (::p_api is not used). */
extern agt_instance_ctrl_t g_timer0_ctrl_preset;
extern const timer_cfg_t g_timer0_cfg_preset;

#ifndef g_periodic_timer_callback
void g_periodic_timer_callback(timer_callback_args_t *p_args);
#endif
extern const mqtt_onchip_da16xxx_cfg_t g_mqtt_onchip_da16xxx_cfg_preset;

#ifndef mqtt0_callback
void mqtt0_callback(mqtt_onchip_da16xxx_callback_args_t *p_args);
#endif


FSP_FOOTER

#endif
#endif
