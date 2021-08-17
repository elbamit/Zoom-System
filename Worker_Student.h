#ifndef HW5_WORKER_STUDENT_H
#define HW5_WORKER_STUDENT_H
#include "Student.h"



class Worker_Student : public Student{

public:
    Worker_Student(string fname, string lname, string id, double avg): Student(fname, lname, id, avg){};
    virtual ~Worker_Student(){};


    virtual void print_working();
    virtual string Prepare_message(string const message);


    virtual void Insert_to_lazy(Room* after_room, Room* before_room);
    virtual void Insert_to_worker(Room* after_room, Room* before_room);
};


#endif //HW5_WORKER_STUDENT_H
