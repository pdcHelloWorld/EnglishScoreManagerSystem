

// ����һ������������ʵ�ְ��ɼ��Ӹߵ��Ͷ�ѧ����Ϣ��������ʹ�ò��������㷨
User *sort_users(User *head) {
    if (head == NULL || head->next == NULL) { // �������Ϊ�ջ���ֻ��һ����㣬��ֱ�ӷ���
        return head;
    }
    User *sorted_head = head; // ָ�������򲿷ֵ�ͷ��㣬��ʼ��Ϊԭ�����ͷ���
    User *sorted_tail = head; // ָ�������򲿷ֵ�β��㣬��ʼ��Ϊԭ�����ͷ���
    User *unsorted_head = head->next; // ָ��δ���򲿷ֵ�ͷ��㣬��ʼ��Ϊԭ����ĵڶ������
    sorted_tail->next = NULL; // �������򲿷ֵ�β����next�ֶ���ΪNULL����ʾ�����򲿷ֺ�δ���򲿷ֵķֽ�

    while (unsorted_head != NULL) { // ����δ���򲿷�
        User *unsorted_next = unsorted_head->next; // ����unsorted_head����һ����㣬��ֹ��ʧ
        User *sorted_prev = NULL; // ָ�������򲿷ֵĵ�ǰ����ǰһ����㣬��ʼ��ΪNULL
        User *sorted_curr = sorted_head; // ָ�������򲿷ֵĵ�ǰ��㣬��ʼ��Ϊ�����򲿷ֵ�ͷ���
        while (sorted_curr != NULL) {
            if (unsorted_head->total_score > sorted_curr->total_score) { // ���δ���򲿷ֵĵ�ǰ�����ִܷ��������򲿷ֵĵ�ǰ�����ܷ֣�������ѭ��
                break;
            }
            sorted_prev = sorted_curr;
            sorted_curr = sorted_curr->next; // ����ѭ��
        }
        if (sorted_prev == NULL) { // ���ѭ��������sorted_prev��Ȼ��NULL��˵��δ���򲿷ֵĵ�ǰ���Ӧ�ò��뵽�����򲿷ֵ�ͷ��
            unsorted_head->next = sorted_head; // ��δ���򲿷ֵĵ�ǰ����next�ֶ�ָ�������򲿷ֵ�ͷ���
            sorted_head = unsorted_head; // �������򲿷ֵ�ͷ������Ϊδ���򲿷ֵĵ�ǰ���
        } else { // ����˵��δ���򲿷ֵĵ�ǰ���Ӧ�ò��뵽sorted_prev��sorted_curr֮��
            unsorted_head->next = sorted_curr; // ��δ���򲿷ֵĵ�ǰ����next�ֶ�ָ��sorted_curr
            sorted_prev->next = unsorted_head; // ��sorted_prev��next�ֶ�ָ��δ���򲿷ֵĵ�ǰ���
            if (sorted_curr == NULL) { // ���sorted_curr��NULL��˵��δ���򲿷ֵĵ�ǰ�����뵽�������򲿷ֵ�β��
                sorted_tail = unsorted_head; // �������򲿷ֵ�β������Ϊδ���򲿷ֵĵ�ǰ���
            }
        }
        unsorted_head = unsorted_next; // ��unsorted_headָ����һ����㣬����ѭ��
    }

    return sorted_head; // ���������򲿷ֵ�ͷ���A
}

// ����һ��������������ӡ������ѧ����Ϣ
void print_users(User *head) {
    printf("רҵ\t�༶\t����\t��\t�ܷ�\n");
    User *user = head;
    while (user != NULL) {
        printf("%s\t%s\t%s\t%s\t%d\n", user->major, user->class, user->name, user->answers, user->total_score);
        User *temp = user;
        user = user->next;
        free(temp);
    }
}

// ����������
void SortScore() {
    User *head = read_users1("stu.txt"); // ���ļ��ж�ȡѧ����Ϣ�����������ͷָ��
    User *sorted_head = sort_users(head); // ����sort_users���������ɼ��Ӹߵ��Ͷ�ѧ����Ϣ�������򣬷���һ������
    print_users(sorted_head); // ����print_users��������ӡ������ѧ����Ϣ
}
