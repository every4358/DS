#include  <iostream>

typedef int ElemType;
struct LNode
{
    ElemType data;
    struct LNode *next;
};

typedef struct LNode LNode;//定义了一个类型别名 LNode，指向结构体类型 struct LNode。
typedef struct LNode *LinkList;//定义了一个类型别名 LinkList，指向 struct LNode 类型的指针。
//和上面2-9代码是一样的
// typedef struct LNode{
//     ElemType data;
//     struct LNode *next;
// }LNode, *LinkList;


bool InitList(LinkList &L)
{
    L = NULL; //初始化一个空表
    return true;
}

bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false; // 插入位置无效

    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    if (s == NULL)
        return false; // 内存分配失败

    s->data = e;    // 设置新节点的数据
    s->next = NULL; // 新节点的下一个节点初始化为空

    if (i == 1) // 插入到链表头部
    {
        s->next = L; // 新节点的下一个节点指向原来的链表头
        L = s;       // 更新链表头为新节点
        return true;
    }

    // 如果不是插入到头部，则找到插入位置的前一个节点
    LNode *p = L;
    int j = 1;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }

    // 如果 p 为空，说明插入位置超出了链表长度
    if (p == NULL)
        return false;

    // 插入新节点到 p 之后
    s->next = p->next;
    p->next = s;

    return true;
}

// 打印单链表
void PrintList(LinkList L) {
    LNode *p = L; // p 指向链表的头节点
    if (p == NULL) {
        std::cout << "链表为空" << std::endl;
        return;
    }
    while (p->next != NULL) { // 遍历链表直到倒数第二个节点
        std::cout << p->data << ", "; // 打印当前节点的数据，并在末尾添加逗号
        p = p->next; // 移动到下一个节点
    }
    std::cout << p->data; // 打印最后一个节点的数据，不加逗号
    std::cout << std::endl; // 打印完所有节点后换行
}

// 销毁链表
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
        std::cout << "单链表LinkList初始化成功！" << std::endl;
        // 向链表中插入一些元素
        if (ListInsert(L, 1, 25)) {
            std::cout << "插入成功" << std::endl;
    PrintList(L); // 假设 PrintList 已被修改以仅使用 std::cout
} else {
    std::cout << "插入失败" << std::endl;
}
        // ListInsert(L, 1, 10);
        // ListInsert(L, 2, 20);
        // ListInsert(L, 3, 30);

        std::cout << "当前单链表L为："<<"";
        // 打印链表
        PrintList(L); // 应该输出: 10 20 30
        // 销毁链表以释放内存
        DestroyList(L);
    } else {
        std::cout << "单链表LinkList初始化失败！" << std::endl;
    }
    return 0;
}
//struct LNode * p = (struct LNode *) malloc(sizeof(struct LNode));
