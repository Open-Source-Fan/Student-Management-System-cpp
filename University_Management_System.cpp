//University-Management-System-cpp

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string StudentName;
    int RollNumber;
    float CGPA;
    vector<string> courseList;

public:
    Student() {
        StudentName = "";
        RollNumber = 0;
        CGPA = 0.0;
    }

    Student(string name, int roll, float grade) {
        StudentName = name;
        RollNumber = roll;
        CGPA = (grade >= 0.0 && grade <= 4.0) ? grade : 0.0;
    }

    Student(const Student& s) {
        StudentName = s.StudentName;
        RollNumber = s.RollNumber;
        CGPA = s.CGPA;
        courseList = s.courseList;
    }

    ~Student() {}

    void addCourse(string course) {
        if (course != "") {
            courseList.push_back(course);
        } else {
            cout << "Course name cannot be empty.\n";
        }
    }

    void updateCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 4.0) {
            CGPA = newCGPA;
        } else {
            cout << "Invalid CGPA. Must be between 0.0 and 4.0.\n";
        }
    }

    void displayInfo() {
        cout << "------------------------\n";
        cout << "Name: " << StudentName << endl;
        cout << "Roll Number: " << RollNumber << endl;
        cout << "CGPA: " << CGPA << endl;
        cout << "Courses: ";
        if (courseList.empty()) {
            cout << "None";
        } else {
            for (int i = 0; i < courseList.size(); i++) {
                cout << courseList[i];
                if (i != courseList.size() - 1)
                    cout << ", ";
            }
        }
        cout << "\n------------------------\n";
    }

    int getRollNumber() {
        return RollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> allStudents;

public:
    void addStudent(Student s) {
        allStudents.push_back(s);
    }

    Student* findStudent(int roll) {
        for (int i = 0; i < allStudents.size(); i++) {
            if (allStudents[i].getRollNumber() == roll) {
                return &allStudents[i];
            }
        }
        return nullptr;
    }

    void showAllStudents() {
        if (allStudents.empty()) {
            cout << "No student records found.\n";
        } else {
            for (int i = 0; i < allStudents.size(); i++) {
                allStudents[i].displayInfo();
            }
        }
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n--------- Student Management System Records -----\n";
        cout << "1. Add New Student\n";
        cout << "2. Add Course to Student\n";
        cout << "3. Update Student CGPA\n";
        cout << "4. Display Student Information\n";
        cout << "5. Display All Students\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int roll;
            float CGPA;
            cout << "Enter student name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter CGPA: ";
            cin >> CGPA;

            Student s(name, roll, CGPA);
            sms.addStudent(s);
            cout << "Student added successfully.\n";

        } else if (choice == 2) {
            int roll;
            string course;
            cout << "Enter roll number to add course: ";
            cin >> roll;
            Student* s = sms.findStudent(roll);
            if (s != nullptr) {
                cout << "Enter course name: ";
                cin.ignore();
                getline(cin, course);
                s->addCourse(course);
                cout << "Course added.\n";
            } else {
                cout << "Student not found.\n";
            }

        } else if (choice == 3) {
            int roll;
            float newCGPA;
            cout << "Enter roll number to update CGPA: ";
            cin >> roll;
            Student* s = sms.findStudent(roll);
            if (s != nullptr) {
                cout << "Enter new CGPA: ";
                cin >> newCGPA;
                s->updateCGPA(newCGPA);
                cout << "CGPA updated.\n";
            } else {
                cout << "Student not found.\n";
            }

        } else if (choice == 4) {
            int roll;
            cout << "Enter roll number to display info: ";
            cin >> roll;
            Student* s = sms.findStudent(roll);
            if (s != nullptr) {
                s->displayInfo();
            } else {
                cout << "Student not found.\n";
            }

        } else if (choice == 5) {
            sms.showAllStudents();
        } else if (choice != 0) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    cout << "Exiting program.\n";
    return 0;
}

