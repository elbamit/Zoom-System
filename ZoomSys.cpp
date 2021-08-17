#include "ZoomSys.h"


//Constructor, receive the path of the file to deal with as an argument
ZoomSys::ZoomSys(string path_to_file) {

    //ifstream is a file stream class used for reading our file
    ifstream file(path_to_file);
    string line;

    //Get the next line until the end of the file is reached
    while (getline(file, line)) {
        int index_end = 0;
        string token = "";
        string myline = line;
        int i = 0;
        vector<string> args_of_stud;
        while (i < 5) {

            //If we reached the last token
            if (i == 4) {
                token = myline[0];
                args_of_stud.push_back(token);
                break;
            }
            //Find the next \t
            index_end = myline.find('\t');
            //Get the token
            token = myline.substr(0, index_end);
            //Add the token to the vector of strings
            args_of_stud.push_back(token);
            //Delete from myline(the copy of the line we're dealing with) the token we used and the \t
            myline.erase(0, index_end + 1);
            i++;
        }//Inside while closer

        //Cast
        double avg = stod(args_of_stud[3]);
        char type = args_of_stud[4][0];

        try
        {
            //Add the student to the system
            addStudent_param(args_of_stud[0], args_of_stud[1], args_of_stud[2], avg, type);
        }
        catch (exception& e)
        {
            cout<<e.what()<<endl;
        }


    } //extern while closer
}



//Destructor
ZoomSys::~ZoomSys()
{
    //Clear the rooms map
    if (this->map_rooms.size() != 0)
    {
        //Iterates through every key value pair and deletes the pair (which is the room itself)
        map<int,Room*>::iterator it;
        for (it = this->map_rooms.begin(); it != this->map_rooms.end(); it++)
        {
            delete(it->second);
        }
        this->map_rooms.clear();
    }


    //Clear the students vector
    if (this->vec_students.size() != 0)
    {
        //Iterates through object and deletes it (which is the student itself)
        vector<Student*>::iterator it;
        for (it = this->vec_students.begin(); it != this->vec_students.end(); it++)
        {
            delete(*it);
        }

        this->vec_students.clear();
    }
}


//Main function for adding a student to the system - Asks for details from user
void ZoomSys::addStudent()
{
    string fname, lname, id;
    double avg;
    char type_of_student;
    cout << "---Create Student---"<<endl;
    cout << "First name:"<<endl;
    cin >> fname;
    cout << "Last name:"<<endl;
    cin >> lname;
    cout << "ID:"<<endl;
    cin >> id;
    cout <<"avg:"<<endl;
    cin >> avg;
    cout << "Worker(W) or Lazy(L) or Responsible(R) Student?"<<endl;
    cin>>type_of_student;

    //Calls the add student function with parameters
    try
    {
        this->addStudent_param(fname, lname, id, avg, type_of_student);
    }
    catch (exception& e)
    {
        cout << e.what()<<endl;
    }


}

//Function that gets student's details and adds him to the system
void ZoomSys::addStudent_param(string fname, string lname, string id, double avg, char type_of_stud)
{
    //Checks the average is between 0-100
    if (avg < 0 || avg > 100)
    {
        throw invalid_details();
    }

    //Checks if given student already exists in the system
    if (find_student(id) != nullptr)
    {
        throw invalid_details();
    }

    //Responsible student
    if (type_of_stud == 'R')
    {
        Responsible_Student* curr = new Responsible_Student(fname, lname, id, avg);
        this->vec_students.push_back(curr);
    }

    //Worker student
    else if (type_of_stud == 'W')
    {
        Worker_Student* curr = new Worker_Student(fname, lname, id, avg);
        this->vec_students.push_back(curr);
    }

    //Lazy student
    else if (type_of_stud == 'L')
    {
        Lazy_Student* curr = new Lazy_Student(fname, lname, id, avg);
        this->vec_students.push_back(curr);
    }

    //Type of student is not 'R'\'L'\'W' - returns false
    else
    {
        throw invalid_details();
    }
}


//Main function that removes a student from the system - Asks for details from user
void ZoomSys::removeStudent()
{
    string id;
    cout<<"---Remove Student---"<<endl;
    cin>>id;

    //Calls the remove student function with parameters
    try
    {
        this->removeStudent_param(id);
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
    }
}


//Function that removes a given student from the system including the room - returns a boolean value if remove has succeded
bool ZoomSys::removeStudent_param(string id)
{
    //Finds a pointer to the student with the given id
    Student* found_stud = this->find_student(id);

    //If student is not found - throws an exception
    if (found_stud == nullptr)
    {
        throw id_exception();
    }

    //Finds the searched student room number
    int found_student_room_num = found_stud->Get_Room_Num();

    //If student is in a room (room number is not -1) - deletes the student from his room
    if (found_student_room_num != -1)
    {
        //Finds a pointer to the student's room
        Room* found_room;
        found_room = find_room(found_student_room_num);

        //Removes the given student from the room
        found_room->Remove_student(id);
    }

    //Deletes the student from the vector of students
    this->vec_students.erase(this->vec_students.begin() + this->find_student_pos(id));
}




