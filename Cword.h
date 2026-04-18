#ifndef CWORD_H
#define CWORD_H

typedef struct {
    int opCode;
    int param1;
    int param2;
    int sign;
} MemWord;


MemWord setData(int data);
int getData(MemWord w);
void debugMemWord(MemWord w);

#endif