#include "include/vector.h"
#include <stddef.h>

int main()
{
	vector *v = v_new();
	v_push(v, "iucfbsp", 5, -1, 'N', 3.01, 1, "lol", v);
	v_print(v);
	v_set(v, 0, V_BOOL, 1);
	v_set(v, 4, V_FLOAT, 5.79);
	v_set(v, v->size - 1, V_STRING, "......");
	v_debug(v);
	v_free(v);
}
