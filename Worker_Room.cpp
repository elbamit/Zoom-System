#include "Worker_Room.h"
#include "Student.h"


//Destructor
Worker_Room::~Worker_Room()
{
    if(this->vector_of_Students.size() > 0)
    {
        //Iterates through every student and moves them to loby
        vector<Student*>::iterator it;
        for (it = this->vector_of_Students.begin(); it != this->vector_of_Students.end(); it++)
        {
            this->Remove_student((*it)->Get_ID());
        }

        this->vector_of_Students.clear();
    }
}


//Function that adds students to a room using Polymorphysm principles
void Worker_Room::Move_student(Student* s)
{
    s->Insert_to_worker(this, this->Get_papa_room());
}