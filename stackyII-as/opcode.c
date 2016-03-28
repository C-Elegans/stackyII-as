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
uint16_t decodeInstruction(char* instruction,labelVector* labels){
	char* op = strtok(instruction, " ");
	char* data = strtok(NULL," ");
	uint16_t opcode = lookup_opcode(op);
	if(data == NULL){
		printf("op: %s \n",op);
		printf("opcode: %04x\n",opcode);
	}else{
		printf("op: %s data: %s\n",op,data);
		uint16_t modified_data = decode_data(data, labels);
		opcode |= modified_data & 0x7fff;
		
		fprintf(stderr,"opcode: %04x\n",opcode);
	}
	return opcode;
}