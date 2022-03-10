################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app.c \
../blink.c \
../gpio.c \
../i2c.c \
../leuart.c \
../main.c \
../max17043.c \
../mfrc522.c \
../motor.c \
../timer.c \
../usart.c 

OBJS += \
./app.o \
./blink.o \
./gpio.o \
./i2c.o \
./leuart.o \
./main.o \
./max17043.o \
./mfrc522.o \
./motor.o \
./timer.o \
./usart.o 

C_DEPS += \
./app.d \
./blink.d \
./gpio.d \
./i2c.d \
./leuart.d \
./main.d \
./max17043.d \
./mfrc522.d \
./motor.d \
./timer.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
app.o: ../app.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"app.d" -MT"app.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

blink.o: ../blink.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"blink.d" -MT"blink.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gpio.o: ../gpio.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"gpio.d" -MT"gpio.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

i2c.o: ../i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"i2c.d" -MT"i2c.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

leuart.o: ../leuart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"leuart.d" -MT"leuart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ../main.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"main.d" -MT"main.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

max17043.o: ../max17043.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"max17043.d" -MT"max17043.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

mfrc522.o: ../mfrc522.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"mfrc522.d" -MT"mfrc522.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

motor.o: ../motor.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"motor.d" -MT"motor.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer.o: ../timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"timer.d" -MT"timer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

usart.o: ../usart.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -std=c99 '-DDEBUG_EFM=1' '-DEFM32HG222F64=1' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/autogen" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/Device/SiliconLabs/EFM32HG/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/CMSIS/Include" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/device_init/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/emlib/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/driver/leddrv/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/common/toolchain/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/system/inc" -I"/Applications/Simplicity Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.2//platform/service/sleeptimer/inc" -I"/Users/maxpettit/SimplicityStudio/EVEE/EVEE_AT_ONE/config" -O0 -Wall -Wextra -fno-builtin -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -c -fmessage-length=0 -MMD -MP -MF"usart.d" -MT"usart.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


