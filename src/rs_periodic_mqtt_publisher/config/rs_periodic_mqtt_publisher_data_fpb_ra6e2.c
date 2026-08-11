#if RS_PERIODIC_MQTT_PUBLISH_PRESET_CONFIG_USE
#include "common_data.h"
#include "hal_data.h"
#include "main_thread.h"
#include "r_dtc.h"
#include "rm_at_transport_da16xxx_uart.h"
#include "rm_wifi_da16xxx_cfg.h"
#include "r_agt.h"
#include "rm_mqtt_onchip_da16xxx.h"
#include "rs_periodic_mqtt_publisher_data_fpb_ra6e2.h"
#include "vector_data.h"

dtc_instance_ctrl_t g_transfer1_ctrl_preset;

#if (1 == 1)
transfer_info_t g_transfer1_info_preset DTC_TRANSFER_INFO_ALIGNMENT =
{ .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.repeat_area = TRANSFER_REPEAT_AREA_DESTINATION,
  .transfer_settings_word_b.irq = TRANSFER_IRQ_END,
  .transfer_settings_word_b.chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .transfer_settings_word_b.size = TRANSFER_SIZE_1_BYTE,
  .transfer_settings_word_b.mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = (uint16_t) 0,
  .length = (uint16_t) 0, };
#elif (1 > 1)
    /* User is responsible to initialize the array. */
    transfer_info_t g_transfer1_info[1] DTC_TRANSFER_INFO_ALIGNMENT;
    #else
    /* User must call api::reconfigure before enable DTC transfer. */
#endif

const dtc_extended_cfg_t g_transfer1_cfg_extend_preset =
{ .activation_source = VECTOR_NUMBER_SCI9_RXI,

#if BSP_CFG_DCACHE_ENABLED
    #if (1 == 1)
        .p_user_config_info =  &g_transfer1_user_config_info,
    #else
        .p_user_config_info = NULL,
    #endif
#else
        /* p_user_config_info not present. */
#endif
};

const transfer_cfg_t g_transfer1_cfg_preset =
{
#if BSP_CFG_DCACHE_ENABLED
    #if (1 > 0)
        .p_info              = g_transfer1_info_fsp_nocache,
    #else
        .p_info = NULL,
    #endif
#else
#if (1 == 1)
  .p_info = &g_transfer1_info_preset,
#elif (1 > 1)
        .p_info              = g_transfer1_info,
    #else
        .p_info = NULL,
    #endif
#endif
  .p_extend = &g_transfer1_cfg_extend_preset,
};

/* Instance structure to use this module. */
const transfer_instance_t g_transfer1_preset =
{ .p_ctrl = &g_transfer1_ctrl_preset, .p_cfg = &g_transfer1_cfg_preset, .p_api = &g_transfer_on_dtc };


dtc_instance_ctrl_t g_transfer0_ctrl_preset;

#if (1 == 1)
transfer_info_t g_transfer0_info_preset DTC_TRANSFER_INFO_ALIGNMENT =
{ .transfer_settings_word_b.dest_addr_mode = TRANSFER_ADDR_MODE_FIXED,
  .transfer_settings_word_b.repeat_area = TRANSFER_REPEAT_AREA_SOURCE,
  .transfer_settings_word_b.irq = TRANSFER_IRQ_END,
  .transfer_settings_word_b.chain_mode = TRANSFER_CHAIN_MODE_DISABLED,
  .transfer_settings_word_b.src_addr_mode = TRANSFER_ADDR_MODE_INCREMENTED,
  .transfer_settings_word_b.size = TRANSFER_SIZE_1_BYTE,
  .transfer_settings_word_b.mode = TRANSFER_MODE_NORMAL,
  .p_dest = (void*) NULL,
  .p_src = (void const*) NULL,
  .num_blocks = (uint16_t) 0,
  .length = (uint16_t) 0, };
#elif (1 > 1)
    /* User is responsible to initialize the array. */
    transfer_info_t g_transfer0_info[1] DTC_TRANSFER_INFO_ALIGNMENT;
    #else
    /* User must call api::reconfigure before enable DTC transfer. */
