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
    // 构造函数
    Member();
    Member(const char* n, const char* g, const char* m, const char* p);

    // 虚析构函数（用于多态）
    virtual ~Member();

    // 获取成员信息的接口（封装：保护数据不被直接访问）
    const char* getName() const;
    const char* getGender() const;
    const char* getMajor() const;
    const char* getPosition() const;

    // 设置成员信息的接口
    void setName(const char* n);
    void setGender(const char* g);
    void setMajor(const char* m);
    void setPosition(const char* p);

    // 纯虚函数：导出为CSV行（子类必须实现）
    virtual void toCSV(char* buffer, int bufferSize) = 0;
    // 纯虚函数：显示成员信息
    virtual void displayInfo() = 0;
    // 纯虚函数：获取组别（学生特有，教师返回空）
    virtual const char* getGroup() const;
    // 纯虚函数：获取学号（学生特有，教师返回空）
    virtual const char* getStudentID() const;
};

// teacher(derived class A)
class Teacher : public Member {
public:
    // 构造函数
    Teacher();
    Teacher(const char* n, const char* g, const char* m, const char* p);

    // 实现纯虚函数
    void toCSV(char* buffer, int bufferSize) override;
    void displayInfo() override;
};

// 派生类：学生
class Student : public Member {
private:
    char group[MAX_GROUP];
    char studentID[MAX_STUDENT_ID];
public:
    // 构造函数
    Student();
    Student(const char* n, const char* g, const char* m, const char* p, 
            const char* gr, const char* id);

    // 封装：获取/设置组别和学号
    const char* getGroup() const override;
    const char* getStudentID() const override;
    void setGroup(const char* gr);
    void setStudentID(const char* id);

    // 实现纯虚函数
    void toCSV(char* buffer, int bufferSize) override;
    void displayInfo() override;
};

// 实验室类：管理所有成员
class Lab {
private:
    Member* members[MAX_MEMBERS];  // 多态数组：存储教师/学生对象
    int memberCount;               // 当前成员数量
    const char* csvFilePath;       // CSV文件路径
    void sortMembers();    // 排序辅助函数：按组别、职位排序

public:
    // constructor
    Lab(const char* path);
    // destructor
    ~Lab();
    // 加载/保存CSV文件
    bool loadFromCSV();
    bool saveToCSV();
    // 成员管理功能
    bool addMember(Member* newMember);
    Member* findMember(const char* name);
    bool deleteMember(const char* name);
    void showAllMembers();
    void countMembers();
};

// menu function declaration
void showMenu();

#endif