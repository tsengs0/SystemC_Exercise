LIB_DIR=-L/usr/systemc/lib64-linux64

INC_DIR=-I/usr/systemc/include

LIB=-lsystemc



APP=rgb_to_yuv



all: rgb_to_yuv.o testbench.o main.o

	g++ -o $(APP) $(LIB_DIR) $(LIB) rgb_to_yuv.o testbench.o main.o



rgb_to_yuv.o:/home/tsengs0/C_program/SystemC/RGB_to_YUV/src/rgb_to_yuv.cpp /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/rgb_to_yuv.h  /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/class.h

	g++ $(INC_DIR) -c /home/tsengs0/C_program/SystemC/RGB_to_YUV/src/rgb_to_yuv.cpp

testbench.o:/home/tsengs0/C_program/SystemC/RGB_to_YUV/src/testbench.cpp /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/testbench.h /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/class.h

	g++ $(INC_DIR) -c /home/tsengs0/C_program/SystemC/RGB_to_YUV/src/testbench.cpp

main.o:/home/tsengs0/C_program/SystemC/RGB_to_YUV/src/main.cpp /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/class.h /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/testbench.h /home/tsengs0/C_program/SystemC/RGB_to_YUV/inc/rgb_to_yuv.h
	
	g++ $(INC_DIR) -c /home/tsengs0/C_program/SystemC/RGB_to_YUV/src/main.cpp

clean:

	rm -rf $(APP) *.o

