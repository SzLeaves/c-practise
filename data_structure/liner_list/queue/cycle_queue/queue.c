#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

// 初始化队列
Queue *InitQueue(void) {
    Queue *queue = (Queue *) calloc(1, sizeof(Queue));
    if (queue)
        return queue;
    else
        return NULL;
}

// 入队函数
bool AssignQueue(Queue *queue, ElemType data) {
    // 创建队列和队列已满的情况
    if (!queue || IsQueueFull(queue))
        return false;

    queue->data[queue->rear] = data;

    // 队尾指针到数组末端时指向数组首元素
    if (queue->rear + 1 == QUEUE_SIZE)
        queue->rear = 0;
    else
        queue->rear++;

    // 队列长度增加
    queue->size++;
    return true;
}

// 出队函数
bool ExitQueue(Queue *queue) {
    // 创建队列和队列为空的情况
    if (!queue || IsQueueEmpty(queue))
        return false;

    // 队头指针到数组末端时指向数组首元素
    if (queue->front + 1 == QUEUE_SIZE)
        queue->front = 0;
    else
        queue->front++;

    // 队列长度减少
    queue->size--;
    return true;
}

// 显示队列元素
void PrintQueue(Queue *queue) {
    int length = 0;
    for (int index = queue->front; length < queue->size; length++) {
        if (index == QUEUE_SIZE)
            index = 0;

        printf("%d ", queue->data[index]);
        index++;
    }

    if (!length)
        printf("\n-- 队列为空 --\n");
    else
        printf("\n-- 输出完成 --\n");
}

// 判断队列是否为空
bool IsQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

// 判断队列是否为满
bool IsQueueFull(Queue *queue) {
    return queue->size == QUEUE_SIZE;
}