#ifndef HW5_LAZY_ROOM_H
#define HW5_LAZY_ROOM_H
#include "Room.h"

class Lazy_Room : public Room{
public:
    Lazy_Room():Room(){};
    virtual ~Lazy_Room();


    virtual void Move_student(Student* s);
};


#endif //HW5_LAZY_ROOM_H
