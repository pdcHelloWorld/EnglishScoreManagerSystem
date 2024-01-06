// 从文件中读取用户的信息
// read_users是“计算成绩”时候的读取用户信息函数，不含成绩
User *read_users(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filename);
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
// 根据姓名删除指定学生信息，返回新的头指针和被删除的学生信息
User **delete_user_by_name(User *head, char *name) {
    User *current = head;
    User *previous = NULL;
    User *deleted = NULL; // 定义一个指针变量，用来指向被删除的学生信息
    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("没有找到姓名为%s的学生\n", name);
        return NULL;
    }
    if (previous == NULL) {
        head = current->next;
        deleted = current; // 把被删除的学生信息赋值给deleted
    } else {
        previous->next = current->next;
        deleted = current; // 把被删除的学生信息赋值给deleted

    }
    User **result = (User **)malloc(sizeof(User *) * 2); // 定义一个指针的指针，用来返回两个指针
    result[0] = head; // 第一个指针是新的头指针
    result[1] = deleted; // 第二个指针是被删除的学生信息
    return result;
}

// 把学生信息保存到文件中
void save_users(User *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filename);
        return;
    }
    User *user = head;
    while (user != NULL) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        user = user->next;
    }
    fclose(fp);
    printf("学生信息保存至文件%s.\n", filename);
}

// 把被删除的学生记录保存到文件中
void save_deleted_record(User *deleted, char *filename) {
    FILE *fp = fopen(filename, "a"); // 以追加模式打开文件
    if (fp == NULL) {
        printf("文件%s打开失败\n", filename);
        return;
    }
    fprintf(fp, "%s专业%s班%s同学信息被删除\n", deleted->major, deleted->class, deleted->name);
    fclose(fp);
    printf("被删除的学生记录保存至文件%s.\n", filename);
}

// 删除学生信息的主函数
void DelInfo() {
    User *head = read_users("stu.txt");
    char name[100]; //存储要删除的学生的姓名
    ShowScore();
    printf("请输入要删除的学生的姓名：");
    scanf("%s", name);
    User **result = delete_user_by_name(head, name);
    if (result == NULL) { // 如果返回值为空，说明没有找到匹配的姓名，就直接返回
        return;
    }
    User *new_head = result[0]; // 获取新的头指针
    User *deleted = result[1]; // 获取被删除的学生信息
    free(result); // 释放内存
    save_users(new_head, "stu.txt");
    save_deleted_record(deleted, "stu1.txt"); // 调用save_deleted_record函数，把被删除的学生记录保存到另一个文件中
    free(deleted); // 释放内存
}
