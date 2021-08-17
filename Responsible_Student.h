#ifndef HW5_RESPONSIBLE_STUDENT_H
#define HW5_RESPONSIBLE_STUDENT_H
#include "Student.h"

class Responsible_Student : public Student {

public:
    Responsible_Student(string fname, string lname, string id, double avg): Student(fname, lname, id, avg){};
    virtual ~Responsible_Student(){};


    virtual string Prepare_message(string const message);
    virtual void print_working(){};


    virtual void Insert_to_lazy(Room* after_room, Room* before_room);
    virtual void Insert_to_worker(Room* after_room, Room* before_room);

};


#endif //HW5_RESPONSIBLE_STUDENT_H
