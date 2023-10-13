#include "../include/vector.h"

vector *v_new()
{
	vector *v = malloc(sizeof(vector));
	v->capacity = INITIAL_CAPACITY;
	v->size = 0;
	if (!(v->data = malloc(INITIAL_CAPACITY * sizeof(v_element))))
		perror("v_new: malloc");
	return v;
}

void v_free(vector *const v)
{
	free(v->data);
	free(v);
}

void v_resize(vector *const v, const size_t new_capacity)
{
	if (!(v->data = realloc(v->data, new_capacity * sizeof(v_element))))
		perror("v_resize: realloc");
}
