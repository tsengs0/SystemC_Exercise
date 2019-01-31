LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench
OPTION=-Wall -O0

APP=SysTick



all: main.o Multiplexer.o timer_reg.o reg_format.o
	 g++ ${OPTION} -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/Multiplexer.o obj/timer_reg.o obj/reg_format.o

timer_reg.o: src/timer_reg.cpp inc/timer_reg.h inc/reg_format.h
	 g++ $(INC_DIR) -c src/timer_reg.cpp
	mv timer_reg.o obj/

Multiplexer.o: src/Multiplexer.cpp inc/Multiplexer.h
	 g++ $(INC_DIR) -c src/Multiplexer.cpp
	mv Multiplexer.o obj/

reg_format.o: src/reg_format.cpp inc/reg_format.h
	 g++ $(INC_DIR) -c src/reg_format.cpp
	mv reg_format.o obj/

main.o: src/main.cpp src/reg_format.cpp inc/reg_format.h src/Multiplexer.cpp inc/Multiplexer.h src/timer_reg.cpp inc/timer_reg.h
	 g++ ${OPTION} $(INC_DIR) -c src/main.cpp
	mv main.o obj/

clean:
	rm -rf $(APP) obj/*.o 

