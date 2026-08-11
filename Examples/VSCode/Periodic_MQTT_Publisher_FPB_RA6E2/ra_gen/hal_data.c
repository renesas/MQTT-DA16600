/* generated HAL source file - do not edit */
#include "hal_data.h"
sci_uart_instance_ctrl_t     g_uart_jlob_vcom_ctrl;

            baud_setting_t               g_uart_jlob_vcom_baud_setting =
            {
                /* Baud rate calculated with 0.469% error. */ .semr_baudrate_bits_b.abcse = 0, .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 0, .brr = 53, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme = false
            };

            /** UART extended configuration for UARTonSCI HAL driver */
            const sci_uart_extended_cfg_t g_uart_jlob_vcom_cfg_extend =
            {
                .clock                = SCI_UART_CLOCK_INT,
                .rx_edge_start          = SCI_UART_START_BIT_FALLING_EDGE,
                .noise_cancel         = SCI_UART_NOISE_CANCELLATION_DISABLE,
                .rx_fifo_trigger        = SCI_UART_RX_FIFO_TRIGGER_MAX,
                .p_baud_setting         = &g_uart_jlob_vcom_baud_setting,
                .flow_control           = SCI_UART_FLOW_CONTROL_RTS,
                #if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
                .flow_control_pin       = (bsp_io_port_pin_t) UINT16_MAX,
                #endif
                .rs485_setting = {
                    .enable = SCI_UART_RS485_DISABLE,
                    .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
                #if 0xFF != 0xFF
                    .de_control_pin = BSP_IO_PORT_FF_PIN_0xFF,
                #else
                    .de_control_pin       = (bsp_io_port_pin_t) UINT16_MAX,
                #endif
                },
                .irda_setting = {
                    .ircr_bits_b.ire = 0,
                    .ircr_bits_b.irrxinv = 0,
                    .ircr_bits_b.irtxinv = 0,
                },
            };

            /** UART interface configuration */
            const uart_cfg_t g_uart_jlob_vcom_cfg =
            {
                .channel             = 0,
                .data_bits           = UART_DATA_BITS_8,
                .parity              = UART_PARITY_OFF,
                .stop_bits           = UART_STOP_BITS_1,
                .p_callback          = NULL,
                .p_context           = NULL,
                .p_extend            = &g_uart_jlob_vcom_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
                .p_transfer_tx       = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
                .p_transfer_rx       = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
                .rxi_ipl             = (12),
                .txi_ipl             = (12),
                .tei_ipl             = (12),
                .eri_ipl             = (12),
#if defined(VECTOR_NUMBER_SCI0_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI0_RXI,
#else
                .rxi_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI0_TXI,
#else
                .txi_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI0_TEI,
#else
                .tei_irq             = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI0_ERI,
#else
                .eri_irq             = FSP_INVALID_VECTOR,
#endif
            };

/* Instance structure to use this module. */
const uart_instance_t g_uart_jlob_vcom =
{
    .p_ctrl        = &g_uart_jlob_vcom_ctrl,
    .p_cfg         = &g_uart_jlob_vcom_cfg,
    .p_api         = &g_uart_on_sci
};
/* UART Communication Device */

rm_comms_uart_instance_ctrl_t g_comms_jlob_vcom_ctrl;

#if BSP_CFG_RTOS == 1 // ThreadX

 #if !defined(g_comms_jlob_vcom_tx_mutex)
 rm_comms_mutex_t g_comms_jlob_vcom_tx_mutex =
 {
     .p_name = "g_comms_jlob_vcom tx mutex",
 };
 #endif

 #if !defined(g_comms_jlob_vcom_rx_mutex)
 rm_comms_mutex_t g_comms_jlob_vcom_rx_mutex =
 {
     .p_name = "g_comms_jlob_vcom rx mutex",
 };
 #endif

 #if !defined(g_comms_jlob_vcom_tx_semaphore)
 rm_comms_semaphore_t g_comms_jlob_vcom_tx_semaphore =
 {
     .p_name = "g_comms_jlob_vcom tx semaphore",
 };
 #endif

  #if !defined(g_comms_jlob_vcom_rx_semaphore)
 rm_comms_semaphore_t g_comms_jlob_vcom_rx_semaphore =
 {
     .p_name = "g_comms_jlob_vcom rx semaphore",
 };
 #endif

#elif BSP_CFG_RTOS == 2 // FreeRTOS

#if !defined(g_comms_jlob_vcom_tx_mutex)
rm_comms_mutex_t g_comms_jlob_vcom_tx_mutex;
#endif

#if !defined(g_comms_jlob_vcom_rx_mutex)
rm_comms_mutex_t g_comms_jlob_vcom_rx_mutex;
#endif
#if !defined(g_comms_jlob_vcom_tx_semaphore)
rm_comms_semaphore_t g_comms_jlob_vcom_tx_semaphore;
#endif

#if !defined(g_comms_jlob_vcom_rx_semaphore)
rm_comms_semaphore_t g_comms_jlob_vcom_rx_semaphore;
#endif

#else

#endif

rm_comms_uart_extended_cfg_t g_comms_jlob_vcom_extended_cfg =
{
#if BSP_CFG_RTOS

#if !defined(g_comms_jlob_vcom_tx_mutex)
    .p_tx_mutex = &g_comms_jlob_vcom_tx_mutex,
#else
    .p_tx_mutex = NULL,
#endif

#if !defined(g_comms_jlob_vcom_rx_mutex)
    .p_rx_mutex = &g_comms_jlob_vcom_rx_mutex,
#else
    .p_rx_mutex = NULL,
#endif

#if !defined(g_comms_jlob_vcom_tx_semaphore)
    .p_tx_semaphore = &g_comms_jlob_vcom_tx_semaphore,
#else
    .p_tx_semaphore = NULL,
#endif

#if !defined(g_comms_jlob_vcom_rx_semaphore)
    .p_rx_semaphore = &g_comms_jlob_vcom_rx_semaphore,
#else
    .p_rx_semaphore = NULL,
#endif
    .mutex_timeout  = 0xFFFFFFFF,
#endif
    .p_uart = &g_uart_jlob_vcom,
};

const rm_comms_cfg_t g_comms_jlob_vcom_cfg =
{
    .semaphore_timeout  = 0xFFFFFFFF,
    .p_lower_level_cfg  = NULL,
    .p_extend           = (void*)&g_comms_jlob_vcom_extended_cfg,
    .p_callback         = comms_jlob_vcom_callback,
};

const rm_comms_instance_t g_comms_jlob_vcom =
{
    .p_ctrl = &g_comms_jlob_vcom_ctrl,
    .p_cfg  = &g_comms_jlob_vcom_cfg,
    .p_api  = &g_comms_on_comms_uart,
};
void g_hal_init(void) {
g_common_init();
}
