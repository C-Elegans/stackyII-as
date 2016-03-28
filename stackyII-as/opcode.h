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
#define PUSH 0x8000
#define NOP 0x0000
#define ADD 0x0001
uint16_t decodeInstruction(char*,labelVector*);
#endif /* opcode_h */
