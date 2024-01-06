

// 从文件中读取用户的信息
// read_users是“计算成绩”时候的读取用户信息函数，不含成绩
User *read_users3(char *filename) {
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

// 计算用户的总分，并更新用户的信息
void calculate_score(User *user, Question *questions) {
    user->total_score = 0;
    Question *question = questions;
    int i = 0; // 记录题目的序号
    while (question != NULL) {
        //若用户答案等于问题答案则加分
        if (user->answers[i] == question->answer) {
            user->total_score += question->score;
        }
        i++;
        question = question->next;
    }
}

//将用户的信息和总分保存到文件中
void save_scores(char *filename, User *users) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("文件%s打开失败\n", filename);
        return;
    }
    fprintf(fp, "专业\t班级\t姓名\t答案\t总分\n");
    User *user = users;
    while (user != NULL) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        user = user->next;
    }
    fclose(fp);
    printf("成绩已保存到%s\n", filename);
}

// 计算成绩主函数
void CalScore() {
    Question *questions = read_questions("timu.txt");
    if (questions == NULL) {
        printf("题目读取失败\n");
        return;
    }
    User *users = read_users3("stu.txt");
    if (users == NULL) {
        printf("学生读取失败\n");
        return;
    }
    User *user = users;
    while (user != NULL) {
        calculate_score(user, questions);
        user = user->next;
    }
    save_scores("stu.txt", users);
}
