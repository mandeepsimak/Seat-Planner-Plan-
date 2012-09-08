// Including user defined header file
#include "files.h"

// Class Declaration

// Class Room declaration for getting room details
class Room
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
class RollNo
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

class Exam
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
