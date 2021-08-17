#include <iostream>
#include "Student.h"
#include "Lazy_Student.h"
#include "Responsible_Student.h"
#include "Worker_Student.h"
#include "Room.h"
#include "Lazy_Room.h"
#include "Worker_Room.h"
#include "ZoomSys.h"



//    int main() {

//    Student* ido = new Student("ido", "hersko", "1", 45);
//    cout << "simple print: \n" << *ido << endl;
//
//    cout << "details print: "<<endl;
//    ido->Print_Student_Details();
//
//    ido->set_room_num(32);
////    ido->Add_Message("elbaz a gever");
//
//    cout << "details print number 2:  "<<endl;
//    ido->Print_Student_Details();

//    Lazy_Student* amit = new Lazy_Student("amit", "elbaz", "1", 99);
//    amit->set_room_num(4);
//    cout << "amit det" <<endl;
//    cout << *amit<< endl;

//    Responsible_Student* ido = new Responsible_Student("ido", "king", "2", 90);
//    string  mess = "hello kapara";

//    Worker_Student* shaked = new Worker_Student("shaked", "queen", "3", 89);

//    string x = ido->Prepare_message(mess);
//    Lazy_Room* l_room = new Lazy_Room();
//    if (l_room == nullptr)
//    {
//        cout << "l_room = null"<< endl;
//    }
//    Room* room1 = new Room();
//    room1->Split_room('1');
//    cout<<room1->Get_room_ID()<<endl;
//    room1->Add_student(shaked);
//    room1->Add_student(amit);
//    room1->Add_student(ido);
//    room1->Split_room('1');
//    room1->Set_left_room(new Lazy_Room());
//    room1->Set_right_room(new Worker_Room());

//    cout << room1->Get_left_room()->Get_room_ID()<<endl;
//    cout << room1->Get_right_room()->Get_room_ID()<<endl;
//    cout << room1->Get_left_room()->Get_papa_room()->Get_room_ID()<<endl;
//    cout << room1->Get_right_room()->Get_papa_room()->Get_room_ID()<<endl;

//    amit->Insert_to_lazy(*(room1->Get_left_room()), *(room1));
//    room1->Print_stud();
//    cout<<"-_-"<<endl;
//    room1->Get_left_room()->Print_stud();
//    Worker_Room* w_room = new Worker_Room();
//    vector<Student*> temp_v = room1->Get_vector_copy();
//    vector<Student*>::iterator it;
//    for (it = temp_v.begin(); it != temp_v.end(); it++)
//    {
//
//            cout<<(*it)->Get_ID()<<endl;
//            room1->Get_right_room()->Move_student((*it));
//            room1->Get_left_room()->Move_student((*it));
//
//
//    }
//
//    room1->Get_right_room()->Move_student(*shaked);
//    room1->Get_right_room()->Move_student(*amit);
//    room1->Get_right_room()->Move_student(*ido);
//
//    room1->Get_left_room()->Move_student(*shaked);
//    room1->Get_left_room()->Move_student(*amit);
//    room1->Get_left_room()->Move_student(*ido);
//
//    cout<<"rightroom"<<endl;
//    room1->Get_right_room()->Print_stud();
//    cout<<"leftroom"<<endl;
//    room1->Get_left_room()->Print_stud();
//    cout<<"room1"<<endl;
//    room1->Print_stud();
//    l_room->Move_student(*ido);
//    cout << l_room->Get_room_ID() << endl;
//    l_room->Print_stud();
//
//    cout << x << endl;
//
//    if(amit->Get_ID() == "2p")
//        cout<<"gooooooo"<<endl;
//
//    Room* room1 = new Room();
//    room1->Split_room();
//    int roomid = room1->Get_room_ID();
//
//    v.push_back(amit);
//
//    room1->Print_stud();
//    Room* room2 = room1->Get_left_room();
//    Room* room3 = room1->Get_right_room();
//
//    room1->Add_student(amit);
//    room1->Add_student(ido);
//    room1->Add_student(shaked);

//    ZoomSys* sys1 = new ZoomSys("input");
//    sys1->Add_student(amit->Get_First_Name(), amit->Get_Last_Name(), amit->Get_ID(), amit->Get_Average(),'L');
//    sys1->Add_student(ido->Get_First_Name(), ido->Get_Last_Name(), ido->Get_ID(), ido->Get_Average(),'R');
//    sys1->Add_student(shaked->Get_First_Name(), shaked->Get_Last_Name(), shaked->Get_ID(), shaked->Get_Average(),'W');

