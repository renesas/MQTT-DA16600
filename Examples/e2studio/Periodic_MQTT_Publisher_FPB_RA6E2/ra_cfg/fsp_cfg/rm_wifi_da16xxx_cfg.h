/* generated configuration header file - do not edit */
#ifndef RM_WIFI_DA16XXX_CFG_H_
#define RM_WIFI_DA16XXX_CFG_H_
#ifdef __cplusplus
            extern "C" {
            #endif

#define WIFI_DA16XXX_CFG_PARAM_CHECKING_ENABLED        ((BSP_CFG_PARAM_CHECKING_ENABLE))
#define WIFI_DA16XXX_CFG_DA16600_SUPPORT               (1)
#define WIFI_DA16XXX_CFG_CHECK_SDK_VERSION             (1)
#define WIFI_DA16XXX_CFG_NUM_CREATEABLE_SOCKETS        ((1))

#if ((1 == 1) || (1 == RA_NOT_DEFINED))
#define WIFI_DA16XXX_CFG_MAX_SOCKET_RX_SIZE            (1)
#define WIFI_DA16XXX_CFG_CMD_TX_BUF_SIZE               (512)
#else
            #define WIFI_DA16XXX_CFG_MAX_SOCKET_RX_SIZE            (8192)
            #define WIFI_DA16XXX_CFG_CMD_TX_BUF_SIZE               (1500)
            #endif

#define WIFI_DA16XXX_CFG_CMD_RX_BUF_SIZE               (3000)
#define WIFI_DA16XXX_CFG_TLS_SUPPORT                   (RA_NOT_DEFINED)
#define WIFI_DA16XXX_CFG_SNTP_ENABLE                   (1)
#define RM_AT_TRANSPORT_DA16XXX_INTERFACE_UART

#ifdef __cplusplus
}
#endif
#endif /* RM_WIFI_DA16XXX_CFG_H_ */
