#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;

struct stackTable {
    int data[MAX];
    int top; 
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

void balikStack(stackTable &s);
void pushAscending(stackTable &s, int x);
void getInputStream(stackTable &s);

#endif
