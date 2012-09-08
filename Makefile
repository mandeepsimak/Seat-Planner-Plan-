SEAT = SeatPlan-Main.o SeatPlan.o		                       		# target
CC = g++									# compiler variable
DEBUG = -g									# debugging flag 
CFLAGS = -Wall -c $(DEBUG)							# linking flag
LFLAGS = -Wall $(DEBUG)					  	  # flag used in compiling and creating object files	

# All targets 
all: seat run_seat

# target to generate executable file.

#input: $(INPUT)
#	$(CC) $(LFLAGS) $(INPUT) -o input

seat: $(SEAT)
	$(CC) $(LFLAGS) $(SEAT) -o SeatPlan

# target to run executable file
#run_input: 
#	./input

run_seat:
	./SeatPlan

# dependencies of seat_main.cpp
#input_main.o: input_main.cpp input.h
#	$(CC) $(CFLAGS) input_main.cpp

# dependencies of seat_main.cpp
#input.o: input.cpp input.h
#	$(CC) $(CFLAGS) input.cpp

# dependencies of seat_main.cpp
SeatPlam-Main.o: SeatPlan-Main.cpp SeatPlan.h files.h header.h
	$(CC) $(CFLAGS) SeatPlan-Main.cpp

# dependencies of seat_functions.cpp
SeatPlan.o: SeatPlan.cpp SeatPlan.h files.h header.h
	$(CC) $(CFLAGS) SeatPlan.cpp 

# to destroy all the object and exectuable file
clean:
	rm -f *.o SeatPlan SeatPlan.out

# to create tar file 	
tar:
	tar cfv seat.tar input_main.o input.o seat_main.o seat_functions.o
