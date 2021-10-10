#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define FAIL -1

// ADT
typedef int elemtype;
typedef struct {
    elemtype data[MAXSIZE];
    int length;
} SeqList;


/*
    线性表创建：InitList()
    初始条件：线性表不存在
    操作结果：构造新的空线性表
*/
SeqList *InitList(void);

/*
    线性表初始化：AssignSeqList(Seqlist *)
    初始条件：表不存在数据
    操作结果：构造一个具体指定数值的线性表
*/
void AssignSeqList(SeqList *);

/*
    线性表输出：OutputSeqList(Seqlist *)
    初始条件：表存在数据
    操作结果：构造一个具体指定数值的线性表
*/
void OutputSeqList(SeqList *);

/*
    线性表插入：InsertList(Seqlist *, int, elemtype)
    初始条件：线性表存在，插入位置正确（1 <= i <= n+1）
    操作结果：在线性表的第 i 个位置上插入一个值为 x 的新元素
              返回插入后的节点下标
*/
int InsertList(SeqList *, elemtype, int);

/*
    线性表删除：DelList(Seqlist *, int)
    初始条件：线性表存在，删除位置正确（1 <= i <= n+1）
    操作结果：指定int序号并删除指定下标的元素
              在指定下标位置后一位前向移动（覆盖）元素
*/
void DelList(SeqList *, int);

/*
    线性表查找：QueryList(Seqlist *, elemtype)
    初始条件：线性表存在
    操作结果：查找elemtype指定的元素，如果查找成功返回找到的序号
              否则返回-1
*/
int QueryList(SeqList *, elemtype);

/*
    清空缓冲区：flash_buff()
    操作结果：清空输入缓冲区的剩余字符
*/
void flash_buff(void);
