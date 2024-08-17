#include <stdio.h>

typedef struct 
{
    int num; //号数
    int people; //人数
}Custome;

//顺序表的实现---静态分配
#define Maxize 10
typedef struct
{
    ElemType data[Maxize];//用静态的"数组"存放数据元素
    int length;//顺序表的当前长度
}SqList;//顺序表类型(静态分配方式)

//顺序表的实现---动态分配
#define InitSize 10 //初始分配内存空间
typedef struct{
    ElemType *data;//指示动态分配数组的指针
    int MaxSize;//顺序表的最大容量
    int length;//顺序表的类型定义（动态分配方式）
}SqList;

    // key:动态申请和释放内存空间
    // C ---malloc,free函数
    //     L.data = (ElemType *)malloc(sizeof(ElemType) *InitSize);
    // c++ --- new,delete关键字