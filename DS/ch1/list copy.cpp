#include <stdio.h>

typedef struct 
{
    int num; //����
    int people; //����
}Custome;

//˳����ʵ��---��̬����
#define Maxize 10
typedef struct
{
    ElemType data[Maxize];//�þ�̬��"����"�������Ԫ��
    int length;//˳���ĵ�ǰ����
}SqList;//˳�������(��̬���䷽ʽ)

//˳����ʵ��---��̬����
#define InitSize 10 //��ʼ�����ڴ�ռ�
typedef struct{
    ElemType *data;//ָʾ��̬���������ָ��
    int MaxSize;//˳�����������
    int length;//˳�������Ͷ��壨��̬���䷽ʽ��
}SqList;

    // key:��̬������ͷ��ڴ�ռ�
    // C ---malloc,free����
    //     L.data = (ElemType *)malloc(sizeof(ElemType) *InitSize);
    // c++ --- new,delete�ؼ���