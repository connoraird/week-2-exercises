#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"

using namespace std;


int main()
{
    // declare a department 
    Department computerScience("Compter science");

    // declare a student
    Student studentA("Student A");

    // set student's department
    studentA.setDepartment(&computerScience);

    // add student to department list
    computerScience.registerStudent(&studentA);

    return 0;
}