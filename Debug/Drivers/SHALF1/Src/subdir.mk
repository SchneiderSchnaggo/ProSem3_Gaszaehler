################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SHALF1/Src/shalf1.c \
../Drivers/SHALF1/Src/shalf1ADC.c \
../Drivers/SHALF1/Src/shalf1DMA.c \
../Drivers/SHALF1/Src/shalf1EXTI.c \
../Drivers/SHALF1/Src/shalf1GPIO.c \
../Drivers/SHALF1/Src/shalf1I2C.c \
../Drivers/SHALF1/Src/shalf1RCC.c \
../Drivers/SHALF1/Src/shalf1SPI.c \
../Drivers/SHALF1/Src/shalf1SysTick.c \
../Drivers/SHALF1/Src/shalf1Timer.c \
../Drivers/SHALF1/Src/shalf1USART.c 

OBJS += \
./Drivers/SHALF1/Src/shalf1.o \
./Drivers/SHALF1/Src/shalf1ADC.o \
./Drivers/SHALF1/Src/shalf1DMA.o \
./Drivers/SHALF1/Src/shalf1EXTI.o \
./Drivers/SHALF1/Src/shalf1GPIO.o \
./Drivers/SHALF1/Src/shalf1I2C.o \
./Drivers/SHALF1/Src/shalf1RCC.o \
./Drivers/SHALF1/Src/shalf1SPI.o \
./Drivers/SHALF1/Src/shalf1SysTick.o \
./Drivers/SHALF1/Src/shalf1Timer.o \
./Drivers/SHALF1/Src/shalf1USART.o 

C_DEPS += \
./Drivers/SHALF1/Src/shalf1.d \
./Drivers/SHALF1/Src/shalf1ADC.d \
./Drivers/SHALF1/Src/shalf1DMA.d \
./Drivers/SHALF1/Src/shalf1EXTI.d \
./Drivers/SHALF1/Src/shalf1GPIO.d \
./Drivers/SHALF1/Src/shalf1I2C.d \
./Drivers/SHALF1/Src/shalf1RCC.d \
./Drivers/SHALF1/Src/shalf1SPI.d \
./Drivers/SHALF1/Src/shalf1SysTick.d \
./Drivers/SHALF1/Src/shalf1Timer.d \
./Drivers/SHALF1/Src/shalf1USART.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SHALF1/Src/%.o Drivers/SHALF1/Src/%.su: ../Drivers/SHALF1/Src/%.c Drivers/SHALF1/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-SHALF1-2f-Src

clean-Drivers-2f-SHALF1-2f-Src:
	-$(RM) ./Drivers/SHALF1/Src/shalf1.d ./Drivers/SHALF1/Src/shalf1.o ./Drivers/SHALF1/Src/shalf1.su ./Drivers/SHALF1/Src/shalf1ADC.d ./Drivers/SHALF1/Src/shalf1ADC.o ./Drivers/SHALF1/Src/shalf1ADC.su ./Drivers/SHALF1/Src/shalf1DMA.d ./Drivers/SHALF1/Src/shalf1DMA.o ./Drivers/SHALF1/Src/shalf1DMA.su ./Drivers/SHALF1/Src/shalf1EXTI.d ./Drivers/SHALF1/Src/shalf1EXTI.o ./Drivers/SHALF1/Src/shalf1EXTI.su ./Drivers/SHALF1/Src/shalf1GPIO.d ./Drivers/SHALF1/Src/shalf1GPIO.o ./Drivers/SHALF1/Src/shalf1GPIO.su ./Drivers/SHALF1/Src/shalf1I2C.d ./Drivers/SHALF1/Src/shalf1I2C.o ./Drivers/SHALF1/Src/shalf1I2C.su ./Drivers/SHALF1/Src/shalf1RCC.d ./Drivers/SHALF1/Src/shalf1RCC.o ./Drivers/SHALF1/Src/shalf1RCC.su ./Drivers/SHALF1/Src/shalf1SPI.d ./Drivers/SHALF1/Src/shalf1SPI.o ./Drivers/SHALF1/Src/shalf1SPI.su ./Drivers/SHALF1/Src/shalf1SysTick.d ./Drivers/SHALF1/Src/shalf1SysTick.o ./Drivers/SHALF1/Src/shalf1SysTick.su ./Drivers/SHALF1/Src/shalf1Timer.d ./Drivers/SHALF1/Src/shalf1Timer.o ./Drivers/SHALF1/Src/shalf1Timer.su ./Drivers/SHALF1/Src/shalf1USART.d ./Drivers/SHALF1/Src/shalf1USART.o ./Drivers/SHALF1/Src/shalf1USART.su

.PHONY: clean-Drivers-2f-SHALF1-2f-Src

