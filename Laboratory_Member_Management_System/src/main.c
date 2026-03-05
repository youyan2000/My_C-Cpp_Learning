#include "member.hpp"

int main() {
    // 创建实验室对象（指定CSV文件路径）
    Lab lab("lib/lab_members.csv");

    int choice;
    char inputBuffer[1024];
    char name[MAX_NAME], gender[MAX_GENDER], major[MAX_MAJOR];
    char position[MAX_POSITION], group[MAX_GROUP], studentID[MAX_STUDENT_ID];

    while (true) {
        showMenu();
        // 读取用户选择（C语言输入方式）
        if (fscanf(stdin, "%d", &choice) != 1) {
            // 处理输入错误
            fgets(inputBuffer, sizeof(inputBuffer), stdin); // 清空缓冲区
            printf("错误：请输入有效的数字！\n");
            continue;
        }
        fgets(inputBuffer, sizeof(inputBuffer), stdin); // 清空换行符

        switch (choice) {
            case 1: {// 添加教师
                printf("\n----- 添加教师 -----\n");
                printf("请输入姓名：");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0; // 去除换行符

                printf("请输入性别：");
                fgets(gender, MAX_GENDER, stdin);
                gender[strcspn(gender, "\n")] = 0;

                printf("请输入专业：");
                fgets(major, MAX_MAJOR, stdin);
                major[strcspn(major, "\n")] = 0;

                printf("请输入职位（如指导教师）：");
                fgets(position, MAX_POSITION, stdin);
                position[strcspn(position, "\n")] = 0;

                // 创建教师对象并添加
                lab.addMember(new Teacher(name, gender, major, position));
                break;
            }

            case 2: {// 添加学生
                printf("\n----- 添加学生 -----\n");
                printf("请输入姓名：");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;

                printf("请输入性别：");
                fgets(gender, MAX_GENDER, stdin);
                gender[strcspn(gender, "\n")] = 0;

                printf("请输入专业：");
                fgets(major, MAX_MAJOR, stdin);
                major[strcspn(major, "\n")] = 0;

                printf("请输入职位：");
                fgets(position, MAX_POSITION, stdin);
                position[strcspn(position, "\n")] = 0;

                printf("请输入组别：");
                fgets(group, MAX_GROUP, stdin);
                group[strcspn(group, "\n")] = 0;

                printf("请输入学号：");
                fgets(studentID, MAX_STUDENT_ID, stdin);
                studentID[strcspn(studentID, "\n")] = 0;

                // 创建学生对象并添加
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

            case 3: {// 查询成员
                printf("\n----- 查询成员 -----\n");
                printf("请输入要查询的姓名：");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;

                Member* found = lab.findMember(name);
                if (found) {
                    printf("\n找到成员信息：\n");
                    found->displayInfo();
                } else {
                    printf("未找到成员：%s\n", name);
                }
                break;
            }

            case 4: {// 删除成员
                printf("\n----- 删除成员 -----\n");
                printf("请输入要删除的姓名：");
                fgets(name, MAX_NAME, stdin);
                name[strcspn(name, "\n")] = 0;

                lab.deleteMember(name);
                break;
            }

            case 5: {// 显示所有成员
                lab.showAllMembers();
                break;
            }

            case 6: {// 统计数量
                lab.countMembers();
                break;
            }

            case 7: {// 退出系统
                printf("\n正在保存数据...\n");
                lab.saveToCSV();
                printf("数据保存完成，系统退出！\n");
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
