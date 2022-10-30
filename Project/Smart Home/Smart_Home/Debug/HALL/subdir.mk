################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/BUZZER.c \
../HALL/EEPROM.c \
../HALL/KEYPAD.c \
../HALL/LCD.c \
../HALL/LED.c \
../HALL/Servo.c \
../HALL/TEMP.c 

OBJS += \
./HALL/BUZZER.o \
./HALL/EEPROM.o \
./HALL/KEYPAD.o \
./HALL/LCD.o \
./HALL/LED.o \
./HALL/Servo.o \
./HALL/TEMP.o 

C_DEPS += \
./HALL/BUZZER.d \
./HALL/EEPROM.d \
./HALL/KEYPAD.d \
./HALL/LCD.d \
./HALL/LED.d \
./HALL/Servo.d \
./HALL/TEMP.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/%.o: ../HALL/%.c HALL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