#endif

const dtc_extended_cfg_t g_transfer0_cfg_extend_preset =
{ .activation_source = VECTOR_NUMBER_SCI9_TXI,

#if BSP_CFG_DCACHE_ENABLED
    #if (1 == 1)
        .p_user_config_info =  &g_transfer0_user_config_info,
    #else
        .p_user_config_info = NULL,
    #endif
#else
        /* p_user_config_info not present. */
#endif
};

const transfer_cfg_t g_transfer0_cfg_preset =
{
#if BSP_CFG_DCACHE_ENABLED
    #if (1 > 0)
        .p_info              = g_transfer0_info_fsp_nocache,
    #else
        .p_info = NULL,
    #endif
#else
#if (1 == 1)
  .p_info = &g_transfer0_info_preset,
#elif (1 > 1)
        .p_info              = g_transfer0_info,
    #else
        .p_info = NULL,
    #endif
#endif
  .p_extend = &g_transfer0_cfg_extend_preset,
};

/* Instance structure to use this module. */
const transfer_instance_t g_transfer0_preset =
{ .p_ctrl = &g_transfer0_ctrl_preset, .p_cfg = &g_transfer0_cfg_preset, .p_api = &g_transfer_on_dtc };

sci_uart_instance_ctrl_t g_uart9_ctrl_preset;

baud_setting_t g_uart9_baud_setting_preset =
        {
        /* Baud rate calculated with 0.469% error. */.semr_baudrate_bits_b.abcse = 0,
          .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 0, .brr = 53, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
                  false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart9_cfg_extend_preset =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &g_uart9_baud_setting_preset, .flow_control =
          SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
  .rs485_setting =
  { .enable = SCI_UART_RS485_DISABLE, .polarity = SCI_UART_RS485_DE_POLARITY_HIGH,
#if 0xFF != 0xFF
                    .de_control_pin = BSP_IO_PORT_FF_PIN_0xFF,
                #else
    .de_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
          },
  .irda_setting =
  { .ircr_bits_b.ire = 0, .ircr_bits_b.irrxinv = 0, .ircr_bits_b.irtxinv = 0, }, };

/** UART interface configuration */
const uart_cfg_t g_uart9_cfg_preset =
{ .channel = 9, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          rm_at_transport_da16xxx_uart_callback,
  .p_context = NULL, .p_extend = &g_uart9_cfg_extend_preset,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == g_transfer0)
                .p_transfer_tx       = NULL,
#else
  .p_transfer_tx = &g_transfer0_preset,
#endif
#if (RA_NOT_DEFINED == g_transfer1)
                .p_transfer_rx       = NULL,
#else
  .p_transfer_rx = &g_transfer1_preset,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI9_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI9_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI9_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI9_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI9_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI9_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart9_preset =
{ .p_ctrl = &g_uart9_ctrl_preset, .p_cfg = &g_uart9_cfg_preset, .p_api = &g_uart_on_sci };

#ifndef RS_PERIODIC_MQTT_PUBLISH_PRESET_CONFIG_USE
const char *g_at_transport_da16xxx_uart_cmd_baud = "115200";
#endif

at_transport_da16xxx_instance_ctrl_t g_at_transport_da16xxx_ctrl_preset;
const at_transport_da16xxx_extended_cfg_t g_at_transport_da16xxx_cfg_extend_preset =
{
#define RA_NOT_DEFINED (1)
  .num_uarts = 1,
  .reset_pin = AT_TRANSPORT_DA16XXX_CFG_RESET_PIN, .uart_instances =
  {

#if (RA_NOT_DEFINED == g_uart9)
            NULL,
        #else
    &g_uart9_preset,
#endif

    NULL,

#undef RA_NOT_DEFINED
          }
};

at_transport_da16xxx_cfg_t g_at_transport_da16xxx_cfg_preset =
{ .p_extend = &g_at_transport_da16xxx_cfg_extend_preset, .p_callback = rm_wifi_da16xxx_callback, };

