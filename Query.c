#include "Allfunction.h"
#include <stdio.h>
#include <stdlib.h>

void query()
{
    int requirement, gra, cla, id, max, * iddd, sco, i;
    float average;
    id = 0;
    struct Student student[10000];
    long filelength = openfile(&student[0]);
    system("cls");
    printf("--------------------------------------------------------------------------------");
    printf("enter your requirement\n");
    printf("1 : get the max grade of the student\n");
    printf("2 : get the lowest grade\n");
    printf("3 : get the average\n");
    printf("4 : get the student ID who is under score\n");
    printf("5 : get the student ID who is over a score\n");
    printf("q : quit\n");
    while (scanf("%d", &requirement) == 1) {
    	printf("enter the grade and the class in order which you want to find\n");
        scanf("%d %d", &gra, &cla);
        switch(requirement) {       // 根据用户的不同指令转到不同的函数执行相应的功能 
            case 1: get_max(filelength, gra, cla, &student[0]);
                    break;
            case 2: get_min(filelength, gra, cla, &student[0]);
                    break;
            case 3: aver(filelength, gra, cla, &student[0]);
                    break;
            case 4: printf("Please enter the score you want to find that whose score is under it\n");
                    scanf("%d", &sco);
		            down(filelength, gra, cla, sco, &student[0]);
                    break;
            case 5: printf("Please enter the score you want to find that whose score is over it\n");
                    scanf("%d", &sco);
                    up(filelength, gra, cla, sco, &student[0]);
                   break;
            default: break;
        }
        printf("--------------------------------------------------------------------------------");
        printf("enter your requirement ");
        printf("or enter q to quit\n");
	}
	getchar();
}

void get_max(long all_num, int grade, int class_, struct Student * stu)  // 获取最高分 
{
    int id = 0, max, i, t, flag = 0;
    for(i = 0; i < all_num; i++) { // 找到第一个这个年级和班级的数据
        if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
            id = stu->ID;
            max = stu->score;
            flag = 1;
            break;
        }
        stu++;
    }
    if (flag == 0) {  // 没有找到这个班级的数据 
        printf("The grade or the class is not exist or you enter the wrong grade or class\n");
    } else {
        for (t = i; t < all_num; t++) {    // 找到第一个数据继续往后找符合条件的数据 ,如果大于则把这个值赋给max 
        if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
            if (max < stu->score) {
                max = stu->score;
                id = stu->ID;
            }
        }
        stu++;
        }
        printf("the max grade is %d, and the ID is %d\n", max, id);
    }
}
    

void get_min(long all_num, int grade, int class_, struct Student * stu) { // 获取最低分 
    int i, t, id, min, flag = 0;
    for(i = 0; i < all_num; i++) { // 找到第一个这个年级和班级的数据
        if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
            id = stu->ID;
            min = stu->score;
            flag = 1;
            break;
        }
        stu++;
    }
    if (flag == 0) {        // 没有找到这个班级的数据 
        printf("The grade or the class is not exist or you enter the wrong grade or class\n");
    } else {
        for (t = i; t < all_num; t++) {  // 找到第一个数据继续往后找符合条件的数据 ,如果小于则把这个值赋给min 
        if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
            if (min > stu->score) {
                min = stu->score;
                id = stu->ID;
            }
        }
        stu++;
    }
    printf("the min grade is %d, and the ID is %d\n", min, id);	
    }
}

void aver(long all_num, int grade, int class_, struct Student * stu) {
	int i, count = 0, n = 0, flag = 0;
	float ave;
	for (i = 0; i < all_num; i++) {    // 把符合条件的数都加起来 
		if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
		 count += stu->score;
		 n++;
		 flag = 1;
	    }
   }
   if (flag == 0) {   // 没有找到这个班级和年纪的数据 
       printf("The grade or the class is not exist or you enter the wrong grade or class\n");
   } else {
       ave = (float) count / n;        // 计算符合条件的数的平均值 
       printf("The average is %.3f\n", ave);
   }
}

void down(long all_num, int grade, int class_, int score, struct Student * stu) {
	int i, n = 0, idd[1000], flag = 0;
	for (i = 0; i < all_num; i++) {        // 找到符合条件的ID，并存储 
		if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
			if (stu->score < score) {
				idd[n] = stu->ID;
				n++;
				flag = 1;
			}
	    }
	    stu++;
   }
   if (flag == 0) {
       printf("The grade or the class is not exist or you enter the wrong grade or class\n");
   } else {
       printf("Next is the student ID\n");
   for (i = 0; i < n; i++) {    // 输出符合条件的ID 
   	    printf("%d\n", idd[i]);
    }
   }
}

void up(long all_num, int grade, int class_, int score, struct Student * stu) {
	int i, n = 0, idd[10000], flag = 0;
	for (i = 0; i < all_num; i++) {     // 找到符合条件的ID，并存储 
		if(stu->grade == grade && stu->class_ == class_ && stu->if_exist == 1) {
			if (stu->score > score) {
				idd[n] = stu->ID;
				n++;
				flag = 1;
			}
	    }
   }
   if (flag == 0) {
       printf("The grade or the class is not exist or you enter the wrong grade or class\n");
   } else {
       printf("Next is the student ID\n");
    for (i = 0; i < n; i++) {   // 输出符合条件的ID
   	    printf("%d\n", idd[i]);
    }
   }
}
