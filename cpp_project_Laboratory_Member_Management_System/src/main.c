#include "member.hpp"

int main() {
    printf("Welcome to the Laboratory Member Management System!\n");
    printf("Please enter the path to the CSV file: \n");
    char csvPath[1024];
    fgets(csvPath, sizeof(csvPath), stdin);
    csvPath[strcspn(csvPath, "\n")] = 0;
    Lab lab(csvPath);

    int choice;
    char inputBuffer[1024];
    char name[MAX_NAME], gender[MAX_GENDER], major[MAX_MAJOR];
    char position[MAX_POSITION], group[MAX_GROUP], studentID[MAX_STUDENT_ID];

    while (true) {
        showMenu();

        if (fscanf(stdin, "%d", &choice) != 1) {
            fgets(inputBuffer, sizeof(inputBuffer), stdin); 
            printf("[menu]error: please enter a valid number!\n");
            continue;
        }
        fgets(inputBuffer, sizeof(inputBuffer), stdin);

        switch (choice) {
            case 1: {// add teacher
                printf("\n----- add teacher -----\n");
                printf("Please enter name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0; 

                printf("Please enter gender: ");
                fgets(gender, MAX_GENDER, stdin);
                gender[strcspn(gender, "\n")] = 0;

                printf("Please enter major: ");
                fgets(major, MAX_MAJOR, stdin);
                major[strcspn(major, "\n")] = 0;

                strcpy(position, "teacher"); 

                lab.addMember(new Teacher(name, gender, major, position));
                break;
            }

            case 2: {// add student
                printf("\n----- add student -----\n");
                printf("Please enter name: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Please enter gender: ");
                fgets(gender, MAX_GENDER, stdin);
                gender[strcspn(gender, "\n")] = 0;

                printf("Please enter major: ");
                fgets(major, MAX_MAJOR, stdin);
                major[strcspn(major, "\n")] = 0;

                strcpy(position, "student");

                printf("Please enter group: ");
                fgets(group, MAX_GROUP, stdin);
                group[strcspn(group, "\n")] = 0;

                printf("Please enter student ID: ");
                fgets(studentID, MAX_STUDENT_ID, stdin);
                studentID[strcspn(studentID, "\n")] = 0;

                Student* stu = new Student();
                stu->setName(name);
                stu->setGender(gender);
                stu->setMajor(major);
                stu->setPosition(position);
                stu->setGroup(group);
                stu->setStudentID(studentID);
                lab.addMember(stu);
                break;
            }

            case 3: {// query member by name
                printf("\n----- query member -----\n");
                printf("Please enter name of the member to query: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;

                Member* found = lab.findMember(name);
                if (found) {
                    printf("\nFound member information:\n");
                    found->displayInfo();
                } else {
                    printf("Member not found: %s\n", name);
                }
                break;
            }

            case 4: {// delete member by name
                printf("\n----- delete member -----\n");
                printf("Please enter name of the member to delete: ");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;

                lab.deleteMember(name);
                break;
            }

            case 5: {// show all members
                lab.showAllMembers();
                break;
            }

            case 6: {// count members
                lab.countMembers();
                break;
            }

            case 7: {// exit system
                printf("\nSaving data...\n");
                lab.saveToCSV();
                printf("Data saved successfully, exiting system!\n");
                return 0;
            }

            default:{
                printf("错误：无效的操作序号，请重新输入！\n");
                break;
            }
        }
    }

    return 0;
}
