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
char* ops[] = {"nop","add","sub","out","in","dup","drop","swap","rot","ret","lt","eq","gt","neg","leave","and","or","xor","lshift","rshift","mul","fetch","store","frame","local","jump","call","cjump","push"};
uint16_t opcodes[] = {NOP,ADD,SUB,OUT,IN,DUP,DROP,SWAP,ROT,RET,LT,EQ,GT,NEG,LEAVE,AND,OR,XOR,LSHIFT,RSHIFT,MUL,FETCH,STORE,FRAME,LOCAL,JUMP,CALL,CJUMP,PUSH};
uint16_t masks[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x0fff,0x0fff,0x1fff,0x1fff,0x1fff,0x7fff};
uint16_t lookup_opcode(char* opcode){
	
	for(int i=0;i<sizeof(ops)/sizeof(*ops) && i<sizeof(opcodes)/sizeof(*opcodes);i++){
		if(strcmp(opcode, ops[i])==0){
			return i;
		}
	}
	printf("Invalid Opcode: %s\n",opcode);
	exit(-1);
	return 0;
}
uint16_t decode_data(char* data,labelVector* labels){
	char* index;
	uint16_t data_val = 0;
	
	if((index = strchr(data, (int)':')) != NULL){
		*index = 0;
		label l = vector_find_label(labels, data);
		if(l.label == NULL){
			fprintf(stderr, "No definition found for label: %s",data);
		}
		data_val = l.address;
	}else{
		data_val = strtol(data, NULL, 0);
	}
	return data_val;
}
uint16_t decodeInstruction(char* instruction,labelVector* labels, int address){
	char* op = strtok(instruction, " ");
	char* data = strtok(NULL," ");
	int index = lookup_opcode(op);
	uint16_t opcode = opcodes[index];
	uint16_t mask = masks[index];
	if(data == NULL){
		printf("op: %s \n",op);
		printf("opcode: %04x\n",opcode);
	}else{
		printf("op: %s data: %s\n",op,data);
		uint16_t modified_data = decode_data(data, labels);
		if(opcode == JUMP || opcode == CALL || opcode == CJUMP){
			modified_data = address-modified_data;
		}
		opcode |= modified_data & mask;
		
		printf("opcode: %04x\n",opcode);
	}
	return opcode;
}