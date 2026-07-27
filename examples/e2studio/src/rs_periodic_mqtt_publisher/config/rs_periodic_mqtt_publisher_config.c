#include "rs_periodic_mqtt_publisher/rs_periodic_mqtt_publisher.h"

fsp_err_t rs_mqtt_client_ConfigGenerate (rs_mqtt_client_ctrl_t * const p_ctrl, mqtt_onchip_da16xxx_cfg_t *p_mqtt_cfg,
                                         wifi_da16xxx_cfg_t *p_wifi_da16xxx_cfg, timer_instance_t *p_timer1, transfer_instance_t *p_transfer0,
                                         uart_instance_t *p_uart0, at_transport_da16xxx_instance_t *p_at_transport_da16xxx)
{
//    fsp_err_t err = FSP_SUCCESS;
    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;

    /* Initialize the configurations */
    memset(&p_client_ctrl->rs_mqtt_onchip_da16xxx_ctrl, 0, sizeof(mqtt_onchip_da16xxx_instance_ctrl_t));
    memset(&p_client_ctrl->rs_mqtt_onchip_da16xxx_cfg, 0, sizeof(mqtt_onchip_da16xxx_cfg_t));

    memset(&p_client_ctrl->rs_wifi_da16xxx_cfg, 0, sizeof(wifi_da16xxx_cfg_t));

    memset(&p_client_ctrl->rs_periodic_timer, 0, sizeof(timer_instance_t));
    memset(&p_client_ctrl->rs_periodic_timer_cfg, 0, sizeof(timer_cfg_t));
    memset(&p_client_ctrl->rs_extended_timer_cfg, 0, sizeof(agt_extended_cfg_t));
    memset(&p_client_ctrl->rs_timer_ctrl, 0, sizeof(agt_instance_ctrl_t));

    memset(&p_client_ctrl->rs_uart_instance_ctrl, 0, sizeof(transfer_instance_t));
    memset(&p_client_ctrl->rs_dtc_instance_ctrl, 0, sizeof(dtc_instance_ctrl_t));
    memset(&p_client_ctrl->rs_transfer_info, 0, sizeof(transfer_info_t));
    memset(&p_client_ctrl->rs_dtc_extended_cfg, 0, sizeof(dtc_extended_cfg_t));
    memset(&p_client_ctrl->rs_transfer_cfg, 0, sizeof(transfer_cfg_t));

    memset(&p_client_ctrl->rs_sci_uart_instance_ctrl, 0, sizeof(sci_uart_instance_ctrl_t));
    memset(&p_client_ctrl->rs_baud_setting, 0, sizeof(baud_setting_t));
    memset(&p_client_ctrl->rs_sci_uart_extended_cfg, 0, sizeof(sci_uart_extended_cfg_t));
    memset(&p_client_ctrl->rs_uart_cfg, 0, sizeof(uart_cfg_t));
    memset(&p_client_ctrl->rs_uart_instance, 0, sizeof(uart_instance_t));

    memset(&p_client_ctrl->rs_at_transport_da16xxx_instance_ctrl, 0, sizeof(at_transport_da16xxx_instance_ctrl_t));
    memset(&p_client_ctrl->rs_at_transport_da16xxx_extended_cfg, 0, sizeof(at_transport_da16xxx_extended_cfg_t));
    memset(&p_client_ctrl->rs_at_transport_da16xxx_cfg, 0, sizeof(at_transport_da16xxx_cfg_t));
    memset(&p_client_ctrl->rs_at_transport_da16xxx_instance, 0, sizeof(at_transport_da16xxx_instance_t));

    /* Copy the Settings into SRAM */
    memcpy(&p_client_ctrl->rs_mqtt_onchip_da16xxx_cfg, p_mqtt_cfg, sizeof(mqtt_onchip_da16xxx_cfg_t));
    memcpy(&p_client_ctrl->rs_wifi_da16xxx_cfg, p_wifi_da16xxx_cfg, sizeof(wifi_da16xxx_cfg_t));

    memcpy(&p_client_ctrl->rs_periodic_timer, p_timer1, sizeof(timer_instance_t));
    memcpy(&p_client_ctrl->rs_periodic_timer_cfg, p_timer1->p_cfg, sizeof(timer_cfg_t));
    memcpy(&p_client_ctrl->rs_extended_timer_cfg, p_timer1->p_cfg->p_extend, sizeof(agt_extended_cfg_t));
    memcpy(&p_client_ctrl->rs_timer_ctrl, p_timer1->p_ctrl, sizeof(agt_instance_ctrl_t));

    memcpy(&p_client_ctrl->rs_uart_instance_ctrl, p_transfer0, sizeof(transfer_instance_t));
  //  memcpy(&p_client_ctrl->rs_dtc_instance_ctrl, g_transfer0_ctrl, sizeof(dtc_instance_ctrl_t));
    memcpy(&p_client_ctrl->rs_transfer_info, p_transfer0->p_cfg->p_info, sizeof(transfer_info_t));
    memcpy(&p_client_ctrl->rs_dtc_extended_cfg, p_transfer0->p_cfg->p_extend, sizeof(dtc_extended_cfg_t));
    memcpy(&p_client_ctrl->rs_transfer_cfg, p_transfer0->p_cfg, sizeof(transfer_cfg_t));

    memcpy(&p_client_ctrl->rs_sci_uart_extended_cfg, p_uart0->p_cfg->p_extend, sizeof(sci_uart_extended_cfg_t));
    memcpy(&p_client_ctrl->rs_uart_cfg, p_uart0->p_cfg, sizeof(uart_cfg_t));
    memcpy(&p_client_ctrl->rs_at_transport_da16xxx_extended_cfg, p_at_transport_da16xxx->p_cfg->p_extend, sizeof(at_transport_da16xxx_extended_cfg_t));
    memcpy(&p_client_ctrl->rs_at_transport_da16xxx_cfg, p_at_transport_da16xxx->p_cfg, sizeof(at_transport_da16xxx_cfg_t));


    /* Manually assign addresses of the p_ pointers to configurations in SRAM, except driver APIs*/

     /* Return configuration size*/
    p_client_ctrl->config_size = sizeof (p_client_ctrl);


    return FSP_SUCCESS;
}


fsp_err_t rs_mqtt_client_ConfigCheck (rs_mqtt_client_ctrl_t * const p_ctrl)
{
    fsp_err_t err = FSP_SUCCESS;
    rs_mqtt_client_ctrl_t * p_client_ctrl = (rs_mqtt_client_ctrl_t *) p_ctrl;

        /* Verify the Configurations */
    if(p_client_ctrl != NULL)
    {
        /* Period timer configuration */
        if(p_client_ctrl->rs_periodic_timer_cfg.mode != TIMER_MODE_PERIODIC)
        {
            return FSP_ERR_INVALID_MODE;
        }

    }
    return err;
}

void rs_mqtt_client_GetConfigSize (rs_mqtt_client_ctrl_t * const p_ctrl, size_t *cfg_size)
{
    if(NULL != p_ctrl)
    {
       *cfg_size = sizeof (rs_mqtt_client_ctrl_t);
    }
}
