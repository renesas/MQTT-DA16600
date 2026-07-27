#include "main_thread.h"
#include "common_data.h"
#include "FreeRTOS.h"
#include "rs_periodic_mqtt_publisher/demo/user.h"
#include "rs_periodic_mqtt_publisher/rs_periodic_mqtt_publisher.h"

#define CONNECT_TIMEOUT                     (1000)
#define WIDTH_64                            (64)
#define PERIODIC_TIMER_EVENT                (1 << 0)
#define MQTT_ONCHIP_DA16XXX_TIMEOUT_400MS   (400)
#define MQTT_ONCHIP_DA16XXX_RETURN_TEXT_OK   "OK"


void periodicPublishWithDA16600Entry();
fsp_err_t da16xxx_optional_init (rs_mqtt_client_ctrl_t *p_ctrl );
float generate_random_float(float min, float max);

float publish_data = { 0 };
char pub_buf[WIDTH_64] = { 0 };
static int counter = 0;

EventGroupHandle_t eventGroup;
EventBits_t bits;

rs_mqtt_client_ctrl_t u_mqtt_client_instance;
rs_mqtt_client_cfg_t  u_mqtt_client_cfg;
mqtt_onchip_da16xxx_instance_ctrl_t g_rm_mqtt_onchip_da16xxx_instance;

/* Setup Access Point connection parameters */
WIFINetworkParams_t g_net_params =
{
    .ucChannel                  = 0,
    .xPassword.xWPA.cPassphrase = WIFI_PWD,
    .ucSSID                     = WIFI_SSID,
    .xPassword.xWPA.ucLength    = sizeof(WIFI_PWD),
    .ucSSIDLength               = sizeof(WIFI_SSID),
    .xSecurity                  = eWiFiSecurityWPA2,
};

/* Setup Publish Topic parameters */
mqtt_onchip_da16xxx_pub_info_t pubTopics[1] =
{
    {
        .qos                 = MQTT_ONCHIP_DA16XXX_QOS_0,
        .p_topic_name        = CLIENT_PUB_TOPIC_1,
        .topic_name_Length   = sizeof(CLIENT_PUB_TOPIC_1)
    }
};

/*****************************************************************************************************************
 ** @brief       Performs optional DA16600 MQTT client initialization. For the Demo to work the TLS needs to be
 **              disabled. By default the DA16600 modules are TLS enabled. This Function prepares and sends
 **              optional MQTT configuration commands to the  DA16600 module before the MQTT connection is
 **              established. The function configures AT command transport parameters and updates MQTT security
 **              settings based on the configured authentication parameters.
 **              If no MQTT username and password are configured, TLS is disabled by sending the
 **              corresponding AT command (AT+NWMQTLS=0) to the DA16600 module.
 ** @param[in]   p_ctrl Pointer to the MQTT client control structure containing MQTT configuration,
 **              transport interface, and DA16600 control information.
 **
 ** @retval      FSP_SUCCESS          Optional initialization completed successfully.
 **
 ** @retval      FSP_ERR_WIFI_FAILED  Failed to send the configuration command to the DA16600 module.
 **
 ** @note        This function should be called before starting the MQTT connection.
 **
 ******************************************************************************************************************/
