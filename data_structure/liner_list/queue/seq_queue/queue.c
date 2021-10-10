#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "main.h"

// 初始化队列
SeqQueue *InitSeqQueue(void) {
    SeqQueue *queue = (SeqQueue *) calloc(1, sizeof(SeqQueue));
    if (queue)
        return queue;
    else
        return NULL;
}

// 入队函数
bool AssignSeqQueue(SeqQueue *queue, ElemType data) {
    // 创建队列和队列已满的情况
    if (!queue || IsSeqQueueFull(queue))
        return false;

    queue->data[queue->rear] = data;
    queue->rear++;

    return true;
}

// 出队函数
bool ExitSeqQueue(SeqQueue *queue) {
    // 创建队列和队列为空的情况
    if (!queue || IsSeqQueueEmpty(queue))
        return false;

    queue->front++;
    return true;
}

// 显示队列元素
void PrintSeqQueue(SeqQueue *queue) {
    int index = 0;
    for (index = queue->front; index < queue->rear; index++)
        printf("%d ", queue->data[index]);

    if (index == queue->front)
        printf("\n-- 队列为空 --\n");
    else
        printf("\n-- 输出完成 --\n");
}

// 判断队列是否为空
bool IsSeqQueueEmpty(SeqQueue *queue) {
    return queue->front == queue->rear;
}

// 判断队列是否为满
bool IsSeqQueueFull(SeqQueue *queue) {
    return queue->rear == QUEUE_SIZE;
}