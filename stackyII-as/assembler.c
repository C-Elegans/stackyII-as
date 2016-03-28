//
//  assembler.c
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "assembler.h"
#include "label_list.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
labelVector labels;
void assemble_pass1(FILE* source){
	vector_init(&labels);
	char* line = NULL;
	if(source == NULL)return;
	size_t len = 0;
	ssize_t read =0;
	int address = 0;
	while ((read = getline(&line, &len, source)) != -1) {
		char* index;
		line += strspn(line," \t");
		if((index = strchr(line, (int)';')) != NULL){*index = 0;}
		if((index = strchr(line, (int)'\n')) != NULL){*index = 0;}
		if(*line == 0){continue;} //if line is empty
		printf("%s\n",line);
		if((index = strchr(line, (int)':')) != NULL){ //its a label
			*index = 0;
			char* label_str = malloc((index-line)+1);
			strcpy(label_str, line);
			vector_append(&labels, (label){address,label_str});
		}else{//its an instruction
			address+=2;
		}
	}
	
	vector_print(&labels);
}