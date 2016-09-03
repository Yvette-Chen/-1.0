#include "Allfunction.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modify() {
    int id, idfind, i, demand, flag;
    struct Student stu[10000];
    long filelength = openfile(&stu[0]);
    system("cls");
    printf("--------------------------------------------------------------------------------");
    printf("Please the enter the ID you want to modify\n");
    printf("or enter q to quit\n");
    while (scanf("%d", &id) == 1) {
        flag = 0;
        for (i = 0; i < filelength; i++) {
    		if(stu[i].ID == id && stu[i].if_exist == 1) {
    			idfind = i;
    			flag = 1; 
    			break;
			}
	    }
		if (flag == 0) {
		    printf("The student ID is not exist or you enter the wrong ID\n");
        } else {
            printf("Please enter what you want to modify\n");
    	    printf("1: ID and name\n2: class\n3: grade\n4: score\n");
    	    scanf("%d", &demand);
            switch(demand) {     // 根据用户不同的指令 ，获取一个学生的某些信息，写入结构体进行修改 
		        case 1:
			        printf("enter the ID and name: ");  // 修改ID和姓名 
			        scanf("%d %s", &stu[idfind].ID, &stu[idfind].name);
			        break;
		        case 2:
			        printf("enter the class: ");      // 修改班级 
			        scanf("%d", &stu[idfind].class_);
			        break;
		        case 3:
			        printf("enter the grade: ");      // 修改年级 
			        scanf("%d", &stu[idfind].grade);
			        break;
		        case 4:                     
			        printf("enter the score: ");      // 修改分数 
			        scanf("%d", &stu[idfind].score);
			        break;
			    default:                              // 如果用户输入了非1~4的数字指令，则提示输入错误 
			        printf("Please enter the correct demand\n");
			        break;
	            }
        }
		printf("--------------------------------------------------------------------------------");
		printf("Please the enter the ID you want to modify\n");
        printf("or enter q to quit\n");
	}
   getchar();
   writefile(filelength, &stu[0]);
}
