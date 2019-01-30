LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=hello



all: main.o hello.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) main.o hello.o



hello.o: hello.cpp hello.h

	 g++ $(INC_DIR) -c hello.cpp



main.o: main.cpp hello.*

	 g++ $(INC_DIR) -c main.cpp


clean:
	rm -rf $(APP) *.o $(APP)

