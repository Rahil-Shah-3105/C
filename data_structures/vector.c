/**
 * @file
 * @brief This is a vector implemenation in C. A vector is an expandable array.
 * @details This vector implementation in C comes with some wrapper functions that lets the user work with data without having to worrying about memory.
 */

#include <stdio.h>     /// for IO operations
#include <stdlib.h>    /// for malloc() and free()
#include <assert.h>    /// for testing using assert()

/** This is the struct that defines the vector. */
typedef struct {
    int len;           ///< contains the length of the vector
    int current;       ///< holds the current item
    int* contents;     ///< the internal array itself
} Vector;

/**
 * This function initilaizes the vector and gives it a size of 1
 * and initializes the first index to 0.
 * @params Vector* (a pointer to the Vector struct)
 * @params int     (the actual data to be passed to the vector)
 * @returns none
 */
void init(Vector* vec, int val) {
	fprintf(stderr, ">>> Entering init(vec=%p,val=%p)\n", vec, val);
    vec->contents = (int*)malloc(sizeof(int));
    vec->contents[0] = val;
    vec->current = 0;
    vec->len = 1;
	fprintf(stderr, "<<< Exiting init(vec=%p,val=%p)\n", vec, val);
}

/**
 * This function clears the heap memory allocated by the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @returns: none
 */
void delete(Vector* vec) {
	fprintf(stderr, ">>> Entering delete(vec=%p)\n", vec);
    free(vec->contents);    
	fprintf(stderr, "<<< Exiting delete(vec=%p)\n", vec);
}

/**
 * This function clears the contents of the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @returns: none
 */
void clear(Vector* vec) {
	fprintf(stderr, ">>> Entering clear(vec=%p)\n", vec);
    delete(vec);
    init(vec, 0);
	fprintf(stderr, "<<< Exiting clear(vec=%p)\n", vec);
}

/**
 * This function returns the length the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @returns: int
 */
int len(Vector* vec) {
	fprintf(stderr, ">>> Entering len(vec=%p)\n", vec);
    fprintf(stderr, "<<< Exiting len(vec=%p)\n", vec);
    return vec->len;    
}

/**
 * This function pushes a value to the end of the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @params int     (the value to be pushed)
 * @returns: none
 */
void push(Vector* vec, int val) {
	fprintf(stderr, ">>> Entering push(vec=%p,val=%p)\n", vec, val);
    vec->contents = realloc(vec->contents, (sizeof(int) * (vec->len + 1)));
    vec->contents[vec->len] = val;
    vec->len++;
	fprintf(stderr, "<<< Exiting push(vec=%p,val=%p)\n", vec, val);
}

/**
 * This function get the item at the specified index of the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @params int     (the index to get value from)
 * @returns: int
 */
int get(Vector* vec, int index) {
	fprintf(stderr, ">>> Entering get(vec=%p,index=%p)\n", vec, index);
    if(index < vec->len) {
	fprintf(stderr, "<<< Exiting get(vec=%p,index=%p)\n", vec, index);
        return vec->contents[index];
    }
    return -1;
}

/**
 * This function sets an item at the specified index of the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @params int     (the index to set value at)
 * @returns: none
 */
void set(Vector* vec, int index, int val) {
	fprintf(stderr, ">>> Entering set(vec=%p,index=%p,val=%d)\n", vec, index, val);
    if(index < vec->len) {
        vec->contents[index] = val;
    }
	fprintf(stderr, "<<< Exiting set(vec=%p,index=%p,val=%d)\n", vec, index, val);
}

/**
 * This function gets the next item from the Vector each time it's called.
 * @params Vector* (a pointer to the Vector struct)
 * @returns: int
 */
int next(Vector* vec) {
	fprintf(stderr, ">>> Entering next(vec=%p)\n", vec);
    if(vec->current == vec->len) {
        vec->current = 0;
    }
    int current_val = vec->contents[vec->current];
    vec->current++;
	fprintf(stderr, "<<< Exiting next(vec=%p)\n", vec);
    return current_val;
}

/**
 * This function returns the pointer to the begining of the Vector.
 * @params Vector* (a pointer to the Vector struct)
 * @returns: void*
 */
void* begin(Vector* vec) {
	fprintf(stderr, ">>> Entering begin(vec=%p)\n", vec);
    fprintf(stderr, "<<< Exiting begin(vec=%p)\n", vec);
    return (void*)vec->contents;
}

/**
 * This function prints the entire Vector as a list. 
 * @params Vector* (a pointer to the Vector struct)
 * @returns: none
 */
void print(Vector* vec) {
	fprintf(stderr, ">>> Entering print(vec=%p)\n", vec);
    int size = vec->len;
    printf("[ ");
    for(int count = 0; count < size; count++) {
        printf("%d ", vec->contents[count]);
    }
    printf("]\n");
	fprintf(stderr, "<<< Exiting print(vec=%p)\n", vec);
}

/**
 * This function tests the functions used to work with Vectors.
 * @returns: none
 */
static void test() {
	fprintf(stderr, ">>> Entering test()\n");
    Vector vec;
    init(&vec, 10);
    assert(get(&vec, 0) == 10);
    push(&vec, 20);
    assert(get(&vec, 1) == 20);
    set(&vec, 0, 11);
    assert(get(&vec, 0) == 11);
    assert(next(&vec) == 11);
    set(&vec, 1, 22);
    assert(get(&vec, 1) == 22);
    assert(len(&vec) == 2);
	fprintf(stderr, "<<< Exiting test()\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	fprintf(stderr, ">>> Entering main()\n");
    test();

    Vector vec;
    init(&vec, 10);
    push(&vec, 20);
    print(&vec);
    set(&vec, 0, 11);
    set(&vec, 1, 22);
    print(&vec);
    printf("Length: %d\n", len(&vec));
	fprintf(stderr, "<<< Exiting main()\n");
    return 0;
}
