#include "Responsible_Student.h"
#include "Room.h"

//Function that prepares the official format for a given message
string Responsible_Student :: Prepare_message(string const message)
{
    return this->Get_First_Name() + " " + this->Get_Last_Name() + ":" + message;
}

void Responsible_Student::Insert_to_worker(Room* after_room, Room* before_room) {}

void Responsible_Student::Insert_to_lazy(Room* after_room, Room* before_room) {}