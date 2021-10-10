#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main() {
    LinkStack stack = NULL;
    ElemType data;
    int op;

    system("clear");
    do {
        printf("\t栈应用测试\n");
        printf("*******************************\n");
        printf("*        1----初始化栈　  　　*\n");
        printf("*        2----链式进栈　  　　*\n");
        printf("*        3----链式出栈　　　　*\n");
        printf("*        4----链栈显示　　　　*\n");
        printf("*        0----退　　出　　　　*\n");
        printf("*******************************\n");

        printf("\t请选择菜单项(0－4)：");
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
                if (!res) {
                    printf("元素：%d 出栈成功，出栈后元素如下：\n", pop_data);
                    PrintStack(stack);
                } else if (res == -1)
                    printf("未创建新栈，无法出栈\n");
                else
                    printf("栈中元素为空，无法出栈\n");

                break;
            }

            case 4:
                if (stack) {
                    printf("栈中元素如下：\n");
                    PrintStack(stack);
                } else
                    printf("未创建新栈，无法显示\n");

                break;

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

// 创建空栈
LinkStack InitStack(void) {
    LinkStack new_stack = (StackNode *) calloc(1, sizeof(StackNode));
    if (new_stack) {
        new_stack->next = NULL;
        return new_stack;
    } else
        return NULL;
}

//
int PushStack(LinkStack stack, ElemType data) {
    if (!stack)
        return -1;
    else {
        StackNode *new_stack = (StackNode *) calloc(1, sizeof(StackNode));
        // 判断空间是否允许分配
        if (IsStackFull(new_stack))
            return -2;
        else {
            new_stack->data = data;
            new_stack->next = stack->next;
            stack->next = new_stack;

            return 0;
        }
    }
}

int PopStack(LinkStack stack, ElemType *pop_data) {
    if (!stack)
        return -1;
    else if (IsStackEmpty(stack))
        return -2;
    else {
        StackNode *del_stack = stack->next;
        stack->next = del_stack->next;
        *pop_data = del_stack->data;    // 保存出栈元素
        free(del_stack);

        return 0;
    }
}

void PrintStack(LinkStack stack) {
    if (!stack)
        printf("未创建栈，无法操作\n");
    else if (IsStackEmpty(stack)) {
        printf("栈中元素为空\n");
    } else {
        StackNode *tmp = stack->next;
        while (tmp) {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }

        printf("\n-- 输出完成 --\n\n");
    }
}

// 判断栈空
bool IsStackEmpty(LinkStack stack) {
    return stack->next == NULL;
}

// 判断栈满
bool IsStackFull(StackNode *node) {
    return node == NULL;
}

// 清空缓冲区
void buff_flash(void) {
    while (getchar() != '\n')
        continue;
}