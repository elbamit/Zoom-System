#include "Student.h"

//Constructor
Student::Student(string fname, string lname, string id, double avg) : first_name(fname), last_name(lname), ID(id), average(avg), room_num(-1) {}


//Destructor
Student::~Student()
{
    //Clears the vector of message before deleting the student itself
    if (this->message_vec.size() > 0)
    {
        this->message_vec.clear();
    }
}


//Setter of the room number
void Student::set_room_num(int new_room)
{
    this->room_num = new_room;
}


//Operator overloading - "<<"
ostream& operator<< (ostream& out, const Student& stud)
{
    out << stud.first_name << " " << stud.last_name << " " << stud.ID << " "<< stud.average << " " << stud.room_num << endl;
    return out;
}


//Function that Prints the student's details including all of his messages
void Student::Print_Student_Details() const
{
    cout << *this;
    cout << "---Messages---"<< endl;
    for (int i = 0; i < this->message_vec.size(); i++)
    {
        cout << this->message_vec[i]<<endl;
    }
}

//Funtion that adds a message to the vector of the student
void Student::Add_Message(string const message)
{
    this->message_vec.push_back(message);
}


//Operator overloading - "="
Student& Student::operator= ( const Student& student)
{
    this->first_name = student.first_name;
    this->last_name = student.last_name;
    this->ID = student.ID;
    this->average = student.average;
    this->room_num = student.room_num;

    return *this;

}

