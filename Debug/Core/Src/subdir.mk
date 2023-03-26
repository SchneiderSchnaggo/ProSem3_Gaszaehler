################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/backupData.c \
../Core/Src/delay.c \
../Core/Src/gpio.c \
../Core/Src/main.c \
../Core/Src/modbusRTU.c \
../Core/Src/program.c \
../Core/Src/rs485uart.c \
../Core/Src/shalf1.c \
../Core/Src/shalf1ADC.c \
../Core/Src/shalf1Backup.c \
../Core/Src/shalf1DMA.c \
../Core/Src/shalf1EXTI.c \
../Core/Src/shalf1GPIO.c \
../Core/Src/shalf1I2C.c \
../Core/Src/shalf1RCC.c \
../Core/Src/shalf1SPI.c \
../Core/Src/shalf1SysTick.c \
../Core/Src/shalf1Timer.c \
../Core/Src/shalf1USART.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/backupData.o \
./Core/Src/delay.o \
./Core/Src/gpio.o \
./Core/Src/main.o \
./Core/Src/modbusRTU.o \
./Core/Src/program.o \
./Core/Src/rs485uart.o \
./Core/Src/shalf1.o \
./Core/Src/shalf1ADC.o \
./Core/Src/shalf1Backup.o \
./Core/Src/shalf1DMA.o \
./Core/Src/shalf1EXTI.o \
./Core/Src/shalf1GPIO.o \
./Core/Src/shalf1I2C.o \
./Core/Src/shalf1RCC.o \
./Core/Src/shalf1SPI.o \
./Core/Src/shalf1SysTick.o \
./Core/Src/shalf1Timer.o \
./Core/Src/shalf1USART.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/backupData.d \
./Core/Src/delay.d \
./Core/Src/gpio.d \
./Core/Src/main.d \
./Core/Src/modbusRTU.d \
./Core/Src/program.d \
./Core/Src/rs485uart.d \
./Core/Src/shalf1.d \
./Core/Src/shalf1ADC.d \
./Core/Src/shalf1Backup.d \
./Core/Src/shalf1DMA.d \
./Core/Src/shalf1EXTI.d \
./Core/Src/shalf1GPIO.d \
./Core/Src/shalf1I2C.d \
./Core/Src/shalf1RCC.d \
./Core/Src/shalf1SPI.d \
./Core/Src/shalf1SysTick.d \
./Core/Src/shalf1Timer.d \
./Core/Src/shalf1USART.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/backupData.d ./Core/Src/backupData.o ./Core/Src/backupData.su ./Core/Src/delay.d ./Core/Src/delay.o ./Core/Src/delay.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/modbusRTU.d ./Core/Src/modbusRTU.o ./Core/Src/modbusRTU.su ./Core/Src/program.d ./Core/Src/program.o ./Core/Src/program.su ./Core/Src/rs485uart.d ./Core/Src/rs485uart.o ./Core/Src/rs485uart.su ./Core/Src/shalf1.d ./Core/Src/shalf1.o ./Core/Src/shalf1.su ./Core/Src/shalf1ADC.d ./Core/Src/shalf1ADC.o ./Core/Src/shalf1ADC.su ./Core/Src/shalf1Backup.d ./Core/Src/shalf1Backup.o ./Core/Src/shalf1Backup.su ./Core/Src/shalf1DMA.d ./Core/Src/shalf1DMA.o ./Core/Src/shalf1DMA.su ./Core/Src/shalf1EXTI.d ./Core/Src/shalf1EXTI.o ./Core/Src/shalf1EXTI.su ./Core/Src/shalf1GPIO.d ./Core/Src/shalf1GPIO.o ./Core/Src/shalf1GPIO.su ./Core/Src/shalf1I2C.d ./Core/Src/shalf1I2C.o ./Core/Src/shalf1I2C.su ./Core/Src/shalf1RCC.d ./Core/Src/shalf1RCC.o ./Core/Src/shalf1RCC.su ./Core/Src/shalf1SPI.d ./Core/Src/shalf1SPI.o ./Core/Src/shalf1SPI.su ./Core/Src/shalf1SysTick.d ./Core/Src/shalf1SysTick.o ./Core/Src/shalf1SysTick.su ./Core/Src/shalf1Timer.d ./Core/Src/shalf1Timer.o ./Core/Src/shalf1Timer.su ./Core/Src/shalf1USART.d ./Core/Src/shalf1USART.o ./Core/Src/shalf1USART.su ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

