
//结构体存储题目的信息
typedef struct node {
    char question[100]; //题目
    char answer; //答案
    int score; //分值
    struct node *next; //指向下一个结点的指针
} node;

//创建一个新的结点
node *create_node(char *question, char answer, int score) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) { //判断是否申请成功
        printf("出错\n");
        return NULL;
    }//一一赋值
    strcpy(new_node->question, question);
    new_node->answer = answer;
    new_node->score = score;
    new_node->next = NULL; //初始化指针域
    return new_node;
}

//录入题目
node *input_questions() {
    char *find;//find用于找出fgets函数读入的换行符
    node *head = NULL; //头指针
    node *tail = NULL; //尾指针
    node *temp = NULL; //临时指针
    char question[100];
    char answer;
    int score = 25;
    int count = 0; //记录题目的数量
    while (count<4) {
        printf("题目 %d: ", count + 1);
        fgets(question, 100, stdin);
        find = strchr(question, '\n');  //查找换行符
        if(find) *find = '\0';  //如果找到换行符，把一个空字符放在这里
        printf("答案: ");
        scanf("%c", &answer);
        getchar();
        temp = create_node(question, answer, score); //创建一个新的结点
        if (temp == NULL) {
            printf("出错\n");
            return head;
        }
        if (head == NULL) { //链表为空
            head = temp;
            tail = temp;
        } else {
            tail->next = temp; //将尾结点的指针域指向新结点
            tail = temp; //将尾指针指向新结点
        }
        count++;
    }
    return head;
}

//题目保存到文件中
void save_to_file(node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "题目\t答案\t分值\t\n");
    node *p = head;
    int count = 0;
    while (p != NULL) { //循环遍历链表
        fprintf(fp, "%s\t%c\t%d\n", p->question, p->answer, p->score);
        p = p->next;
        count++;
    }
    fclose(fp);
    printf("题目已保存到%s.\n", filename);
}



//释放链表占用的内存空间
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
    printf("***************************************录入题目********************************************\n");
    node *head = input_questions();
    save_to_file(head, "timu.txt");
    free_list(head);
}




