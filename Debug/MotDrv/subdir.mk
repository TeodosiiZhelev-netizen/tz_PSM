################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MotDrv/MotDrv.c 

OBJS += \
./MotDrv/MotDrv.o 

C_DEPS += \
./MotDrv/MotDrv.d 


# Each subdirectory must supply rules for building sources it contributes
MotDrv/%.o MotDrv/%.su MotDrv/%.cyclo: ../MotDrv/%.c MotDrv/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Type -I../KbdDrv -I../IOHWAB -I../Seat_StateMngr -I../SeatPositionControl -I../CommMngr -I../CommTP -I../MotDrv -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MotDrv

clean-MotDrv:
	-$(RM) ./MotDrv/MotDrv.cyclo ./MotDrv/MotDrv.d ./MotDrv/MotDrv.o ./MotDrv/MotDrv.su

.PHONY: clean-MotDrv

