#include "vector.h"
#include "stack.h"
#include <stdio.h>

int main() {
    printf("=== WEEK 1: INTEGRATION TEST ENGINE ===\n");

    struct stack memory_stack;
    stack_init(&memory_stack); 
    printf("1. Simulating code block parsing sequence...\n");
    
    stack_push(&memory_stack, "{");
    stack_push(&memory_stack, "(");
    stack_push(&memory_stack, "[");

    printf("2. Active internal vector tracker size: %zu\n", memory_stack.vec.size);

    printf("3. Popping items off to verify LIFO order:\n");
    while (!stack_is_empty(&memory_stack)) {
        char *top_bracket = stack_pop(&memory_stack);
        printf("   Popped token: %s\n", top_bracket);
    }

    // Comprehensive destruction pass: Ensure 0 leaks are dropped on the heap
    stack_free(&memory_stack);
    printf("=== TEST COMPLETE: MEMORY CLEANUP CLEAR ===\n");
    return 0;
}