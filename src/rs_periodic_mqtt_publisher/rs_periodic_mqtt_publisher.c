/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "rs_periodic_mqtt_publisher.h"
#include "rm_wifi_api.h"

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*********************************************************************************************************************
 *  @brief       Initializes the Wi-Fi network and acquires an IP address for the MQTT client.
 *               This function performs the network initialization sequence required before establishing
 *               an MQTT connection. The following operations are executed:
 *               - Validates input control and configuration pointers.
 *               - Powers on the Wi-Fi module.
 *               - Connects the module to the configured Access Point (AP).
 *               - Retrieves the network IP configuration from the Wi-Fi stack.
 *               - Updates the network initialization status and phase information.
 *               The network initialization progress is tracked through the nwk_init_phase member
 *               of the configuration structure, allowing the application to determine the stage
 *               at which a failure occurred.
 *  @param[in]   p_ctrl Pointer to the MQTT client control structure.
 *  @param[in]   p_cfg  Pointer to the MQTT client configuration structure containing
 *               network parameters and IP configuration information.
 *  @retval      FSP_SUCCESS                 Network initialized successfully and IP address acquired.
 *  @retval      FSP_ERR_INVALID_POINTER     One or more input pointers are NULL.
 *  @retval      FSP_ERR_WIFI_INIT_FAILED    WiFi Init Failed.
 *  @retval      eWiFiFailure                General Wi-Fi operation failure.
 *  @retval      eWiFiTimeout                Wi-Fi operation timed out.
 *  @retval      eWiFiNotConnected           Failed to connect to the configured Access Point.
 *  @note        On successful completion, the network initialization phase is updated to
 *               RS_NWK_IP_INITIALIZED and the network status is set to RS_NWK_INITIALIZED.
 *  @return      See @ref RENESAS_ERROR_CODES or the Wi-Fi driver API return codes for
 *               additional error information.
 ***********************************************************************************************************************/
fsp_err_t rs_mqtt_client_NetworkInit (rs_mqtt_client_ctrl_t * const p_ctrl, rs_mqtt_client_cfg_t *p_cfg)
{
    fsp_err_t err = FSP_SUCCESS;
    WIFIReturnCode_t wifi_err;


    FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_INVALID_POINTER);
    FSP_ERROR_RETURN(NULL != p_cfg, FSP_ERR_INVALID_POINTER);

    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;
    rs_mqtt_client_cfg_t * p_client_cfg = (rs_mqtt_client_cfg_t *) p_cfg;

    WIFINetworkParams_t  *p_net_params = &p_client_cfg->net_params;
    WIFIIPConfiguration_t  *p_ipconfig = &p_client_cfg->ipconfig;
    p_client_ctrl->nwk_status = RS_NWK_NOT_INITIALIZED;
    p_cfg->nwk_init_phase = RS_NWK_WIFI_NOT_INITIALIZED;

    /* Open connection to the Wifi Module */
    err = rm_wifi_da16xxx_open(&p_client_ctrl->rs_wifi_da16xxx_cfg);
    if (err != FSP_SUCCESS)
    {
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);
    }
    p_cfg->nwk_init_phase = RS_NWK_WIFI_TURNED_ON;

    /* Connect to the Access Point */
    wifi_err = WIFI_ConnectAP(p_net_params);
    if (eWiFiSuccess != wifi_err)
    {
        FSP_ERROR_RETURN(eWiFiSuccess == wifi_err, (fsp_err_t)wifi_err);
    }
    p_cfg->nwk_init_phase = RS_NWK_WIFI_CONNECTED;

    if (WIFI_GetIPInfo(p_ipconfig) != eWiFiSuccess)
    {
        FSP_ERROR_RETURN(eWiFiSuccess == wifi_err, (fsp_err_t)wifi_err);
    }
    p_cfg->nwk_init_phase = RS_NWK_IP_INITIALIZED;
    p_client_ctrl->nwk_status = RS_NWK_INITIALIZED;
    return err;
}

