#include <stdlib.h>
#include <stdio.h>
#include "main.h"

// 线性表创建
SeqList *InitList(void) {
    SeqList *List = (SeqList *) calloc(1, sizeof(SeqList));
    if (List) {
        // 结构名不是元素首地址，需要解引用
        // 等同于L->length
        (*List).length = 0;
        return List;

    } else {
        return NULL;
    }
}

// 线性表初始化
void AssignSeqList(SeqList *List) {
    int var_length = 0;
    printf("输入初始化元素的个数：");
    scanf("%d", &var_length);

    if (var_length > MAXSIZE)
        printf("长度超过限制\n");
    else {
        (*List).length = var_length;
        for (int i = 0; i < var_length; i++) {
            printf("请输入第%d个元素：", i + 1);
            int flag = scanf("%d", &((*List).data[i]));

            // 非法输入时的处理
            if (!flag) {
                flash_buff();   // 清空缓冲区剩余输入
                // 重新读取输入
                while (!flag) {
                    printf("非法输入，请输入整数：");
                    flag = scanf("%d", &(*List).data[i]);
                    flash_buff();
                }
            }
        }

        printf("输入完毕\n");
        OutputSeqList(List);
    }
}

// 线性表输出
void OutputSeqList(SeqList *List) {
    printf("输出线性表存储数值：\n");
    for (int i = 0; i < (*List).length; i++) {
        printf("%d ", (*List).data[i]);
    }

    printf("\n");
}

// 线性表插入
int InsertList(SeqList *List, elemtype var, int index) {
    // 判断插入位置是否非法，长度是否大于线性表
    if (index <= 0 || index > MAXSIZE) {
        printf("插入位置非法\n");
    } else if ((*List).length == MAXSIZE) {
        printf("线性表已满\n");
    } else {
        // 从线性表后端开始往后移动元素一位，直到插入点为止
        for (int i = ((*List).length - 1); i > (index - 1); i--)
            (*List).data[i + 1] = (*List).data[i];

        // 在插入点处赋值
        (*List).data[index] = var;

        // 线性表长度加1
        (*List).length++;

        return index;
    }
    return FAIL;
}

// 线性表删除
void DelList(SeqList *List, int index) {
    // 查找准备删除的元素下标
    if (index > (*List).length) {
        printf("未找到指定位置的元素\n");
    } else {
        // 从指定下标开始向前移动元素（覆盖）
        for (int i = index; i < (*List).length; i++) {
            (*List).data[i] = (*List).data[i + 1];
        }

        printf("删除成功，在第%d位删除\n", index);
        OutputSeqList(List);
    }
}

// 线性表查找
int QueryList(SeqList *List, elemtype var) {
    int index;
    for (index = 0; index < (*List).length; index++)
        if ((*List).data[index] == var)
            break;

    if (index == (*List).length)
        return FAIL;

    return index + 1;
}

// 缓冲区清空函数
void flash_buff(void) {
    while (getchar() != '\n')
        continue;
}