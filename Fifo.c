#include "Fifo.h"


#include <stdint.h>
#include "Fifo_cfg.h"
static uint8_t fifo_heap[HEAP_SIZE];

static uint32_t heap_offset = 0;

extern fifo_t fifo_cfg[];



// 简单的malloc实现（不支持free）
void* my_malloc(uint32_t size) {
    if (heap_offset + size > HEAP_SIZE) return NULL;
    void* ptr = &fifo_heap[heap_offset];
    heap_offset += size;
    return ptr;
}
// 初始化FIFO，item_size为元素大小，capacity为最大元素数
  bool fifo_init(void)
{
    fifo_t *fifo;
    for(uint32_t i=0;i<FIFO_NUM;i++){
        fifo = &fifo_cfg[i];
        if (!fifo) return false;
        fifo->buffer = my_malloc(fifo->item_size * fifo->capacity);
        if (!fifo->buffer) return false;
        fifo->head = 0;
        fifo->tail = 0;
        fifo->count = 0;
    }
    return true;
}


// 释放FIFO资源
  void fifo_reset(fifo_t *fifo)
{
    if (fifo) {
        fifo->head = 0;
        fifo->tail = 0;
        fifo->count = 0;
    }
}

// 入队（写入），data为指向数据的指针
  bool fifo_push(fifo_t *fifo,  void *data)
{
    if (!fifo || !data || fifo->count == fifo->capacity) return false;
    memcpy((char*)fifo->buffer + fifo->head * fifo->item_size, data, fifo->item_size);
    fifo->head = (fifo->head + 1) % fifo->capacity;
    fifo->count++;
    return true;
}

// 出队（读取），data为指向接收数据的指针
  bool fifo_pop(fifo_t *fifo, void *data)
{
    if (!fifo || !data || fifo->count == 0) return false;
    memcpy(data, (char*)fifo->buffer + fifo->tail * fifo->item_size, fifo->item_size);
    fifo->tail = (fifo->tail + 1) % fifo->capacity;
    fifo->count--;
    return true;
}

// 获取FIFO当前元素数
  uint32_t fifo_size( fifo_t *fifo)
{
    return fifo ? fifo->count : 0;
}

// 判断FIFO是否已满
  bool fifo_is_full( fifo_t *fifo)
{
    return fifo && fifo->count == fifo->capacity;
}

// 判断FIFO是否为空
  bool fifo_is_empty( fifo_t *fifo)
{
    return fifo && fifo->count == 0;
}
