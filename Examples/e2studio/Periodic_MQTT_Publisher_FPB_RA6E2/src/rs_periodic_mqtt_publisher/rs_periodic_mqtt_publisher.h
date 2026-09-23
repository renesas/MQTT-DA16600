/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/*******************************************************************************************************************//**
 * @addtogroup RM_MQTT_CLIENT
 * @{
 **********************************************************************************************************************/

#ifndef RM_MQTT_CLIENT_H
#define RM_MQTT_CLIENT_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "hal_data.h"
#include "rm_mqtt_onchip_da16xxx.h"
#include "r_timer_api.h"
#include "r_agt.h"
#include "r_dtc.h"
#include "rm_at_transport_da16xxx_uart.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
/** Event in the function return code */
typedef enum e_rs_mqtt_client_event
{
    RS_MQTT_CLIENT_OPEN = 1,
    RS_MQTT_CLIENT_CONNECTED = 2,
    RS_MQTT_CLIENT_DISCONNECTED = 3,
    RS_MQTT_CLIENT_STARTED = 4,
    RS_MQTT_CLIENT_NOT_STARTED = 5,
    RS_MQTT_CLIENT_CONNECTION_ACTIVE = 6,
    RS_MQTT_CLIENT_CONNECTION_NOT_ACTIVE = 7,
    RS_MQTT_CLIENT_EVENT_ERROR = 8,
    RS_MQTT_TIMER_INIT_COMPLETE = 9,
    RS_MQTT_TIMER_INIT_FAILED = 10,
    RS_MQTT_TIMER_DEINIT_COMPLETE = 11,
    RS_MQTT_TIMER_STARTED = 12,
    RS_MQTT_EVENT_TIMER_OPERATION_COMPLETE = 13,
    RS_MQTT_EVENT_TIMER_ERROR = 14,
    RS_NWK_WIFI_NOT_INITIALIZED = 15,
    RS_NWK_WIFI_TURNED_ON = 16,
    RS_NWK_WIFI_CONNECTED = 17,
    RS_NWK_IP_INITIALIZED = 18,
    RS_NWK_INITIALIZED = 19,
    RS_NWK_NOT_INITIALIZED = 20,
} rs_mqtt_client_event_t;


/** MQTT Client cfg  block */
typedef struct st_rs_mqtt_client_cfg
{
    uint32_t nwk_init_phase;            ///< network status flag.
    WIFINetworkParams_t net_params;
    WIFIIPConfiguration_t ipconfig;

    uint32_t mqtt_init_phase;      ///< mqtt status flag
    uint32_t connect_timeout;  ///<mqtt connetion timeout value
} rs_mqtt_client_cfg_t;



/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** MQTT  control structure. */
typedef struct st_rs_mqtt_client_ctrl
{
    size_t                                config_size;                  ///< Config Size
    uint32_t                              timer_status;                 ///< timer status flag
    uint32_t                              nwk_status;                   ///< network status flag
    uint32_t                              mqtt_status;                  ///< mqtt status flag

    mqtt_onchip_da16xxx_instance_ctrl_t   rs_mqtt_onchip_da16xxx_ctrl;  ///< Pointer to the mqtt onchip DA16600 control structure.
    mqtt_onchip_da16xxx_cfg_t             rs_mqtt_onchip_da16xxx_cfg;   ///< Pointer to the mqtt onchip DA16600 config structure.

    timer_instance_t                      rs_periodic_timer;            ///< Timer API used to access hardware.
    timer_cfg_t                           rs_periodic_timer_cfg;
    agt_extended_cfg_t                    rs_extended_timer_cfg;
    agt_instance_ctrl_t                   rs_timer_ctrl;

    dtc_instance_ctrl_t                   rs_dtc_instance_ctrl[2];
    transfer_info_t                       rs_transfer_info[2];
    dtc_extended_cfg_t                    rs_dtc_extended_cfg[2];
    transfer_cfg_t                        rs_transfer_cfg[2];

    transfer_instance_t                   rs_uart_instance_ctrl[2];
    sci_uart_instance_ctrl_t              rs_sci_uart_instance_ctrl;
    baud_setting_t                        rs_baud_setting;
    sci_uart_extended_cfg_t               rs_sci_uart_extended_cfg;
    uart_cfg_t                            rs_uart_cfg;
    uart_instance_t                       rs_uart_instance;

    at_transport_da16xxx_instance_ctrl_t  rs_at_transport_da16xxx_instance_ctrl;
    at_transport_da16xxx_extended_cfg_t   rs_at_transport_da16xxx_extended_cfg;
    at_transport_da16xxx_cfg_t            rs_at_transport_da16xxx_cfg;
    at_transport_da16xxx_instance_t       rs_at_transport_da16xxx_instance;

    wifi_da16xxx_cfg_t                    rs_wifi_da16xxx_cfg;
} rs_mqtt_client_ctrl_t;



/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/
fsp_err_t rs_mqtt_client_NetworkInit(rs_mqtt_client_ctrl_t * const p_client_ctrl, rs_mqtt_client_cfg_t  * p_cfg);
fsp_err_t rs_mqtt_client_PeriodicConnectionStart(rs_mqtt_client_ctrl_t * const p_client_ctrl, rs_mqtt_client_cfg_t  * p_cfg);
fsp_err_t rs_mqtt_client_PeriodicConnectionStop(rs_mqtt_client_ctrl_t * const p_client_ctrl);
fsp_err_t rs_mqtt_client_Subscribe (rs_mqtt_client_ctrl_t * const p_ctrl, mqtt_onchip_da16xxx_sub_info_t * const p_sub_info, size_t  subscription_count);
fsp_err_t rs_mqtt_client_DataSend (rs_mqtt_client_ctrl_t * const p_ctrl, mqtt_onchip_da16xxx_pub_info_t *  p_pub_info);
fsp_err_t rs_mqtt_client_DataRecv (rs_mqtt_client_ctrl_t * const p_ctrl);

fsp_err_t rs_mqtt_client_ConfigGenerate (rs_mqtt_client_ctrl_t *  p_ctrl,  mqtt_onchip_da16xxx_cfg_t *p_mqtt_cfg,
                                         wifi_da16xxx_cfg_t *p_wifi_da16xxx_cfg, timer_instance_t *p_timer, agt_instance_ctrl_t *p_timer_ctrl,
                                         transfer_instance_t *p_transfer0, transfer_instance_t *p_transfer1, uart_instance_t *p_uart, sci_uart_instance_ctrl_t *p_uart_ctrl,
                                         at_transport_da16xxx_instance_t *p_at_transport_da16xxx, at_transport_da16xxx_instance_ctrl_t *p_at_transport_da16xxx_ctrl);

fsp_err_t rs_mqtt_client_ConfigCheck (rs_mqtt_client_ctrl_t * const p_client_ctrl);
void rs_mqtt_client_GetConfigSize (rs_mqtt_client_ctrl_t * const p_client_ctrl, size_t * size);



#endif                                 /* RM_MQTT_CLIENT_H */

/*******************************************************************************************************************//**
 * @} (end addtogroup RM_MQTT_CLIENT)
 **********************************************************************************************************************/
