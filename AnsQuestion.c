

//��ȡ��Ŀ��Ϣ
Question *read_questions(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�ļ�%s��ʧ��\n", filename);
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

// ���⺯��
char answer_question(Question *question) {
    printf("%s\n", question->question);
    printf("��Ĵ�: ");
    char answer;
    scanf("%c", &answer);
    getchar();
    while (answer != 'Y' && answer != 'N') {
        printf("������Y��N��Ϊ��\n");
        scanf("%c", &answer);
        getchar();
    }
    return answer;
}

//���û�����רҵ���༶�������������𰸱��浽�ļ���
void input_and_save_answers(char *filename, char *answers, int count) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("�ļ�%s��ʧ��\n", filename);
        return;
    }
    char major[100];
    char class[100];
    char name[100];
    printf("����������רҵ��");
    scanf("%s", major);
    printf("���������İ༶��");
    scanf("%s", class);
    printf("����������������");
    scanf("%s", name);
    fprintf(fp, "%s\t%s\t%s\t", major, class, name);
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%c", answers[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);
    printf("�𰸱������ļ�%s.\n", filename);
}

//����������
void AnsQuestion() {
    Question *head = read_questions("timu.txt");
    char answers[100];
    int count = 0; //��¼��Ŀ������
    Question *question = head;
    while (question != NULL) {
        printf("��%d��: ", count + 1);
        answers[count] = answer_question(question); // ����answer_question��������ʾ��Ŀ���������û��Ĵ𰸣��洢��answers������
        count++;
        question = question->next; // ��Ŀָ����£�����
    }
    input_and_save_answers("stu.txt", answers, count);
}
