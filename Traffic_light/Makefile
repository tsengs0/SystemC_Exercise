LIB_DIR=-L/usr/systemc/lib64-linux64

INC_DIR=-I/usr/systemc/include

LIB=-lsystemc



APP=light



all: main.o light.o fsm.o

	g++ -o $(APP) $(LIB_DIR) $(LIB) main.o light.o fsm.o



light.o: light.cpp light.h

	g++ $(INC_DIR) -c light.cpp

fsm.o: fsm.cpp fsm.h
	
	g++ $(INC_DIR) -c fsm.cpp


main.o: main.cpp light.h fsm.h 

	g++ $(INC_DIR) -c main.cpp



clean:

	rm -rf $(APP) *.o

