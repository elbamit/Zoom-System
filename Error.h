#ifndef HW5_ERROR_H
#define HW5_ERROR_H
#include <iostream>
#include <exception>
using namespace std;

class Error {

};

class id_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "id doesn't exists";
    }
};

class student_permissions : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "this student don't have permission";
    }

};

class split_before : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "This room was split before";
    }

};

class invalid_details :  public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Please enter valid details";
    }

};


#endif //HW5_ERROR_H
