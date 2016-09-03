`#include <stdio.h>
#include <stdlib.h>
#include "Allfunction.h"

int main() {
    int requirement;
    char ch;
    printf("----------------------- the Student Score Management System---------------------");
    printf("please enter your requirement\n");
    printf("1: Append records\n2: Delete records\n");
    printf("3: Modify records\n4: Querying records\n");
    printf("5: consult records\nQ/q: quit\n");
    while(scanf("%d", &requirement) == 1) {
    	judge_ifvalid(&requirement);
        requi_swit_main(requirement);
        printf("Now your requirement is completed\n");
        printf("enter your next requirement, or enter Q/q to quit\n");
		system("cls");
		printf("----------------------- the Student Score Management System---------------------");
        printf("please enter your requirement\n");
        printf("1: Append records\n2: Delete records\n");
        printf("3: Modify records\n4: Querying records\n");
        printf("5: consult records\nQ/q: quit\n");
    }
    printf("Bye, see you next time!\n");
    return;
}`
