

#ifndef FIFO_H
#define FIFO_H

#include <stdbool.h>
#include <stdint.h>
#include "Fifo_cfg.h"

// 通用FIFO缓冲区结构体
typedef struct {
    void *buffer;       // 指向数据缓冲区
    uint32_t item_size; // 每个元素的大小（字节）
    uint32_t capacity;  // 缓冲区最大存储元素数
    uint32_t head;      // 头索引（写入）
    uint32_t tail;      // 尾索引（读取）
    uint32_t count;     // 当前元素数
} fifo_t;

bool fifo_init(void);
void fifo_reset(fifo_t *fifo);
bool fifo_push(fifo_t *fifo,  void *data);
bool fifo_pop(fifo_t *fifo, void *data);
uint32_t fifo_size(fifo_t *fifo);
bool fifo_is_full(fifo_t *fifo);
bool fifo_is_empty( fifo_t *fifo);
#endif