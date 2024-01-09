################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/data.c \
../src/main.c \
../src/queue_array.c \
../src/stack_array.c 

C_DEPS += \
./src/data.d \
./src/main.d \
./src/queue_array.d \
./src/stack_array.d 

OBJS += \
./src/data.o \
./src/main.o \
./src/queue_array.o \
./src/stack_array.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/data.d ./src/data.o ./src/main.d ./src/main.o ./src/queue_array.d ./src/queue_array.o ./src/stack_array.d ./src/stack_array.o

.PHONY: clean-src

