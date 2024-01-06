
//�����Ƕ��ֶβ�ѯ�����еı���
char fields[2][10]; // �洢�ֶ���
char values[2][10]; // �洢�ֶ�ֵ
// read_users1�ǳ��ˡ�����ɼ���ʱ��������Ҫ��ȡ��Ϣʱ�Ķ�ȡ�û���Ϣ���������гɼ�
User *read_users1(char *filename) {
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
// ���ֶ�������ѯ�û�����Ϣ
void query_by_one_field(User *head, char *field, char *value) {
    int found = 0; // ��־��������¼�Ƿ��ҵ�ƥ����û�
    printf("*****��ѯ%s Ϊ %s*****\n", field, value); //field����Ҫ��ѯ���ֶΣ�value�Ǹ��ֶζ�Ӧ�������ʣ�
    User *user = head; // ����һ���û�ָ�룬��������������ʼָ��ͷָ��
    while (user != NULL) { // ѭ����������ֱ���û�ָ��Ϊ��
        if (strcmp(field, "רҵ") == 0 && strcmp(user->major, value) == 0) {
            printf("רҵ��%s\t�༶��%s\t������%s\t�𰸣�%s\t�ɼ���%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        } else if (strcmp(field, "�༶") == 0 && strcmp(user->class, value) == 0) {
            printf("רҵ��%s\t�༶��%s\t������%s\t�𰸣�%s\t�ɼ���%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        } else if (strcmp(field, "����") == 0 && strcmp(user->name, value) == 0) {
            printf("רҵ��%s\t�༶��%s\t������%s\t�𰸣�%s\t�ɼ���%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        }
        user = user->next; // ���û�ָ�����Ϊ��һ���û��ṹ�壬��������
    }
    if (found == 0) {
        printf("�Ҳ���\n");
    }
}


//******�����Ƕ��ֶεļ�������*********
// �Ƚ��û��ṹ���е�ĳ���ֶκ��û������ֵ�Ƿ����
// user - �û��ṹ��ָ�룬field - �ֶ�����value - �ֶ�ֵ
// 1 - ��ȣ�0 - �����
int match(User *user, char *field, char *value) {
    if (strcmp(field, "רҵ") == 0 && strcmp(user->major, value) == 0) {
        return 1;
    } else if (strcmp(field, "�༶") == 0 && strcmp(user->class, value) == 0) {
        return 1;
    } else if (strcmp(field, "����") == 0 && strcmp(user->name, value) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// �����ֶ�������ѯ�û�����Ϣ
// head - �û��ṹ�������ͷָ�룬fields - �ֶ������飬values - �ֶ�ֵ����
void query_by_multi_fields(User *head, char fields[2][10], char values[2][10]) {
    int found = 0; // ��־����
    printf("��ѯ%s Ϊ %s �Լ� %s Ϊ %s:\n", fields[0], values[0], fields[1], values[1]);
    User *user = head;
    while (user != NULL) { // ��������
        int count = 0; // ��¼ƥ����ֶθ���
        for (int i = 0; i < 2; i++) { // ѭ�������û�����������ֶ�
            if (match(user, fields[i], values[i])) { // ����ֶ�ƥ�䣬���Ӽ���
                count++;
            }
        }
        if (count == 2) { // ��������ֶζ�ƥ�䣬���
            printf("רҵ��%s\t�༶��%s\t������%s\t�𰸣�%s\t�ɼ���%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        }
        user = user->next;
    }
    if (found == 0) {
        printf("�Ҳ���\n");
    }
}


// ��ѯѧ���ɼ���������
void QueryScore() {
    User *head = read_users1("stu.txt"); // ���ļ��ж�ȡ�û�����Ϣ��������һ�������ͷָ��
    char choice;
    char field[100]; // ��ѯ�������ֶ�
    char value[100]; // ��ѯ������ֵ
    char field1[100]; // ���ֶβ�ѯ�����ĵ�һ���ֶ�
    char value1[100]; // ���ֶβ�ѯ�����ĵ�һ��ֵ
    char field2[100]; // ���ֶβ�ѯ�����ĵڶ����ֶ�
    char value2[100]; // ���ֶβ�ѯ�����ĵڶ���ֵ
    printf("ѡһ����ѯ��ʽ:\n");
    printf("1. ���ֶβ�ѯ\n");
    printf("2. ���ֶβ�ѯ\n");
    printf("3. �˳�\n");
    scanf("%c", &choice);
    getchar();
    system("cls");
    switch (choice) {
        case '1': // ѡ�񰴵��ֶβ�ѯ
            printf("����Ҫ���ҵ��ֶ�(רҵ/�༶/����):\n");
            scanf("%s", field);
            printf("������Ҫ��ѯ��ֵ:\n");
            scanf("%s", value);
            query_by_one_field(head, field, value); // ���������ͷָ�룬���е��ֶβ�ѯ
            break;
        case '2': // ѡ�񰴶��ֶβ�ѯ
            for (int i = 0; i < 2; i++) {
                printf("�����%d���ֶ���(רҵ/�༶/����):\n", i + 1);
                scanf("%s", fields[i]);
                printf("�����%d���ֶ�ֵ:\n", i + 1);
                scanf("%s", values[i]);
            }
            query_by_multi_fields(head, fields, values); // ���������ͷָ�룬���ж��ֶβ�ѯ
            break;
        case '3':
            printf("�ټ�\n");
            break;
        default:
            printf("ֻ����123Ŷ\n");
            break;
    }
}
