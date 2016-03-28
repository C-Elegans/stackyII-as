//
//  main.c
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "assembler.h"
#define VERSION 0.1
void* readf(FILE* fp){
	void* buf = NULL;
	if(fp != NULL){
		if (fseek(fp, 0L, SEEK_END) == 0) {
		size_t bufsize = ftell(fp);
		if(bufsize == -1){fprintf(stderr,"Error reading file!\n");exit(-1);}
		buf = malloc(sizeof(char)*(bufsize+1));
		fseek(fp,0L, SEEK_SET);
		size_t newlen = fread(buf, sizeof(char), bufsize, fp);
		if(newlen == 0){fprintf(stderr,"Error reading file!\n");exit(-1);}
		else{
			((char*)buf)[newlen++] = '\0';
		}
		}
		
	}
	return buf;
}
int main(int argc, char * argv[]) {
	char* inputfile = NULL;
	char* outputfile = NULL;
	int opt;
	while((opt =getopt(argc, argv, "vi:o:")) != -1){
		switch (opt) {
			case 'i':
				inputfile = optarg;
			break;
			case 'o':
				outputfile = optarg;
			break;
			case 'v':
				puts("usage -vh -i [file] -o [file]\n");
				exit(0);
			break;
	
		}
		
		
	
	}
	if(inputfile == NULL || outputfile == NULL){
		printf("stackyII-as, version: %.1f\n",VERSION);
		printf("No input files specified\n");
		exit(0);
	}
	printf("input: %s output: %s\n",inputfile,outputfile);
	FILE* inputFP = fopen(inputfile, "r");
	FILE* outputFP = fopen(outputfile, "wb");
	assemble_pass1(inputFP);
	
	
    return 0;
}

