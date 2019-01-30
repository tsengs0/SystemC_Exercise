LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=HA



all: main.o Half_adder.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/Half_adder.o



Half_adder.o: src/Half_adder.cpp inc/Half_adder.h

	 g++ $(INC_DIR) -c src/Half_adder.cpp
	mv Half_adder.o obj/



main.o: src/main.cpp src/Half_adder.cpp inc/Half_adder.h

	 g++ $(INC_DIR) -c src/main.cpp
	mv main.o obj/

testbench: $(APP) 
	./$(APP)
	mv *.vcd $(TB_DIR) ; gtkwave $(TB_DIR)/*.vcd

clean:

	rm -rf $(APP) obj/*.o $(TB_DIR)/*.vcd

