#include "main_thread.h"
#include "common_data.h"
#include "FreeRTOS.h"

extern void periodicPublishWithDA16600Entry();


/* Main Thread entry function */
/* pvParameters contains TaskHandle_t */
void main_thread_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    periodicPublishWithDA16600Entry();

}
