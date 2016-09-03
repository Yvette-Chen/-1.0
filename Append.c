#include "Allfunction.h"
#include <stdio.h>
#include <stdlib.h>

void append_record() {  // 添加成绩的函数 
    int i = 0, totol;
    struct Student stu[10000];
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("Now let's start appending\n");
    printf("First please enter the totol students\n");
    scanf("%d", &totol);
    getchar();
    FILE *fp;
    if ((fp = fopen("student_record.txt", "a+b")) == NULL)
	 printf("Failed to open the file\n"); 
    for (i = 0; i < totol; i++) {    //  提示用户按要求输入相应的数据                            
        printf("please enter number %d student's data\n", i + 1);
        printf("Please enter the student ID and the name: ");
        scanf("%d %s", &stu[i].ID, &stu[i].name);
        printf("Please enter the student class and the grade: ");
        scanf("%d %d", &stu[i].class_, &stu[i].grade);
        printf("Please enter the student score: ");
        scanf("%d", &stu[i].score);
        stu[i].if_exist = 1;
        printf("--------------------------------------------------------------------------------");
        if ((fwrite(&stu[i], sizeof(struct Student), 1, fp)) != 1) {
        	printf("Failed to write in\n");
	    } 
    }
    fclose(fp);
}
