#ifndef HW5_STUDENT_H
#define HW5_STUDENT_H
#include <string.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include"Error.h"
using namespace std;

class Room;
class Student {
private:
    string first_name;
    string last_name;
    string ID;
    double average;
    int room_num;


protected:
    vector<string> message_vec;

public:
    Student(string fname, string lname, string id, double avg);
    virtual ~Student();
    virtual void set_room_num(int new_room);
    friend ostream& operator<<(ostream& out, const Student& stud);
    void Print_Student_Details()const;

    string Get_First_Name() const {return this->first_name;};
    string Get_Last_Name() const {return this->last_name;};
    string Get_ID() const {return this->ID;};
    int Get_Room_Num()const {return this->room_num;};

    void Add_Message(string const message);
    virtual void print_working() = 0;
    virtual string Prepare_message(string const message) = 0;

    Student& operator= (const Student& student);

    virtual void Insert_to_lazy(Room* after_room, Room* before_room) = 0;
    virtual void Insert_to_worker(Room* after_room, Room* before_room) = 0;

};


#endif //HW5_STUDENT_H
