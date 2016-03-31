The stacky-II instruction set is descended from my first (unnamed) stack based cpu, with a few minor differences.
Whereas my first cpu, henceforth known as stacky-I, had 8 and 16 bit instructions, stacky-II has only 16 bit ones
Stacky-I has 2 stacks, but had no ability to view memory more than 3 levels below the TOS
Stacky-II will have only one stack, but will have a Local instruction that reads values relative to an implicit stack frame
add: 0x0001, pops two values off the stack, adds them, and pushes the result onto the stack

sub: 0x0002, pops two values off the stack, subtracts the second from the first, and pushes the result

out: 0x0003, pops a value off of the stack and outputs it to the console (LEDs on the real thing)

in: 0x0004, does nothing right now

dup: 0x0005, duplicates the top of the stack

drop: 0x0006, pops the top of the stack

swap: 0x0007, swaps the top of the stack with the next value on the stack

rot: 0x0008, rotates the top 3 values

ret: 0x0009, returns from a subroutine

lt: 0x000A, pushes a 1 if the second value on the stack is less than the top of the stack, 0 otherwise

eq: 0x000B, pushes a 1 if the top two values on the stack are equal

gt: 0x000C, pushes a 1 if the second value on the stack is greater than the top of the stack, 0

neg: 0x000D, negates the top of the stack

leave:0x000E, moves the base pointer into the stack pointer. used to delete a stack frame

0x000F,0x0010, RESERVED

and: 0x0011, ands the top two values on the stack

or: 0x0012, ors the top two values on the stack

xor: 0x0013, exclusive ors the top two values on the stack

lshift/rshift: 0x0014/0x0015, shifts the 2nd value on the stack by the top of the stack

mul: 0x16, multiplies the top two values on the stack, and stores the lower half

fetch: 0x17, retrieves the value at the address at the top of the stack and pushes it onto the stack

store: 0x18, stores the 2nd value on the stack in program memory at the address on the top of the stack

************************DATA INSTRUCTIONS************************
these instructions use immediate data, encoded in the lower bits of the instruction.
the second value listed here is the mask for the allowable data bits
jump: 0x2000,0x1FFF - jumps to the relative address encoded in the instruction

call: 0x4000,0x1FFF - jumps to the relative address encoded in the instruction, and pushes the current ip on the stack

cjump: 0x6000,0x1FFF - pops the top of the stack, and jumps if the value is not zero

push: 0x8000,0x7FFF - pushes the immediate value onto the stack

frame: 0x0400, 0x03FF - pushes the base pointer on the stack, and creates space for X amount of variables 

local: 0x0800,0x03FF - reads the address formed by the immediate value+the base pointer and pushes it onto the stack

slocal: 0x0C00,0x3ff - pops the top off the stack and stores it at the immediate value + the base pointer