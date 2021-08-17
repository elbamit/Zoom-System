#include "Worker_Student.h"
#include "Room.h"

void Worker_Student::print_working()
{
    cout << this->Get_First_Name() << " " << this->Get_Last_Name() <<" is working"<<endl;
    return;
}


void Worker_Student::Insert_to_lazy(Room* after_room, Room* before_room) {}

//Function that adds students to a room using Polymorphysm principles
void Worker_Student::Insert_to_worker(Room* after_room, Room* before_room)
{
    before_room->Remove_student(this->Get_ID());
    after_room->Add_student(this);

}

string Worker_Student::Prepare_message(string const message)
{
    throw student_permissions();
}