fsp_err_t da16xxx_optional_init(rs_mqtt_client_ctrl_t  *p_ctrl)
{

    mqtt_onchip_da16xxx_instance_ctrl_t *p_mqtt_da16xxx_ctrl = &p_ctrl->rs_mqtt_onchip_da16xxx_ctrl;
    mqtt_onchip_da16xxx_cfg_t  *p_mqtt_cfg = &p_ctrl->rs_mqtt_onchip_da16xxx_cfg;

    at_transport_da16xxx_instance_t const * p_transport_instance =   p_mqtt_cfg->p_transport_instance;
    at_transport_da16xxx_data_t atcmd;

    atcmd.p_at_cmd_string      = (uint8_t *) p_mqtt_da16xxx_ctrl->cmd_tx_buff;
    atcmd.at_cmd_string_length = 0;
    atcmd.p_response_buffer    = p_mqtt_da16xxx_ctrl->cmd_rx_buff;
    atcmd.response_buffer_size = sizeof(p_mqtt_da16xxx_ctrl->cmd_rx_buff);
    atcmd.timeout_ms           = MQTT_ONCHIP_DA16XXX_TIMEOUT_400MS;
    atcmd.p_expect_code        = MQTT_ONCHIP_DA16XXX_RETURN_TEXT_OK;
    atcmd.comm_ch_id           = 0;

    /* Set MQTT ALPN settings */
    if ((NULL == p_mqtt_cfg->p_mqtt_user_name) && (NULL == p_mqtt_cfg->p_mqtt_password))
     {
         /* Disable TLS with AT+NWMQTLS */
         snprintf((char *) &p_mqtt_da16xxx_ctrl->cmd_tx_buff, sizeof(p_mqtt_da16xxx_ctrl->cmd_tx_buff), "AT+NWMQTLS=0\r");
         FSP_ERROR_RETURN(FSP_SUCCESS ==
                          p_transport_instance->p_api->atCommandSendThreadSafe(p_transport_instance->p_ctrl, &atcmd),
                          FSP_ERR_WIFI_FAILED);
     }

    return FSP_SUCCESS;
}

/*****************************************************************************************************************
 ** @brief       Single Point application entry function for periodic MQTT publishing using the DA16600 Wi-Fi
 **              module. This function initializes the MQTT client configuration, establishes a Wi-Fi connection,
 **              obtains an IP address, starts the MQTT connection, and periodically publishes simulated
 **              temperature sensor data to the configured MQTT topic.
 **              The periodic publish operation is driven by a timer event. Upon receiving the PERIODIC_TIMER_EVENT
 **              notification, a random temperature value is generated, formatted as a string, and published to the
 **              MQTT broker.
 **
 ** @retval      NONE
 ******************************************************************************************************************/
void periodicPublishWithDA16600Entry()
{
    fsp_err_t err = FSP_SUCCESS;
    WIFIIPConfiguration_t ipconfig = {RESET_VALUE};
    uint32_t nwk_init_status = RS_NWK_NOT_INITIALIZED;
    size_t cfg_size = RESET_VALUE;

    /* Return configuration size */
    rs_mqtt_client_GetConfigSize(&u_mqtt_client_instance,  &cfg_size);

    /* Copy configurations into SRAM */
    rs_mqtt_client_ConfigGenerate (&u_mqtt_client_instance, (mqtt_onchip_da16xxx_cfg_t *)&g_mqtt_onchip_da16xxx_cfg,
                                  (wifi_da16xxx_cfg_t*) &g_wifi_da16xxx_cfg, (timer_instance_t *)&g_timer0,
                                  (transfer_instance_t *)&g_transfer0, (uart_instance_t *)&g_uart9,
                                  (at_transport_da16xxx_instance_t *)&g_at_transport_da16xxx);

    /* Check the configurations  */
    err = rs_mqtt_client_ConfigCheck(&u_mqtt_client_instance);

    u_mqtt_client_cfg.net_params = g_net_params;
    u_mqtt_client_cfg.connect_timeout = CONNECT_TIMEOUT;
    u_mqtt_client_instance.rs_mqtt_onchip_da16xxx_ctrl = g_rm_mqtt_onchip_da16xxx_instance;

    /* Turn ON the WiFi and make a connection to the access Point and Obtain the IP address for the Client */
    err = rs_mqtt_client_NetworkInit(&u_mqtt_client_instance, &u_mqtt_client_cfg);
    if (FSP_SUCCESS != err)
    {
        printf("\r\n Wi-Fi initialization failed! \r\n");
        nwk_init_status = (uint32_t)u_mqtt_client_cfg.nwk_init_phase;

        if(RS_NWK_WIFI_NOT_INITIALIZED == nwk_init_status)
        {

        }
        if(RS_NWK_WIFI_TURNED_ON == nwk_init_status)
        {

        }
        if(RS_NWK_WIFI_CONNECTED == nwk_init_status)
        {

        }
        __asm("BKPT #0\n");
    }
    else
    {

        ipconfig = (WIFIIPConfiguration_t)u_mqtt_client_cfg.ipconfig;
        nwk_init_status = (uint32_t)u_mqtt_client_cfg.nwk_init_phase;

        printf("\r\n Wi-Fi connection successful! \r\n");
        if(RS_NWK_IP_INITIALIZED == nwk_init_status){
            printf("\r\nIP Addr: %d.%d.%d.%d\r\n",
                 ((uint8_t *)ipconfig.xIPAddress.ulAddress)[0],
                 ((uint8_t *)ipconfig.xIPAddress.ulAddress)[1],
                 ((uint8_t *)ipconfig.xIPAddress.ulAddress)[2],
                 ((uint8_t *)ipconfig.xIPAddress.ulAddress)[3]);
            }
    }

    printf("\r\nStarting the MQTT Connection...\r\n");

    da16xxx_optional_init(&u_mqtt_client_instance);

    err = rs_mqtt_client_PeriodicConnectionStart(&u_mqtt_client_instance, &u_mqtt_client_cfg);
    if (FSP_SUCCESS != err)
    {
        printf("\r\nMQTT initialization failed!\r\n");
        __asm("BKPT #0\n");
    }
    printf("\r\nMQTT initialization Successful and connection started!\r\n");


    while (1)
    {
        bits = xEventGroupWaitBits(g_periodic_event_group, PERIODIC_TIMER_EVENT,  pdTRUE, pdFALSE, pdMS_TO_TICKS(100000));

        if (bits & PERIODIC_TIMER_EVENT)
        {
            printf("\r\nPeriodic Counter iteration =%d \r\n",counter);
            /* Assign payload pointer to sensor data buffer */
            // Generate random temperature between 20.00 and 30.00 degrees
            publish_data = generate_random_float(20.00f, 30.00f);

            /* Assign payload pointer to sensor data buffer */
            pubTopics[0].p_payload = pub_buf;

            /* Copy sensor data into buffer while converting to string */
            snprintf(pub_buf, WIDTH_64, "%.2f", publish_data);
            pubTopics[0].payload_length = strlen(pubTopics[0].p_payload);

            err = rs_mqtt_client_DataSend(&u_mqtt_client_instance, &pubTopics[0]);
            printf("Published Temperature Data  =%f \r\n",publish_data);
            /* Handle event */
            xEventGroupClearBits(g_periodic_event_group, PERIODIC_TIMER_EVENT);

        }
    }
}

