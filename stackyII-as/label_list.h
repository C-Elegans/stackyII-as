//
//  label_list.h
//  stackyII-as
//
//  Created by Michael Nolan on 3/28/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef label_list_h
#define label_list_h

#include <stdio.h>
typedef struct {
	int address;
	char* label;
}label;
typedef struct{
	size_t size;
	size_t capacity;
	label* labels;
} labelVector;
void vector_init(labelVector*);


void vector_append(labelVector *vector, label value);

label vector_get(labelVector *vector, int index);

void vector_set(labelVector *vector, int index, label value);

void vector_double_capacity_if_full(labelVector *vector);

void vector_free(labelVector *vector);

void vector_print(labelVector* vector);
#endif /* label_list_h */
