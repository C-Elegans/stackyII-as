//
//  opcode.c
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "opcode.h"
char* ops[] = {"nop","add","push"};
uint16_t opcodes[] = {NOP,ADD,PUSH};
uint16_t lookup_opcode(char* opcode){
	for(int i=0;i<sizeof(ops)/sizeof(*ops) && i<sizeof(opcodes)/sizeof(*opcodes);i++){
		if(strcmp(opcode, ops[i])==0){
			return opcodes[i];
		}
	}
	printf("Invalid Opcode: %s\n",opcode);
	exit(-1);
	return 0;
}
uint16_t decodeInstruction(char* instruction,labelVector* labels){
	char* op = strtok(instruction, " ");
	char* data = strtok(NULL," ");
	uint16_t opcode = lookup_opcode(op);
	if(data == NULL){
		printf("op: %s \n",op);
		printf("opcode: %04x\n",opcode);
	}else{
		printf("op: %s data: %s\n",op,data);
		uint16_t modified_data = 0;
		
		fprintf(stderr,"opcode: %04x\n",opcode);
	}
	return 0;
}