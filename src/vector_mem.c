#include "../include/vector.h"

vector *v_new()
{
	vector *const v = malloc(sizeof(vector));

	if (!v)
	{
		perror("v_new: malloc");
		return NULL;
	}

	if (!v_init(v))
	{
		free(v);
		return NULL;
	}

	return v;
}

bool v_init(vector *const v)
{
	v_element *const data = malloc(V_INITIAL_CAPACITY * sizeof(v_element));

	if (!data)
	{
		perror("v_init: malloc");
		return false;
	}

	v->capacity = V_INITIAL_CAPACITY;
	v->size = 0;
	v->data = data;

	return true;
}

bool v_copy(vector *const dest, const vector *const src)
{
	const size_t mem_size = src->size * sizeof(v_element);
	v_element *const dest_data = realloc(dest->data, mem_size);

	if (!dest_data)
	{
		perror("v_copy: malloc");
		return false;
	}

	dest->capacity = src->capacity;
	dest->size = src->size;
	dest->data = memcpy(dest_data, src->data, mem_size);

	return true;
}

vector *v_dup(const vector *const old)
{
	vector *const new = malloc(sizeof(vector));

	if (!new)
	{
		perror("v_dup: malloc");
		return NULL;
	}

	v_copy(new, old);
	return new;
}

void v_free(vector *const v)
{
	free(v->data);
	free(v);
}

bool v_resize(vector *const v, const size_t new_capacity)
{
	v_element *const new_data = realloc(v->data, new_capacity * sizeof(v_element));

	if (!new_data)
	{
		perror("v_resize: realloc");
		return false;
	}

	v->data = new_data;
	v->capacity = new_capacity;

	if (v->size > v->capacity)
		v->size = v->capacity;

	return true;
}
