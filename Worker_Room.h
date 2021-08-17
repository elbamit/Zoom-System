#ifndef HW5_WORKER_ROOM_H
#define HW5_WORKER_ROOM_H
#include "Room.h"

class Worker_Room : public Room{
public:
    Worker_Room():Room(){};
    virtual ~Worker_Room();

    virtual void Move_student(Student* s);
};

#endif //HW5_WORKER_ROOM_H
