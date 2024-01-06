//����ͷ�ļ���������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome();
//¼����Ŀ
void InputQuestion();
//����
void AnsQuestion();
//����ɼ�
void CalScore();
//��ʾ�ɼ�
void ShowScore();
//��ѯѧ���ɼ�
void QueryScore();
//ɾ��ѧ����Ϣ
void DelInfo();
//ͳ��ѧ���ɼ�
void SumScore();
//�ɼ�����
void SortScore();
// ���ļ��ж�ȡ��Ŀ


//��Ŀ
typedef struct Question {
    char question[100];
    char answer;
    int score;
    struct Question *next;
} Question;

//�û�����Ϣ
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
    printf("ѧ��Ӣ��ɼ�����ϵͳV24.01.01\n");
    printf("\t1.¼����Ŀ\n");
    printf("\t2.����\n");
    printf("\t3.����ɼ�\n");
    printf("\t4.��ʾ�ɼ�\n");
    printf("\t5.��ѯѧ���ɼ�\n");
    printf("\t6.ɾ��ѧ����Ϣ\n");
    printf("\t7.ͳ��ѧ���ɼ�\n");
    printf("\t8.�ɼ�����\n");
    printf("\t0.�˳�����\n");
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
        printf("1 - ������0 - �˳�\n");
        scanf("%d",&choice);
        if(choice == 0) break;
    }

    return 0;
}
