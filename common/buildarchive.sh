mkdir static/
arm-none-eabi-gcc -c controllermodel.cpp -o static/controllermodel.o
arm-none-eabi-gcc -c sysexmessaging.cpp -o static/sysexmessaging.o
ar rcs static/common.a static/controllermodel.o static/sysexmessaging.o