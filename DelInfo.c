// ���ļ��ж�ȡ�û�����Ϣ
// read_users�ǡ�����ɼ���ʱ��Ķ�ȡ�û���Ϣ�����������ɼ�
User *read_users(char *filename) {
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
// ��������ɾ��ָ��ѧ����Ϣ�������µ�ͷָ��ͱ�ɾ����ѧ����Ϣ
User **delete_user_by_name(User *head, char *name) {
    User *current = head;
    User *previous = NULL;
    User *deleted = NULL; // ����һ��ָ�����������ָ��ɾ����ѧ����Ϣ
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("û���ҵ�����Ϊ%s��ѧ��\n", name);
        return NULL;
    }
    if (previous == NULL) {
        head = current->next;
        deleted = current; // �ѱ�ɾ����ѧ����Ϣ��ֵ��deleted
    } else {
        previous->next = current->next;
        deleted = current; // �ѱ�ɾ����ѧ����Ϣ��ֵ��deleted

    }
    User **result = (User **)malloc(sizeof(User *) * 2); // ����һ��ָ���ָ�룬������������ָ��
    result[0] = head; // ��һ��ָ�����µ�ͷָ��
    result[1] = deleted; // �ڶ���ָ���Ǳ�ɾ����ѧ����Ϣ
    return result;
}

// ��ѧ����Ϣ���浽�ļ���
void save_users(User *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("�ļ�%s��ʧ��\n", filename);
        return;
    }
    User *user = head;
    while (user != NULL) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        user = user->next;
    }
    fclose(fp);
    printf("ѧ����Ϣ�������ļ�%s.\n", filename);
}

// �ѱ�ɾ����ѧ����¼���浽�ļ���
void save_deleted_record(User *deleted, char *filename) {
    FILE *fp = fopen(filename, "a"); // ��׷��ģʽ���ļ�
    if (fp == NULL) {
        printf("�ļ�%s��ʧ��\n", filename);
        return;
    }
    fprintf(fp, "%sרҵ%s��%sͬѧ��Ϣ��ɾ��\n", deleted->major, deleted->class, deleted->name);
    fclose(fp);
    printf("��ɾ����ѧ����¼�������ļ�%s.\n", filename);
}

// ɾ��ѧ����Ϣ��������
void DelInfo() {
    User *head = read_users("stu.txt");
    char name[100]; //�洢Ҫɾ����ѧ��������
    ShowScore();
    printf("������Ҫɾ����ѧ����������");
    scanf("%s", name);
    User **result = delete_user_by_name(head, name);
    if (result == NULL) { // �������ֵΪ�գ�˵��û���ҵ�ƥ�����������ֱ�ӷ���
        return;
    }
    User *new_head = result[0]; // ��ȡ�µ�ͷָ��
    User *deleted = result[1]; // ��ȡ��ɾ����ѧ����Ϣ
    free(result); // �ͷ��ڴ�
    save_users(new_head, "stu.txt");
    save_deleted_record(deleted, "stu1.txt"); // ����save_deleted_record�������ѱ�ɾ����ѧ����¼���浽��һ���ļ���
    free(deleted); // �ͷ��ڴ�
}