/*******************************************************************************************************************//**
 * @brief       Opens and starts the MQTT client connection for periodic publish applications.
 *              This function initializes all resources required for periodic MQTT communication.
 *              The following operations are performed:
 *              - Validates input control and configuration pointers.
 *              - Opens the periodic timer instance used to trigger MQTT publish events.
 *              - Opens the DA16XXX MQTT middleware instance.
 *              - Establishes a connection to the configured MQTT broker.
 *              - Starts the periodic timer once the MQTT connection is established.
 *              - Updates MQTT initialization and runtime status information.
 *              The MQTT initialization progress is tracked through the mqtt_init_phase member
 *              of the configuration structure, allowing the application to determine the stage
 *              at which a failure occurred.
 * @param[in]   p_ctrl Pointer to the MQTT client control structure.
 * @param[in]   p_cfg  Pointer to the MQTT client configuration structure containing
 *              MQTT connection parameters and runtime status information.
 * @retval      FSP_SUCCESS                 MQTT client successfully opened, connected and periodic timer started.
 * @retval      FSP_ERR_INVALID_POINTER     One or more input pointers are NULL.
 * @retval      FSP_ERR_ALREADY_OPEN        MQTT or timer instance is already open.
 * @retval      FSP_ERR_ASSERTION           One or more configuration parameters are invalid.
 * @note        Upon successful completion:- MQTT connection phase is updated to RS_MQTT_CLIENT_STARTED.
 *                                         - MQTT status is updated to RS_MQTT_CLIENT_CONNECTION_ACTIVE.
 *                                         - Periodic timer is started and ready to generate publish events.
 * @return      See @ref RENESAS_ERROR_CODES or the return codes from the Timer and MQTT DA16XXX middleware APIs for
 *              additional error information.
 * **********************************************************************************************************************/
fsp_err_t rs_mqtt_client_PeriodicConnectionStart(rs_mqtt_client_ctrl_t *const p_ctrl, rs_mqtt_client_cfg_t *p_cfg)
    {
        fsp_err_t err = FSP_SUCCESS;

        FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_INVALID_POINTER);
        FSP_ERROR_RETURN(NULL != p_cfg, FSP_ERR_INVALID_POINTER);

        rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;
        rs_mqtt_client_cfg_t * p_client_cfg = (rs_mqtt_client_cfg_t *) p_cfg;

        mqtt_onchip_da16xxx_instance_ctrl_t * p_mqtt_da16xxx_ctrl = &p_client_ctrl->rs_mqtt_onchip_da16xxx_ctrl;
        mqtt_onchip_da16xxx_cfg_t * p_mqtt_da16xxx_cfg = &p_client_ctrl->rs_mqtt_onchip_da16xxx_cfg;

        /* Open timer instance in raw mode at the user selected seconds timeout */
        timer_instance_t const * p_timer = &p_client_ctrl->rs_periodic_timer;
        err = p_timer->p_api->open(p_timer->p_ctrl, p_timer->p_cfg);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        p_client_ctrl->timer_status = RS_MQTT_TIMER_INIT_COMPLETE;

        err = RM_MQTT_DA16XXX_Open(p_mqtt_da16xxx_ctrl, p_mqtt_da16xxx_cfg);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        /* Set the mqtt connection open flag */
        p_client_cfg->mqtt_init_phase = RS_MQTT_CLIENT_OPEN;

        err = RM_MQTT_DA16XXX_Connect(p_mqtt_da16xxx_ctrl, p_client_cfg->connect_timeout);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        /* Set client connected  flag */
        p_client_cfg->mqtt_init_phase = RS_MQTT_CLIENT_CONNECTED;

        err = p_timer->p_api->start(p_timer->p_ctrl);
        FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

        p_client_ctrl->timer_status = RS_MQTT_TIMER_STARTED;
        /* Set client started flag */
        p_client_cfg->mqtt_init_phase = RS_MQTT_CLIENT_STARTED;
        p_client_ctrl->mqtt_status = RS_MQTT_CLIENT_CONNECTION_ACTIVE;

        return err;
    }