//    sys1->addStudent();
//    sys1->Print_students();
//    sys1->assignStudent();

//    sys1->removeStudent();
//    sys1->Print_students();
//    sys1->Add_room();//0
//    sys1->Add_room();//1
//    sys1->Add_room();//2
//    sys1->Assign_student("1", 1);
//    sys1->Assign_student("2", 1);
//    sys1->Assign_student("3", 1);
//    sys1->Split_given_room(1);
//    sys1->Split_given_room(3);
//    sys1->Split_given_room(4);
//    sys1->Print_sys();
//    cout<<"---------"<<endl;
//    sys1->Work(1);
//    sys1->Remove_room_from_sys(1);


//    sys1->Assign_student("2", 2);
//    cout<<room1->Get_left_room()->Get_room_ID()<<endl;
//    cout<<room1->Get_right_room()->Get_room_ID()<<endl;
//    sys1->Split_given_room(1);

//    cout<<room1->Get_left_room()->Get_room_ID()<<endl;
//    cout<<room1->Get_right_room()->Get_room_ID()<<endl;
//    sys1->Print_sys();
//    sys1->Print_students();





//    cout << 5/2 << endl;


//    room1->Print_room();
//    room1->Delete_room();

//    map<string, Student*> mymap;
//    mymap["amit"] = amit;
//    mymap["ido"] = ido;
//    mymap["shaked"] = shaked;
//    map<int, Room*> mymap1;
//    mymap1[1] = room1;
//    map<int, Room*>:: iterator it;
//    it = mymap1.find(1);
//    it->second->Remove_student("2");
//    it->second->Print_stud();
//    cout<<"------"<<endl;
//    room1->Print_stud();


//    delete sys1;
//    delete(amit);
//    delete(ido);
//    delete(shaked);





//    room1.Remove_student("1");
//    room1.Remove_student("2");
//    room1.Remove_student("3");

//    room1.Split_room();
//    Room* room3 = room1.Get_right_room();

//    room2.Add_student(amit);



//    room1.Remove_student("1");
//    room1.Remove_student("2");
//    room1.Remove_student("3");


//    room1.Print_stud();


//    amit.set_room_num(-1);
//    cout << "22222" << endl;
//    cout <<amit<< endl;
//    delete ido;




//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}



//#include "ZoomSys.h"
int main(int argc, char*argv[]) {
//    ZoomSys* zoomSys = new ZoomSys("/home/ise/Desktop/Advanced programming/Homeworks/HW5/input.txt");
    ZoomSys* zoomSys = new ZoomSys(argv[1]);
    char menuOption;
    while(menuOption!='0')
    {
        cout<< "1. Add Student" << endl;
        cout<< "2. Remove Student" << endl;
        cout<< "3. Assign Student" << endl;
        cout<< "4. Add Room" << endl;
        cout<< "5. Split Room" << endl;
        cout<< "6. Remove Room" << endl;
        cout<< "7. Work" << endl;
        cout<< "8. Send Message" << endl;
        cout<< "9. Print Rooms" << endl;
        cout<< "p. Print Students" << endl;
        cout<< "d. Print Student details" << endl;
        cout<< "0. Exit" << endl;
        cin >> menuOption;
        switch(menuOption){
            case '1':
                zoomSys->addStudent();
                break;
            case '2':
                zoomSys->removeStudent();
                break;
            case '3':
                zoomSys->assignStudent();
                break;
            case '4':
                zoomSys->addRoom();
                break;
            case '5':
                zoomSys->splitRoom();
                break;
            case '6':
                zoomSys->removeRoom();
                break;
            case '7':
                zoomSys->work();
                break;
            case '8':
                zoomSys->sendMessage();
                break;
            case '9':
                zoomSys->printRooms();
                break;
            case 'p':
                zoomSys->printStudents();
                break;
            case 'd':
                zoomSys->printStudentDetails();
                break;
            case '0':
                cout<<"Bye.."<<endl;
                delete zoomSys;
                break;
        }
    }

    return 0;
}
