#include "Lazy_Student.h"
#include "Room.h"

//Change the room num and print the crying message
void Lazy_Student ::set_room_num(int new_room)
{
    cout << this->Get_First_Name()<< " " << this->Get_Last_Name() << " is crying"<< endl;
    this->Student::set_room_num(new_room);
}

//Function that adds students to a room using Polymorphysm principles
void Lazy_Student::Insert_to_lazy(Room* after_room, Room* before_room)
{
    before_room->Remove_student_no_cry(this->Get_ID());
    after_room->Add_student(this);

}

void Lazy_Student::Insert_to_worker(Room* after_room, Room* before_room) {}


string Lazy_Student::Prepare_message(string const message)
{
    throw student_permissions();
}