/*******************************************************************************************************************
 * @brief       Subscribes the MQTT client to one or more MQTT topics.
 *              This function registers one or more topic subscriptions with the connected MQTT broker.
 *              The topic information, including topic names and Quality of Service (QoS) levels,
 *              is provided through the subscription information structure. Upon successful subscription, messages
 *              published to the subscribed topics are received by the MQTT client and delivered to the application
 *              through the registered MQTT callback function.
 * @param[in]   p_ctrl              Pointer to the MQTT client control structure.
 * @param[in]   p_sub_info          Pointer to an array of MQTT subscription information structures.
 * @param[in]   subscription_count  Number of topics to subscribe to.
 * @retval      FSP_SUCCESS                 Successfully subscribed to the specified MQTT topics.
 * @retval      FSP_ERR_INVALID_POINTER     One or more input pointers are NULL.
 * @retval      FSP_ERR_NOT_OPEN            MQTT client is not open or connected.
 * @retval      FSP_ERR_ASSERTION           One or more subscription parameters are invalid.
 * @note        The MQTT client must be connected to the broker before calling this function.
 *              Incoming messages for subscribed topics are handled through the configured MQTT callback function.
 * @return      See @ref RENESAS_ERROR_CODES or the MQTT DA16XXX middleware API return codes for additional error information.
 **********************************************************************************************************************/
fsp_err_t rs_mqtt_client_Subscribe (rs_mqtt_client_ctrl_t * const p_ctrl, mqtt_onchip_da16xxx_sub_info_t * const p_sub_info,
                                    size_t  subscription_count)
{
    fsp_err_t err = FSP_SUCCESS;

    FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_INVALID_POINTER);
    FSP_ERROR_RETURN(NULL != p_sub_info, FSP_ERR_INVALID_POINTER);
    FSP_ERROR_RETURN(subscription_count > 0, FSP_ERR_ASSERTION);

    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;

    mqtt_onchip_da16xxx_instance_ctrl_t * p_mqtt_da16xxx_ctrl = &p_client_ctrl->rs_mqtt_onchip_da16xxx_ctrl;
    mqtt_onchip_da16xxx_sub_info_t *p_subTopics =  (mqtt_onchip_da16xxx_sub_info_t *)p_sub_info;

    if(p_client_ctrl->mqtt_status ==  RS_MQTT_CLIENT_CONNECTION_ACTIVE)
    {
        err = RM_MQTT_DA16XXX_Subscribe(p_mqtt_da16xxx_ctrl, p_subTopics, subscription_count);
    }
    else
    {
        err = FSP_ERR_NOT_ENABLED;
    }
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return err;
}

/*******************************************************************************************************************
 * @brief       Stops the periodic MQTT publish service and closes the MQTT client connection.
 *              This function performs the shutdown sequence for the periodic MQTT client operation.
 *              The following operations are executed:
 *              - Stops the periodic timer used for publish events.
 *              - Closes the timer instance and releases associated resources.
 *              - Terminates the MQTT connection and closes the DA16XXX MQTT middleware instance.
 *              - Updates the MQTT and timer status information to indicate that the service
 *                has been stopped and deinitialized.
 *              After successful completion, periodic publish operations are disabled and the
 *              MQTT client is disconnected from the broker.
 * @param[in]   p_ctrl Pointer to the MQTT client control structure.
 * @retval      FSP_SUCCESS                 MQTT client and periodic timer successfully stopped.
 * @retval      FSP_ERR_INVALID_POINTER     p_ctrl is NULL.
 * @retval      FSP_ERR_NOT_OPEN            MQTT client or timer instance is not open.
 * @note        This function should be called before application shutdown or whenever the
 *              periodic MQTT publishing service is no longer required.
 * @return      See @ref RENESAS_ERROR_CODES or the return codes from the Timer and MQTT DA16XXX middleware APIs for
 *              additional error information.
 **********************************************************************************************************************/
