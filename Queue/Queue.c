// First In First Out

// Vipul Vaishanv
// Dated: 2022-04-17

// Array implementation of queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue
{
    int front, rear, size;
    unsigned int capacity;
    int *arr;
};

struct Queue *createQueue(unsigned int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int *)malloc(sizeof(int) * queue->capacity);
    return queue;
}

bool isFull(struct Queue *queue)
{
    if (queue->size == queue->capacity)
    {
        printf("Queue is Full\n");
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(struct Queue *queue)
{
    if (queue->size == 0)
    {
        printf("Queue is Empty\n");
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

int rear(struct Queue *queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

int traverseQueue(struct Queue *queue)
{
    for (int i = 0; i < queue->size; i++)
    {
        printf("%d\n", queue->arr[i]);
    }
}

int main(void)
{
    struct Queue *queue = createQueue(10);

    enqueue(queue, 20);
    enqueue(queue, 30);
    dequeue(queue);
    enqueue(queue, 40);

    traverseQueue(queue);

    return 0;
}