
#if RS_PERIODIC_MQTT_PUBLISH_PRESET_CONFIG_USE

#include "common_data.h"
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
transfer_info_t g_transfer0_info_preset[1] DTC_TRANSFER_INFO_ALIGNMENT;
#else
/* User must call api::reconfigure before enable DTC transfer. */
#endif

const dtc_extended_cfg_t g_transfer0_cfg_extend_preset =
{ .activation_source = VECTOR_NUMBER_SCI0_TXI, };

const transfer_cfg_t g_transfer0_cfg_preset =
{
#if (1 == 1)
  .p_info = &g_transfer0_info_preset,
#elif (1 > 1)
    .p_info              = g_transfer0_info_preset,
#else
    .p_info = NULL,
#endif
  .p_extend = &g_transfer0_cfg_extend_preset, };

/* Instance structure to use this module. */
const transfer_instance_t g_transfer0_preset =
{ .p_ctrl = &g_transfer0_ctrl_preset, .p_cfg = &g_transfer0_cfg_preset, .p_api = &g_transfer_on_dtc_preset };
sci_uart_instance_ctrl_t g_uart0_ctrl_preset;

baud_setting_t g_uart0_baud_setting_preset =
        {
        /* Baud rate calculated with 0.469% error. */.semr_baudrate_bits_b.abcse = 0,
          .semr_baudrate_bits_b.abcs = 0, .semr_baudrate_bits_b.bgdm = 1, .cks = 0, .brr = 53, .mddr = (uint8_t) 256, .semr_baudrate_bits_b.brme =
                  false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart0_cfg_extend_preset =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_1, .p_baud_setting = &g_uart0_baud_setting_preset, .flow_control =
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
const uart_cfg_t g_uart0_cfg_preset =
{ .channel = 0, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          rm_at_transport_da16xxx_uart_callback,
  .p_context = NULL, .p_extend = &g_uart0_cfg_extend_preset,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == g_transfer0_preset)
                .p_transfer_tx       = NULL,
#else
  .p_transfer_tx = &g_transfer0_preset,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI0_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI0_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI0_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI0_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI0_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart0_preset =
{ .p_ctrl = &g_uart0_ctrl_preset, .p_cfg = &g_uart0_cfg_preset, .p_api = &g_uart_on_sci_preset };
const char *g_at_transport_da16xxx_uart_cmd_baud = "115200";
at_transport_da16xxx_instance_ctrl_t g_at_transport_da16xxx_ctrl_preset;
const at_transport_da16xxx_extended_cfg_t g_at_transport_da16xxx_cfg_extend_preset =
{
#define RA_NOT_DEFINED (1)
  .num_uarts = 1,
  .reset_pin = AT_TRANSPORT_DA16XXX_CFG_RESET_PIN, .uart_instances =
  {

#if (RA_NOT_DEFINED == g_uart0_preset)
            NULL,
        #else
    &g_uart0_preset,
#endif

    NULL,

#undef RA_NOT_DEFINED
          } };

at_transport_da16xxx_cfg_t g_at_transport_da16xxx_cfg_preset =
{ .p_extend = &g_at_transport_da16xxx_cfg_extend_preset, .p_callback = rm_wifi_da16xxx_callback, };

const at_transport_da16xxx_instance_t g_at_transport_da16xxx =
        { .p_ctrl = &g_at_transport_da16xxx_ctrl_preset, .p_cfg = &g_at_transport_da16xxx_cfg_preset, .p_api =
                  &g_at_transport_da16xxx_on_uart_preset, };
/** WiFi DA16XXX configuration */
const wifi_da16xxx_cfg_t g_wifi_da16xxx_cfg_preset =
{ .p_transport_instance = &g_at_transport_da16xxx_preset,
  .num_sockets = WIFI_DA16XXX_CFG_NUM_CREATEABLE_SOCKETS,
  .country_code = (uint8_t*) "US",
  .sntp_server_ip = (uint8_t*) "216.239.35.0",
  .sntp_utc_offset_in_hours = -8, };

EventGroupHandle_t g_periodic_event_group;
#if 1
StaticEventGroup_t g_periodic_event_group_memory;
#endif
void rtos_startup_err_callback(void *p_instance, void *p_data);
TimerHandle_t g_receiveTaskWakeUp;
#if 1
StaticTimer_t g_receiveTaskWakeUp_memory;
#endif
void rtos_startup_err_callback(void *p_instance, void *p_data);

#include "main_thread.h"

gpt_instance_ctrl_t g_timer1_ctrl_preset;
#if 0
const gpt_extended_pwm_cfg_t g_timer1_pwm_extend_preset =
{
    .trough_ipl             = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_COUNTER_UNDERFLOW)
    .trough_irq             = VECTOR_NUMBER_GPT1_COUNTER_UNDERFLOW,
#else
    .trough_irq             = FSP_INVALID_VECTOR,
#endif
    .poeg_link              = GPT_POEG_LINK_POEG0,
    .output_disable         = (gpt_output_disable_t) ( GPT_OUTPUT_DISABLE_NONE),
    .adc_trigger            = (gpt_adc_trigger_t) ( GPT_ADC_TRIGGER_NONE),
    .dead_time_count_up     = 0,
    .dead_time_count_down   = 0,
    .adc_a_compare_match    = 0,
    .adc_b_compare_match    = 0,
    .interrupt_skip_source  = GPT_INTERRUPT_SKIP_SOURCE_NONE,
    .interrupt_skip_count   = GPT_INTERRUPT_SKIP_COUNT_0,
    .interrupt_skip_adc     = GPT_INTERRUPT_SKIP_ADC_NONE,
    .gtioca_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
    .gtiocb_disable_setting = GPT_GTIOC_DISABLE_PROHIBITED,
};
#endif
const gpt_extended_cfg_t g_timer1_extend_preset =
        { .gtioca =
        { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .gtiocb =
          { .output_enabled = false, .stop_level = GPT_PIN_LEVEL_LOW },
          .start_source = (gpt_source_t) (GPT_SOURCE_NONE), .stop_source = (gpt_source_t) (GPT_SOURCE_NONE), .clear_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .count_up_source = (gpt_source_t) (GPT_SOURCE_NONE), .count_down_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_source =
                  (gpt_source_t) (GPT_SOURCE_NONE),
          .capture_b_source = (gpt_source_t) (GPT_SOURCE_NONE), .capture_a_ipl = (BSP_IRQ_DISABLED), .capture_b_ipl =
                  (BSP_IRQ_DISABLED),
          .compare_match_c_ipl = (BSP_IRQ_DISABLED), .compare_match_d_ipl = (BSP_IRQ_DISABLED), .compare_match_e_ipl =
                  (BSP_IRQ_DISABLED),
          .compare_match_f_ipl = (BSP_IRQ_DISABLED),
#if defined(VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_A)
    .capture_a_irq         = VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_A,
#else
          .capture_a_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_B)
    .capture_b_irq         = VECTOR_NUMBER_GPT1_CAPTURE_COMPARE_B,
#else
          .capture_b_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_COMPARE_C)
    .compare_match_c_irq   = VECTOR_NUMBER_GPT1_COMPARE_C,
