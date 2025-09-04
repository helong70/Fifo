
#include "Fifo.h"

fifo_t fifo_cfg[]={
    {
        .buffer = 0,
        .item_size = sizeof(int),
        .capacity = 10, 
        .head = 0, 
        .tail = 0, 
        .count = 0
    },
    {
        .buffer = 0,
        .item_size = sizeof(int),
        .capacity = 10, 
        .head = 0, 
        .tail = 0, 
        .count = 0
    },
    {
        .buffer = 0,
        .item_size = sizeof(int),
        .capacity = 10, 
        .head = 0, 
        .tail = 0, 
        .count = 0
    }
}