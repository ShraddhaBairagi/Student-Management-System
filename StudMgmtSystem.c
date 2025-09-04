#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int age;

    void input() {
        cout << "Enter Roll No: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
    }

    void display() {
        cout << "Roll: " << roll << " | Name: " << name << " | Age: " << age << endl;
    }
};

void addStudent() {
    Student s;
    s.input();
    ofstream file("students.txt", ios::app);
    file << s.roll << "," << s.name << "," << s.age << endl;
    file.close();
    cout << "Student Added!\n";
}

void viewStudents() {
    ifstream file("students.txt");
    string line;
    cout << "\n--- Student Records ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Add Student\n2. View Students\n3. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else break;
    }
    return 0;
}
