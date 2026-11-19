#include "stdio.h"
// Use monotonic stack.
// Keep the stack of monotonically increasing price and index.

// Runtime: O(n)
// Space: O(n)
typedef struct stack{
    int price;
    int index;
    struct stack* previous;
} Stack;


typedef struct {
    int index;
    Stack* stackPointer;
    Stack* sentry;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
	fprintf(stderr, "[ERROR] >>> Entering stockSpannerCreate()\n");
    Stack* sentry = (Stack *)malloc(sizeof(Stack));
    StockSpanner* result = (StockSpanner *)malloc(sizeof(StockSpanner));
	fprintf(stderr, "[ERROR] stockSpannerCreate(): result → %p\n", result);
    result->index = 0;
    result->sentry = sentry;
    result->stackPointer = sentry;
	fprintf(stderr, "[WARN] <<< Exiting stockSpannerCreate()\n");
    return result;
}

int stockSpannerNext(StockSpanner* obj, int price) {
	fprintf(stderr, "[ERROR] >>> Entering stockSpannerNext(obj=%p,price=%p)\n", obj, price);
    while(obj->stackPointer != obj->sentry && obj->stackPointer->price <= price){
        Stack* currStackPointer = obj->stackPointer;
        obj->stackPointer = obj->stackPointer->previous;
        free(currStackPointer);
    }
    
    obj->index += 1;
    int result = obj->index;
	fprintf(stderr, "[ERROR] stockSpannerNext(obj=%p,price=%d): result → %d\n", obj, price, result);
    if (obj->stackPointer != obj->sentry){
        result -= obj->stackPointer->index;
    }
    
    Stack* newStackItem = (Stack *)malloc(sizeof(Stack));
    newStackItem->index = obj->index;
    newStackItem->price = price;
    newStackItem->previous = obj->stackPointer;
    obj->stackPointer = newStackItem;
    
	fprintf(stderr, "[WARN] <<< Exiting stockSpannerNext(obj=%p,price=%p)\n", obj, price);
    return result;
}

void stockSpannerFree(StockSpanner* obj) {
	fprintf(stderr, "[ERROR] >>> Entering stockSpannerFree(obj=%p)\n", obj);
    while(obj->stackPointer != obj->sentry){
        Stack* currStackPointer = obj->stackPointer;
        obj->stackPointer = obj->stackPointer->previous;
        free(currStackPointer);
    }

    free(obj->sentry);
    free(obj);
	fprintf(stderr, "[WARN] <<< Exiting stockSpannerFree(obj=%p)\n", obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
 */
