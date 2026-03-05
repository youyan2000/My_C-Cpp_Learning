#include "member.hpp"

// ==================== Class Member ====================
Member::Member() {
    memset(name, 0, sizeof(name));
    memset(gender, 0, sizeof(gender));
    memset(major, 0, sizeof(major));
    memset(position, 0, sizeof(position));
}

Member::Member(const char* n, const char* g, const char* m, const char* p) {
    strncpy(name, n, MAX_NAME-1);
    strncpy(gender, g, MAX_GENDER-1);
    strncpy(major, m, MAX_MAJOR-1);
    strncpy(position, p, MAX_POSITION-1);
}

Member::~Member() {}

const char* Member::getName() const { return name; }
const char* Member::getGender() const { return gender; }
const char* Member::getMajor() const { return major; }
const char* Member::getPosition() const { return position; }

void Member::setName(const char* n) { strncpy(name, n, MAX_NAME-1); }
void Member::setGender(const char* g) { strncpy(gender, g, MAX_GENDER-1); }
void Member::setMajor(const char* m) { strncpy(major, m, MAX_MAJOR-1); }
void Member::setPosition(const char* p) { strncpy(position, p, MAX_POSITION-1); }

const char* Member::getGroup() const { return ""; }
const char* Member::getStudentID() const { return ""; }

// ==================== Class Teacher ====================
Teacher::Teacher() : Member() {}
Teacher::Teacher(const char* n, const char* g, const char* m, const char* p) 
    : Member(n, g, m, p) {}

void Teacher::toCSV(char* buffer, int bufferSize) {
    snprintf(buffer, bufferSize, "%s,%s,%s,%s,教师,,", 
            getName(), getGender(), getMajor(), getPosition());
}

void Teacher::displayInfo() {
    printf("【teacher】\n");
    printf("name: %s\n", getName());
    printf("gender: %s\n", getGender());
    printf("major: %s\n", getMajor());
    printf("position: %s\n", getPosition());
    printf("------------------------\n");
}

// ==================== Class Student ====================
Student::Student() : Member() {
    memset(group, 0, sizeof(group));
    memset(studentID, 0, sizeof(studentID));
}

Student::Student(const char* n, const char* g, const char* m, const char* p, 
        const char* gr, const char* id) : Member(n, g, m, p) {
    strncpy(group, gr, MAX_GROUP-1);
    strncpy(studentID, id, MAX_STUDENT_ID-1);
}

const char* Student::getGroup() const { return group; }
const char* Student::getStudentID() const { return studentID; }
void Student::setGroup(const char* gr) { strncpy(group, gr, MAX_GROUP-1); }
void Student::setStudentID(const char* id) { strncpy(studentID, id, MAX_STUDENT_ID-1); }

void Student::toCSV(char* buffer, int bufferSize) {
    snprintf(buffer, bufferSize, "%s,%s,%s,%s,学生,%s,%s", 
            getName(), getGender(), getMajor(), getPosition(), 
            getGroup(), getStudentID());
}

void Student::displayInfo() {
    printf("【student】\n");
    printf("name: %s\n", getName());
    printf("gender: %s\n", getGender());
    printf("major: %s\n", getMajor());
    printf("position: %s\n", getPosition());
    printf("group: %s\n", getGroup());
    printf("studentID: %s\n", getStudentID());
    printf("------------------------\n");
}

// ==================== Class Lab ====================
Lab::Lab(const char* path) : memberCount(0), csvFilePath(path) {
    // inite members array
    for (int i = 0; i < MAX_MEMBERS; i++) {
        members[i] = nullptr;
    }
    // load CSV data
    loadFromCSV();
}

Lab::~Lab() {
    for (int i = 0; i < memberCount; i++) {
        delete members[i];
        members[i] = nullptr;
    }
}

void Lab::sortMembers() {
    if (memberCount <= 1) return;

    for (int i = 0; i < memberCount-1; i++) {
        for (int j = 0; j < memberCount-1-i; j++) {
            // 先按组别排序（教师组别为空，排前面）
            int groupCmp = strcmp(members[j]->getGroup(), members[j+1]->getGroup());
            if (groupCmp > 0) {
                // exchange members[j] and members[j+1]
                Member* temp = members[j];
                members[j] = members[j+1];
                members[j+1] = temp;
            } else if (groupCmp == 0) {
                // 组别相同，按职位排序
                int posCmp = strcmp(members[j]->getPosition(), members[j+1]->getPosition());
                if (posCmp > 0) {
                    Member* temp = members[j];
                    members[j] = members[j+1];
                    members[j+1] = temp;
                }
            }
        }
    }
}

