/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_sci_uart.h"
            #include "r_uart_api.h"
#include "../ra/fsp/src/rm_comms_lock/rm_comms_lock.h"
#include "rm_comms_uart.h"
#include "rm_comms_api.h"
FSP_HEADER
/** UART on SCI Instance. */
            extern const uart_instance_t      g_uart_jlob_vcom;

            /** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
            extern sci_uart_instance_ctrl_t     g_uart_jlob_vcom_ctrl;
            extern const uart_cfg_t g_uart_jlob_vcom_cfg;
            extern const sci_uart_extended_cfg_t g_uart_jlob_vcom_cfg_extend;

            #ifndef NULL
            void NULL(uart_callback_args_t * p_args);
            #endif
/* UART Communication Device */
extern const rm_comms_instance_t g_comms_jlob_vcom;
extern rm_comms_uart_instance_ctrl_t g_comms_jlob_vcom_ctrl;
extern const rm_comms_cfg_t g_comms_jlob_vcom_cfg;

#ifndef comms_jlob_vcom_callback
void comms_jlob_vcom_callback(rm_comms_callback_args_t * p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
