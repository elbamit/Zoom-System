#ifndef HW5_ZOOMSYS_H
#define HW5_ZOOMSYS_H
#include <string.h>
#include <stdio.h>
#include "Responsible_Student.h"
#include "Worker_Student.h"
#include "Lazy_Student.h"
#include "Room.h"
#include "Error.h"
#include <fstream>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


class ZoomSys {

private:
    vector<Student*> vec_students;
    map<int, Room*> map_rooms;

public:
    ZoomSys(string path_to_file);
    ~ZoomSys();

    void addStudent();
    void addStudent_param(string fname, string lname, string id, double avg,  char type_of_stud);

    void removeStudent();
    bool removeStudent_param(string id);

    void assignStudent();
    bool assignStudent_param(string stud_id, int room_id);

    void addRoom();

    void splitRoom();
    void splitRoom_param(int room_id);

    void removeRoom();
    void removeRoom_param(int room_id);

    void work();
    void work_param(int room_id);

    void sendMessage();

    void printRooms();

    void printStudents();

    void printStudentDetails();



    //Helper functions
    vector<int> find_rooms_to_delete(Room* start_room, vector<int> vector_of_index);
    Student* find_student(string stud_id);
    int find_student_pos(string stud_id);
    Room* find_room(int room_id);

};


#endif //HW5_ZOOMSYS_H
