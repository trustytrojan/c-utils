#ifndef __VECTOR__
#define __VECTOR__

#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 1.5

typedef union
{
	long l;
	double d;
} v_data;

typedef enum
{
	V_CHAR,
	V_SIGNED,
	V_UNSIGNED,
	V_FLOAT,
	V_BOOL,
	V_STRING,
	V_PTR
} v_datatype;

typedef struct
{
	v_datatype type;
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
void v_free(vector *v);

// Resize `v`'s internal array to `new_capacity`.
void v_resize(vector *v, size_t new_capacity);

// Grow `v`'s capacity by a factor of `GROWTH_FACTOR`.
void v_grow(vector *v);

// Shrink `v`'s capacity by a factor of `GROWTH_FACTOR`.
void v_shrink(vector *v);

// Get a pointer to the `v_element` at `index` in `v`. Passing an out-of-bounds `index` will result in undefined behavior.
v_element *v_get(vector *v, size_t index);

/**
 * Push one or more elements into `v`.
 * Type specifiers:
 * - `%i` Signed integer. Accepts any integer type.
 * - `%u` Unsigned integer. Accepts any integer type. Will be interpreted as unsigned when printing.
 * - `%f` Floating point. Accepts `float` or `double`.
 * - `%c` Character. Only accepts `char`.
 * - `%s` String. Only accepts `char *`.
 * - `%b` Boolean. Accepts any integer type. Will print as either `true` or `false`.
 * - `%p` Pointer. Accepts any pointer type.
 */
void v_push(vector *v, const char *const types, ...);

// Print the contents of `v` to `stdout`.
void v_print(vector *const v);

#endif
