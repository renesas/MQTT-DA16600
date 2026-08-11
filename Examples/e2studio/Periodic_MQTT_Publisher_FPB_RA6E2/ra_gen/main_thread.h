/* generated thread header file - do not edit */
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
