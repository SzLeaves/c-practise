#ifndef STACK_MAIN_H
#define STACK_MAIN_H

#include <stdbool.h>

// 新建基础数据类型
typedef int ElemType;
typedef struct node {
    ElemType data;
    struct node *next;
} StackNode;
typedef StackNode *LinkStack;

/* 创建空栈：InitStack
 * 前置条件：内存空间允许
 * 操作结果：新建并返回空栈的地址*/
LinkStack InitStack(void);

/* 入栈函数：PushStack
 * 前置条件：已新建栈stack
 * 操作结果：将指定的元素入栈，并返回操作是否成功*/
int PushStack(LinkStack, ElemType);

/* 出栈函数：PopStack
 * 前置条件L：已新建栈stack，栈中有元素
 * 操作结果：将栈顶部元素出栈，取回出栈元素并返回操作是否成功*/
int PopStack(LinkStack, ElemType *);

/* 显示栈中元素：PrintStack
 * 前置条件：已新建栈stack
 * 操作结果：显示栈中的所有元素*/
void PrintStack(LinkStack);

/* 判断栈空：IsStackEmpty
 * 前置条件：已新建栈stack
 * 操作结果：判断栈是否为空并返回bool值 */
bool IsStackEmpty(LinkStack);

/* 判断栈空：IsStackEmpty
 * 前置条件：已新建栈stack
 * 操作结果：判断栈是否为空并返回bool值 */
bool IsStackFull(StackNode *);

/* 清空缓冲区函数：buff_flash
 * 操作结果：清空缓冲区输入 */
void buff_flash(void);

#endif //STACK_MAIN_H
