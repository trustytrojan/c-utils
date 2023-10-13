#ifndef __VECTOR__
#define __VECTOR__

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 1.5

typedef union
{
	long l;
	double d;
} v_data;

#define V_CHAR 'c'
#define V_SIGNED 'i'
#define V_UNSIGNED 'u'
#define V_FLOAT 'f'
#define V_BOOL 'b'
#define V_STRING 's'
#define V_PTR 'p'

typedef struct
{
	char type;
	v_data data;
} v_element;

typedef struct
{
	size_t capacity;
	size_t size;
	v_element *data;
} vector;

// Create a new vector.
vector *v_new();

// Free all memory used by `v`. This will render all further operations on it as undefined behavior.
void v_free(vector *const v);

// Resize `v`'s internal array to `new_capacity`. Calling with `new_capacity < v->size` will result in data loss.
void v_resize(vector *const v, const size_t new_capacity);

// Return a pointer to the `v_element` at `index` in `v`. Passing an out-of-bounds `index` will return `NULL`.
v_element *v_get(const vector *const v, const size_t index);

/**
 * Set the element at `index` in `v` to a new value.
 * Passing an out-of-bounds `index` will cause an invalid write.
 * Any arguments after the first are ignored.
 */
void v_set(vector *const v, const size_t index, const char type, ...);

/**
 * Push one or more elements into `v`.
 * ### Type specifiers
 * You must supply valid type specifiers for each element to push. Incorrectly typing values will result in undefined behavior.
 * - `i` Signed integer. Accepts any integer type.
 * - `u` Unsigned integer. Accepts any integer type. Will be interpreted as unsigned when printing.
 * - `f` Floating point. Accepts `float` or `double`.
 * - `c` Character. Only accepts `char`.
 * - `s` String. Only accepts `char *`.
 * - `b` Boolean. Accepts any integer type. Will print as either `true` or `false`.
 * - `p` Pointer. Accepts any pointer type.
 * 
 * ### Correct usage
 * ```c
 * vector *v = v_new();
 * v_push(v, "isc", 5, "five", '5');
 * ```
 * 
 * ### Erroneous usage
 * ```c
 * v_push(v, "isc", '5', 5, "five");
 * v_print(v);
 * ```
 * The `v_print` call will segfault due to reading at address `0x5`.
 */
void v_push(vector *const v, const char *const types, ...);

// Print the elements of `v` to `stdout`.
void v_print(const vector *const v);

// Print debug info about `v` to `stdout`.
void v_debug(const vector *const v);

#endif
