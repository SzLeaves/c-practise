#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main(void) {
    SeqStack stack = NULL;
    ElemType data;
    int op;

    system("clear");
    do {
        printf("\t栈应用测试\n");
        printf("*******************************\n");
        printf("*        1----初始化栈　  　　*\n");
        printf("*        2----顺序进栈　  　　*\n");
        printf("*        3----顺序出栈　　　　*\n");
        printf("*        4----顺序栈显示　　　*\n");
        printf("*        5----进制转换　　　　*\n");
        printf("*        0----退　　出　　　　*\n");
        printf("*******************************\n");

        printf("\t请选择菜单项(0－5)：");
        scanf("%d", &op);
        buff_flash();

        printf("-------------------------------\n");
        switch (op) {
            case 0:
                printf("退出系统\n");
                break;

            case 1:
                stack = InitStack();
                if (!stack)
                    printf("创建新栈失败，空间不足\n");
                else
                    printf("创建新栈成功\n");

                break;

            case 2: {
                printf("请输入需要入栈的数据：");
                scanf("%d", &data);
                buff_flash();

                int res = PushStack(stack, data);
                if (!res) {
                    printf("入栈成功，入栈后元素如下：\n");
                    PrintStack(stack);
                } else if (res == -1)
                    printf("未创建新栈，无法入栈\n");
                else
                    printf("栈已满，无法入栈");

                break;
            }

            case 3: {
                ElemType pop_data;
                int res = PopStack(stack, &pop_data);
                if (res == -1)
                    printf("未创建新栈，无法出栈\n");
                else if (res == -2)
                    printf("栈中元素为空，无法出栈\n");
                else {
                    printf("元素：%d 出栈成功，出栈后元素如下：\n", pop_data);
                    PrintStack(stack);
                }

                break;
            }

            case 4:
                if (stack) {
                    printf("栈中元素如下：\n");
                    PrintStack(stack);
                } else
                    printf("未创建新栈，无法显示\n");

                break;

            case 5: {
                int base;
                printf("请输入需要转换的十进制数和基数：");
                int correct = scanf("%d,%d", &data, &base);
                buff_flash();

                // 异常处理
                if (correct != 2) {
                    printf("输入数值有误，无法计算\n");
                    break;
                }

                SeqStack conver_stack = InitStack();
                char *res = BaseConversion(conver_stack, data, base);

                printf("转换后结果：%s\n", res);
                free(conver_stack);

                break;
            }

            default:
                printf("没有这个选项，请重新输入\n");
                break;
        }

        printf("请按回车键继续...\n");
        getchar();
        system("clear");

    } while (op);

    return 0;
}

// 初始化栈
SeqStack InitStack(void) {
    SeqStack new_stack = (ElemNode *) calloc(1, sizeof(ElemNode));
    if (!new_stack)
        return NULL;

    new_stack->top = -1;
    return new_stack;
}

// 入栈函数
int PushStack(SeqStack stack, ElemType data) {
    if (!stack)
        return -1;
    else if (IsStackFull(stack))
        return -2;
    else {
        int index = ++stack->top;
        stack->data[index] = data;
        return 0;
    }
}

// 出栈函数
int PopStack(SeqStack stack, ElemType *pop_data) {
    if (!stack)
        return -1;
    else if (IsStackEmpty(stack))
        return -2;
    else {
        *pop_data = stack->data[stack->top];
        stack->top--;
        return 0;
    }
}

// 显示栈中元素
void PrintStack(SeqStack stack) {
    if (!stack)
        printf("未创建栈，无法操作\n");
    else if (IsStackEmpty(stack))
        printf("栈内元素为空\n");
    else {
        int length = stack->top + 1;
        for (int i = 0; i < length; i++)
            printf("%d ", stack->data[i]);

        printf("\n-- 输出完成 --\n\n");
    }
}

// 判断栈是否为空
bool IsStackEmpty(SeqStack stack) {
    return stack->top == -1;
}

// 判断栈是否为满
bool IsStackFull(SeqStack stack) {
    return stack->top == STACK_MAXSIZE - 1;
}

// 进制转换
char *BaseConversion(SeqStack stack, ElemType data, int base) {
    // 0的任意进制转换都为0
    if (data == 0)
        return "0";

    // 对基数求余，余数入栈
    while (data) {
        int remainder = data % base;
        PushStack(stack, remainder);
        data = data / base;
    }

    int index = 0;
    int length = stack->top + 1;
    char *conver_num = (char *) calloc(length, sizeof(char));
    // 出栈输出倒序余数
    while (stack->top != -1) {
        ElemType pop_data = 0;
        PopStack(stack, &pop_data);
        // 判断十六进制转字符
        if (pop_data >= 0 && pop_data <= 9)
            conver_num[index] = pop_data + '0';
        else
            conver_num[index] = pop_data - 10 + 'a';

        index++;
    }

    return conver_num;
}

// 清空缓冲区
void buff_flash(void) {
    while (getchar() != '\n')
        continue;
}