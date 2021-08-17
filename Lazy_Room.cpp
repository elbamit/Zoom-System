#include "Lazy_Room.h"
#include "Student.h"

Lazy_Room::~Lazy_Room()
{
    if(this->vector_of_Students.size() > 0)
    {
        //Iterates through every student and removes them from the room
        vector<Student*>::iterator it;
        for (it = this->vector_of_Students.begin(); it != this->vector_of_Students.end(); it++)
        {
            this->Remove_student((*it)->Get_ID());
        }

        this->vector_of_Students.clear();
    }
}

//Function that adds students to a room using Polymorphysm principles
void Lazy_Room::Move_student(Student* s)
{
    s->Insert_to_lazy(this, this->Get_papa_room());
}