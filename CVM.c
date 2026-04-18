#include "Cword.h"   // defines MemWord, buildMemWord(), debugMemWord()
#include <stdio.h>

#define MEM_SIZE 100
#define REG_SIZE 5




void run(MemWord ram[], MemWord reg[], int pc) {
    int done = 0;  // C has no boolean, 0 = false, 1 = true
    
    while (1) {  // while(true) in C
        // FETCH
        int opCode = ram[pc].opCode;
        int param1 = ram[pc].param1;
        int param2 = ram[pc].param2;
        
        // DECODE AND EXECUTE
        switch(opCode) {
            case 11: // WRITE
                printf("%d\n", getData(ram[param1]));
                break;
                
            case 12: // READ
                printf("Enter data:\n");
                int input;
                scanf("%d", &input);
                ram[param1] = setData(input);
                break;
                
            case 21: // STORE
                ram[param2] = setData(getData(reg[param1]));
                break;
                
            case 22: // LOAD
                reg[param1] = setData(getData(ram[param2]));
                break;
                
            case 31: // ADD
                reg[param1] = setData(getData(reg[param1]) + getData(reg[param2]));
                break;
                
            case 32: // SUBTRACT
                reg[param1] = setData(getData(reg[param1]) - getData(reg[param2]));
                break;
                
            case 33: // MULTIPLY
                reg[param1] = setData(getData(reg[param1]) * getData(reg[param2]));
                break;
                
            case 34: // DIVIDE
                reg[param1] = setData(getData(reg[param1]) / getData(reg[param2]));
                break;
                
            case 41: // BRANCH
                pc = param1;
                break;
                
            case 42: // BRANCHZERO
                if (getData(reg[param2]) == 0)
                    pc = param1;
                else
                    pc++;
                break;
                
            case 43: // BRANCHPOS
                if (getData(reg[param2]) > 0)
                    pc = param1;
                else
                    pc++;
                break;
                
            case 99: // HALT
                done = 1;
                break;
        }
        
        // Increment PC if this wasn't a branch
        if (opCode > 43 || opCode < 41)
            pc++;
            
        if (done) break;
    }

    
}

int main() {
    MemWord ram[MEM_SIZE];
    MemWord reg[REG_SIZE];
    int pc = 0;
    int i;              // declare i once here at the top
    int data;
    char filename[100];

    // Initialize memory and registers to zero
    for (i = 0; i < MEM_SIZE; i++)
        ram[i] = setData(0);
    for (i = 0; i < REG_SIZE; i++)
        reg[i] = setData(0);

    // Prompt user for filename
    printf("Please enter the file name of the program to load:\n");
    scanf("%s", filename);

    // Open the file
    FILE *inFile = fopen(filename, "r");
    if (inFile == NULL) {
        printf("Illegal file.\n");
        return 1;
    }

    // Load program into ram
    i = 0;
    while (fscanf(inFile, "%d", &data) == 1 && i < MEM_SIZE) {
        ram[i] = setData(data);
        i++;
    }
    fclose(inFile);

    run(ram, reg, pc); //call run on the loaded Ram and possible loaded registers

    // Memory dump after HALT
printf("\n\nMemory dump:\n");
for (i = 0; i < MEM_SIZE; i++) {
    printf("%02d ", i);
    debugMemWord(ram[i]);
}

    return 0;
}




