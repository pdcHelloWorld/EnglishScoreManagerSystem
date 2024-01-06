

// 定义一个函数，用来实现按成绩从高到低对学生信息进行排序，使用插入排序算法
User *sort_users(User *head) {
    if (head == NULL || head->next == NULL) { // 如果链表为空或者只有一个结点，就直接返回
        return head;
    }
    User *sorted_head = head; // 指向已排序部分的头结点，初始化为原链表的头结点
    User *sorted_tail = head; // 指向已排序部分的尾结点，初始化为原链表的头结点
    User *unsorted_head = head->next; // 指向未排序部分的头结点，初始化为原链表的第二个结点
    sorted_tail->next = NULL; // 把已排序部分的尾结点的next字段置为NULL，表示已排序部分和未排序部分的分界

    while (unsorted_head != NULL) { // 遍历未排序部分
        User *unsorted_next = unsorted_head->next; // 保存unsorted_head的下一个结点，防止丢失
        User *sorted_prev = NULL; // 指向已排序部分的当前结点的前一个结点，初始化为NULL
        User *sorted_curr = sorted_head; // 指向已排序部分的当前结点，初始化为已排序部分的头结点
        while (sorted_curr != NULL) {
            if (unsorted_head->total_score > sorted_curr->total_score) { // 如果未排序部分的当前结点的总分大于已排序部分的当前结点的总分，就跳出循环
                break;
            }
            sorted_prev = sorted_curr;
            sorted_curr = sorted_curr->next; // 继续循环
        }
        if (sorted_prev == NULL) { // 如果循环结束后，sorted_prev仍然是NULL，说明未排序部分的当前结点应该插入到已排序部分的头部
            unsorted_head->next = sorted_head; // 把未排序部分的当前结点的next字段指向已排序部分的头结点
            sorted_head = unsorted_head; // 把已排序部分的头结点更新为未排序部分的当前结点
        } else { // 否则，说明未排序部分的当前结点应该插入到sorted_prev和sorted_curr之间
            unsorted_head->next = sorted_curr; // 把未排序部分的当前结点的next字段指向sorted_curr
            sorted_prev->next = unsorted_head; // 把sorted_prev的next字段指向未排序部分的当前结点
            if (sorted_curr == NULL) { // 如果sorted_curr是NULL，说明未排序部分的当前结点插入到了已排序部分的尾部
                sorted_tail = unsorted_head; // 把已排序部分的尾结点更新为未排序部分的当前结点
            }
        }
        unsorted_head = unsorted_next; // 把unsorted_head指向下一个结点，继续循环
    }

    return sorted_head; // 返回已排序部分的头结点A
}

// 定义一个函数，用来打印排序后的学生信息
void print_users(User *head) {
    printf("专业\t班级\t姓名\t答案\t总分\n");
    User *user = head;
    while (user != NULL) {
        printf("%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        User *temp = user;
        user = user->next;
        free(temp);
    }
}

// 排序主函数
void SortScore() {
    User *head = read_users1("stu.txt"); // 从文件中读取学生信息，返回链表的头指针
    User *sorted_head = sort_users(head); // 调用sort_users函数，按成绩从高到低对学生信息进行排序，返回一个链表
    print_users(sorted_head); // 调用print_users函数，打印排序后的学生信息
}
