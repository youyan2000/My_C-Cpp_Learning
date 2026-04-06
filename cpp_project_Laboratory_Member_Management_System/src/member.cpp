#include "member.hpp"

/* ==================== Class Member ==================== */
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
const char* Member::getGroup() const { return ""; }
const char* Member::getStudentID() const { return ""; }

void Member::setName(const char* n) { strncpy(name, n, MAX_NAME-1); }
void Member::setGender(const char* g) { strncpy(gender, g, MAX_GENDER-1); }
void Member::setMajor(const char* m) { strncpy(major, m, MAX_MAJOR-1); }
void Member::setPosition(const char* p) { strncpy(position, p, MAX_POSITION-1); }

/* ==================== Class Teacher ==================== */
Teacher::Teacher() : Member() {}
Teacher::Teacher(const char* n, const char* g, const char* m, const char* p) 
    : Member(n, g, m, p) {}

void Teacher::toCSV(char* buffer, int bufferSize) {
    snprintf(buffer, bufferSize, "%s,%s,%s,%s,,", 
            getName(), getGender(), getMajor(), getPosition());
}

void Teacher::displayInfo() {
    printf("[teacher]\n");
    printf("name: %s\n", getName());
    printf("gender: %s\n", getGender());
    printf("major: %s\n", getMajor());
    printf("position: %s\n", getPosition());
    printf("------------------------\n");
}

/* ==================== Class Student ==================== */
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
    snprintf(buffer, bufferSize, "%s,%s,%s,%s,%s,%s", 
            getName(), getGender(), getMajor(), getPosition(), 
            getGroup(), getStudentID());
}

void Student::displayInfo() {
    printf("[student]\n");
    printf("name: %s\n", getName());
    printf("gender: %s\n", getGender());
    printf("major: %s\n", getMajor());
    printf("position: %s\n", getPosition());
    printf("group: %s\n", getGroup());
    printf("studentID: %s\n", getStudentID());
    printf("------------------------\n");
}

/* ==================== Class Lab ==================== */
Lab::Lab(const char* path) : memberCount(0), csvFilePath(path) {
    // inite members array
    for (int i = 0; i < MAX_MEMBERS; i++) {
        members[i] = nullptr;
    }
    // load CSV data
    loadFromCSV();
    printf("The initialization of the laboratory member management system has been completed!\n");
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
            // 1.Sort by group
            int groupCmp = strcmp(members[j]->getGroup(), members[j+1]->getGroup());
            if (groupCmp > 0) {
                Member* temp = members[j];
                members[j] = members[j+1];
                members[j+1] = temp;
            } else if (groupCmp == 0) {
                // 2.Sort by position
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
        printf("[loadFromCSV] Warning: The data file was not found. A new file will be created.\n");
        return false;
    }

    // clear existing members
    for (int i = 0; i < memberCount; i++) {
        delete members[i];
        members[i] = nullptr;
    }
    memberCount = 0;

    char buffer[1024];
    fgets(buffer, sizeof(buffer), fp);
    
    // Read the data row by row
    while (fgets(buffer, sizeof(buffer), fp) && memberCount < MAX_MEMBERS) {
        
        buffer[strcspn(buffer, "\n")] = 0;
        // Split fields
        char* name = strtok(buffer, ",");
        char* gender = strtok(nullptr, ",");
        char* major = strtok(nullptr, ",");
        char* position = strtok(nullptr, ",");
        char* group = strtok(nullptr, ",");
        char* studentID = strtok(nullptr, ",");

        if (!name || !gender || !major || !position) {
            printf("[loadFromCSV] Warning: Invalid CSV row, skipped.\n");
            continue;
        }

        // Create mumber
        if (strcmp(position, "teacher") == 0) {
            members[memberCount++] = new Teacher(name, gender, major, position);
        } else if (strcmp(position, "student") == 0) {
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
    printf("[loadFromCSV] Successfully loaded %d member data.\n", memberCount);
    return true;
}

bool Lab::saveToCSV() {
    FILE* fp = fopen(csvFilePath, "w");
    if (!fp) {
        printf("[saveToCSV] error: CANNOT write to file! \n");
        return false;
    }

    // Write the header
    fprintf(fp, "name,gender,major,position,group,studentID\n");

    // Write in all member data
    char csvBuffer[1024];
    sortMembers();
    for (int i = 0; i < memberCount; i++) {
        members[i]->toCSV(csvBuffer, sizeof(csvBuffer));
        fprintf(fp, "%s\n", csvBuffer);
    }

    fclose(fp);
    printf("[saveToCSV] Successfully saved %d member data to file.\n", memberCount);
    return true;
}

bool Lab::addMember(Member* newMember) {
    // Check validity
    if (!newMember) {
        printf("[addMember] error: invalid member object! \n");
        return false;
    }
    // Check maximum quantity
    if (memberCount >= MAX_MEMBERS) {
        printf("[addMember] error: Member count has reached the limit!\n");
        return false;
    }
    // Check duplicate names
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getName(), newMember->getName()) == 0) {
            printf("[addMember] error: A member with the same name already exists!\n");
            return false;
        }
    }

    members[memberCount++] = newMember;
    printf("[addMember] Successfully added member: %s\n", newMember->getName());
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
            delete members[i];
            for (int j = i; j < memberCount-1; j++) {
                members[j] = members[j+1];
            }
            members[memberCount-1] = nullptr;
            memberCount--;
            printf("[deleteMember] Successfully deleted member: %s\n", name);
            return true;
        }
    }
    printf("[deleteMember] error: Member not found: %s\n", name);
    return false;
}

void Lab::showAllMembers() {
    // Check validity
    if (memberCount == 0) {
        printf("[showAllMembers] error: No member data available!\n");
        return;
    }

    sortMembers();
    printf("\n===== All members of the laboratory (sorted by group and position) =====\n");
    for (int i = 0; i < memberCount; i++) {
        members[i]->displayInfo();
    }
}

void Lab::showAllStudents() {
    // Check validity
    if (memberCount == 0) {
        printf("[showAllStudents] error: No member data available!\n");
        return;
    }

    sortMembers();
    printf("\n===== All students of the laboratory (sorted by group) =====\n");
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getPosition(), "student") == 0) {
            members[i]->displayInfo();
        }
    }
}

void Lab::showAllTeachers() {
    // Check validity
    if (memberCount == 0) {
        printf("[showAllTeachers] error: No member data available!\n");
        return;
    }

    sortMembers();
    printf("\n===== All teachers of the laboratory (sorted by group) =====\n");
    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getPosition(), "teacher") == 0) {
            members[i]->displayInfo();
        }
    }
}

void Lab::countMembers() {
    int teacherCount = 0;
    int studentCount = 0;

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i]->getPosition(), "teacher") == 0) {
            teacherCount++;
        } else {
            studentCount++;
        }
    }

    printf("\n===== Member Statistics =====\n");
    printf("Teachers Number: %d\n", teacherCount);
    printf("Students Number: %d\n", studentCount);
    printf("Total Number: %d\n", memberCount);
}

/* ==================== Menu function ==================== */
void showMenu() {
    printf("\n===== Laboratory Member Management System =====\n");
    printf("1. add teacher\n");
    printf("2. add student\n");
    printf("3. query member by name\n");
    printf("4. delete member by name\n");
    printf("5. show all members\n");
    printf("6. count members\n");
    printf("7. exit system (auto save)\n");
    printf("=================================\n");
    printf("Please enter the operation number: ");
}
