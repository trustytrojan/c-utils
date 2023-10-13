#include "../include/vector.h"

v_element *v_get(const vector *const v, const size_t index)
{
	return (index >= v->size) ? NULL : v->data + index;
}

/**
 * Internal function.
 * Sets `el->type = type` and `el->data` to the value of the next argument in `*args`.
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

void v_push(vector *const v, const char *types, ...)
{
	const int num_elements = strlen(types);

	size_t new_size = v->size + num_elements;
	if (new_size > v->capacity)
	{
		while ((v->capacity *= GROWTH_FACTOR) < new_size);
		v_resize(v, v->capacity);
	}

	va_list args;
	va_start(args, num_elements);
	for (; *types != '\0'; ++types)
		__set_element(v->data + (v->size++), *types, &args);
}
