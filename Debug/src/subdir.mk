################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AnimacaoFinal.cpp \
../src/AnimacaoGameOver.cpp \
../src/AnimacaoInicial.cpp \
../src/AnimacaoMorte.cpp \
../src/AnimacaoPassouFase.cpp \
../src/Coletavel.cpp \
../src/EfeitosVisuais.cpp \
../src/Enemy.cpp \
../src/Explosao.cpp \
../src/Game.cpp \
../src/Level.cpp \
../src/MainMenu.cpp \
../src/Medkit.cpp \
../src/Parede.cpp \
../src/Personagem.cpp \
../src/Player.cpp \
../src/Projectile.cpp \
../src/Score.cpp \
../src/Utilities.cpp \
../src/main.cpp 

OBJS += \
./src/AnimacaoFinal.o \
./src/AnimacaoGameOver.o \
./src/AnimacaoInicial.o \
./src/AnimacaoMorte.o \
./src/AnimacaoPassouFase.o \
./src/Coletavel.o \
./src/EfeitosVisuais.o \
./src/Enemy.o \
./src/Explosao.o \
./src/Game.o \
./src/Level.o \
./src/MainMenu.o \
./src/Medkit.o \
./src/Parede.o \
./src/Personagem.o \
./src/Player.o \
./src/Projectile.o \
./src/Score.o \
./src/Utilities.o \
./src/main.o 

CPP_DEPS += \
./src/AnimacaoFinal.d \
./src/AnimacaoGameOver.d \
./src/AnimacaoInicial.d \
./src/AnimacaoMorte.d \
./src/AnimacaoPassouFase.d \
./src/Coletavel.d \
./src/EfeitosVisuais.d \
./src/Enemy.d \
./src/Explosao.d \
./src/Game.d \
./src/Level.d \
./src/MainMenu.d \
./src/Medkit.d \
./src/Parede.d \
./src/Personagem.d \
./src/Player.d \
./src/Projectile.d \
./src/Score.d \
./src/Utilities.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -Iheader -I../header -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


