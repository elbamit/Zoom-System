#ifndef HW5_LAZY_STUDENT_H
#define HW5_LAZY_STUDENT_H
#include "Student.h"
//#include "Room.h"
class Lazy_Student : public Student{

public:
    Lazy_Student(string fname, string lname, string id, double avg): Student(fname, lname, id, avg){};
    virtual ~Lazy_Student(){};
    virtual void set_room_num(int new_room);

    virtual void print_working() {};
    virtual string Prepare_message(string const message) ;

    virtual void Insert_to_lazy(Room* after_room, Room* before_room);
    virtual void Insert_to_worker(Room* after_room, Room* before_room);


};


#endif //HW5_LAZY_STUDENT_H
