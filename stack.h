#ifndef STACK_H
#define STACK_H

#include "vector.h"

struct stack
{
    struct vector vec;
};

void stack_init(struct stack *s);
void stack_push(struct stack *s, const char *item);
char *stack_pop(struct stack *s);
int stack_is_empty(struct stack *s);
void stack_free(struct stack *s);

#endif
