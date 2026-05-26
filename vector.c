#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

void vector_init(struct vector *v)
{
    if(v == NULL) return;
    v -> size = 0;
    v -> capacity = 4;
    v -> ptr = (char **) malloc((v -> capacity) * sizeof(char *));
    if (v->ptr == NULL) {
        perror("Vector initialization failed: Out of memory");
        exit(EXIT_FAILURE);
    }
}

void vector_push(struct vector *v, const char *item)
{
    if (v == NULL || item == NULL) return;
    if(v -> size >= v -> capacity) 
    {
        v -> capacity = 2 * (v -> capacity);
        // Defensive Allocation: Collect in a temp pointer first
        char **temp = (char **)realloc(v->ptr, v->capacity * sizeof(char *));
        if (temp == NULL) {
            perror("Vector growth failed: Out of memory");
            // v->ptr remains valid here, preventing a silent memory leak drop
            exit(EXIT_FAILURE);
        }
        v->ptr = temp;
    } 
    v -> ptr[v -> size] = (char *)malloc((strlen(item) + 1) * sizeof(char));
    if (v->ptr[v->size] == NULL) {
        perror("Token space allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(v->ptr[v->size], item);
    v -> size = (v -> size) + 1;
}

char * vector_get(struct vector *v, size_t index)
{
    if(v == NULL || index >= v -> size) return NULL;
    return v->ptr[index];
}

void vector_free(struct vector *v)
{
    if(v == NULL) return;
    for(int i = 0; i < v->size; i += 1)
    {
        if (v->ptr[i] != NULL) 
        {
            free(v->ptr[i]);
        }
    }
    if(v -> ptr != NULL) free(v -> ptr);
    v -> ptr = NULL;
    v -> size = 0;
    v -> capacity = 0;
}