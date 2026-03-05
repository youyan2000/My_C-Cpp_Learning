#include "member.hpp"

// ==================== Member类实现 ====================
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

// ==================== Teacher类实现 ====================
Teacher::Teacher() : Member() {}
Teacher::Teacher(const char* n, const char* g, const char* m, const char* p) 
    : Member(n, g, m, p) {}

void Teacher::toCSV(char* buffer, int bufferSize) {
    snprintf(buffer, bufferSize, "%s,%s,%s,%s,教师,,", 
            getName(), getGender(), getMajor(), getPosition());
}

void Teacher::displayInfo() {
    printf("【教师】\n");
    printf("姓名：%s\n", getName());
    printf("性别：%s\n", getGender());
    printf("专业：%s\n", getMajor());
    printf("职位：%s\n", getPosition());
    printf("------------------------\n");
}

// ==================== Student类实现 ====================
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
    printf("【学生】\n");
    printf("姓名：%s\n", getName());
    printf("性别：%s\n", getGender());
    printf("专业：%s\n", getMajor());
    printf("职位：%s\n", getPosition());
    printf("组别：%s\n", getGroup());
    printf("学号：%s\n", getStudentID());
    printf("------------------------\n");
}

// ==================== Lab类实现 ====================
Lab::Lab(const char* path) : memberCount(0), csvFilePath(path) {
    // 初始化数组
    for (int i = 0; i < MAX_MEMBERS; i++) {
        members[i] = nullptr;
    }
    // 加载CSV文件数据
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
                // 交换
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

    // 清空现有数据
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
        printf("错误：无法写入文件！\n");
        return false;
    }

    // 写入表头
    fprintf(fp, "姓名,性别,专业,职位,类型,组别,学号\n");

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
        printf("错误：无效的成员对象！\n");
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
