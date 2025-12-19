################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Seat_StateMngr/Seat_StateMngr.c 

OBJS += \
./Seat_StateMngr/Seat_StateMngr.o 

C_DEPS += \
./Seat_StateMngr/Seat_StateMngr.d 


# Each subdirectory must supply rules for building sources it contributes
Seat_StateMngr/%.o Seat_StateMngr/%.su Seat_StateMngr/%.cyclo: ../Seat_StateMngr/%.c Seat_StateMngr/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xE -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Type -I../KbdDrv -I../IOHWAB -I../Seat_StateMngr -I../SeatPositionControl -I../CommMngr -I../CommTP -I../MotDrv -I../ManualAdjustment -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Seat_StateMngr

clean-Seat_StateMngr:
	-$(RM) ./Seat_StateMngr/Seat_StateMngr.cyclo ./Seat_StateMngr/Seat_StateMngr.d ./Seat_StateMngr/Seat_StateMngr.o ./Seat_StateMngr/Seat_StateMngr.su

.PHONY: clean-Seat_StateMngr