/*****************************************************************************************************************
 ** @brief       MQTT callback invoked when a subscribed message is received.
 **              This callback is executed by the MQTT driver whenever data is received on a subscribed topic.
 **              User application can parse the topic and payload information from the callback arguments
 **              and perform the required processing.
 ** @param[in]   p_args Pointer to MQTT callback arguments containing topic, Payload, and context information.
 ** @retval      NONE
 ******************************************************************************************************************/
void mqtt0_callback(mqtt_onchip_da16xxx_callback_args_t * p_args)
{
    if (NULL != p_args)
    {
        /* In this Demo there is no Topic subscribed, hence no processing logic here */
        ;
    }
}

/*****************************************************************************************************************
 ** @brief       Periodic timer callback function.
 **              Triggered whenever the configured periodic timer completes a timer cycle. The callback
 **              increments the timer event counter and notifies waiting tasks by setting the
 **              PERIODIC_TIMER_EVENT bit in the event group.
 **              @param[in]   p_args Pointer to timer callback arguments containing timer event information.
 **              @retval      NONE
 ****************************************************************************************************************/
void g_periodic_timer_callback(timer_callback_args_t * p_args)
{
    if (NULL != p_args)
    {
        if (TIMER_EVENT_CYCLE_END == p_args->event)
        {
            /* Set event flag on Periodic timer interrupt  */
            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            counter++;

            xEventGroupSetBitsFromISR(
                  g_periodic_event_group,
                  PERIODIC_TIMER_EVENT,
                  &xHigherPriorityTaskWoken
            );

            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    }
}

/*****************************************************************************************************************
 ** @brief       Generates a random floating-point value within the specified range.
 **              The generated value is uniformly distributed between the minimum and maximum
 **              bounds, inclusive of the lower bound and approaching the upper bound.
 **              @param[in]   min Minimum value of the generated range.
 **              @param[in]   max Maximum value of the generated range.
 **              @retval      Random floating-point value between min and max
 ****************************************************************************************************************/
float generate_random_float(float min, float max)
{
    return min + ((float)rand() / (float)RAND_MAX) * (max - min);
}
