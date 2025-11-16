#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

void CreateQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enQueue(Queue &Q, const string &name);
void deQueue(Queue &Q);
void viewQueue(Queue Q);
void clearQueue(Queue &Q);

#endif