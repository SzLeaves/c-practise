#include <stdio.h>
#include <stdlib.h>
#include "main.h"

// 初始化链表
LinkList InitLinkList(void) {
    LinkList new_list = (LinkNode *) calloc(1, sizeof(LinkNode));
    if (!new_list) {
        return NULL;

    } else {
        printf("-- create list SUCCESSFUL --\n");
        new_list->next = NULL;
        return new_list;
    }
}

// 计算长度
int ListLength(LinkList list) {
    int length = 0;
    LinkNode *tmp = list->next;

    while (tmp) {
        length++;
        tmp = tmp->next;
    }

    return length;
}

// 添加节点
void AddNode(LinkList list) {
    int index = 0, length = 0;
    ElemType tmp_num = 0;

    LinkNode *tmp_node = list;
    LinkNode *new_node;

    printf("please enter length: ");

    scanf("%d", &length);

    printf("please enter number: ");
    for (index = 0; index < length; index++) {
        scanf("%d", &tmp_num);

        new_node = (LinkNode *) calloc(0, sizeof(LinkNode));
        new_node->data = tmp_num;
        new_node->next = NULL;

        tmp_node->next = new_node;
        tmp_node = tmp_node->next;

    }

    printf("-- add node SUCCESSFUL --\n");
}

// 插入节点
int InsertLinkList(LinkList list, ElemType data, int index) {
    int i;
    int length = ListLength(list);
    LinkNode *tmp_node = list;
    LinkNode *new_node;

    index = index - 1;
    if (index < length) {
        for (i = 0; i < index; i++) {
            tmp_node = tmp_node->next;
        }

        new_node = (LinkNode *) calloc(1, sizeof(LinkNode));
        new_node->data = data;
        new_node->next = tmp_node->next;
        tmp_node->next = new_node;

        printf("-- insert node SUCCESSFUL --\n");

    } else {
        printf("** location failed, out of ranges **\n");
        index = -1;
    }

    return index;

}

// 删除节点
int DeleteLinkList(LinkList list, int index) {
    int i = 0;
    int length = ListLength(list);
    LinkNode *tmp_node = list;
    LinkNode *del_node;

    if (index < length) {
        while (tmp_node->next != NULL && i != index - 1) {
            tmp_node = tmp_node->next;
            i++;
        }

        del_node = tmp_node->next;
        tmp_node->next = del_node->next;
        free(del_node);

        printf("-- delete node SUCCESSFUL --\n");

    } else {
        printf("** location failed, out of ranges **\n");
        index = -1;
    }

    return index;
}

// 查询节点
LinkNode *QueryLinkList(LinkList list, ElemType data) {
    LinkNode *tmp = list->next;

    while (tmp != NULL && tmp->data != data) {
        tmp = tmp->next;
    }

    return tmp;

}

// 输出节点
void PrintList(LinkList list) {
    LinkNode *tmp = list->next;
    while (tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n-- out list DONE --\n\n");
}
