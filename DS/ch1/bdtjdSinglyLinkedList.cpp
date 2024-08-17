#include  <iostream>

typedef int ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};

typedef struct LNode LNode;//������һ�����ͱ��� LNode��ָ��ṹ������ struct LNode��
typedef struct LNode *LinkList;//������һ�����ͱ��� LinkList��ָ�� struct LNode ���͵�ָ�롣
//������2-9������һ����
// typedef struct LNode{
//     ElemType data;
//     struct LNode *next;
// }LNode, *LinkList;


bool InitList(LinkList &L)
{
    L = NULL; //��ʼ��һ���ձ�
    return true;
}

bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false; // ����λ����Ч

    LNode *s = (LNode *)malloc(sizeof(LNode)); // �����½ڵ�
    if (s == NULL)
        return false; // �ڴ����ʧ��

    s->data = e;    // �����½ڵ������
    s->next = NULL; // �½ڵ����һ���ڵ��ʼ��Ϊ��

    if (i == 1) // ���뵽����ͷ��
    {
        s->next = L; // �½ڵ����һ���ڵ�ָ��ԭ��������ͷ
        L = s;       // ��������ͷΪ�½ڵ�
        return true;
    }

    // ������ǲ��뵽ͷ�������ҵ�����λ�õ�ǰһ���ڵ�
    LNode *p = L;
    int j = 1;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }

    // ��� p Ϊ�գ�˵������λ�ó�����������
    if (p == NULL)
        return false;

    // �����½ڵ㵽 p ֮��
    s->next = p->next;
    p->next = s;

    return true;
}

// ��ӡ������
void PrintList(LinkList L) {
    LNode *p = L; // p ָ�������ͷ�ڵ�
    if (p == NULL) {
        std::cout << "����Ϊ��" << std::endl;
        return;
    }
    while (p->next != NULL) { // ��������ֱ�������ڶ����ڵ�
        std::cout << p->data << ", "; // ��ӡ��ǰ�ڵ�����ݣ�����ĩβ��Ӷ���
        p = p->next; // �ƶ�����һ���ڵ�
    }
    std::cout << p->data; // ��ӡ���һ���ڵ�����ݣ����Ӷ���
    std::cout << std::endl; // ��ӡ�����нڵ����
}

// ��������
void DestroyList(LinkList &L) {
    LNode *p = L;
    while (p != NULL) {
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
    L = NULL;
}
int main() {
    LinkList L;
    if (InitList(L)) {
        std::cout << "������LinkList��ʼ���ɹ���" << std::endl;
        // �������в���һЩԪ��
        if (ListInsert(L, 1, 25)) {
            std::cout << "����ɹ�" << std::endl;
    PrintList(L); // ���� PrintList �ѱ��޸��Խ�ʹ�� std::cout
} else {
    std::cout << "����ʧ��" << std::endl;
}
        // ListInsert(L, 1, 10);
        // ListInsert(L, 2, 20);
        // ListInsert(L, 3, 30);

        std::cout << "��ǰ������LΪ��"<<"";
        // ��ӡ����
        PrintList(L); // Ӧ�����: 10 20 30
        // �����������ͷ��ڴ�
        DestroyList(L);
    } else {
        std::cout << "������LinkList��ʼ��ʧ�ܣ�" << std::endl;
    }
    return 0;
}
//struct LNode * p = (struct LNode *) malloc(sizeof(struct LNode));
