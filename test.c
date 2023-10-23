#include "include/vector.h"
#include <stddef.h>

int main()
{
	vector *v = v_new();
	v_push(v, "iiii", 1, 4, 6, 9);
	v_debug(v);
	v_insert(v, 1, "iii", 3, 27, 69);
	v_debug(v);
	v_free(v);
}
