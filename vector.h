#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

struct vector
{
    char ** ptr;
    size_t capacity;
    size_t size;
};

void vector_init(struct vector *v);
void vector_push(struct vector *v, const char *item);
char * vector_get(struct vector *v, size_t index);
void vector_free(struct vector *v);

#endif