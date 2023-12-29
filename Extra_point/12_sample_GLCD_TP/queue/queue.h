#ifndef _QUEUE_H
#define _QUEUE_H

#include "../quoridor/quoridor.h"

int isEmpty(Coordinates *queue);
void initQueue(Coordinates *queue);
void enqueue(Coordinates *queue, Coordinates elem);
Coordinates dequeue(Coordinates *queue);
void clearQueue(Coordinates *queue);

#endif