const at_transport_da16xxx_instance_t g_at_transport_da16xxx_preset =
        { .p_ctrl = &g_at_transport_da16xxx_ctrl_preset, .p_cfg = &g_at_transport_da16xxx_cfg_preset, .p_api =
                  &g_at_transport_da16xxx_on_uart, };
/** WiFi DA16XXX configuration */
const wifi_da16xxx_cfg_t g_wifi_da16xxx_cfg_preset =
{ .p_transport_instance = &g_at_transport_da16xxx_preset,
  .num_sockets = WIFI_DA16XXX_CFG_NUM_CREATEABLE_SOCKETS,
  .country_code = (uint8_t*) "US",
  .sntp_server_ip = (uint8_t*) "216.239.35.0",
  .sntp_utc_offset_in_hours = 0,
};


agt_instance_ctrl_t g_timer0_ctrl_preset;
const agt_extended_cfg_t g_timer0_extend_preset =
{ .count_source = AGT_CLOCK_PCLKB,
  .agto = AGT_PIN_CFG_DISABLED,
  .agtoab_settings_b.agtoa = AGT_PIN_CFG_DISABLED,
  .agtoab_settings_b.agtob = AGT_PIN_CFG_DISABLED,
  .measurement_mode = AGT_MEASURE_DISABLED,
  .agtio_filter = AGT_AGTIO_FILTER_NONE,
  .enable_pin = AGT_ENABLE_PIN_NOT_USED,
  .trigger_edge = AGT_TRIGGER_EDGE_RISING,
  .counter_bit_width = AGT_COUNTER_BIT_WIDTH_32,
};

const timer_cfg_t g_timer0_cfg_preset =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 10 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x1dcd6500,
  .duty_cycle_counts = 0xee6b280, .source_div = (timer_source_div_t) 0, .channel = 0, .p_callback =
          g_periodic_timer_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = (void*) &NULL,
#endif
  .p_extend = &g_timer0_extend_preset,
  .cycle_end_ipl = (12),
#if defined(VECTOR_NUMBER_AGT0_INT)
    .cycle_end_irq       = VECTOR_NUMBER_AGT0_INT,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
};

/* Instance structure to use this module. */
const timer_instance_t g_timer0_preset =
{ .p_ctrl = &g_timer0_ctrl_preset, .p_cfg = &g_timer0_cfg_preset, .p_api = &g_timer_on_agt };

/** MQTT Onchip da16xxx configuration */
const mqtt_onchip_da16xxx_cfg_t g_mqtt_onchip_da16xxx_cfg_preset =
{ .use_mqtt_v311 = (1),
  .rx_timeout = (10),
  .tx_timeout = (10),
  .p_callback = mqtt0_callback,
  .clean_session = (1),
  .alpn_count = (0),
  .p_alpns =
  { NULL, NULL, NULL },
  .tls_cipher_count = (0),
  .keep_alive_seconds = (60),
  .p_client_identifier = NULL,
  .client_identifier_length = (0),
  .p_host_name = "broker.hivemq.com",
  .mqtt_port = (1883),
  .p_mqtt_user_name = NULL,
  .user_name_length = (0),
  .p_mqtt_password = NULL,
  .password_length = (0),
#ifdef CERT_INCLUDE
                        .p_root_ca =                ROOT_CA,
                        .root_ca_size =             (sizeof(ROOT_CA)),
                        .p_client_cert =            CLIENT_CERT,
                        .client_cert_size =         (sizeof(CLIENT_CERT)),
                        .p_client_private_key =     PRIVATE_KEY,
                        .private_key_size =         (sizeof(PRIVATE_KEY)),
#else
  .p_root_ca = NULL,
  .root_ca_size = 0,
  .p_client_cert = NULL,
  .client_cert_size = 0,
  .p_client_private_key = NULL,
  .private_key_size = 0,
#endif
  .p_will_topic = NULL,
  .p_will_msg = NULL,
  .p_sni_name = NULL,
  .will_qos_level = (MQTT_ONCHIP_DA16XXX_QOS_0),
  .p_tls_cipher_suites =
  { (mqtt_onchip_da16xxx_tls_cipher_suites_t) (0x00) },
  .p_transport_instance = &g_at_transport_da16xxx_preset,
};
#endif
