#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include "file_handling.h"
#include "crud.h"
#include "display_search.h"
#include "interface.h"
using namespace std;

int main() {
    vector<Student> students = loadFromFile(); // from file_handling.h
    int choice;
    do {
        menu(); // from interface.h
        cin >> choice;
        switch (choice) {
            case 1: addStudent(students); break;
            case 2: updateStudent(students); break;
            case 3: deleteStudent(students); break;
            case 4: displayAll(students); break;
            case 5: displayByRoll(students); break;
            case 6: searchByName(students); break;
            case 7: searchByDepartment(students); break;
            case 8: sortByGPA(students); break;
            case 9: sortByRoll(students); break;
            case 0: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "student.h"
using namespace std;

void saveToFile(const vector<Student> &students, const string &filename = "students.txt") {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    for (auto &s : students) {
        fout << s.name << ',' << s.roll << ',' << s.department << ','
             << s.gpa << ',' << s.contact << '\n';
    }

    fout.close();
}

vector<Student> loadFromFile(const string &filename = "students.txt") {
    vector<Student> students;
    ifstream fin(filename);
    if (!fin) {
        return students; // file not found on first run
    }

    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        string name, roll, department, gpaStr, contact;
        double gpa;
        size_t pos = 0;
        int field = 0;
        string temp = "";

        for (char ch : line) {
            if (ch == ',') {
                switch (field) {
                    case 0: name = temp; break;
                    case 1: roll = temp; break;
                    case 2: department = temp; break;
                    case 3: gpaStr = temp; break;
                }
                temp.clear();
                field++;
            } else temp += ch;
        }
        contact = temp;
        gpa = stod(gpaStr);
        students.push_back(Student(name, roll, department, gpa, contact));
    }
    fin.close();
    return students;
}

#endif
//member3 209 to 309 lines for you

//member4 311 to 411 lines for you


