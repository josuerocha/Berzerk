################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../soil/SOIL.c \
../soil/image_DXT.c \
../soil/image_helper.c \
../soil/stb_image_aug.c 

OBJS += \
./soil/SOIL.o \
./soil/image_DXT.o \
./soil/image_helper.o \
./soil/stb_image_aug.o 

C_DEPS += \
./soil/SOIL.d \
./soil/image_DXT.d \
./soil/image_helper.d \
./soil/stb_image_aug.d 


# Each subdirectory must supply rules for building sources it contributes
soil/%.o: ../soil/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


