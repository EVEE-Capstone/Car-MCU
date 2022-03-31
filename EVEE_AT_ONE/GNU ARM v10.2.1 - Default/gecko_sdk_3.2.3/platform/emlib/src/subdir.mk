################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_assert.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_cmu.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_core.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_emu.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_gpio.c \
../gecko_sdk_3.2.3/platform/emlib/src/em_i2c.c \
../gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_rtc.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_system.c \
../gecko_sdk_3.2.3/platform/emlib/src/em_timer.c \
../gecko_sdk_3.2.3/platform/emlib/src/em_usart.c 

OBJS += \
./gecko_sdk_3.2.3/platform/emlib/src/em_assert.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_core.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_emu.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_i2c.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_rtc.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_system.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_timer.o \
./gecko_sdk_3.2.3/platform/emlib/src/em_usart.o 

C_DEPS += \
./gecko_sdk_3.2.3/platform/emlib/src/em_assert.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_cmu.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_core.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_emu.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_gpio.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_i2c.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_rtc.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_system.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_timer.d \
./gecko_sdk_3.2.3/platform/emlib/src/em_usart.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_3.2.3/platform/emlib/src/em_assert.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_assert.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_assert.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_assert.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_cmu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_cmu.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_cmu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_core.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_core.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_core.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_emu.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_emu.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_emu.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_emu.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_gpio.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_gpio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_i2c.o: ../gecko_sdk_3.2.3/platform/emlib/src/em_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_i2c.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_i2c.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.o: ../gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_leaurt.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_rtc.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_rtc.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_rtc.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_system.o: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2/platform/emlib/src/em_system.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_system.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_system.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_timer.o: ../gecko_sdk_3.2.3/platform/emlib/src/em_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_timer.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_timer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_3.2.3/platform/emlib/src/em_usart.o: ../gecko_sdk_3.2.3/platform/emlib/src/em_usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_3.2.3/platform/emlib/src/em_usart.d" -MT"gecko_sdk_3.2.3/platform/emlib/src/em_usart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


