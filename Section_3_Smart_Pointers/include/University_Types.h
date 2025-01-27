#include <memory>
#include <iostream>
#include <string>
#include <map>

using namespace std;

// Forward declaration of Department class.
// This is needed to let the compiler know that a type called
// Department will be defined in the code when it compiles the 
// Student class, as the Department class is defined afterwards.
// You can have a pointer to a forward declared class because a 
// pointer is just an address in memory, so the compiler doens't
// need to know anything the data Department contains to work
// out the data layout for Student. 
class Department;

class Student
{
    public:
    Student(const std::string &n);

    ~Student();

    int getId() const;

    void setDepartment(Department* newDepartment);

    Student & operator=(const Student&) = delete;
    Student & operator=(Student&) = delete;
    Student(const Student&) = delete;
    Student(Student&) = delete;

private:
    // Static variable means same value shared by every object in class
    // This allows us to create a unique id for each student by increasing
    // each time
    static int max_id;
    
    string name;
    int id;
    // add a pointer to the department here
    Department* department = nullptr;
};

class Department
{
public:
    Department(const std::string &n);

    ~Department();

    Department & operator=(const Department&) = delete;
    Department & operator=(Department&) = delete;
    Department(const Department&) = delete;
    Department(Department&) = delete;

    void registerStudent(Student* newStudent);

    void deregisterStudent(Student* student);

private:
    string name;
    // add a vector or map of pointers to students here
    std::map<int, Student*> students;
};