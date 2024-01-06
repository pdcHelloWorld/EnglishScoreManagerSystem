

// ���ļ��ж�ȡ�û�����Ϣ
// read_users�ǡ�����ɼ���ʱ��Ķ�ȡ�û���Ϣ�����������ɼ�
User *read_users3(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�ļ�%s��ʧ��\n", filename);
        return NULL;
    }
    char buffer[100];
    fgets(buffer, 100, fp);
    User *head = NULL;
    User *tail = NULL;
    while (fgets(buffer, 100, fp) != NULL) {
        User *user = (User *)malloc(sizeof(User));
        sscanf(buffer, "%s %s %s %s", user->major, user->class, user->name, user->answers);
        user->next = NULL;
        if (head == NULL) {
            head = user;
            tail = user;
        } else {
            tail->next = user;
            tail = user;
        }
    }
    fclose(fp);
    return head;
}

// �����û����ܷ֣��������û�����Ϣ
void calculate_score(User *user, Question *questions) {
    user->total_score = 0;
    Question *question = questions;
    int i = 0; // ��¼��Ŀ�����
    while (question != NULL) {
        //���û��𰸵����������ӷ�
        if (user->answers[i] == question->answer) {
            user->total_score += question->score;
        }
        i++;
        question = question->next;
    }
}

//���û�����Ϣ���ֱܷ��浽�ļ���
void save_scores(char *filename, User *users) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("�ļ�%s��ʧ��\n", filename);
        return;
    }
    fprintf(fp, "רҵ\t�༶\t����\t��\t�ܷ�\n");
    User *user = users;
    while (user != NULL) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        user = user->next;
    }
    fclose(fp);
    printf("�ɼ��ѱ��浽%s\n", filename);
}

// ����ɼ�������
void CalScore() {
    Question *questions = read_questions("timu.txt");
    if (questions == NULL) {
        printf("��Ŀ��ȡʧ��\n");
        return;
    }
    User *users = read_users3("stu.txt");
    if (users == NULL) {
        printf("ѧ����ȡʧ��\n");
        return;
    }
    User *user = users;
    while (user != NULL) {
        calculate_score(user, questions);
        user = user->next;
    }
    save_scores("stu.txt", users);
}
