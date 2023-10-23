#include "../include/vector.h"

v_element *v_get(const vector *const v, const size_t index)
{
	return (index >= v->size) ? NULL : v->data + index;
}

/**
 * Internal function.
 * Sets `el->type = type` and `el->data` to the value of the next argument in
 * `*args`.
 */
void __set_element(v_element *const el, const v_eltype type, va_list *const args)
{
	switch (el->type = type)
	{
	case V_SIGNED:
	case V_CHAR:
	case V_BOOL:
	case V_STRING:
	case V_PTR:
		el->data.l = va_arg(*args, long);
		break;
	case V_UNSIGNED:
		el->data.l = va_arg(*args, unsigned long);
		break;
	case V_FLOAT:
		el->data.d = va_arg(*args, double);
	}
}

bool v_set(vector *const v, const size_t index, const v_eltype type, ...)
{
	if (index >= v->size)
		return false;
	va_list args;
	va_start(args, 1);
	__set_element(v->data + index, type, &args);
	return true;
}

/**
 * Internal function. Performs the insertion of elements at any `index`.
 * `*args` must be initialized using the macro `va_start` BEFORE being passed to
 * `__insert`.
 */
void __insert(vector *const v, size_t index, const size_t num_elements, const char *types, va_list *const args)
{
	// accomodate for new elements
	size_t new_size = v->size + num_elements;
	if (new_size > v->capacity)
	{
		while ((v->capacity *= GROWTH_FACTOR) < new_size);
		v_resize(v, v->capacity);
	}

	// move existing elements to the right if needed
	if (index < v->size)
		for (size_t i = v->size - 1; i >= index; --i)
			v->data[i + num_elements] = v->data[i];

	v->size = new_size;

	// insert the new elements
	for (; *types != '\0'; ++types)
		__set_element(v->data + (index++), *types, args);

	free(args);
}

void v_push(vector *const v, const char *const types, ...)
{
	const int num_elements = strlen(types);
	va_list *const args = malloc(sizeof(va_list));
	va_start(*args, num_elements);
	__insert(v, v->size, num_elements, types, args);
}

void v_insert(vector *const v, const size_t index, const char *const types, ...)
{
	const int num_elements = strlen(types);
	va_list *const args = malloc(sizeof(va_list));
	va_start(*args, num_elements);
	__insert(v, index, num_elements, types, args);
}
