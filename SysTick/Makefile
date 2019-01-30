LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench
OPTION=-O0 -Wall -std=c++11

APP=SysTick



all: main.o Multiplexer.o

	 g++ ${OPTION} -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/Multiplexer.o



Multiplexer.o: src/Multiplexer.cpp inc/Multiplexer.h

	 g++ $(INC_DIR) -c src/Multiplexer.cpp
	mv Multiplexer.o obj/



main.o: src/main.cpp inc/reg_format.h src/Multiplexer.cpp inc/Multiplexer.h

	 g++ ${OPTION} $(INC_DIR) -c src/main.cpp
	mv main.o obj/

clean:
	rm -rf $(APP) obj/*.o 

