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
	if(inputFP == NULL){
		fprintf(stderr, "Error reading file:%s\n",inputfile);
		exit(-1);
	}
	if(outputFP == NULL){
		fprintf(stderr, "Error writing file:%s\n",outputfile);
		exit(-1);
	}
	assemble_pass1(inputFP);
	assemble_pass2(inputFP, outputFP);
	
    return 0;
}

