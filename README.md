# Imaginary-Virtual-Machine
This project is a C-based implementation of an Imaginary Machine Language (IML) Virtual Machine. The VM simulates a simple computer architecture with registers, memory, and a custom instruction set. 

IML rules
The first two digits of each IML instruction are the operation code (opcode). 
operations supported by IML include

o READ = 12; Read a word from the keyboard into a specified memory
location. The first operand is the memory location. The second operand is
unused.

o WRITE = 11; Write a word from a specific location to the screen. The first
operand is the memory location. The second operand is unused.

o LOAD = 22; Load a word from a specific location in memory into a specific
register. The first operand is a register. The second operand is the memory
location.

o STORE = 21; Store the word from a specific register into a specific location in
memory. The first operand is the register. The second operand is the memory
location.

o ADD = 31; Add the values in two registers. Leave the result in the first
register listed. Both operands are registers.

o SUBTRACT = 32; Start with the value in the first register listed and
subtract the value in the second register listed. Leave the result in the first
register. Both operands are registers.

o MULTIPLY = 33; Multiply the values in two specific registers. Leave the
result in the first register. Both operands are registers.

o DIVIDE = 34; Start with the value in the first register listed and divide by the
value in the second register listed. Leave the result in the first register. Both
operands are registers.

o BRANCH = 41;Jump to a specific location in memory. The first operand is a
memory location. The second operand is unused. (Set the program counter to
the specified memory location.)

o BRANCHZERO = 42; Jump to a specific location in memory if a specific
register contains zero. The first operand is a memory location. The second
operand is a register.

o BRANCHPOS = 43; Jump to a specific location in memory if a specific
memory location contains a value greater than zero. The first operand is a
memory location. The second operand is a register.

o HALT = 99; Stop. No operands.
