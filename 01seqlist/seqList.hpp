#pragma once
#define N 100
#define SLDataType int
//从0开始依次存储
//静态数据结构，静态顺序表，不太实用
// N固定大小，想多存存不进去 
// 开小了不够用，开大了浪费
/*静态顺序表*/
// struct SeqList
// {
//     int a[N];
//     int size; //记录存储了多少数据
// };

/*动态顺序表*/


typedef struct SeqList
{
    SLDataType *a;
    int size; //存储的数据个数
    int capacity; //存储空间的大小，每次扩容一倍
}SL, SeqList;

//也可以用 SeqList &psl 引用这个语法。表示别名
void SeqListInit(SeqList* psl); //用指针是为了传指针直接拿地址修改数据
void SeqPrint(SeqList* psl);
void SeqListDestroy(SeqList* psl);

//尾上插一个 尾插 O(1)
void SeqListPushBack(SeqList *psl,SLDataType val);
//尾删 O(1)
void SeqListPopBack(SeqList *psl);

//头插 O(n)
void seqListPushFront(SeqList *psl,SLDataType val);
//头删 O(n)
void seqListPopFront(SeqList* psl);

//中间插入 O(n)
void seqListInsert(SeqList* psl, int index,SLDataType val); 

//中间删除 O(n)
void seqListErase(SeqList* psl, int index);

//查找
int seqListFind(SeqList* psl, SLDataType val);

//menu
void menu()
{
    //todo menu easy
    printf("*****************************\n");
    printf("1.尾插数据 2.头插数据\n");
    printf("2.尾删数据 3.头删数据\n");
    printf("3.插入数据 2.头插数据\n");
    printf("*****************************\n");
}