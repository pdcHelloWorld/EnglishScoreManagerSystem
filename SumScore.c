
typedef struct Class {
    int class_num; // 班级编号
    int total_score; // 班级总分
    int student_count; // 班级人数
    double average_score; // 班级平均分
    struct Class *next;
} Class;

// 按班统计总分和平均分，返回一个链表，表示每个班级的信息
Class *sum_score_by_class(User *head) {
    Class *class_head = NULL; // 指向班级链表的头结点
    Class *class_tail = NULL; // 指向班级链表的尾结点
    User *user = head; // 指向学生链表的头结点

    while (user != NULL) {
        Class *class = class_head; // 指向班级链表的头结点
        while (class != NULL) {
            if (class->class_num == atoi(user->class)) { // 如果找到了和当前用户的班级相同的结点，就跳出循环
                break;
            }
            class = class->next; // 否则把class指向下一个结点，继续循环
        }
        if (class == NULL) { // 如果没有找到匹配的班级
            class = (Class *)malloc(sizeof(Class)); // 就动态分配一个新的结点，用来存储当前用户的班级信息
            class->class_num = atoi(user->class); // 把当前用户的班级赋值给新结点的class_num字段
            class->total_score = 0;
            class->student_count = 0;
            class->average_score = 0.0;
            class->next = NULL;
            if (class_head == NULL) { // 如果班级链表为空，就把新结点作为头结点和尾结点
                class_head = class;
                class_tail = class;
            } else { // 否则，就把新结点插入到尾结点的后面，并更新尾结点
                class_tail->next = class;
                class_tail = class;
            }
        }
        class->total_score += user->total_score; // 把当前用户的总分加到班级结点的total_score字段，表示累加这个班级的总分
        class->student_count++; // 把班级结点的student_count字段加一，表示累加这个班级的人数
        user = user->next;
    }

    Class *class = class_head; // 循环结束后，把class指向班级链表的头结点
    while (class != NULL) {
        class->average_score = (double)class->total_score / class->student_count; // 计算班级平均分
        class = class->next;
    }

    return class_head;
}

// 打印班级链表中的数据
void print_class(Class *class_head) {
    printf("班级\t总分\t平均分\n");
    Class *class = class_head;
    while (class != NULL) {
        printf("%d\t%d\t%.2f\n", class->class_num, class->total_score, class->average_score);
        class = class->next;
    }
}

// 按班统计总分和平均分的主函数
void SumScore() {
    User *head = read_users1("stu.txt");
    Class *class_head = sum_score_by_class(head);
    print_class(class_head);
}
