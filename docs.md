# libvector Documentation

## `v_new(void)`
Allocates and initializes (by calling `v_init`) a `vector` on the heap.
Returns a pointer to the new `vector`, or `NULL` if either the allocation or initialization failed (dependent on the return value of `malloc`).

## `v_init(vector *)`
Initializes a vector with the following defaults:
- Sets `v->size` to 0.
- Sets `v->capacity` to `V_INITIAL_CAPACITY`.
- Sets `v->data` to a `malloc`'d memory chunk.

Returns `true` if successful, and `false` otherwise.

## `v_deinit(vector *)`
De-initializes a vector by `free`'ing its `data`.