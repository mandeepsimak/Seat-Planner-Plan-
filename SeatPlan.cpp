// Include SeatPlan.h(contains class declaration)
#include "SeatPlan.h"

// Function Definition

//void common :: common_vars()
//{
//    // Input file variables
//    ROOM_FILE = "Rooms.out";
//    ROLLNO_FILE = "RollNo.out";
//    SEATPLAN_FILE = "SeatPlan.out";
//    //string room_file = "Rooms.out";
//    //string rollno_file = "RollNo.out";
//    
//    // Defining array size
//    MAX_SIZE = 200;
//    MIN_SIZE = 50;

//}

// Room :: Room_details fun. definition
void Room :: Room_details()
{
    infile.open(ROOM_FILE); // Opening Rooms.out file
    infile>>total_rooms;
    getline(infile, room_no[0], '\n');
    for(i=0; i<total_rooms; i++)
    {
        getline(infile, room_no[i], '\n');
        infile>>rows[i]>>cols[i];
    }
    infile.close(); // Closing file
}

// RollNo :: RollNo_details fun. definition
void RollNo :: RollNo_details()
{
    infile.open(ROLLNO_FILE);   // Opening RollNo.out file
    infile>>total_branches;
    //getline(infile, branch_name[0], '\n');
    for(i=0; i<total_branches; i++)
    {
        getline(infile, branch_name[i], '\n');
        infile>>total_subjects[i];
        for(j=0; j<total_subjects[i]; j++)
            getline(infile, subjects[i][j], '\n');
        infile>>total_rollno[i];
        for(j=0; j<total_rollno[i]; j++)
            infile>>rollno[i][j];
    }
    infile.close(); // Closing file
}

// Exam :: Exam_details func. definition
void Exam :: Exam_details()
{
    //getline(cin, examName, '\n');
    cout<<"\n Enter name of examination: ";
    getline(cin, examName, '\n');
    cout<<"\n Enter date of examination: ";
    getline(cin, examDate, '\n');
    cout<<"\n Enter time of examination: ";
    getline(cin, examTime, '\n');
    cout<<"\n Enter venue of examination: ";
    getline(cin, examVenue, '\n');
}

// Exam :: Exam_show_details func. definition
void Exam :: Exam_show_details()
{
    cout<<examName<<endl
        <<"Date: "<<examDate<<endl
        <<"Time: "<<examTime<<endl
        <<"Place:"<<examVenue<<endl;
}

// Constructor of SeatPlan
SeatPlan :: SeatPlan()
{
    n  = 0;
    nxt_room = 0;
    nxt_branch = 0;
    //max_rno = 0;
    sum = 0;
    max_rno= 0;
    
    for(i = 0; i < 4; i++)
    {
        total_array[i] = 0;
        total_seat[i] = 0;
    }
    for(i = 0; i < total_branches; i++)
    {
        start_rno[i] = 37657;
        end_rno[i] = 0;
    }
}

// SeatPlan :: get_details fun. declaration
void SeatPlan :: get_details()
{
    Room_details(); // Getting room details
    RollNo_details();   // Getting roll no details
    Exam_details(); // Getting exam details
}

// SeatPlan ::show_details fun definition
void SeatPlan :: show_details()
{
    cout<<total_rooms<<endl;
    for(i=0; i<total_rooms; i++)
    {
        cout<<room_no[i]<<'\t';
        cout<<rows[i]<<cols[i]<<endl;
    }
    cout<<total_branches<<'\t';
    for(i=0; i<total_branches; i++)
    {
        cout<<branch_name[i]<<'\t';
        cout<<total_subjects[i];
        for(j=0; j<total_subjects[i]; j++)
            cout<<subjects[i][j]<<'\n';
        cout<<total_rollno[i]<<'\t'<<endl;
        for(j=0; j<total_rollno[i]; j++)
            cout<<rollno[i][j]<<'\t';
        cout<<'\n';
    }
}

// Set room no for allotting
void SeatPlan :: set_room()
{
    if(nxt_room<total_rooms)
    {
        row = rows[nxt_room];   // Rows of room
        col = cols[nxt_room];   // Columns of room
        //exam_room = room_no[nxt_room];  // Room name
        nxt_room++; // Next room
    }
}

// For Setting seat_array with roll nos.
void SeatPlan :: set_seatarray()
{
    if(nxt_branch == 0)
    {
        for(i = 0; i < 4; i++)
        {
            for(j = 0; j < total_rollno[nxt_branch]; j++)
                seat_array[i][j] = rollno[nxt_branch][j];
             total_seat[i] = total_rollno[nxt_branch];
             nxt_branch++;
        }
    }
    else if(nxt_branch < total_branches)
    {
        for(i = 0; i < 4; i++)
        {
            if(total_array[i] >= total_seat[i])
            {
                for(j = 0; j < total_rollno[nxt_branch]; j++)
                    seat_array[i][j] = rollno[nxt_branch][j];
                 total_seat[i] = total_rollno[nxt_branch];
                 nxt_branch++;
            }
        }
    }
    else
    {
        for(i = 0; i < 4; i++)
        {
            if(total_array[i] >= total_seat[i])
            {
                total_array[i] = 0;
                total_seat[i] = 0;
                seat_array[i][total_array[i]] = 0;
            }
        }
    }
    
    /*for(i = 0; i < 4; i++)
    {
        for(j = 0; j < total_rollno[i]; j++)
            cout<<seat_array[i][j]<<"\t";// = rollno[nxt_branch][j];
        cout<<"\n";
    }*/
    //cout<<"seat2";
}

