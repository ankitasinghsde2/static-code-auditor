#include <stdio.h>
#include "vector.h"
#include "stack.h"

void stack_init(struct stack *s)
{
    if(s == NULL) return;

    vector_init(&(s -> vec));
}

void stack_push(struct stack *s, const char *item)
{
    if(s == NULL || item == NULL) return;

    vector_push(&(s -> vec), item);

}

char *stack_pop(struct stack *s)
{
    if(s == NULL || stack_is_empty(s))
    {
        return NULL;
    }

    int top_index = ((s->vec).size) - 1;

    char *top_item = vector_get(&(s -> vec), top_index);

    s ->vec.size--;

    return top_item;
}

int stack_is_empty(struct stack *s)
{
    if(s == NULL) return 1;

    return (s->vec.size == 0);
}

void stack_free(struct stack *s)
{
    if(s == NULL) return;

    vector_free(&(s -> vec));
}