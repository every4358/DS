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

//����ͷ�ڵ�
// bool InitList(LinkList &L)
// {
//     L = NULL; //��ʼ��һ���ձ�
//     return true;
// }

// ���� InsertNextNode ����
bool InsertNextNode(LNode *p, ElemType e);
bool InsertPriorNode (LNode *p, ElemType *s);

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // ����ͷ�ڵ�
    if (L == NULL) {
        // �ڴ����ʧ��
        return false;
    }
    L->next = NULL; // ͷ�ڵ�� next ָ����Ϊ NULL
    return true;
}

//������ָ���ڵ�����Ԫ��
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p; //ָ��Pָ��ǰɨ�赽�Ľڵ�
    int j = 0;//��ǰָ��pָ��ĵڼ����ڵ�
    p = L; //Lָ��ͷ�ڵ㣬ͷ�ڵ��ǵ�0���ڵ�(��������)
    while (p != NULL && j < i-1)
    {
        p = p->next; //pָ����һ���ڵ�
        j++;
    }
    return InsertNextNode(p, e);
    // if(p == NULL)
    //     return false;
    // LNode *s =(LNode *)malloc(sizeof(LNode));
    // if (s == NULL) { // ��� malloc �Ƿ�ɹ�
    //     return false;
    // }
    // s->data =e;
    // s->next=p->next;
    // p->next=s; //���ڵ�s����p֮��
    // //std::cout<<"����ɹ�"<<std::endl;
    // return true;
}

//������ָ�����֮�����Ԫ��e
bool InsertNextNode(LNode *p, ElemType e){
    if (p ==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)//�ڴ����ʧ��
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//ǰ���������p���֮ǰ������s
bool InsertPriorNode (LNode *p, ElemType *s){
    // if (p==NULL || s==NULL)
    //     return false;
    if (p==nullptr)
        return false;
    if (s==nullptr)
        return false;
    LNode *newNode = (LNode *)malloc(sizeof(LNode)); // �����½ڵ��ڴ�
    if (newNode == nullptr)
        return false; // �ڴ����ʧ��
    newNode->next = p->next;
    p->next = newNode;       // �����s���뵽p���֮��
    ElemType temp = p->data; // ����p��������
    p->data = newNode->data;
    newNode->data = temp;
    std::cout << "(����ӡͷ�ڵ�)��3�ڵ�֮ǰ����30�󣬵�����LΪ��"<<"";
    return true;

}

// //ǰ���������p���֮ǰ������s
// bool InsertPriorNode (LNode *p, ElemType *s){
//     if (p==NULL || s==NULL)
//         return false;
    
//     s->next = p->next;
//     p->next = s;    //�����s���뵽p���֮��
//     ElemType temp = p->data;    // ����p��������
//     p->data = s->data;
//     s->data = temp;
//     return true;

// }

// ��ӡ������
void PrintList(LinkList L) {
    LNode *p = L->next; // p ָ�������ͷ�ڵ����һ���ڵ�
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
//         // �������в���һЩԪ��
//         if (ListInsert(L, 1, 25)) {
//     std::cout << "����ɹ�" << std::endl;
//     PrintList(L); // ���� PrintList �ѱ��޸��Խ�ʹ�� std::cout
// } else {
//     std::cout << "����ʧ��" << std::endl;
// }
        std::cout << "��ʼ������LΪ��"<<"";
        // ��ӡ����
        PrintList(L);
        ListInsert(L, 1, 10);
        ListInsert(L, 2, 20);
        ListInsert(L, 3, 30);
        
        std::cout << "(����ӡͷ�ڵ�)��1��2��3�ڵ����10��20��30�󣬵�����LΪ��"<<"";
        // ��ӡ����
        PrintList(L); // Ӧ�����: 10 20 30
        ListInsert(L, 4, 40);
        std::cout << "(����ӡͷ�ڵ�)ListInsert(L, 4, 40)��4�ڵ����40�󣬵�����LΪ��"<<"";
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