bool Lab::loadFromCSV() {
    FILE* fp = fopen(csvFilePath, "r");
    if (!fp) {
        printf("提示：未找到数据文件，将创建新文件。\n");
        return false;
    }

    // clear existing members
    for (int i = 0; i < memberCount; i++) {
        delete members[i];
        members[i] = nullptr;
    }
    memberCount = 0;

    char buffer[1024];
    // 读取表头（跳过第一行）
    fgets(buffer, sizeof(buffer), fp);

    // 逐行读取数据
    while (fgets(buffer, sizeof(buffer), fp) && memberCount < MAX_MEMBERS) {
        // 去除换行符
        buffer[strcspn(buffer, "\n")] = 0;

        // 分割CSV字段
        char* name = strtok(buffer, ",");
        char* gender = strtok(nullptr, ",");
        char* major = strtok(nullptr, ",");
        char* position = strtok(nullptr, ",");
        char* type = strtok(nullptr, ",");
        char* group = strtok(nullptr, ",");
        char* studentID = strtok(nullptr, ",");

        if (!name || !gender || !major || !position || !type) {
            printf("警告：无效的CSV行，跳过。\n");
            continue;
        }

        // 创建对应对象
        if (strcmp(type, "教师") == 0) {
            members[memberCount++] = new Teacher(name, gender, major, position);
        } else if (strcmp(type, "学生") == 0) {
            Student* stu = new Student();
            stu->setName(name);
            stu->setGender(gender);
            stu->setMajor(major);
            stu->setPosition(position);
            if (group) stu->setGroup(group);
            if (studentID) stu->setStudentID(studentID);
            members[memberCount++] = stu;
        }
    }

    fclose(fp);
    printf("成功加载 %d 个成员数据。\n", memberCount);
    return true;
}

bool Lab::saveToCSV() {
    FILE* fp = fopen(csvFilePath, "w");
    if (!fp) {
        printf("error: CANNOT write to file! \n");
        return false;
    }

    // 写入表头
    fprintf(fp, "name,gender,major,position,type,group,studentID\n");

    // 先排序再保存
    sortMembers();

    // 写入所有成员数据
    char csvBuffer[1024];
    for (int i = 0; i < memberCount; i++) {
        members[i]->toCSV(csvBuffer, sizeof(csvBuffer));
        fprintf(fp, "%s\n", csvBuffer);
    }

    fclose(fp);
    printf("成功保存 %d 个成员数据到文件。\n", memberCount);
    return true;
}

bool Lab::addMember(Member* newMember) {
    if (!newMember) {
        printf("error: invalid member object! \n");
        return false;
    }

    // 检查是否超出最大数量
    if (memberCount >= MAX_MEMBERS) {
        printf("错误：成员数量已达上限！\n");
        return false;
    }

    // 检查是否重名
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getName(), newMember->getName()) == 0) {
            printf("错误：已存在同名成员！\n");
            return false;
        }
    }

    members[memberCount++] = newMember;
    printf("成功添加成员：%s\n", newMember->getName());
    return true;
}

Member* Lab::findMember(const char* name) {
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getName(), name) == 0) {
            return members[i];
        }
    }
    return nullptr;
}

bool Lab::deleteMember(const char* name) {
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getName(), name) == 0) {
            // 释放内存
            delete members[i];
            // 前移数组元素
            for (int j = i; j < memberCount-1; j++) {
                members[j] = members[j+1];
            }
            members[memberCount-1] = nullptr;
            memberCount--;
            printf("成功删除成员：%s\n", name);
            return true;
        }
    }
    printf("错误：未找到成员 %s！\n", name);
    return false;
}

void Lab::showAllMembers() {
    if (memberCount == 0) {
        printf("当前无成员数据！\n");
        return;
    }

    // 先排序
    sortMembers();

    printf("\n===== 实验室所有成员（按组别、职位排序）=====\n");
    for (int i = 0; i < memberCount; i++) {
        members[i]->displayInfo();
    }
}

void Lab::countMembers() {
    int teacherCount = 0;
    int studentCount = 0;

    for (int i = 0; i < memberCount; i++) {
        // 通过动态类型判断
        if (strcmp(members[i]->getGroup(), "") == 0 && 
            strcmp(members[i]->getStudentID(), "") == 0) {
            teacherCount++;
        } else {
            studentCount++;
        }
    }

    printf("\n===== 成员统计 =====\n");
    printf("教师数量：%d\n", teacherCount);
    printf("学生数量：%d\n", studentCount);
    printf("总成员数：%d\n", memberCount);
}

// ==================== 菜单函数实现 ====================
void showMenu() {
    printf("\n===== IFR实验室成员管理系统 =====\n");
    printf("1. 添加教师\n");
    printf("2. 添加学生\n");
    printf("3. 根据姓名查询成员\n");
    printf("4. 根据姓名删除成员\n");
    printf("5. 显示所有成员\n");
    printf("6. 统计成员数量\n");
    printf("7. 退出系统（自动保存）\n");
    printf("=================================\n");
    printf("请输入操作序号：");
}
