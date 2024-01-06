
// read_users1是除了“计算成绩”时其他所需要读取信息时的读取用户信息函数，含有成绩
User *read_users2(char *filename) {
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
// 打开stu.txt文件，显示全部学生成绩
void ShowScore() {
    User *users = read_users2("stu.txt");
    printf("专业\t班级\t姓名\t答案\t总分\n");
    User *user = users;
    while (user != NULL) {
        printf("%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        user = user->next;
    }
}
