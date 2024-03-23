#ifndef __VECTOR__
#define __VECTOR__

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 8
#define GROWTH_FACTOR 1.5

typedef union
{
	long l;
	double d;
} v_eldata;

typedef enum
{
	V_CHAR = 'c',
	V_SIGNED = 'i',
	V_UNSIGNED = 'u',
	V_FLOAT = 'f',
	V_BOOL = 'b',
	V_STRING = 's',
	V_PTR = 'p'
} v_eltype;

typedef struct
{
	v_eltype type;
	v_eldata data;
} v_element;

typedef struct
{
	size_t capacity;
	size_t size;
	v_element *data;
} vector;

// Create a new empty vector.
vector *v_new();

// Copy a vector.
vector *v_copy(const vector *const v);

// Free all memory used by `v`. This will render all further operations on it as undefined behavior.
void v_free(vector *const v);

// Resize `v`'s internal array to `new_capacity`. Calling with `new_capacity < v->size` will result in data loss.
bool v_resize(vector *const v, const size_t new_capacity);

// Return a pointer to the `v_element` at `index` in `v`. Passing an out-of-bounds `index` will return `NULL`.
v_element *v_get(const vector *const v, const size_t index);

/**
 * Set the element at `index` in `v` to a new value. Any arguments after the
 * first are ignored. Returns whether the operation was successful. Passing an
 * out-of-bounds index will return false.
 */
bool v_set(vector *const v, const size_t index, const v_eltype type, ...);

/**
 * Push one or more elements to the end of `v`.
 * ### Type specifiers
 * You must supply valid type specifiers for each element to push. Incorrectly
 * typing values will result in undefined behavior.
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
 * ### Erroneous usage
 * ```c
 * v_push(v, "isc", '5', 5, "five");
 * v_print(v);
 * ```
 * The `v_print` call will segfault due to reading at address `0x5`.
 */
void v_push(vector *const v, const char *const types, ...);

/**
 * Insert one or more elements into `v` at `index`.
 * ### Type specifiers
 * You must supply valid type specifiers for each element to push. Incorrectly
 * typing values will result in undefined behavior.
 * - `i` Signed integer. Accepts any integer type.
 * - `u` Unsigned integer. Accepts any integer type. Will be interpreted as unsigned when printing.
 * - `f` Floating point. Accepts `float` or `double`.
 * - `c` Character. Only accepts `char`.
 * - `s` String. Only accepts `char *`.
 * - `b` Boolean. Accepts any integer type. Will print as either `true` or `false`.
 * - `p` Pointer. Accepts any pointer type.
 */
void v_insert(vector *const v, size_t index, const char *types, ...);

// Print the elements of `v` to `stdout`.
void v_print(const vector *const v);

// Print debug info about `v` to `stdout`.
void v_debug(const vector *const v);

#endif
