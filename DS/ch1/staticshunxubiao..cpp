#include <stdio.h>

//˳����ʵ��---��̬����
#define MaxSize 10
typedef struct
{
    int data[MaxSize];//�þ�̬��"����"�������Ԫ��
    int length;//˳���ĵ�ǰ����
}SqList;//˳�������(��̬���䷽ʽ)



//��������---��ʼ��һ��˳���
void InitList(SqList &L){
    for(int i=0; i<MaxSize; i++)
        L.data[i]=0;//����������Ԫ������ΪĬ�ϳ�ʼֵ
    L.length=0; //˳����ʼ����Ϊ0
}

int main(){
    SqList L;//����˳���L
    InitList(L);//��ʼ��˳���L
    for(int i=0; i<MaxSize; i++)
        printf("data[%d] = %d\n", i,L.data[i]);
    printf("length = %d\n", L.length);
    return 0;

}