#else
          .compare_match_c_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_COMPARE_D)
    .compare_match_d_irq   = VECTOR_NUMBER_GPT1_COMPARE_D,
#else
          .compare_match_d_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_COMPARE_E)
    .compare_match_e_irq   = VECTOR_NUMBER_GPT1_COMPARE_E,
#else
          .compare_match_e_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_GPT1_COMPARE_F)
    .compare_match_f_irq   = VECTOR_NUMBER_GPT1_COMPARE_F,
#else
          .compare_match_f_irq = FSP_INVALID_VECTOR,
#endif
          .compare_match_value =
          { (uint32_t) 0x0, /* CMP_A */
            (uint32_t) 0x0, /* CMP_B */
            (uint32_t) 0x0, /* CMP_C */
            (uint32_t) 0x0, /* CMP_D */
            (uint32_t) 0x0, /* CMP_E */
            (uint32_t) 0x0, /* CMP_F */},
          .compare_match_status = ((0U << 5U) | (0U << 4U) | (0U << 3U) | (0U << 2U) | (0U << 1U) | 0U), .capture_filter_gtioca =
                  GPT_CAPTURE_FILTER_NONE,
          .capture_filter_gtiocb = GPT_CAPTURE_FILTER_NONE,
#if 0
    .p_pwm_cfg             = &g_timer1_pwm_extend,