//Main function that assigns a student to a room - asks for details from the user
void ZoomSys::assignStudent()
{
    string stud_id;
    int room_id;
    cout<<"---Assign Student---"<<endl;
    cout<<"Enter student id:" << endl;
    cin >> stud_id;
    cout << "Enter room id:" << endl;
    cin >> room_id;

    //Calls the assign student function with parameters
    try
    {
        this->assignStudent_param(stud_id, room_id);
    }
    catch (exception& e)
    {
        cout << e.what()<<endl;
    }
}

//Function that assigns a given student to a given room
bool ZoomSys::assignStudent_param(string stud_id, int room_id)
{
    //Finds a pointer to the student with the given id
    Student* found_stud = this->find_student(stud_id);

    //If student is not found - throws an exception
    if (found_stud == nullptr)
    {
        throw id_exception();
    }

    //Finds a pointer to the destination room
    Room* dest_room;
    if (room_id != -1)
    {
        dest_room = this->find_room(room_id);

        //If destination room doesn't exists - throws an exception
        if (dest_room == nullptr)
        {
            throw id_exception();
        }
    }

    //Finds the current room number of the given student
    int found_student_room_num = found_stud->Get_Room_Num();

    //Student is currently in a room (not in the lobby)
    if (found_student_room_num > 0)
    {
        //Finds a pointer for the student's current room
        Room* curr_room = this->find_room(found_student_room_num);

        //Deletes the student from current room - places him in the lobby
        curr_room->Remove_student_no_cry(stud_id);
    }

    //Student is in the lobby
    else
    {
        //Now student's current room is -1 (lobby) - we assign him the new room number
        found_stud->Student::set_room_num(room_id);
    }

    //If destination room is an actual room and not the lobby
    if (room_id != -1)
    {
        //Adds the student to the new room
        dest_room->Add_student_no_cry(found_stud);
    }
}


//Function that creates a new room in the system
void ZoomSys::addRoom()
{
    //Creates a new room
    Room* new_room = new Room();

    //Adds it to the map of rooms
    this->map_rooms[new_room->Get_room_ID()] = new_room;

    cout<<"New room created"<<endl;
}


//Main function that asks the user for a split option and splits it
void ZoomSys::splitRoom()
{
    int room_id;
    cout << "---Split Room---"<<endl;
    cout<<"Room id:"<<endl;
    cin >> room_id;

    //Calls the Split student function with parameters
    try
    {
        this->splitRoom_param(room_id);
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
    }
}


//Function that splits a given room and chooses between character split and size split. Updates students appropriatly
//Returns a boolean value
void ZoomSys::splitRoom_param(int room_id)
{
    //Finds a pointer of the room to be splitted
    Room* room_to_split = this->find_room(room_id);

    //Given room_id doesnt exist in system - throws exception
    if (room_to_split == nullptr)
    {
        throw id_exception();
    }

    //Given room has been splitted before - throws exception
    if (room_to_split->Get_split_situation() == true)
    {
        throw split_before();
    }

    //Prints mini menu to user and asks for input
    char user_input;
    cout<<"1.Character split"<<endl;
    cout<<"2.Size split" << endl;
    cin>> user_input;

    //Character split
    if (user_input == '1')
    {
        //First we split the room (the function creates 2 children room and update matching fields)
        room_to_split->Split_room(user_input);

        //Adds it to the map of rooms
        this->map_rooms[room_to_split->Get_left_room()->Get_room_ID()] = room_to_split->Get_left_room();
        this->map_rooms[room_to_split->Get_right_room()->Get_room_ID()] = room_to_split->Get_right_room();

        //We save a copy of vector of students of the given room so we can iterate on it.
        vector<Student*> v_copy = room_to_split->Get_vector_copy();

        //Iterates through every student and adds him to both the new rooms - if he is not of the appropriate type he won't be added
        vector<Student*>::iterator student_iter;
        for(student_iter = v_copy.begin(); student_iter != v_copy.end(); student_iter++)
        {
            //Tries to add the student in both rooms. Only iAf student's type matches the room he will be added
            room_to_split->Get_left_room()->Move_student((*student_iter));
            room_to_split->Get_right_room()->Move_student((*student_iter));
            //Else - student is responsible so he stays in the same room
        }
    }

    //Size split
    else if (user_input == '2')
    {
        //First we split the room (the function creates 2 children room and update matching fields)
        room_to_split->Split_room(user_input);

        //Adds it to the map of rooms
        this->map_rooms[room_to_split->Get_left_room()->Get_room_ID()] = room_to_split->Get_left_room();
        this->map_rooms[room_to_split->Get_right_room()->Get_room_ID()] = room_to_split->Get_right_room();

        //We save a copy of vector of students of the given room so we can iterate on it.
        vector<Student*> v_copy = room_to_split->Get_vector_copy();

        vector<Student*>::iterator student_iter;
        int first_half_size = room_to_split->Get_num_of_students() / 2;

        //Iterates through every first half of students
        student_iter = v_copy.begin();
        for(int i = 0; i < first_half_size ; i++)
        {
            //Assigns the current student to the left room - it won't change the copy vector so the index are still the same
            assignStudent_param((*student_iter)->Get_ID(), room_to_split->Get_left_room()->Get_room_ID());
            advance(student_iter,1);
        }

        //Iterates until end of vector
        while (student_iter != v_copy.end())
        {
            //Assigns the current student to the right room - it won't change the copy vector so the index are still the same
            assignStudent_param((*student_iter)->Get_ID(), room_to_split->Get_right_room()->Get_room_ID());
            advance(student_iter,1);
        }
    }

    //Every other input from the user is an invalid input - throws exception
    else
    {
        throw invalid_details();
    }
}