fsp_err_t rs_mqtt_client_PeriodicConnectionStop (rs_mqtt_client_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;

    FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_INVALID_POINTER);

    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;
    mqtt_onchip_da16xxx_instance_ctrl_t * p_mqtt_da16xxx_ctrl = &p_client_ctrl->rs_mqtt_onchip_da16xxx_ctrl;

    /* Close timer instance  */
    timer_instance_t const * p_timer =  &p_client_ctrl->rs_periodic_timer;

    err = p_timer->p_api->stop(p_timer->p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = p_timer->p_api->close(p_timer->p_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    err = RM_MQTT_DA16XXX_Close(p_mqtt_da16xxx_ctrl);
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    /* Clear time status and mqtt status  flag */
    p_client_ctrl->mqtt_status = RS_MQTT_CLIENT_DISCONNECTED;
    p_client_ctrl->timer_status = RS_MQTT_TIMER_DEINIT_COMPLETE;

    return err;
}

/*******************************************************************************************************************
 * @brief       Publishes data to a configured MQTT topic.
 *              This function sends the specified payload to an MQTT broker using an active MQTT
 *              connection. The topic information, payload buffer, payload length, QoS level,
 *              and retain settings are provided through the publish information structure.
 *              The function passes the publish request to the DA16XXX MQTT middleware and
 *              verifies that the publish operation completes successfully.
 * @param[in]   p_ctrl      Pointer to the MQTT client control structure.
 * @param[in]   p_pub_info  Pointer to the MQTT publish information structure containing
 *                          topic and payload details for the publish operation.
 * @retval      FSP_SUCCESS                 Data successfully published to the MQTT topic.
 * @retval      FSP_ERR_INVALID_POINTER     One or more input pointers are NULL.
 * @retval      FSP_ERR_NOT_OPEN            MQTT client is not open or connected.
 * @note        The MQTT client must be successfully connected to a broker before calling
 *              this function.
 * @return      See @ref RENESAS_ERROR_CODES or the MQTT DA16XXX middleware API return codes for additional error
 *              information.
 **********************************************************************************************************************/
fsp_err_t rs_mqtt_client_DataSend (rs_mqtt_client_ctrl_t * const p_ctrl, mqtt_onchip_da16xxx_pub_info_t * p_pub_info)
{
    fsp_err_t err = FSP_SUCCESS;

    FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_INVALID_POINTER);
    FSP_ERROR_RETURN(NULL != p_pub_info, FSP_ERR_INVALID_POINTER);

    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;

    mqtt_onchip_da16xxx_instance_ctrl_t * p_mqtt_da16xxx_ctrl = &p_client_ctrl->rs_mqtt_onchip_da16xxx_ctrl;
    mqtt_onchip_da16xxx_pub_info_t *p_pubTopics =  (mqtt_onchip_da16xxx_pub_info_t *)p_pub_info;

    err = RM_MQTT_DA16XXX_Publish(p_mqtt_da16xxx_ctrl, p_pubTopics);

    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return err;
}

/*******************************************************************************************************************
 * @brief       Receives MQTT data from a subscribed topic.
 *              This function initiates a receive operation on the active MQTT connection and waits
 *              for incoming MQTT messages published to topics subscribed by the client.
 *              When a message is received, the MQTT DA16XXX middleware processes the received
 *              packet and invokes the registered MQTT callback function, allowing the application
 *              to access the received topic and payload data.
 * @param[in]   p_ctrl Pointer to the MQTT client control structure.
 * @retval      FSP_SUCCESS                 MQTT receive operation completed successfully.
 * @retval      FSP_ERR_INVALID_POINTER     p_ctrl is NULL.
 * @retval      FSP_ERR_NOT_OPEN            MQTT client instance is not open.
 * @note        Received MQTT messages are delivered to the application via the registered MQTT callback function.
 * @return      See @ref RENESAS_ERROR_CODES or the MQTT DA16XXX middleware API return codes for additional error
 *              information.
 **********************************************************************************************************************/
fsp_err_t rs_mqtt_client_DataRecv (rs_mqtt_client_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    FSP_ERROR_RETURN(NULL != p_ctrl, FSP_ERR_INVALID_POINTER);

    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;
    mqtt_onchip_da16xxx_instance_ctrl_t * p_mqtt_da16xxx_ctrl = &p_client_ctrl->rs_mqtt_onchip_da16xxx_ctrl;

    err = RM_MQTT_DA16XXX_Receive(p_mqtt_da16xxx_ctrl);
        /* Waiting for receive process completed. */
    FSP_ERROR_RETURN(FSP_SUCCESS == err, err);

    return err;
}


 /*******************************************************************************************************************//**
 * @} (end addtogroup )
 **********************************************************************************************************************/

