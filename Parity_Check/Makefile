LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=PARITY

all: main.o Parity.o
	 g++ -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/Parity.o

Parity.o: src/Parity.cpp inc/Parity.h
	g++ $(INC_DIR) -c src/Parity.cpp
	mv Parity.o obj/

testbench: $(APP) 
	./$(APP)
	mv *.vcd $(TB_DIR) ; gtkwave $(TB_DIR)/*.vcd

path: 
	mkdir src ; mv *.cpp src/
	mkdir inc ; mv *.h inc/
	mkdir testbench
	mkdir obj

main.o: src/main.cpp src/Parity.cpp inc/Parity.h
	g++ $(INC_DIR) -c src/main.cpp
	mv main.o obj/

clean:

	rm -rf $(APP) obj/*.o $(TB_DIR)/*.vcd

