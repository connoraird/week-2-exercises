#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"

using namespace std;

Student::Student(const std::string &n) : name(n), id(max_id++) {
    cout << "Student " << name << " created." << endl;
}

Student::~Student() {
    cout << "Student " << name << " destroyed." << endl;
    department->deregisterStudent(this);
}

int Student::getId() const { return id; }

void Student::setDepartment(Department* newDepartment)
{
    if (department != nullptr) department->deregisterStudent(this);
    department = newDepartment;
    department->registerStudent(this);
}

// Static variables need to be initialised outside their class declaration
int Student::max_id = 0;

Department::Department(const std::string &n) : name(n)
{
    cout << "Department " << name << " created." << endl;
}

Department::~Department()
{
    cout << "Department " << name << " destroyed." << endl;
}

void Department::registerStudent(Student* newStudent)
{
    int studentId = newStudent->getId();
    auto found = students.find(studentId);
    if (found->first != studentId) students[studentId] = newStudent;
}

void Department::deregisterStudent(Student* student)
{
    students.erase(student->getId());
}
