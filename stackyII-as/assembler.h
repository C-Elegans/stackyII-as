//
//  assembler.h
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef assembler_h
#define assembler_h

#include <stdio.h>

void assemble_pass1(FILE* source);
void assemble_pass2(FILE* source, FILE* dest);
#endif /* assembler_h */
