#ifndef LAB_MEMBER_HPP
#define LAB_MEMBER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define constants
#define MAX_NAME 50
#define MAX_MAJOR 50
#define MAX_GENDER 10
#define MAX_POSITION 20
#define MAX_GROUP 10
#define MAX_STUDENT_ID 20
#define MAX_MEMBERS 100

// base class: Member
class Member {
protected:
    char name[MAX_NAME];
    char gender[MAX_GENDER];
    char major[MAX_MAJOR];
    char position[MAX_POSITION];

public:
    Member();
    Member(const char* n, const char* g, const char* m, const char* p);
    virtual ~Member();

    const char *getName() const;              // Obtain Name
    const char *getGender() const;            // Obtain Gender
    const char *getMajor() const;             // Obtain Major
    const char *getPosition() const;          // Obtain Position
    virtual const char *getGroup() const;     // Obtain group (unique to students, teachers leave blank)
    virtual const char *getStudentID() const; // Obtain student ID (unique to students, teachers return empty)
        
    void setName(const char* n);
    void setGender(const char* g);
    void setMajor(const char* m);
    void setPosition(const char* p);

    virtual void toCSV(char *buffer, int bufferSize) = 0; // Outport as CSV rows
    virtual void displayInfo() = 0;                       // Display member information
};

// teacher(derived class A)
class Teacher : public Member {
public:
    Teacher();
    Teacher(const char* n, const char* g, const char* m, const char* p);

    void toCSV(char* buffer, int bufferSize) override;
    void displayInfo() override;
};

// student(derived class B)
class Student : public Member {
private:
    char group[MAX_GROUP];
    char studentID[MAX_STUDENT_ID];
public:
    Student();
    Student(const char* n, const char* g, const char* m, const char* p, 
            const char* gr, const char* id);

    const char *getGroup() const override;
    const char *getStudentID() const override;
    void setGroup(const char* gr);
    void setStudentID(const char* id);

    void toCSV(char* buffer, int bufferSize) override;
    void displayInfo() override;
};

// manage all members (derived class C)
class Lab {
private:
    Member *members[MAX_MEMBERS]; // Array for members storage
    int memberCount;              // current number of members
    const char *csvFilePath;      // CSV file path
    void sortMembers();           // Sorting auxiliary function
public:
    Lab(const char* path);
    ~Lab();

    bool loadFromCSV(); // Save CSV file
    bool saveToCSV();   // Load CSV file

    bool addMember(Member *newMember);    // Add member
    Member *findMember(const char *name); // Query member information by name
    bool deleteMember(const char *name);  // Delete member by name
    void showAllMembers();                // Show all mumbers
    void showAllStudents();               // Show all students
    void showAllTeachers();               // Show all teachers
    void countMembers();                  // Statistics number of teachers and students
};

void showMenu(); // Show the menu

#endif