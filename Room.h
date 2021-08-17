#ifndef HW5_ROOM_H
#define HW5_ROOM_H
#include <string.h>
#include <stdio.h>

#include <vector>
#include <iostream>
using namespace std;

class Student;
class Room {
private:
    static int rooms_number;

    int ID_room;

    bool Has_been_splited;

    Room* Papa_room;
    Room* Left_room;
    Room* Right_room;

protected:
    vector<Student*> vector_of_Students;

public:
    Room();
    virtual ~Room();
    void Add_student(Student*  student);
    Student* Remove_student(string id_to_remove);
    void Split_room(char option);
    void Delete_room();
    void Print_room() const;
    int Get_num_of_students() const;
    Room& operator= (Room& room);
    void Add_student_no_cry(Student* student);
    Student* Remove_student_no_cry(string id_to_remove);
    Room* Get_left_room();
    Room* Get_right_room();
    Room* Get_papa_room();
    int Get_room_ID();

    bool Get_split_situation();
    virtual void Move_student(Student* s){};
    vector<Student*> Get_vector_copy();
};


#endif //HW5_ROOM_H
