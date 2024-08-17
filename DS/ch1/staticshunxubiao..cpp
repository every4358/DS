#include <stdio.h>

//顺序表的实现---静态分配
#define MaxSize 10
typedef struct
{
    int data[MaxSize];//用静态的"数组"存放数据元素
    int length;//顺序表的当前长度
}SqList;//顺序表类型(静态分配方式)



//基本操作---初始化一个顺序表
void InitList(SqList &L){
    for(int i=0; i<MaxSize; i++)
        L.data[i]=0;//将所有数据元素设置为默认初始值
    L.length=0; //顺序表初始长度为0
}

int main(){
    SqList L;//声明顺序表L
    InitList(L);//初始化顺序表L
    for(int i=0; i<MaxSize; i++)
        printf("data[%d] = %d\n", i,L.data[i]);
    printf("length = %d\n", L.length);
    return 0;

}


