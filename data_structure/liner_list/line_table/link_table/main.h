#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} LinkNode;
typedef LinkNode *LinkList;

/* 链表初始化函数: InitLinkList
 * 前置条件：无
 * 后置条件：创建并初始化新链表，返回新链表头节点地址 */
LinkList InitLinkList(void);

/* 计算链表长度函数: List
 * 前置条件：已有新链表list
 * 后置条件：计算新链表list的节点数量（即长度）并返回 */
int ListLength(LinkList);

/* 添加节点函数: InitLinkList
 * 前置条件：已有新链表list
 * 后置条件：计算新链表list的节点数量（即长度）并返回 */
void AddNode(LinkNode *);

/* 插入节点函数：InsertLinkList
 * 前置条件：已有新链表list
 * 后置条件：在指定位置插入新的节点，返回插入的索引位置*/
int InsertLinkList(LinkNode *, ElemType, int);

/* 删除节点函数：DeleteLinkList
 * 前置条件：已有新链表list
 * 后置条件：在指定位置删除新的节点，返回删除的索引位置*/
int DeleteLinkList(LinkNode *, int);

/* 查询节点函数：QueryLinkList
 * 前置条件：已有新链表list
 * 后置条件：查找与节点数据域匹配的值，若找到则返回该节点地址*/
LinkNode *QueryLinkList(LinkNode *, ElemType);

/* 输出线性表函数：PrintList
 * 前置条件：已有新链表list
 * 后置条件：输出链表所有数据域的数值*/
void PrintList(LinkNode *);
