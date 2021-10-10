#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void) {
    SeqQueue *queue = NULL;
    ElemType data = 0;
    int op = 0;

    system("clear");
    do {
        printf("\t队列子系统\n");
        printf("********************************\n");
        printf("*      1----初始化队列　  　　 *\n");
        printf("*      2----进 队 列　  　　   *\n");
        printf("*      3----出 队 列　　　　   *\n");
        printf("*      4----显示队列　　　　   *\n");
        printf("*      5----判断队列是否为空   *\n");
        printf("*      0----返　　回　　　　   *\n");
        printf("********************************\n");
        printf("\t请选择菜单项(0－5)：");
        scanf("%d", &op);
        buff_flash();

        printf("------------------------------\n");
        switch (op) {
            case 0:
                printf("退出系统\n");
                break;

            case 1: {
                queue = InitSeqQueue();
                if (queue)
                    printf("队列创建成功\n");
                else
                    printf("队列创建失败\n");

                break;
            }

            case 2: {
                printf("请输入需要入队的元素：");
                int flag = scanf("%d", &data);
                buff_flash();

                if (flag) {
                    if (AssignSeqQueue(queue, data)) {
                        printf("入队成功，队列中有以下元素：\n");
                        PrintSeqQueue(queue);
                    } else
                        printf("入队失败，未创建队列或队列已满\n");
                } else
                    printf("非法输入，无法操作\n");

                break;
            }

            case 3: {
                if (ExitSeqQueue(queue)) {
                    printf("出列成功，队列中有以下元素：\n");
                    PrintSeqQueue(queue);
                } else
                    printf("出列失败，未创建队列或队列为空\n");

                break;
            }

            case 4: {
                if (queue) {
                    printf("队列中有以下元素：\n");
                    PrintSeqQueue(queue);
                } else
                    printf("显示失败，未创建队列\n");

                break;
            }

            case 5: {
                if (queue) {
                    if (IsSeqQueueEmpty(queue))
                        printf("队列为空\n");
                    else
                        printf("队列非空\n");
                } else
                    printf("操作失败，未创建队列\n");

                break;
            }

            default:
                printf("没有这个选项，请重新选择\n");
                break;
        }

        printf("\n请按任意键继续...");
        getchar();
        system("clear");

    } while (op);

    return 0;
}

// 清空缓冲区函数
void buff_flash(void) {
    while (getchar() != '\n') continue;
}