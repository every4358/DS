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

//不带头节点
// bool InitList(LinkList &L)
// {
//     L = NULL; //初始化一个空表
//     return true;
// }

// 声明 InsertNextNode 函数
bool InsertNextNode(LNode *p, ElemType e);
bool InsertPriorNode (LNode *p, ElemType *s);

bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配头节点
    if (L == NULL) {
        // 内存分配失败
        return false;
    }
    L->next = NULL; // 头节点的 next 指针设为 NULL
    return true;
}

//单链表指定节点后插入元素
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p; //指针P指向当前扫描到的节点
    int j = 0;//当前指针p指向的第几个节点
    p = L; //L指向头节点，头节点是第0个节点(不存数据)
    while (p != NULL && j < i-1)
    {
        p = p->next; //p指向下一个节点
        j++;
    }
    return InsertNextNode(p, e);
    // if(p == NULL)
    //     return false;
    // LNode *s =(LNode *)malloc(sizeof(LNode));
    // if (s == NULL) { // 检查 malloc 是否成功
    //     return false;
    // }
    // s->data =e;
    // s->next=p->next;
    // p->next=s; //将节点s连到p之后
    // //std::cout<<"插入成功"<<std::endl;
    // return true;
}

//单链表指定结点之后插入元素e
bool InsertNextNode(LNode *p, ElemType e){
    if (p ==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)//内存分配失败
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//前插操作：在p结点之前插入结点s
bool InsertPriorNode (LNode *p, ElemType *s){
    // if (p==NULL || s==NULL)
    //     return false;
    if (p==nullptr)
        return false;
    if (s==nullptr)
        return false;
    LNode *newNode = (LNode *)malloc(sizeof(LNode)); // 分配新节点内存
    if (newNode == nullptr)
        return false; // 内存分配失败
    newNode->next = p->next;
    p->next = newNode;       // 将结点s插入到p结点之后
    ElemType temp = p->data; // 保存p结点的数据
    p->data = newNode->data;
    newNode->data = temp;
    std::cout << "(不打印头节点)在3节点之前插入30后，单链表L为："<<"";
    return true;

}

// //前插操作：在p结点之前插入结点s
// bool InsertPriorNode (LNode *p, ElemType *s){
//     if (p==NULL || s==NULL)
//         return false;
    
//     s->next = p->next;
//     p->next = s;    //将结点s插入到p结点之后
//     ElemType temp = p->data;    // 保存p结点的数据
//     p->data = s->data;
//     s->data = temp;
//     return true;

// }

// 打印单链表
void PrintList(LinkList L) {
    LNode *p = L->next; // p 指向链表的头节点的下一个节点
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
//         // 向链表中插入一些元素
//         if (ListInsert(L, 1, 25)) {
//     std::cout << "插入成功" << std::endl;
//     PrintList(L); // 假设 PrintList 已被修改以仅使用 std::cout
// } else {
//     std::cout << "插入失败" << std::endl;
// }
        std::cout << "初始单链表L为："<<"";
        // 打印链表
        PrintList(L);
        ListInsert(L, 1, 10);
        ListInsert(L, 2, 20);
        ListInsert(L, 3, 30);
        
        std::cout << "(不打印头节点)在1、2、3节点插入10、20、30后，单链表L为："<<"";
        // 打印链表
        PrintList(L); // 应该输出: 10 20 30
        ListInsert(L, 4, 40);
        std::cout << "(不打印头节点)ListInsert(L, 4, 40)在4节点插入40后，单链表L为："<<"";
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
