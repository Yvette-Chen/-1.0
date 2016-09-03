#include "Allfunction.h"
#include <stdio.h>
#include <stdlib.h>

void delete_number() {
    int id, i, idfind, flag, requi, grade, class_, if_delete;
    struct Student student[10000];
    long filelength = openfile(&student[0]);
    system("cls");
    printf("--------------------------------------------------------------------------------");
    printf("Please enter the kind of the data you want to delete\n");
    printf("1: grade  2: class  3: only one student  q: quit\n");
    while (scanf("%d", &requi) == 1) {
        if_delete = 0;
    	switch (requi) {           //  根据用户输入的不同指令，跳转到不同的删除信息的函数，并获取相应的数据 
    		case 1:
    			printf("Please enter the grade\n");    // 删除一整个年级 
    			scanf("%d", &grade);
    			grade_delete(grade, filelength, &student[0]);   
				break;
			case 2:
				printf("Please enter the class and its grade\n");   // 删除一个班级 
				printf("enter the class: ");
				scanf("%d", &class_);
				printf("enter the grade: ");
				scanf("%d", &grade);
			    cla_delete(class_, grade, filelength, &student[0]);
			    break; 
			case 3:                                           // 删除一个学生的信息 
			    printf("please enter the student ID: ");
				scanf("%d", &id);
				if_delete = id_delete(id, filelength, &student[0]);
				if(if_delete) {
				    printf("Deleted succeessfully\n");
                } else {
                    printf("The student ID is not exist\n");
                }
				break;
		}
		printf("please enter next requirement or enter q to quit\n");
	}
	getchar();
    writefile(filelength, &student[0]);
}

void grade_delete(int grade, int filelength, struct Student * stu) {     // 删除一整个年级 
	int i;
	for (i = 0; i < filelength; i++) {
		if (stu->grade == grade) {
		    stu->if_exist = 0;    
        }
        stu++;
	}
	printf("Deleted succeessfully\n");
}

void cla_delete(int class_, int grade, int filelength, struct Student * stu) {  // 删除一个班级 
	int i;
	for (i = 0; i < filelength; i++) {
		if (stu->grade == grade && stu->class_ == class_)
		    stu->if_exist = 0;
		stu++;
	}
	printf("Deleted succeessfully\n");
}

int id_delete(int id, int filelength, struct Student * stu) {    // 删除一个学生的信息，如果成功删除返回1，反之学生ID不存在返回0 
	int i, idfind, flag = 0, exit_ = 1;
	for (i = 0; i < filelength; i++) {
            if (stu->ID == id) {
                flag = 1;
                if (stu->if_exist == 0) {
                    exit_ = 0;
                }
                break;
            }
            stu++;
        }
    if (flag == 0 || exit == 0) {
        return 0;
    } else {
        stu->if_exist = 0;
        return 1;
    }
}
