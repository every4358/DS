#include <iostream>

// 顺序表的实现---动态分配
#define InitSize 10 // 初始分配内存空间
typedef struct
{
    int *data;   // 指示动态分配数组的指针
    int MaxSize; // 顺序表的最大容量
    int length;  // 顺序表的类型定义（动态分配方式）
} SeqList;

//顺序表的基本操作---初始化
void InitList(SeqList &L)
{
    // 用malloc为L申请内存空间
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

//顺序表的基本操作---插入
bool ListInsert(SeqList &L, int i, int e)
{
    if (i<1 || i>L.length+1)// 判断插入位置是否合法
    {
        std::cout<<"插入位置不合法！"<<std::endl;
        return false;
    }
    if (L.length >= L.MaxSize)
    {
        std::cout<<"插入位置不合法！"<<std::endl;
        return false;
    }
    for(int j=L.length;j>=i;j--)//将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i-1]=e;//将e插入第i个元素
    L.length++;
    return true;
}

////顺序表的基本操作---删除
bool ListDelete(SeqList &L, int i, int &e)
{
    if(i<1 || i>L.length) //判断i的范围是否有效
        return false;
    e = L.data[i-1];
    for(int j=i; j<L.length; j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

//顺序表的基本操作---按位查找
int GetElem(SeqList L, int i)
{
    return L.data[i-1];
}

//顺序表的基本操作---按值查找
int LocateElem(SeqList L, int e)
{
    for(int i=0; i<L.length; i++)
        if(L.data[i]==e)
            return i+1;
    return 0;
}


// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data;
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i]; // 拷贝原数据到新区域
    L.MaxSize = L.MaxSize + len;// 更新MaxSize
    free(p);// 释放原内存
}

int main()
{
    SeqList L;   // 声明顺序表L
    InitList(L); // 初始化顺序表L
    // 往顺序表中随便插入几个元素
    for (int i = 0; i < L.MaxSize; i++)
    {
        L.data[i] = i;
        L.length++;
    }
    std::cout<<"顺序表L："<<"";
    for (int i = 0; i < L.length; i++)
        std::cout << L.data[i] << " ";
    // 增加顺序表的容量
    IncreaseSize(L, 5);
    std::cout << "L.length=" << L.length << std::endl;

    //插入元素后的顺序表
    ListInsert(L, 3, 4);
    std::cout<<"第3个位置插入元素4后的顺序表L："<<"";
    
    for(int i=0; i<L.length; i++)
        std::cout<<L.data[i]<<" ";
    std::cout << " L.length=" << L.length << std::endl;

    //删除第3个元素后的顺序表
    int e=-1;//用变量e把被删除的元素带回来
    if(ListDelete(L, 3, e))
    {
        printf("删除第3个位置的元素后L.length: ");
        for(int i=0; i<L.length; i++)
            std::cout<<L.data[i]<<" ";
        printf("L.length=%d\n", L.length);
    }
        
    else
        printf("删除失败\n");

    //按位查找
    GetElem(L, 9);
    std::cout<<"顺序表按位查找第9个位置的元素为："<<GetElem(L, 9)<<std::endl;
    //按值查找
    LocateElem(L, 8);
    std::cout<<"顺序表按值查找值为8的元素位置为："<<LocateElem(L, 9)<<std::endl;
    return 0;
}
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <iostream>

// // 顺序表的实现---动态分配
// #define InitSize 10 // 初始分配内存空间
// typedef struct {
//     int *data;       // 指示动态分配数组的指针
//     int MaxSize;     // 顺序表的最大容量
//     int length;      // 顺序表的当前长度
// } SeqList;

// void InitList(SeqList &L) {
//     // 使用new为L申请内存空间
//     L.data = new int[InitSize];
//     L.length = 0;
//     L.MaxSize = InitSize;
// }

// // 增加动态数组的长度
// void IncreaseSize(SeqList &L, int len) {
//     int *p = L.data;
//     L.data = new int[L.MaxSize + len];
//     for (int i = 0; i < L.length; i++)
//         L.data[i] = p[i]; // 拷贝原数据到新区域
//     L.MaxSize = L.MaxSize + len;
//     delete[] p;
// }

// int main() {
//     SeqList L; // 声明顺序表L
//     InitList(L); // 初始化顺序表L
//     // 往顺序表中随便插入几个元素
//     for (int i = 0; i < L.MaxSize; i++) {
//         L.data[i] = i;
//         L.length++;
//     }
//     // 打印顺序表中的元素
//     for (int i = 0; i < L.length; i++)
//         std::cout << L.data[i] << " ";
//     std::cout << std::endl;

//     // 增加顺序表的容量
//     IncreaseSize(L, 5);

//     // 打印增加容量后的顺序表状态
//     std::cout << "MaxSize after increase: " << L.MaxSize << std::endl;
//     std::cout << "Length after increase: " << L.length << std::endl;

//     // 释放内存
//     delete[] L.data;

//     return 0;
// }
