#include <stdio.h>
#include <stdlib.h> // for abs()


//define struct 
typedef struct {
    int opCode;
    int param1;
    int param2;
    int sign; // +1 or -1
} MemWord;




// setData equivalent - takes raw integer, loads into struct
MemWord setData(int data) {
    MemWord w;
    w.sign = (data < 0) ? -1 : 1;
    data = abs(data);
    w.opCode = data / 10000;
    data = data % 10000;
    w.param1 = data / 100;
    w.param2 = data % 100;
    return w;
}

// getData equivalent - reassembles struct back into raw integer
int getData(MemWord w) {
    int result = w.opCode * 10000 + w.param1 * 100 + w.param2;
    return (w.sign < 0) ? -result : result;
}

// Debug word
void debugMemWord(MemWord w) {
 
    int combinedWord = w.opCode*10000 + w.param1*100 + w.param2;
    if (w.sign < 0) combinedWord = -combinedWord;

    printf("Word: %+06d\n", combinedWord);        
    printf("Opcode: %02d\n", w.opCode);      
    printf("Param1: %02d\n", w.param1);      
    printf("Param2: %02d\n", w.param2);      
    printf("Sign: %c\n", (w.sign > 0) ? '+' : '-');
}

