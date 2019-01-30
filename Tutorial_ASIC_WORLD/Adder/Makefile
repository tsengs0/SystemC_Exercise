LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=adder



all: main.o 

	 g++ -o $(APP) $(LIB_DIR) $(LIB) main.o

main.o: main.cpp

	 g++ $(INC_DIR) -c -lm main.cpp

testbench: $(APP) 
	./$(APP)

clean:

	rm -rf $(APP) *.o *.vcd
	clear

