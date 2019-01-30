LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64
INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=MUX_4x1



all: main.o Multiplexer.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/Multiplexer.o



Multiplexer.o: src/Multiplexer.cpp inc/Multiplexer.h

	 g++ $(INC_DIR) -c src/Multiplexer.cpp
	mv Multiplexer.o obj/



main.o: src/main.cpp src/Multiplexer.cpp inc/Multiplexer.h

	 g++ $(INC_DIR) -c src/main.cpp
	mv main.o obj/

testbench: $(APP) 
	./$(APP)
	mv *.vcd $(TB_DIR) ; gtkwave $(TB_DIR)/*.vcd

clean:

	rm -rf $(APP) obj/*.o $(TB_DIR)/*.vcd

