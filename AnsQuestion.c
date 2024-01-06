

//读取题目信息
Question *read_questions(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filename);
        return NULL;
    }
    char buffer[100];
    fgets(buffer, 100, fp);
    Question *head = NULL;
    Question *tail = NULL;
    while (fgets(buffer, 100, fp) != NULL) {
        Question *question = (Question *)malloc(sizeof(Question));
        sscanf(buffer, "%s %c %d", question->question, &question->answer, &question->score);
        question->next = NULL;
        if (head == NULL) {
            head = question;
            tail = question;
        } else {
            tail->next = question;
            tail = question;
        }
    }
    fclose(fp);
    return head;
}

// 答题函数
char answer_question(Question *question) {
    printf("%s\n", question->question);
    printf("你的答案: ");
    char answer;
    scanf("%c", &answer);
    getchar();
    while (answer != 'Y' && answer != 'N') {
        printf("请输入Y或N作为答案\n");
        scanf("%c", &answer);
        getchar();
    }
    return answer;
}

//让用户输入专业、班级、姓名，并将答案保存到文件中
void input_and_save_answers(char *filename, char *answers, int count) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filename);
        return;
    }
    char major[100];
    char class[100];
    char name[100];
    printf("请输入您的专业：");
    scanf("%s", major);
    printf("请输入您的班级：");
    scanf("%s", class);
    printf("请输入您的姓名：");
    scanf("%s", name);
    fprintf(fp, "%s\t%s\t%s\t", major, class, name);
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%c", answers[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
    printf("答案保存至文件%s.\n", filename);
}

//答题主函数
void AnsQuestion() {
    Question *head = read_questions("timu.txt");
    char answers[100];
    int count = 0; //记录题目的数量
    Question *question = head;
    while (question != NULL) {
        printf("第%d题: ", count + 1);
        answers[count] = answer_question(question); // 调用answer_question函数，显示题目，并返回用户的答案，存储到answers数组中
        count++;
        question = question->next; // 题目指针更新，遍历
    }
    input_and_save_answers("stu.txt", answers, count);
}