//Main function that removes a given room from the system - ask details from user
void ZoomSys::removeRoom()
{
    int room_id;
    cout<<"---Remove Room---"<<endl;
    cout<<"Enter room id:"<<endl;
    cin >> room_id;

    //Calls the Removes student function with parameters
    try
    {
        this->removeRoom_param(room_id);
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
    }
}


//Function that removes a given room and all of his children from the system
void ZoomSys::removeRoom_param(int room_id)
{
    //Finds a pointer to the given room id
    Room* room_to_remove = this->find_room(room_id);

    //If given id doesn't match any room - throws an exception
    if (room_to_remove == nullptr)
    {
        throw id_exception();
    }


    //Finds the room numbers that needs to be manually erased from the system
    vector<int> empty_vec;
    vector<int> room_vec_to_del;
    room_vec_to_del = find_rooms_to_delete(room_to_remove, empty_vec);

    //Main part of the function - deletes the room itself and it's children
    //Assigns the students accordingly
    room_to_remove->Delete_room();

    //Now we have to manually erase from the system all the rooms that have been emptied and deleted
    vector<int>::iterator room_id_to_del;
    for (room_id_to_del = room_vec_to_del.begin(); room_id_to_del != room_vec_to_del.end(); room_id_to_del++)
    {
        this->map_rooms.erase((*room_id_to_del));
    }
}


//Main function to make students of a specific room to work
void ZoomSys::work()
{
    int room_id;
    cout<<"Enter the room you want to work:"<<endl;
    cin >> room_id;

    //Calls the work student function with parameters
    try
    {
        this->work_param(room_id);
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
    }
}

//Function that makes the responsible students in the given room to say they work
void ZoomSys::work_param(int room_id)
{
    //Finds a pointer to the given room id
    Room* found_room = this->find_room(room_id);

    //If given id doesn't match any room - throws an exception
    if (found_room == nullptr)
    {
        throw id_exception();
    }


    //Iterates through a copy of the vector of students of current room
    vector<Student*>::iterator student_it;
    vector<Student*> copy_v = found_room->Get_vector_copy();
    for (student_it = copy_v.begin(); student_it != copy_v.end(); student_it++)
    {
        //Prints the working message
        //It is a virtual func - only a worker student will actually print a message
        (*student_it)->print_working();
    }
}

//Function that asks the user for student id and a message - if he's responsible he will send to all the room the message
void ZoomSys::sendMessage()
{
    string user_input_id;
    string user_input_msg;

    //Gets input from user the id
    cout<<"Enter the id:"<<endl;
    cin >> user_input_id;

    Student* found_stud;
    try
    {
        //Searches for the given id in the vector of students
        found_stud = this->find_student(user_input_id);
        //Throws exception if student is not found
        if (found_stud == nullptr)
        {
            throw id_exception();
        }
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
        return;
    }

    //Gets the input message from the user
    cout<<"Enter the message:"<<endl;
    cin>>user_input_msg;

    string prepared_msg;

    //If student is responsible - there won't be an exception thrown
    try
    {
        //Prepares the message to send to everyone in the room
        prepared_msg = found_stud->Prepare_message(user_input_msg);
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
        return;
    }

    //Finds the room id of the given student
    int student_room_id = found_stud->Get_Room_Num();

    //Finds a pointer to the room where the given student is
    Room* found_room = find_room(student_room_id);

    //Iterates on every student in a copy of the found room
    vector<Student*>::iterator stud_in_room;
    vector<Student*> v_copy = found_room->Get_vector_copy();
    for (stud_in_room = v_copy.begin(); stud_in_room != v_copy.end(); stud_in_room++)
    {
        //Finds the id of the current student
        string curr_stud_id = (*stud_in_room)->Get_ID();
        //Adds the prepared message to the found student
        this->find_student(curr_stud_id)->Add_Message(prepared_msg);
    }
}


