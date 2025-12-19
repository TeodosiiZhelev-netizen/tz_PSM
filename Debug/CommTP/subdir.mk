################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CommTP/CommTp.c 

OBJS += \
./CommTP/CommTp.o 

C_DEPS += \
./CommTP/CommTp.d 


# Each subdirectory must supply rules for building sources it contributes
CommTP/%.o CommTP/%.su CommTP/%.cyclo: ../CommTP/%.c CommTP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Type -I../KbdDrv -I../IOHWAB -I../Seat_StateMngr -I../SeatPositionControl -I../CommMngr -I../CommTP -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CommTP

clean-CommTP:
	-$(RM) ./CommTP/CommTp.cyclo ./CommTP/CommTp.d ./CommTP/CommTp.o ./CommTP/CommTp.su

.PHONY: clean-CommTP

