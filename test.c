#include "src/vector.h"

int main()
{
	vector *v = v_new();
	v_push(v, "%i", 5);
	v_push(v, "%b", 0);
	v_push(v, "%u", 69);
	v_print(v);
	v_free(v);
}
