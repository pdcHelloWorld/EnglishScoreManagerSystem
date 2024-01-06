
//这俩是多字段查询函数中的变量
char fields[2][10]; // 存储字段名
char values[2][10]; // 存储字段值
// read_users1是除了“计算成绩”时其他所需要读取信息时的读取用户信息函数，含有成绩
User *read_users1(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件%s.\n", filename);
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
// 单字段条件查询用户的信息
void query_by_one_field(User *head, char *field, char *value) {
    int found = 0; // 标志变量，记录是否找到匹配的用户
    printf("*****查询%s 为 %s*****\n", field, value); //field是所要查询的字段，value是该字段对应的量（词）
    User *user = head; // 定义一个用户指针，用来遍历链表，初始指向头指针
    while (user != NULL) { // 循环遍历链表，直到用户指针为空
        if (strcmp(field, "专业") == 0 && strcmp(user->major, value) == 0) {
            printf("专业：%s\t班级：%s\t姓名：%s\t答案：%s\t成绩：%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        } else if (strcmp(field, "班级") == 0 && strcmp(user->class, value) == 0) {
            printf("专业：%s\t班级：%s\t姓名：%s\t答案：%s\t成绩：%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        } else if (strcmp(field, "姓名") == 0 && strcmp(user->name, value) == 0) {
            printf("专业：%s\t班级：%s\t姓名：%s\t答案：%s\t成绩：%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        }
        user = user->next; // 将用户指针更新为下一个用户结构体，继续遍历
    }
    if (found == 0) {
        printf("找不到\n");
    }
}


//******下面是多字段的几个函数*********
// 比较用户结构体中的某个字段和用户输入的值是否相等
// user - 用户结构体指针，field - 字段名，value - 字段值
// 1 - 相等，0 - 不相等
int match(User *user, char *field, char *value) {
    if (strcmp(field, "专业") == 0 && strcmp(user->major, value) == 0) {
        return 1;
    } else if (strcmp(field, "班级") == 0 && strcmp(user->class, value) == 0) {
        return 1;
    } else if (strcmp(field, "姓名") == 0 && strcmp(user->name, value) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// 按多字段条件查询用户的信息
// head - 用户结构体链表的头指针，fields - 字段名数组，values - 字段值数组
void query_by_multi_fields(User *head, char fields[2][10], char values[2][10]) {
    int found = 0; // 标志变量
    printf("查询%s 为 %s 以及 %s 为 %s:\n", fields[0], values[0], fields[1], values[1]);
    User *user = head;
    while (user != NULL) { // 遍历链表
        int count = 0; // 记录匹配的字段个数
        for (int i = 0; i < 2; i++) { // 循环遍历用户输入的两个字段
            if (match(user, fields[i], values[i])) { // 如果字段匹配，增加计数
                count++;
            }
        }
        if (count == 2) { // 如果两个字段都匹配，输出
            printf("专业：%s\t班级：%s\t姓名：%s\t答案：%s\t成绩：%d\n", user->major, user->class, user->name, user->answers,
                   user->total_score);
            found = 1;
        }
        user = user->next;
    }
    if (found == 0) {
        printf("找不到\n");
    }
}


// 查询学生成绩的主函数
void QueryScore() {
    User *head = read_users1("stu.txt"); // 从文件中读取用户的信息，并返回一个链表的头指针
    char choice;
    char field[100]; // 查询条件的字段
    char value[100]; // 查询条件的值
    char field1[100]; // 多字段查询条件的第一个字段
    char value1[100]; // 多字段查询条件的第一个值
    char field2[100]; // 多字段查询条件的第二个字段
    char value2[100]; // 多字段查询条件的第二个值
    printf("选一个查询方式:\n");
    printf("1. 单字段查询\n");
    printf("2. 多字段查询\n");
    printf("3. 退出\n");
    scanf("%c", &choice);
    getchar();
    system("cls");
    switch (choice) {
        case '1': // 选择按单字段查询
            printf("输入要查找的字段(专业/班级/姓名):\n");
            scanf("%s", field);
            printf("输入你要查询的值:\n");
            scanf("%s", value);
            query_by_one_field(head, field, value); // 传入链表的头指针，进行单字段查询
            break;
        case '2': // 选择按多字段查询
            for (int i = 0; i < 2; i++) {
                printf("输入第%d个字段名(专业/班级/姓名):\n", i + 1);
                scanf("%s", fields[i]);
                printf("输入第%d个字段值:\n", i + 1);
                scanf("%s", values[i]);
            }
            query_by_multi_fields(head, fields, values); // 传入链表的头指针，进行多字段查询
            break;
        case '3':
            printf("再见\n");
            break;
        default:
            printf("只输入123哦\n");
            break;
    }
}
