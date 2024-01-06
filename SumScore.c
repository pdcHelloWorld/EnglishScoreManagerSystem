
typedef struct Class {
    int class_num; // �༶���
    int total_score; // �༶�ܷ�
    int student_count; // �༶����
    double average_score; // �༶ƽ����
    struct Class *next;
} Class;

// ����ͳ���ֺܷ�ƽ���֣�����һ��������ʾÿ���༶����Ϣ
Class *sum_score_by_class(User *head) {
    Class *class_head = NULL; // ָ��༶�����ͷ���
    Class *class_tail = NULL; // ָ��༶�����β���
    User *user = head; // ָ��ѧ�������ͷ���

    while (user != NULL) {
        Class *class = class_head; // ָ��༶�����ͷ���
        while (class != NULL) {
            if (class->class_num == atoi(user->class)) { // ����ҵ��˺͵�ǰ�û��İ༶��ͬ�Ľ�㣬������ѭ��
                break;
            }
            class = class->next; // �����classָ����һ����㣬����ѭ��
        }
        if (class == NULL) { // ���û���ҵ�ƥ��İ༶
            class = (Class *)malloc(sizeof(Class)); // �Ͷ�̬����һ���µĽ�㣬�����洢��ǰ�û��İ༶��Ϣ
            class->class_num = atoi(user->class); // �ѵ�ǰ�û��İ༶��ֵ���½���class_num�ֶ�
            class->total_score = 0;
            class->student_count = 0;
            class->average_score = 0.0;
            class->next = NULL;
            if (class_head == NULL) { // ����༶����Ϊ�գ��Ͱ��½����Ϊͷ����β���
                class_head = class;
                class_tail = class;
            } else { // ���򣬾Ͱ��½����뵽β���ĺ��棬������β���
                class_tail->next = class;
                class_tail = class;
            }
        }
        class->total_score += user->total_score; // �ѵ�ǰ�û����ּܷӵ��༶����total_score�ֶΣ���ʾ�ۼ�����༶���ܷ�
        class->student_count++; // �Ѱ༶����student_count�ֶμ�һ����ʾ�ۼ�����༶������
        user = user->next;
    }

    Class *class = class_head; // ѭ�������󣬰�classָ��༶�����ͷ���
    while (class != NULL) {
        class->average_score = (double)class->total_score / class->student_count; // ����༶ƽ����
        class = class->next;
    }

    return class_head;
}

// ��ӡ�༶�����е�����
void print_class(Class *class_head) {
    printf("�༶\t�ܷ�\tƽ����\n");
    Class *class = class_head;
    while (class != NULL) {
        printf("%d\t%d\t%.2f\n", class->class_num, class->total_score, class->average_score);
        class = class->next;
    }
}

// ����ͳ���ֺܷ�ƽ���ֵ�������
void SumScore() {
    User *head = read_users1("stu.txt");
    Class *class_head = sum_score_by_class(head);
    print_class(class_head);
}
