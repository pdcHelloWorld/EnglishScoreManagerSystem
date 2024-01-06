
// read_users1�ǳ��ˡ�����ɼ���ʱ��������Ҫ��ȡ��Ϣʱ�Ķ�ȡ�û���Ϣ���������гɼ�
User *read_users2(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("�޷����ļ�%s.\n", filename);
        return NULL;
    }
    char buffer[100];
    fgets(buffer, 100, fp);
    User *head = NULL;
    User *tail = NULL;
    while (fgets(buffer, 100, fp) != NULL) {
        User *user = (User *)malloc(sizeof(User));
        sscanf(buffer, "%s %s %s %s %d", user->major, user->class, user->name, user->answers,
               &user->total_score);
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
// ��stu.txt�ļ�����ʾȫ��ѧ���ɼ�
void ShowScore() {
    User *users = read_users2("stu.txt");
    printf("רҵ\t�༶\t����\t��\t�ܷ�\n");
    User *user = users;
    while (user != NULL) {
        printf("%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        user = user->next;
    }
}
