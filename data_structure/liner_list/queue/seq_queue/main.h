#include <stdbool.h>

#define QUEUE_SIZE 5

typedef int ElemType;
typedef struct {
    ElemType data[QUEUE_SIZE];
    int front;  // 队头(出列)
    int rear;   // 队尾(入列)
} SeqQueue;

/* 初始化队列： InitSeqQueue
   前置条件：无
   操作结果：初始化队列并返回队列指针 */
SeqQueue *InitSeqQueue(void);

/* 入队函数：AssignSeqQueue
   前置条件：已有新队列queue，队列未满
   操作结果：使新元素从队头(front)入队，返回操作结果(bool)*/
bool AssignSeqQueue(SeqQueue *, ElemType);

/* 出队函数：ExitSeqQueue
   前置条件：已有新队列queue，队列不为空
   操作结果：使队尾(rear)元素出队，返回操作结果(bool)*/
bool ExitSeqQueue(SeqQueue *);

/* 显示队列元素：PrintSeqQueue
   前置条件：已有新队列queue
   操作结果：输出队列中所有元素结果 */
void PrintSeqQueue(SeqQueue *);

/* 判断队列是否为空：IsSeqQueueEmpty
   前置条件：已有新队列queue
   操作结果：返回队列是否为空(bool) */
bool IsSeqQueueEmpty(SeqQueue *);

/* 判断队列是否为满：IsSeqQueueFull
   前置条件：已有新队列queue
   操作结果：返回队列是否已满(bool) */
bool IsSeqQueueFull(SeqQueue *);

/* 清空缓冲区：buff_flash
   操作结果：清空缓冲区剩余字符 */
void buff_flash(void);