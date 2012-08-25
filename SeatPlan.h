// Including user defined header file
#include "files.h"

// Class Declaration

// Class Room declaration for getting room details
class Room
{
    protected:
    
    // Room variables
    string room_no[min_size];
    int rows[min_size], cols[min_size], total_rooms;
    
    public:
    
    // For getting room details
    void Room_details();
};

// Class RollNo declaration for getting roll no details
class RollNo
{
    protected:
    
    //Roll No variables
    int total_branches, rollno[min_size][max_size], total_rollno[min_size],
        total_subjects;
    string branch_name[min_size], subjects[min_size][min_size];
    
    public:
    
    // For getting roll no details
    void RollNo_details();
};

// Class SeatPlan for sitting plan
class SeatPlan : public Room, RollNo
{
    protected:
    
    
    public:
    
    // Getting room and roll no details
    void get_details();
};
