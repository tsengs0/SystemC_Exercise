LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=sc_time



all: sc_time.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) sc_time.o



sc_time.o: sc_time.cpp

	 g++ $(INC_DIR) -c sc_time.cpp

clean:
	rm -rf $(APP) *.o