//Function that prints all the rooms info in the system
void ZoomSys::printRooms()
{
    map<int, Room*>::iterator iter;
    for(iter = this->map_rooms.begin(); iter != this->map_rooms.end(); iter++)
    {
        iter->second->Print_room();
    }
}


//Function that prints all the students in the system
void ZoomSys::printStudents()
{
    cout<<"First name, Last Name, ID, Avg, Room ID"<<endl;
    vector<Student*>::iterator student_iter;
    for(student_iter = this->vec_students.begin(); student_iter != this->vec_students.end(); student_iter++)
    {
        cout<<(*(*student_iter));
    }
}


//Function that gets from user a student id and prints its details
void ZoomSys::printStudentDetails()
{
    string user_id;
    cout << "Enter student id:"<<endl;
    cin>>user_id;

    Student* found_stud;
    try
    {
        //Throws exception if the id user gave is not in the system
        found_stud = this->find_student(user_id);
        if (found_stud == nullptr)
            throw id_exception();
    }
    catch (exception& e)
    {
        cout<<e.what()<<endl;
        return;
    }

    found_stud->Print_Student_Details();
}



//HELPER FUNCTIONS

//Helper function that searches recursively for every room index that is associated to a given room
//Returns a vector of room id's that are all children of the start room
vector<int> ZoomSys::find_rooms_to_delete(Room* start_room, vector<int> vector_of_index)
{

    //If room has no children - adds his room id to the vector
    if (start_room->Get_left_room() == nullptr && start_room->Get_right_room() == nullptr) {
        vector_of_index.push_back(start_room->Get_room_ID());
        return vector_of_index;
    }

    //If room has only right child - adds his room id to the vector
    //Calls the function recursively with the right child as start room
    if (start_room->Get_left_room() == nullptr) {
        vector_of_index.push_back(start_room->Get_room_ID());
        return find_rooms_to_delete(start_room->Get_right_room(), vector_of_index);
    }

    //If room has only left child - adds his room id to the vector
    //Calls the function recursively with the left child as start room
    if (start_room->Get_right_room() == nullptr) {
        vector_of_index.push_back(start_room->Get_room_ID());
        return find_rooms_to_delete(start_room->Get_left_room(), vector_of_index);
    }

        //Room has 2 children - calls the function recursively with right and left child
    else {
        vector<int> vec1 = find_rooms_to_delete(start_room->Get_left_room(), vector_of_index);
        vector<int> vec2 = find_rooms_to_delete(start_room->Get_right_room(), vector_of_index);
        vector<int> result;
        result.push_back(start_room->Get_room_ID());
        result.insert(result.begin(), vec1.begin(), vec1.end());
        result.insert(result.end(), vec2.begin(), vec2.end());
        return result;
    }
}



//Helper function that searches for an id of student in the map and returns a pointer to him
//If student is not found - function returns null;
Student* ZoomSys::find_student(string stud_id)
{
    Student* found_stud;
    //Iterates through the vector of students
    vector<Student*>::iterator found_student_iter;
    for(found_student_iter = this->vec_students.begin(); found_student_iter != this->vec_students.end(); found_student_iter++)
    {
        //If given ID has been found
        if ((*found_student_iter)->Get_ID() == stud_id)
        {
            //Returns a pointer to the found student
            found_stud = *found_student_iter;
            return found_stud;
        }
    }

    //Student is not found - returns null
    return nullptr;

}


//Helper function that searches for an id of student in the vector and returns its index
//If student doesn't exist in the vector - returns -1
int ZoomSys::find_student_pos(string stud_id)
{
    int found_stud_index = 0;
    //Iterates through the vector of students
    vector<Student*>::iterator found_student_iter;
    for(found_student_iter = this->vec_students.begin(); found_student_iter != this->vec_students.end(); found_student_iter++)
    {
        //If given ID has been found
        if ((*found_student_iter)->Get_ID() == stud_id)
        {
            //Returns a the found student's index
            return found_stud_index;

        }
        found_stud_index++;
    }

    //Student is not found - returns -1
    return -1;
}

//Helper function that searches for an id of room in the map and returns a pointer to him
//If room is not found - function returns null;
Room* ZoomSys::find_room(int room_id)
{
    //Finds an iterator of the room of the given id
    map<int, Room*>::iterator found_room_iter;
    found_room_iter = this->map_rooms.find(room_id);

    //If room is not found - returns false
    if (found_room_iter == this->map_rooms.end())
    {
        return nullptr;
    }

    //Student is room - returns a pointer to it
    else
    {
        return found_room_iter->second;
    }
}



