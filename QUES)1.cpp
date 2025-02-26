#include <iostream>
#include <string>

class Student {
private:
    // Private member variables to store the everything about the student
    std::string name;
    int rollNumber;
    char grade;

public:
    // Constructor to initialize the student object
    Student(std::string n, int r, char g) : name(n), rollNumber(r), grade(g) {}

    // Copy constructor : creates a a copy of the object
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        grade = s.grade;
    }

    //display the student's details
    void display() const {
        std::cout << "Name: " << name << ", Roll Number: " << rollNumber << ", Grade: " << grade << std::endl;
    }
};

int main() {
    Student student1("John Doe", 101, 'A'); //Object 1

    Student student2 = student1; //Object 2 which is copied from Object 1

    std::cout << "Original Student:" << std::endl;//Original Student Object
    student1.display();

    std::cout << "Duplicate Student:" << std::endl;//Duplicate Student Object
    student2.display();

    return 0;
}