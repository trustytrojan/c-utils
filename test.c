#include "include/vector.h"

int main()
{
	puts("vector *const v = v_new()");
	vector *const v = v_new();

	puts("v_debug(v)");
	v_debug(v);
	
	puts("v_push(v, \"iiii\", 1, 4, 6, 9)");
	v_push(v, "iiii", 1, 4, 6, 9);
	
	puts("v_debug(v)");
	v_debug(v);
	
	puts("v_insert(v, 1, \"iii\", 3, 27, 69)");
	v_insert(v, 1, "iii", 3, 27, 69);

	puts("v_debug(v)");
	v_debug(v);
	
	puts("vector *const v2 = v_copy(v)");
	vector *const v2 = v_copy(v);

	puts("v_debug(v)");
	v_debug(v);

	puts("v_debug(v2)");
	v_debug(v2);
	
	puts("v_insert(v2, 2, \"sb\", \"i am a string\", false)");
	v_insert(v2, 2, "sb", "i am a string", false);

	puts("v_debug(v)");
	v_debug(v);
	
	puts("v_debug(v2)");
	v_debug(v2);

	puts("v_free(v)");
	v_free(v);

	puts("v_free(v2)");
	v_free(v2);
}
