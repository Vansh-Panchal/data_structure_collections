#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

class Student
{
private:
    int rollNo;
    string name;

public:

    Student()
    {
        rollNo = 0;
        name = "";
    }

    Student(int rollNo,const string& name)
    {
        this->rollNo = rollNo;
        this->name = name;
    }

    bool operator==(const Student& other) const
    {
        return rollNo == other.rollNo;
    }
};

int main()
{
    HashMap<Student,string> students;

    students.put(
        Student(101,"Ali"),
        "Computer Science"
    );

    students.put(
        Student(102,"Ahmed"),
        "Software Engineering"
    );

    students.put(
        Student(103,"Sara"),
        "Artificial Intelligence"
    );

    students.put(
        Student(104,"Usman"),
        "Cyber Security"
    );

    students.put(
        Student(105,"Ayesha"),
        "Data Science"
    );

    cout << "Size: "
         << students.size()
         << endl;

    cout << "Load Factor: "
         << students.loadFactor()
         << endl;

    cout << "\nDepartment of Student 103: "
         << students.get(
                Student(103,"Sara")
            )
         << endl;

    cout << "\nContains Student 102: "
         << students.containsKey(
                Student(102,"Ahmed")
            )
         << endl;

    students.remove(
        Student(102,"Ahmed")
    );

    cout << "\nAfter Remove" << endl;

    cout << "Contains Student 102: "
         << students.containsKey(
                Student(102,"Ahmed")
            )
         << endl;

    cout << "Size: "
         << students.size()
         << endl;

    students.clear();

    cout << "\nAfter Clear" << endl;

    cout << "Size: "
         << students.size()
         << endl;

    cout << "Is Empty: "
         << students.isEmpty()
         << endl;

    return 0;
}