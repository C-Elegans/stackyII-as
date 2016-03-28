//
//  label_list.c
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "label_list.h"
#include <stdlib.h>
#define INITIAL_CAPACITY 20
void vector_init(labelVector* vector){
	vector->size = 0;
	vector->capacity = INITIAL_CAPACITY;
	vector->labels = malloc(sizeof(label)*INITIAL_CAPACITY);
}


void vector_append(labelVector *vector, label value){
	vector_double_capacity_if_full(vector);
	vector->labels[vector->size++] = value;
}

label vector_get(labelVector *vector, int index){
	if (index >= vector->size || index < 0) {
		printf("Index %d out of bounds for vector of size %zu\n", index, vector->size);
		exit(1);
	}
	return vector->labels[index];
}

void vector_set(labelVector *vector, int index, label value){
	if (index >= vector->size || index < 0) {
		printf("Index %d out of bounds for vector of size %zu\n", index, vector->size);
		exit(1);
	}
	while (index >= vector->size) {
		vector_append(vector, (label){0,NULL});
	}
	vector->labels[index] = value;
}

void vector_double_capacity_if_full(labelVector *vector){
	if(vector->size >= vector->capacity){
		vector->capacity *= 2;
		vector->labels = realloc(vector->labels, vector->capacity * sizeof(label));
	}
}

void vector_free(labelVector *vector){
	free(vector->labels);
}
void vector_print(labelVector* vector){
	size_t index = 0;
	while (index < vector->size) {
		label l = vector->labels[index];
		printf("label: %s at %d\n",l.label,l.address);
		index++;
	}
}