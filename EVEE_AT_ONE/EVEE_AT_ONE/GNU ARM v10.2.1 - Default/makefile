################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include gecko_sdk_3.2.3/platform/service/system/src/subdir.mk
-include gecko_sdk_3.2.3/platform/service/sleeptimer/src/subdir.mk
-include gecko_sdk_3.2.3/platform/service/device_init/src/subdir.mk
-include gecko_sdk_3.2.3/platform/emlib/src/subdir.mk
-include gecko_sdk_3.2.3/platform/driver/leddrv/src/subdir.mk
-include gecko_sdk_3.2.3/platform/common/toolchain/src/subdir.mk
-include gecko_sdk_3.2.3/platform/Device/SiliconLabs/EFM32HG/Source/GCC/subdir.mk
-include gecko_sdk_3.2.3/platform/Device/SiliconLabs/EFM32HG/Source/subdir.mk
-include autogen/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: EVEE_AT_ONE.axf

# Tool invocations
EVEE_AT_ONE.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen/linkerfile.ld" -Xlinker --gc-sections -Xlinker -Map="EVEE_AT_ONE.map" --specs=nano.specs -o EVEE_AT_ONE.axf -Wl,--start-group "./app.o" "./blink.o" "./gpio.o" "./i2c.o" "./leuart.o" "./main.o" "./max17043.o" "./mfrc522.o" "./motor.o" "./timer.o" "./usart.o" "./autogen/sl_device_init_clocks.o" "./autogen/sl_event_handler.o" "./autogen/sl_simple_led_instances.o" "./gecko_sdk_3.2.3/platform/Device/SiliconLabs/EFM32HG/Source/GCC/startup_efm32hg.o" "./gecko_sdk_3.2.3/platform/Device/SiliconLabs/EFM32HG/Source/system_efm32hg.o" "./gecko_sdk_3.2.3/platform/common/toolchain/src/sl_memory.o" "./gecko_sdk_3.2.3/platform/driver/leddrv/src/sl_led.o" "./gecko_sdk_3.2.3/platform/driver/leddrv/src/sl_simple_led.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_assert.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_core.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_emu.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_i2c.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_rtc.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_system.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_timer.o" "./gecko_sdk_3.2.3/platform/emlib/src/em_usart.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_emu_s0.o" "./gecko_sdk_3.2.3/platform/service/device_init/src/sl_device_init_nvic.o" "./gecko_sdk_3.2.3/platform/service/sleeptimer/src/sl_sleeptimer.o" "./gecko_sdk_3.2.3/platform/service/sleeptimer/src/sl_sleeptimer_hal_rtc.o" "./gecko_sdk_3.2.3/platform/service/system/src/sl_system_init.o" "./gecko_sdk_3.2.3/platform/service/system/src/sl_system_process_action.o" -lgcc -lc -lm -lnosys -Wl,--end-group -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: EVEE_AT_ONE.hex'
	arm-none-eabi-objcopy -O ihex "EVEE_AT_ONE.axf" "EVEE_AT_ONE.hex"
	@echo ' '

	@echo 'Building bin file: EVEE_AT_ONE.bin'
	arm-none-eabi-objcopy -O binary "EVEE_AT_ONE.axf" "EVEE_AT_ONE.bin"
	@echo ' '

	@echo 'Building s37 file: EVEE_AT_ONE.s37'
	arm-none-eabi-objcopy -O srec "EVEE_AT_ONE.axf" "EVEE_AT_ONE.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "EVEE_AT_ONE.axf" -A
	@echo ' '

# Other Targets
clean:
	-@$(foreach FILE, $(EXECUTABLES), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(OBJS), $(shell $(RM) $(FILE)) )
	-@$(foreach FILE, $(C_DEPS), $(shell $(RM) $(FILE)) )
	-$(RM) EVEE_AT_ONE.axf
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
