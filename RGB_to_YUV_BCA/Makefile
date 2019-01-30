LIB_DIR=-L/usr/systemC/lib-linux64

INC_DIR=-I/usr/systemC/include

LIB=-lsystemc



APP=rgb_to_yuv



all: rgb_to_yuv.o testbench.o main.o

	g++ -o $(APP) $(LIB_DIR) $(LIB) rgb_to_yuv.o testbench.o main.o



rgb_to_yuv.o:rgb_to_yuv.cpp rgb_to_yuv.h  class.h

	g++ $(INC_DIR) -c rgb_to_yuv.cpp

testbench.o:testbench.cpp testbench.h class.h

	g++ $(INC_DIR) -c testbench.cpp

main.o:main.cpp class.h testbench.h rgb_to_yuv.h
	
	g++ $(INC_DIR) -c main.cpp

clean:

	rm -rf $(APP) *.o

