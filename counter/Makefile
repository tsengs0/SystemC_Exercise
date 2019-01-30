LIB_DIR=-L/usr/local/systemc-2.3.2/lib-linux64

INC_DIR=-I/usr/local/systemc-2.3.2/include

LIB=-lsystemc -lm

#g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o hello hello.cpp -lsystemc -lm
#g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux -o out sample.cpp -lsystemc -lm




APP=counter



all: main.o counter.o

	 g++ -o $(APP) $(LIB_DIR) $(LIB) main.o counter.o



counter.o: counter.cpp counter.h

	 g++ $(INC_DIR) $(LIB_DIR) counter.cpp $(LIB)



main.o: main.cpp counter.h

	 g++ $(INC_DIR) $(LIB_DIR) main.cpp $(LIB)



clean:

	rm -rf $(APP) *.o

