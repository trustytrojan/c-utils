#include "../include/vector.h"

vector *v_new()
{
	vector *const v = malloc(sizeof(vector));

	if (!v)
	{
		perror("v_new: malloc");
		return NULL;
	}

	v->capacity = INITIAL_CAPACITY;
	v->size = 0;

	if (!(v->data = malloc(v->capacity * sizeof(v_element))))
	{
		perror("v_new: malloc");
		free(v);
		return NULL;
	}

	return v;
}

void *memdup(const void *const src, const size_t size)
{
	void *const dest = malloc(size);

	if (!dest)
	{
		perror("memdup: malloc");
		return NULL;
	}

	return memcpy(dest, src, size);
}

vector *v_copy(const vector *const old)
{
	vector *const new = memdup(old, sizeof(vector));
	
	if (!new)
		return NULL;
	
	if (!(new->data = memdup(old->data, old->capacity * sizeof(v_element))))
	{
		free(new);
		return NULL;
	}

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
