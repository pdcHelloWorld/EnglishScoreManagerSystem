//所有头文件包含在这

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome();
//录入题目
void InputQuestion();
//答题
void AnsQuestion();
//计算成绩
void CalScore();
//显示成绩
void ShowScore();
//查询学生成绩
void QueryScore();
//删除学生信息
void DelInfo();
//统计学生成绩
void SumScore();
//成绩排序
void SortScore();
// 从文件中读取题目


//题目
typedef struct Question {
    char question[100];
    char answer;
    int score;
    struct Question *next;
} Question;

//用户的信息
typedef struct User {
    char major[100];
    char class[100];
    char name[100];
    char answers[10];
    int total_score;
    struct User *next;
} User;
#include "InputQuestion.c"
#include "AnsQuestion.c"
#include "DelInfo.c"
#include "QueryScore.c"
#include "ShowScore.c"
#include "SortScore.c"
#include "SumScore.c"
#include "CalScore.c"



void welcome() {
    system("cls");
    printf("学生英语成绩管理系统V24.01.01\n");
    printf("\t1.录入题目\n");
    printf("\t2.答题\n");
    printf("\t3.计算成绩\n");
    printf("\t4.显示成绩\n");
    printf("\t5.查询学生成绩\n");
    printf("\t6.删除学生信息\n");
    printf("\t7.统计学生成绩\n");
    printf("\t8.成绩排序\n");
    printf("\t0.退出程序\n");
}

int main() {
    int choice = 0;
    while (1) {
        welcome();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                system("cls");
                InputQuestion();
                break;
            case 2:
                system("cls");
                AnsQuestion();
                break;
            case 3:
                system("cls");
                CalScore();
                break;
            case 4:
                system("cls");
                ShowScore();
                break;
            case 5:
                system("cls");
                QueryScore();
                break;
            case 6:
                system("cls");
                DelInfo();
                break;
            case 7:
                system("cls");
                SumScore();
                break;
            case 8:
                system("cls");
                SortScore();
                break;
            case 0:
                system("exit");
                break;
        }
        printf("***********************\n");
        printf("1 - 继续；0 - 退出\n");
        scanf("%d",&choice);
        if(choice == 0) break;
    }

    return 0;
}
