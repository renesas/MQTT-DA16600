################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/bsp/mcu/all/bsp_clocks.c \
../ra/fsp/src/bsp/mcu/all/bsp_common.c \
../ra/fsp/src/bsp/mcu/all/bsp_delay.c \
../ra/fsp/src/bsp/mcu/all/bsp_group_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_guard.c \
../ra/fsp/src/bsp/mcu/all/bsp_io.c \
../ra/fsp/src/bsp/mcu/all/bsp_ipc.c \
../ra/fsp/src/bsp/mcu/all/bsp_irq.c \
../ra/fsp/src/bsp/mcu/all/bsp_macl.c \
../ra/fsp/src/bsp/mcu/all/bsp_ospi_b.c \
../ra/fsp/src/bsp/mcu/all/bsp_register_protection.c \
../ra/fsp/src/bsp/mcu/all/bsp_sbrk.c \
../ra/fsp/src/bsp/mcu/all/bsp_sdram.c \
../ra/fsp/src/bsp/mcu/all/bsp_security.c 

C_DEPS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.d \
./ra/fsp/src/bsp/mcu/all/bsp_common.d \
./ra/fsp/src/bsp/mcu/all/bsp_delay.d \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_guard.d \
./ra/fsp/src/bsp/mcu/all/bsp_io.d \
./ra/fsp/src/bsp/mcu/all/bsp_ipc.d \
./ra/fsp/src/bsp/mcu/all/bsp_irq.d \
./ra/fsp/src/bsp/mcu/all/bsp_macl.d \
./ra/fsp/src/bsp/mcu/all/bsp_ospi_b.d \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.d \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.d \
./ra/fsp/src/bsp/mcu/all/bsp_sdram.d \
./ra/fsp/src/bsp/mcu/all/bsp_security.d 

CREF += \
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.cref 

OBJS += \
./ra/fsp/src/bsp/mcu/all/bsp_clocks.o \
./ra/fsp/src/bsp/mcu/all/bsp_common.o \
./ra/fsp/src/bsp/mcu/all/bsp_delay.o \
./ra/fsp/src/bsp/mcu/all/bsp_group_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_guard.o \
./ra/fsp/src/bsp/mcu/all/bsp_io.o \
./ra/fsp/src/bsp/mcu/all/bsp_ipc.o \
./ra/fsp/src/bsp/mcu/all/bsp_irq.o \
./ra/fsp/src/bsp/mcu/all/bsp_macl.o \
./ra/fsp/src/bsp/mcu/all/bsp_ospi_b.o \
./ra/fsp/src/bsp/mcu/all/bsp_register_protection.o \
./ra/fsp/src/bsp/mcu/all/bsp_sbrk.o \
./ra/fsp/src/bsp/mcu/all/bsp_sdram.o \
./ra/fsp/src/bsp/mcu/all/bsp_security.o 

MAP += \
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/bsp/mcu/all/%.o: ../ra/fsp/src/bsp/mcu/all/%.c
	@echo 'Building file: $<'
	$(file > $@.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -Os -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -std=c99 -fshort-enums -fno-unroll-loops -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_cfg\\fsp_cfg\\bsp" -I"." -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_gen" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_cfg\\fsp_cfg" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_cfg\\aws" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\src" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\inc" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\inc\\api" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\inc\\instances" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_freertos_port" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_wifi_da16xxx" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_at_transport_da16xxx_uart" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_mqtt_onchip_da16xxx" -D_RENESAS_RA_ -D_RA_CORE=CM33 -D_RA_ORDINAL=1 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -x c "$<" -c -o "$@")
	@clang --target=arm-none-eabi @"$@.in"

