#include "Room.h"
#include "Student.h"
#include "Lazy_Room.h"
#include "Worker_Room.h"

int Room::rooms_number = 0;

//Constructor
Room::Room()
{
    this->ID_room = rooms_number;
    this->rooms_number++;
    this->Has_been_splited = false;
    this->Papa_room = nullptr;
    this->Left_room = nullptr;
    this->Right_room = nullptr;
}

//Destructor
Room::~Room()
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

//Adds a student to a room, update the room_num of the students.
void Room::Add_student(Student* student)
{
    this->vector_of_Students.push_back(student);
    student->set_room_num(this->ID_room);
}

//Adds a student to a room without making him cry, update the room_num of the students.
void Room::Add_student_no_cry(Student* student)
{
    this->vector_of_Students.push_back(student);
    student->Student::set_room_num(this->ID_room);
}


//Remove a student and returns it (like POP in a stack)
Student* Room::Remove_student(string id_to_remove)
{
    vector<Student*>::iterator it;
    for(it = this->vector_of_Students.begin(); it != this->vector_of_Students.end(); it++)
    {
        if((*it)->Get_ID() == id_to_remove)
        {
            //Set the student's room number to the lobby
            (*it)->set_room_num(-1);

            //Erases the student from the vector of student of the room
            this->vector_of_Students.erase(it);
            return (*it);
        }
    }
    return nullptr;
}

//Removes a student without making lazy ones cry and returns him
Student* Room::Remove_student_no_cry(string id_to_remove)
{
    vector<Student*>::iterator it;
    for(it = this->vector_of_Students.begin(); it != this->vector_of_Students.end(); it++)
    {
        if((*it)->Get_ID() == id_to_remove)
        {
            //Set the student's room number to the lobby (whithout making him cry)
            (*it)->Student::set_room_num(-1);

            //Erases the student from the vector of student of the room
            this->vector_of_Students.erase(it);
            return (*it);
        }
    }
    return nullptr;
}

//Splits a room into 2 rooms
void Room::Split_room(char option)
{
    //Character split
    if (option == '1')
    {
        //Creates matching rooms
        Room* left_room = new Worker_Room();
        Room* right_room = new Lazy_Room();

        //Updates the pointers of son and fathers
        this->Right_room = right_room;
        this->Left_room = left_room;

        right_room->Papa_room = this;
        left_room->Papa_room = this;

        this->Has_been_splited = true;
    }

    //Size split
    if (option == '2')
    {
        //Creates 2 new regular rooms
        Room* left_room = new Room();
        Room* right_room = new Room();

        //Updates the pointers of son and fathers
        this->Right_room = right_room;
        this->Left_room = left_room;

        right_room->Papa_room = this;
        left_room->Papa_room = this;

        this->Has_been_splited = true;
    }

}


//Function that deletes a room and moves the students to the correct rooms/lobby
void Room::Delete_room()
{
    //If room has no childrens
    if (this->Left_room == nullptr && this->Right_room == nullptr)
    {
        //If room has no father and no childrens
        if (this->Papa_room == nullptr)
        {
            vector<Student*>::iterator it;
            vector<Student*> copy_v = this->Get_vector_copy();
            int student_counter = 0;

            //Sets every student's room to -1 (lobby)
            for(it = copy_v.begin(); it != copy_v.end(); it++)
            {
                this->Remove_student((*it)->Get_ID());
            student_counter++;
            }
        }
        //Room has a father and no childrens
        else
        {
            vector<Student*>::iterator it;
            vector<Student*> copy_v = this->Get_vector_copy();
            //Sets every student's room to father's room numb
            for(it = copy_v.begin(); it != copy_v.end(); it++)
            {
                if ((*it) == nullptr)
                {
                    break;
                }
                this->Get_papa_room()->Add_student(this->vector_of_Students[0]);
                this->vector_of_Students.erase(this->vector_of_Students.begin());

            }

        }
        delete (this);
        return;
    }

    //Room has a left child but no right child
    else if (this->Right_room == nullptr)
    {
        this->Left_room->Delete_room();
        this->Left_room = nullptr;

        //Disconnects the Father pointer from the son
        if (this->Get_papa_room() != nullptr)
        {
            Room* my_papa = this->Get_papa_room();
            if (my_papa->Get_left_room() == this)
            {
                my_papa->Left_room = nullptr;
            }
            else
            {
                my_papa->Right_room = nullptr;
            }
        }
        this->Delete_room();
    }

    //Room has a right child but no left child
    else if (this->Left_room == nullptr)
    {
        this->Right_room->Delete_room();
        this->Right_room = nullptr;

        //Disconnects the papa pointer from the son
        if (this->Get_papa_room() != nullptr)
        {
            Room* my_papa = this->Get_papa_room();
            if (my_papa->Get_left_room() == this)
            {
                my_papa->Left_room = nullptr;
            }
            else
            {
                my_papa->Right_room = nullptr;
            }
        }

        this->Delete_room();
    }

    //Room has right and left children
    else
    {
        this->Left_room->Delete_room();
        this->Left_room = nullptr;
        this->Right_room->Delete_room();
        this->Right_room = nullptr;

        //Disconnects the papa pointer from the son
        if (this->Get_papa_room() != nullptr)
        {
            Room* my_papa = this->Get_papa_room();
            if (my_papa->Get_left_room() == this)
            {
                my_papa->Left_room = nullptr;
            }
            else
            {
                my_papa->Right_room = nullptr;
            }
        }
        this->Delete_room();
    }

}

//Operator overloading - "="
Room& Room::operator= (Room& room)
{
    this->ID_room = room.ID_room;
    this->Has_been_splited = room.Has_been_splited;
    this->Papa_room = room.Papa_room;
    this->Left_room = room.Left_room;
    this->Right_room = room.Right_room;

    for (int i = 0; i < room.vector_of_Students.size() ; ++i) {
        this->vector_of_Students.push_back(room.vector_of_Students[i]);
    }
    return *this;

}


//Function that prints the room id and the number of students inside the room
void Room::Print_room() const
{
    cout << "room id:" << this->ID_room << ", students:" << this->Get_num_of_students() << endl;
}




//HELPER FUNCTIONS

//Helper function that returns the number of students in the room
int Room::Get_num_of_students() const
{
    return this->vector_of_Students.size();
}

//Helper function that returns a pointer to the left room
Room* Room::Get_left_room()
{
    return this->Left_room;
}

//Helper function that returns a pointer to the right room
Room* Room::Get_right_room()
{
    return this->Right_room;
}

//Helper function that returns a pointer to the father room
Room* Room::Get_papa_room()
{
    return this->Papa_room;
}



//Getter for the room ID
int Room::Get_room_ID()
{
    return this->ID_room;
}



//Returns a boolean value depending if room has been splited or not
bool Room::Get_split_situation()
{
    if (this->Has_been_splited == 0)
    {
        return false;
    }

    else
        return true;
}


//Function that returns a copy of the vector of student (so it can't be changed from outside)
vector<Student*> Room::Get_vector_copy()
{
    return (this->vector_of_Students);
}