################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ALPRHandler.cpp \
../src/PlateRecognitionServer.cpp \
../src/QueueHandler.cpp 

OBJS += \
./src/ALPRHandler.o \
./src/PlateRecognitionServer.o \
./src/QueueHandler.o 

CPP_DEPS += \
./src/ALPRHandler.d \
./src/PlateRecognitionServer.d \
./src/QueueHandler.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/mateusz/workspace/pgjs/openalpr/src/openalpr -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


