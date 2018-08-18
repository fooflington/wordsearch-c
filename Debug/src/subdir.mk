################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/dir.c \
../src/grid.c \
../src/rnd.c \
../src/wordsearch.c 

OBJS += \
./src/dir.o \
./src/grid.o \
./src/rnd.o \
./src/wordsearch.o 

C_DEPS += \
./src/dir.d \
./src/grid.d \
./src/rnd.d \
./src/wordsearch.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


