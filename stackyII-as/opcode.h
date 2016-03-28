//
//  opcode.h
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef opcode_h
#define opcode_h
#include <stdint.h>
#include "label_list.h"
#define NOP 0x0000
#define ADD 0x0001
#define SUB 2
#define OUT 3
#define IN 4
#define DUP 5
#define DROP 6
#define SWAP 7
#define ROT 8
#define RET 9
#define LT 10
#define EQ 11
#define GT 12
#define NEG 13
#define LEAVE 14
#define AND 17
#define OR 18
#define XOR 19
#define LSHIFT 20
#define RSHIFT 21
#define MUL 22
#define FETCH 23
#define STORE 24

#define FRAME 0x1000

#define LOCAL 0x3000
#define JUMP 0x2000
#define CALL 0x4000
#define CJUMP 0x6000
#define PUSH 0x8000
uint16_t decodeInstruction(char*,labelVector*,int);
#endif /* opcode_h */
