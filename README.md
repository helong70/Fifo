# Fifo 项目说明

## 项目简介
本项目实现了一个通用的 FIFO（先进先出队列）数据结构，支持不同类型数据的存储和操作。包含自定义内存分配、队列初始化、入队、出队等基本功能。

## 文件结构
- `Fifo.c`：FIFO 功能实现，包括初始化、入队、出队等。
- `Fifo.h`：FIFO 相关结构体和函数声明。
- `Fifo_cfg.c`：FIFO 配置示例，展示不同类型队列的初始化。
- `Fifo_cfg.h`：FIFO 配置相关声明。

## 主要结构体
```c
// Fifo.h 中定义
typedef struct {
    void *buffer;      // 数据缓冲区指针
    size_t item_size;  // 单个元素大小
    size_t capacity;   // 队列容量
    size_t head;       // 队列头索引
    size_t tail;       // 队列尾索引
    size_t count;      // 当前元素数量
} fifo_t;
```

## 主要接口
- `bool fifo_init(void);`  // 初始化队列
- `void fifo_free(fifo_t *fifo);`                                    // 释放队列资源
- `bool fifo_push(fifo_t *fifo, const void *data);`                  // 入队
- `bool fifo_pop(fifo_t *fifo, void *data);`                         // 出队
- `size_t fifo_size(fifo_t *fifo);`                                  // 获取队列元素数
- `bool fifo_is_full(fifo_t *fifo);`                                 // 判断队列是否满
- `bool fifo_is_empty(fifo_t *fifo);`                                // 判断队列是否空

## 使用方法
1. 包含头文件 `#include "Fifo.h"`
2. 定义并初始化 `fifo_t` 结构体
3. 调用 `fifo_init` 分配缓冲区
4. 使用 `fifo_push` 和 `fifo_pop` 操作队列
5. 使用完毕后调用 `fifo_free` 释放资源

## 示例
```c
fifo_t my_fifo;
fifo_init(&my_fifo, sizeof(int), 10);
int value = 123;
fifo_push(&my_fifo, &value);
fifo_pop(&my_fifo, &value);
fifo_free(&my_fifo);
```

## 许可证
MIT License
