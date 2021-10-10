#include <stdbool.h>

#define QUEUE_SIZE 5

typedef int ElemType;
typedef struct {
    ElemType data[QUEUE_SIZE];
    int front;  // 队头(出列)
    int rear;   // 队尾(入列)
    int size;   // 队列长度
} Queue;

/* 初始化队列： InitQueue
   前置条件：无
   操作结果：初始化队列并返回队列指针 */
Queue *InitQueue(void);

/* 入队函数：AssignQueue
   前置条件：已有新队列queue，队列未满
   操作结果：使新元素从队头(front)入队，返回操作结果(bool)*/
bool AssignQueue(Queue *, ElemType);

/* 出队函数：ExitQueue
   前置条件：已有新队列queue，队列不为空
   操作结果：使队尾(rear)元素出队，返回操作结果(bool)*/
bool ExitQueue(Queue *);

/* 显示队列元素：PrintQueue
   前置条件：已有新队列queue
   操作结果：输出队列中所有元素结果 */
void PrintQueue(Queue *);

/* 判断队列是否为空：IsQueueEmpty
   前置条件：已有新队列queue
   操作结果：返回队列是否为空(bool) */
bool IsQueueEmpty(Queue *);

/* 判断队列是否为满：IsQueueFull
   前置条件：已有新队列queue
   操作结果：返回队列是否已满(bool) */
bool IsQueueFull(Queue *);

/* 清空缓冲区：buff_flash
   操作结果：清空缓冲区剩余字符 */
void buff_flash(void);