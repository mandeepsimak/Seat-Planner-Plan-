// Include header.h file
#include "header.h"

// Input file variables
char ROOM_FILE[20] = "Rooms.out";
char ROLLNO_FILE[20] = "RollNo.out";
char SEATPLAN_FILE[20] = "SeatPlan.out";
//string room_file = "Rooms.out";
//string rollno_file = "RollNo.out";

// Defining array size
const int MAX_SIZE = 200;
const int MIN_SIZE = 50;

// fstream variables
ifstream infile;    // For reading contents of file
ofstream outfile;   // For writing contents into file

// for looping variables
int i, j, k;