// Seat Allotment
void SeatPlan :: seat_plan()
{
//    cout<<"seat1";
    set_seatarray();
    //set_room();
    
    for(int rooms = 0; rooms < total_rooms; rooms++)
    {
        set_room();
//        cout<<"seat";
        for(x = 0; x < col; x++)
        {
            for(y = 0; y < row; y++)
            {
                //set_seatarray();
                
                if(n < 4 && n >= 0)
                {
                    set_seat[rooms][y][x] = seat_array[n][total_array[n]];
                    total_array[n]++;
                    n++;
                }
            }
            if(n >= 4 || n < 0)
            {
                n = 0;
            }
        }
    }
    
    /*for(k = 0; k < total_rooms; k++)
    {
        cout<<"Room No: "<<room_no[k]<<endl;
        
        for(x=0; x<rows[k]; x++)
        {
            for(y=0; y<cols[k]; y++)
            {
                cout<<branch(set_seat[k][y][x])<<set_seat[k][y][x]<<"\t";
            }
            cout<<'\n';
        }
    }*/
    
}

// Display seat plan
void SeatPlan :: display_plan()
{
    outfile.open(SEATPLAN_FILE);
    
    for(k = 0; k < total_rooms; k++)
    {
        count_rollno();
        Exam_show_details();
        
        outfile<<"Room No: "<<room_no[k]<<"\n"<<endl;
        
        for(x=0; x<rows[k]; x++)
        {
            for(y=0; y<cols[k]; y++)
            {
                outfile<<branch(set_seat[k][x][y])<<set_seat[k][x][y]<<"\t";
            }
            outfile<<'\n';
        }
        outfile<<'\n';
        //for(k=0; k<total_branches; i++)
        {
            if(count[k] != 0)
                outfile<<branch_name[k]<<" : ";
        
            if(start_rno[k] != 37657 && end_rno[k] != 0)
                outfile<<"{"<<start_rno[k]<<" to "<<end_rno[k]<<"}";
        
            if(count[k] != 0)
                outfile<<" = "<<count[k]<<"\n"<<endl;
        }
    
        outfile<<"\nTotal: "<<sum<<"\n\n";
    }
    
    
    outfile.close();
}

// Return name of branch
string SeatPlan :: branch(int rno)
{
    string brnch;
    for(i=0; i<total_branches; i++)
    {
        for(j=0; j<total_rollno[i]; j++)
        {
            if(rno==rollno[i][j])//start_roll[i] && rno<=end_roll[i])
            {
                brnch = branch_name[i];
                brnch.append("-");
                count[i]++;// = count[i] + 1;
                sum += 1;
                if(rno < start_rno[i])
                    start_rno[i] = rno;
                if(rno > end_rno[i])
                    end_rno[i] = rno;
                break;
            }
            
        }
    }
    return brnch;
}

// Counting rollnos
void SeatPlan :: count_rollno()
{
    for(i= 0; i < total_branches; i++)
    {
        count[i]=0;
        start_rno[i] = 37657;
        end_rno[i] = 0;
        if(total_rollno[i] > max_rno)
            max_rno = total_rollno[i];
    }
}

// Validation seat plan
void SeatPlan :: valid()
{
    int students=0, seats=0;
    max_rno = 0;
    char choice;

    for(x=0; x<total_branches; x++)
    {
        students += total_rollno[x];
    }
    for(x=0; x<total_rooms; x++)
    {
        seats += (rows[x] * cols[x]);
    }

    if(students > seats)
    {
        system("clear");
        cout<<"\nThis strategy is not applicable because of less seats."
            <<endl<<"Total Seats: "<<seats<<endl
            <<"Total students: "<<students<<endl
            <<"More Seats Required: "<<(students-seats)<<endl
            <<"Please add more rooms in input file."<<endl;
    }
    else if(seats > students || seats == students)
    {
        system("clear");
        cout<<"\n Strategy - 1"
            <<endl<<"Total Seats: "<<seats<<endl
            <<"Total students: "<<students<<endl;
        int d = max_rno / 18;
        int r = max_rno % 18;
        if(d > total_rooms)
        {
            cout<<"This Strategy is not appicaple."<<endl
                <<"Rooms required for max. class rollno: "<<d<<endl
                <<"Add more rooms in input file to complete this stretegy"
                <<endl;
        }
        else
        {
            do
            {
                cout<<"\nStrategy applicable. Press 'Y' to continue."<<endl;
                cin>>choice;

                switch(choice)
                {
                    case 'Y':
                        //exam_details();
                        //report_choice();
                        seat_plan();	// Call to seat_plan() function
                        display_plan();
                        cout<<"\n Check seatplan.out file for seat plan."<<endl;
                        break;
                
                    default:
                        cout<<"\nWrong Choice"<<endl;
                        break;
                    }
            }
            while(choice != 'Y');
        }
    }
}

