// Including user defined header file
#include "files.h"

// Class Declaration

//// Class for defining common vriables
//class common
//{
//    protected:
//    
//        // Input file variables
//    char ROOM_FILE[20] = "Rooms.out";
//    char ROLLNO_FILE[20] = "RollNo.out";
//    char SEATPLAN_FILE[20] = "SeatPlan.out";
//    //string room_file = "Rooms.out";
//    //string rollno_file = "RollNo.out";
//    
//    // Defining array size
//    const int MAX_SIZE = 200;
//    const int MIN_SIZE = 50;

//    // fstream variables
//    ifstream infile;    // For reading contents of file
//    ofstream outfile;   // For writing contents into file
//    
//    // for looping variables
//    int i, j, k;
//    
//    public:
//    
//    void common_vars();
//};

// Class Room declaration for getting room details
class Room// : public common
{
    protected:
    
    // Room variables
    string room_no[MIN_SIZE];
    int rows[MIN_SIZE], cols[MIN_SIZE], total_rooms;
    
    public:
    
    // For getting room details
    void Room_details();
};

// Class RollNo declaration for getting roll no details
class RollNo //: public Room
{
    protected:
    
    //Roll No variables
    int total_branches, rollno[MIN_SIZE][MAX_SIZE], total_rollno[MIN_SIZE],
        total_subjects[MIN_SIZE];
    string branch_name[MIN_SIZE], subjects[MIN_SIZE][MIN_SIZE];
    
    public:
    
    // For getting roll no details
    void RollNo_details();
};

class Exam// : public RollNo
{
    protected:
    
    // Variables for exam details.
    string examName, examTime, examDate, examVenue;
    
    public:
    
    void Exam_details();
    void Exam_show_details();
};

// Class SeatPlan for sitting plan
class SeatPlan : public Room, public RollNo, public Exam
{
    protected:
    
    int row, col, nxt_room, nxt_branch, x, y, n, sum, count[MIN_SIZE],
        seat_array[MIN_SIZE][MAX_SIZE], total_seat[MIN_SIZE],
        total_array[MIN_SIZE], set_seat[MIN_SIZE][MIN_SIZE][MAX_SIZE],
        start_rno[MIN_SIZE], end_rno[MIN_SIZE], max_rno;//[MIN_SIZE];
    
    public:
    
    // Getting room and roll no details
    SeatPlan();
    void get_details();
    void show_details();
    void set_room();
    void set_seatarray();
    void seat_plan();
    void display_plan();
    string branch(int);
    void count_rollno();
    void valid();
    
};
