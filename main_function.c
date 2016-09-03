`#include "Allfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void judge_ifvalid(int * demand) {  // 判断用户是否输入合法的指令 
    int requirement;
    requirement = * demand;
    while (1) {
        if (requirement == 1 || requirement== 2 || requirement == 3 || requirement == 4 || requirement == 5) {
            break;
        } else {
            printf("The invalid requirement, enter again\n");
            scanf("%d", &requirement);
        }
    }
}

void requi_swit_main(int demand) {  // 匹配用户的指令，跳转到业务逻辑层 
    switch(demand) {
        case 1:
            append_record();
            break;
        case 2: 
            delete_number();
            break;
        case 3: 
            modify();
            break;
        case 4: 
            query();
            break;
        case 5:
            consult();
            break;
    }
}

long openfile(struct Student * studenttemp) {   // 打开文件，写入结构体 
	FILE *fp;
	int i;
	long filelength;
	struct Student temp;
	if ((fp = fopen("student_record.txt","rb")) == NULL) {
		printf("Failed to open the file\n");
		exit(1);
	}
   fseek(fp, 0, SEEK_END);
   filelength = ftell(fp);
   filelength /= sizeof(struct Student);
   rewind(fp);
   for (i = 0; i < filelength; i++) {
   	    fread(&temp, sizeof(struct Student), 1, fp);
   	    studenttemp->ID = temp.ID;
        strcpy(studenttemp->name, temp.name);
        studenttemp->grade = temp.grade;
        studenttemp->class_ = temp.class_;
        studenttemp->score = temp.score;
        studenttemp->if_exist = temp.if_exist;
        studenttemp++; 
   }
   fclose(fp);
   return filelength;
}

void writefile(int filelength, struct Student * studenttemp) {  // 把结构体数据写入文件 
	FILE *fp;
	int i;
	struct Student temp;
	if ((fp = fopen("student_record.txt","wb")) == NULL) {
		printf("Failed to open the file/n");
		exit(1);
	}
	for (i = 0; i < filelength; i++) {
	    temp.ID = studenttemp->ID;
        strcpy(temp.name,studenttemp->name);
        temp.grade = studenttemp->grade;
        temp.class_ = studenttemp->class_;
        temp.score = studenttemp->score;
        temp.if_exist = studenttemp->if_exist;
        studenttemp++; 
		fwrite(&temp, sizeof(struct Student), 1, fp);
	}
	fclose(fp);
}

void consult() {  // 查询成绩的函数 
	int id;
	int i, idfind, flag;
	struct Student stu[10000];
	long filelength = openfile(&stu[0]);
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("Please enter the ID you want to consult\n");
	printf("or enter q/Q to quit\n");
	while (scanf("%d", &id) == 1) {
		flag = 0;
		for (i = 0; i < filelength; i++) {
			if (stu[i].ID == id) {
				idfind = i;
				flag = 1;
				break;
			}
		}
		if (flag == 0 || stu[idfind].if_exist == 0) {
			printf("The ID is not exist\n");
		} else {
			printf("ID: %d name: %s grade: %d class: %d score: %d\n", stu[idfind].ID,  stu[idfind].name, stu[idfind].grade, stu[idfind].class_, stu[idfind].score);
			printf("--------------------------------------------------------------------------------");
		}
		printf("Please enter the ID you want to consult\n");
	    printf("or enter q/Q to quit\n");
	}
	getchar();
}`