#else
          .p_pwm_cfg = NULL,
#endif
#if 0
    .gtior_setting.gtior_b.gtioa  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.oadflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.oahld  = 0U,
    .gtior_setting.gtior_b.oae    = (uint32_t) false,
    .gtior_setting.gtior_b.oadf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfaen  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsa  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
    .gtior_setting.gtior_b.gtiob  = (0U << 4U) | (0U << 2U) | (0U << 0U),
    .gtior_setting.gtior_b.obdflt = (uint32_t) GPT_PIN_LEVEL_LOW,
    .gtior_setting.gtior_b.obhld  = 0U,
    .gtior_setting.gtior_b.obe    = (uint32_t) false,
    .gtior_setting.gtior_b.obdf   = (uint32_t) GPT_GTIOC_DISABLE_PROHIBITED,
    .gtior_setting.gtior_b.nfben  = ((uint32_t) GPT_CAPTURE_FILTER_NONE & 1U),
    .gtior_setting.gtior_b.nfcsb  = ((uint32_t) GPT_CAPTURE_FILTER_NONE >> 1U),
#else
          .gtior_setting.gtior = 0U,
#endif

          .gtioca_polarity = GPT_GTIOC_POLARITY_NORMAL,
          .gtiocb_polarity = GPT_GTIOC_POLARITY_NORMAL, };

const timer_cfg_t g_timer1_cfg_preset =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 10 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x3b9aca00,
  .duty_cycle_counts = 0x1dcd6500, .source_div = (timer_source_div_t) 0, .channel = 1, .p_callback =
          g_periodic_timer_callback,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = (void*) &NULL,
#endif
  .p_extend = &g_timer1_extend,
  .cycle_end_ipl = (12),
#if defined(VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW)
    .cycle_end_irq       = VECTOR_NUMBER_GPT1_COUNTER_OVERFLOW,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer1_preset =
{ .p_ctrl = &g_timer1_ctrl_preset, .p_cfg = &g_timer1_cfg_preset, .p_api = &g_timer_on_gpt };
#include "mqtt_cert.h"
#define CERT_INCLUDE

/** MQTT Onchip da16xxx configuration */
const mqtt_onchip_da16xxx_cfg_t g_mqtt_onchip_da16xxx_cfg_preset =
{ .use_mqtt_v311 = (1),
  .rx_timeout = (1000),
  .tx_timeout = (1000),
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
  .p_root_ca = ROOT_CA,
  .root_ca_size = (sizeof(ROOT_CA)),
  .p_client_cert = CLIENT_CERT,
  .client_cert_size = (sizeof(CLIENT_CERT)),
  .p_client_private_key = PRIVATE_KEY,
  .private_key_size = (sizeof(PRIVATE_KEY)),
#else
                        .p_root_ca =                NULL,
                        .root_ca_size =             0,
                        .p_client_cert =            NULL,
                        .client_cert_size =         0,
                        .p_client_private_key =     NULL,
                        .private_key_size =         0,
#endif
  .p_will_topic = "will",
  .p_will_msg = "dead",
  .p_sni_name = NULL,
  .will_qos_level = (MQTT_ONCHIP_DA16XXX_QOS_0),
  .p_tls_cipher_suites =
  { (mqtt_onchip_da16xxx_tls_cipher_suites_t) (0x00) },
  .p_transport_instance = &g_at_transport_da16xxx, };
extern uint32_t g_fsp_common_thread_count;

#endif
