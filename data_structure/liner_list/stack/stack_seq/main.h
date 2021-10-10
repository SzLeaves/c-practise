#ifndef SEQ_STACK_MAIN_H
#define SEQ_STACK_MAIN_H

// 顺序栈长度
#define STACK_MAXSIZE 100

#include <stdbool.h>

typedef int ElemType;
typedef struct {
    ElemType data[STACK_MAXSIZE];
    int top;
} ElemNode;
typedef ElemNode *SeqStack;

/* 初始化栈：InitStack
 * 初始条件：无
 * 操作结果：初始化新的顺序栈并返回地址*/
SeqStack InitStack(void);

/* 入栈函数：PushStack
 * 初始条件：已有新栈stack，栈未满
 * 操作结果：使指定元素入栈，栈指针加1*/
int PushStack(SeqStack, ElemType);

/* 出栈函数：PopStack
 * 初始条件：已有新栈stack，栈中有元素
 * 操作结果：使元素出栈，栈指针减1并取回出栈的元素*/
int PopStack(SeqStack, ElemType *);

/* 显示栈中元素：PrintStack
 * 初始条件：已有新栈stack
 * 操作结果：显示栈中所有元素*/
void PrintStack(SeqStack);

/* 判断栈是否为空：IsStackEmpty
 * 初始条件：已有新栈stack
 * 操作结果：判断栈内是否有元素并返回bool值*/
bool IsStackEmpty(SeqStack);

/* 判断栈是否已满：IsStackFull
 * 初始条件：已有新栈stack
 * 操作结果：判断栈是否已满并返回bool值*/
bool IsStackFull(SeqStack);

/* 测试-进制转换：BaseConversion
 * 初始条件：已有栈SeqStack，需要转换的进制与数值
 * 操作结果：通过栈结构转换十进制并返回转换后数值 */
char *BaseConversion(SeqStack, ElemType, int);

/* 清空缓冲区函数：buff_flash
 * 操作结果：清空缓冲区输入 */
void buff_flash(void);

#endif //SEQ_STACK_MAIN_H