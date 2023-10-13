#include "vector.h"

void v_print(vector *const v)
{
	putchar('[');
	for (size_t i = 0; i < v->size; ++i)
	{
		v_element *el = v_get(v, i);
		switch (el->type)
		{
		case V_SIGNED:
			printf("%li", el->data.l);
			break;
		case V_UNSIGNED:
			printf("%lu", (unsigned long)el->data.l);
			break;
		case V_FLOAT:
			printf("%lf", el->data.d);
			break;
		case V_CHAR:
			printf("'%c'", (char)el->data.l);
			break;
		case V_STRING:
			printf("\"%s\"", (char *)el->data.l);
			break;
		case V_BOOL:
			printf("%s", el->data.l ? "true" : "false");
			break;
		case V_PTR:
			printf("%p", (void *)el->data.l);
			break;
		}
		if (i < v->size - 1)
			printf(", ");
	}
	puts("]");
}
