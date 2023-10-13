#include "vector.h"

v_element *v_get(vector *const v, const size_t index)
{
	return v->data + index;
}
