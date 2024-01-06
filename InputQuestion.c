
//�ṹ��洢��Ŀ����Ϣ
typedef struct node {
    char question[100]; //��Ŀ
    char answer; //��
    int score; //��ֵ
    struct node *next; //ָ����һ������ָ��
} node;

//����һ���µĽ��
node *create_node(char *question, char answer, int score) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) { //�ж��Ƿ�����ɹ�
        printf("����\n");
        return NULL;
    }//һһ��ֵ
    strcpy(new_node->question, question);
    new_node->answer = answer;
    new_node->score = score;
    new_node->next = NULL; //��ʼ��ָ����
    return new_node;
}

//¼����Ŀ
node *input_questions() {
    char *find;//find�����ҳ�fgets��������Ļ��з�
    node *head = NULL; //ͷָ��
    node *tail = NULL; //βָ��
    node *temp = NULL; //��ʱָ��
    char question[100];
    char answer;
    int score = 25;
    int count = 0; //��¼��Ŀ������
    while (count<4) {
        printf("��Ŀ %d: ", count + 1);
        fgets(question, 100, stdin);
        find = strchr(question, '\n');  //���һ��з�
        if(find) *find = '\0';  //����ҵ����з�����һ�����ַ���������
        printf("��: ");
        scanf("%c", &answer);
        getchar();
        temp = create_node(question, answer, score); //����һ���µĽ��
        if (temp == NULL) {
            printf("����\n");
            return head;
        }
        if (head == NULL) { //����Ϊ��
            head = temp;
            tail = temp;
        } else {
            tail->next = temp; //��β����ָ����ָ���½��
            tail = temp; //��βָ��ָ���½��
        }
        count++;
    }
    return head;
}

//��Ŀ���浽�ļ���
void save_to_file(node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "��Ŀ\t��\t��ֵ\t\n");
    node *p = head;
    int count = 0;
    while (p != NULL) { //ѭ����������
        fprintf(fp, "%s\t%c\t%d\n", p->question, p->answer, p->score);
        p = p->next;
        count++;
    }
    fclose(fp);
    printf("��Ŀ�ѱ��浽%s.\n", filename);
}



//�ͷ�����ռ�õ��ڴ�ռ�
void free_list(node *head) {
    node *p = head;
    node *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}
void InputQuestion(){
    printf("***************************************¼����Ŀ********************************************\n");
    node *head = input_questions();
    save_to_file(head, "timu.txt");
    free_list(head);
}




