LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc

TB_DIR=testbench

APP=counter



all: main.o counter_4bit.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) obj/main.o obj/counter_4bit.o



counter_4bit.o: src/counter_4bit.cpp inc/counter_4bit.h

	 g++ $(INC_DIR) -c src/counter_4bit.cpp
	mv counter_4bit.o obj/



main.o: src/main.cpp src/counter_4bit.cpp inc/counter_4bit.h

	 g++ $(INC_DIR) -c src/main.cpp
	mv main.o obj/

testbench: $(APP) 
	./$(APP)
	mv *.vcd $(TB_DIR) ; gtkwave $(TB_DIR)/*.vcd

clean:

	rm -rf $(APP) obj/*.o $(TB_DIR)/*.vcd

