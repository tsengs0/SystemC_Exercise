LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=MutexBus



all: main.o mutex_bus.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/mutex_bus.o



mutex_bus.o: src/mutex_bus.cpp inc/mutex_bus.h

	 g++ $(INC_DIR) -c src/mutex_bus.cpp
	mv mutex_bus.o obj/



main.o: src/main.cpp src/mutex_bus.cpp inc/mutex_bus.h

	 g++ $(INC_DIR) -c src/main.cpp
	mv main.o obj/

clean:
	rm -rf $(APP) obj/*.o 

