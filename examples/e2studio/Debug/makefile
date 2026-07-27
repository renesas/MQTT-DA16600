################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

-include makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/rs_periodic_mqtt_publisher/demo/subdir.mk
-include src/rs_periodic_mqtt_publisher/config/subdir.mk
-include src/rs_periodic_mqtt_publisher/subdir.mk
-include src/console/subdir.mk
-include src/subdir.mk
-include ra_gen/subdir.mk
-include ra/fsp/src/rm_wifi_da16xxx/subdir.mk
-include ra/fsp/src/rm_mqtt_onchip_da16xxx/subdir.mk
-include ra/fsp/src/rm_freertos_port/subdir.mk
-include ra/fsp/src/rm_comms_uart/subdir.mk
-include ra/fsp/src/rm_comms_lock/subdir.mk
-include ra/fsp/src/rm_at_transport_da16xxx_uart/subdir.mk
-include ra/fsp/src/r_sci_uart/subdir.mk
-include ra/fsp/src/r_ioport/subdir.mk
-include ra/fsp/src/r_dtc/subdir.mk
-include ra/fsp/src/r_agt/subdir.mk
-include ra/fsp/src/bsp/mcu/ra6e2/subdir.mk
-include ra/fsp/src/bsp/mcu/all/subdir.mk
-include ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/subdir.mk
-include ra/board/ra6e2_fpb/subdir.mk
-include ra/aws/FreeRTOS/FreeRTOS/Source/subdir.mk
-include ra/arm/CMSIS_6/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(JMP_DEPS)),)
-include $(JMP_DEPS)
endif
ifneq ($(strip $(FSY_DEPS)),)
-include $(FSY_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(SRC_UPPER_DEPS)),)
-include $(SRC_UPPER_DEPS)
endif
ifneq ($(strip $(P_UPPER_DEPS)),)
-include $(P_UPPER_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(PP_UPPER_DEPS)),)
-include $(PP_UPPER_DEPS)
endif
ifneq ($(strip $(P_DEPS)),)
-include $(P_DEPS)
endif
ifneq ($(strip $(FSY_UPPER_DEPS)),)
-include $(FSY_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
$(C_DEPS):$(SMS_ASM)
endif
ifneq ($(strip $(SRC_DEPS)),)
-include $(SRC_DEPS)
endif
ifneq ($(strip $(JMP_UPPER_DEPS)),)
-include $(JMP_UPPER_DEPS)
endif
ifneq ($(strip $(PP_DEPS)),)
-include $(PP_DEPS)
endif
ifneq ($(strip $(SX_DEPS)),)
-include $(SX_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(SX_UPPER_DEPS)),)
-include $(SX_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
OBJCOPY += \
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.srec \

SECONDARY_SIZE += \
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.siz \


# All Target
all: MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf secondary-outputs

# Tool invocations
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf: $(OBJS) $(USER_OBJS) $(LIBRARY_GENERATOR_OUTPUTTYPE_OUTPUTS) $(LINKER_SCRIPT)
	$(file > MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf.in,-mcpu=cortex-m33 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv5-sp-d16 -Os -ffunction-sections -fdata-sections -fno-strict-aliasing -fmessage-length=0 -funsigned-char -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return -Wno-parentheses-equality -Wfloat-equal -g3 -o "MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf" $(OBJS) $(USER_OBJS) -T "fsp.lld" -L"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2/script" -L"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\Debug" -Wl,-Map=MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.map -Wl,--start-group -lcrt0 -lc++abi  -Wl,--end-group -Wl,--gc-sections -Wl,--cref -Wl,-z,norelro -Wl,--icf=none -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_cfg\\fsp_cfg\\bsp" -I"." -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_gen" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_cfg\\fsp_cfg" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra_cfg\\aws" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\src" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\inc" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\inc\\api" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\inc\\instances" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_freertos_port" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\aws\\FreeRTOS\\FreeRTOS\\Source\\include" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\arm\\CMSIS_6\\CMSIS\\Core\\Include" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_wifi_da16xxx" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_at_transport_da16xxx_uart" -I"C:\\WS\\FSP_650_060152026\\MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2\\ra\\fsp\\src\\rm_mqtt_onchip_da16xxx")
	@echo Building target: $@ && clang  --target=arm-none-eabi @"MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf.in"> MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.cref
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.srec: MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf
	llvm-objcopy "MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf" -O srec  "MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.srec"
MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.siz: MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf
	llvm-size --format=berkeley "MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf"
# Other Targets
clean:
	-$(file > clean_file.tmp,  $(JMP_DEPS)  $(FSY_DEPS)  $(C_UPPER_DEPS)  $(SECONDARY_SIZE)  $(SRC_UPPER_DEPS)  $(P_UPPER_DEPS)  $(S_DEPS)  $(PP_UPPER_DEPS)  $(P_DEPS)  $(FSY_UPPER_DEPS)  $(C_DEPS)  $(CREF)  $(SRC_DEPS)  $(OBJCOPY)  $(JMP_UPPER_DEPS)  $(PP_DEPS)  $(SX_DEPS)  $(ASM_UPPER_DEPS)  $(OBJS)  $(SX_UPPER_DEPS)  $(ASM_DEPS)  $(MAP)  $(S_UPPER_DEPS) )
	-@ xargs -P 2 -s 32000 -t -a clean_file.tmp $(RM)
	-@$(RM) clean_file.tmp
	-$(RM)  MQTT_Periodic_Publisher_with_DA16600_On_FPB_RA6E2.elf
	-@echo ' '

secondary-outputs: $(OBJCOPY) $(SECONDARY_SIZE)

.PHONY: all clean dependents 

-include ../makefile.targets
