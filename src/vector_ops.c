#include "../include/vector.h"

v_element *v_get(const vector *const v, const size_t index)
{
	return (index >= v->size) ? NULL : v->data + index;
}

/**
 * Internal function.
 * Sets `el->type = type` and `el->data` to the value of the next argument in `*args`.
 */
void __set_element(v_element *const el, const char type, va_list *const args)
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

void v_set(vector *const v, const size_t index, const char type, ...)
{
	va_list args;
	va_start(args, 1);
	v_element *el = v_get(v, index);
	__set_element(el, type, &args);
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
