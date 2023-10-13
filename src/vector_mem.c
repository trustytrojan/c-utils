#include "vector.h"

vector *v_new()
{
	vector *v = malloc(sizeof(vector));
	*v = (vector){.capacity = INITIAL_CAPACITY,
				  .size = 0,
				  .data = malloc(INITIAL_CAPACITY * sizeof(v_element))};
	return v;
}

void v_free(vector *v)
{
	free(v->data);
	free(v);
}

void v_resize(vector *v, size_t new_capacity)
{
	v->data = realloc(v->data, new_capacity);
}

void v_grow(vector *v)
{
	v_resize(v, v->capacity *= GROWTH_FACTOR);
}

void v_shrink(vector *v)
{
	v_resize(v, v->capacity /= GROWTH_FACTOR);
}
