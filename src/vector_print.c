#include "../include/vector.h"

void __print_element(const v_element *const el, const bool debug)
{
	switch (el->type)
	{
	case V_SIGNED:
		printf("%s%li", debug ? "(i) " : "", el->data.l);
		break;
	case V_UNSIGNED:
		printf("%s%lu", debug ? "(u) " : "", (unsigned long)el->data.l);
		break;
	case V_FLOAT:
		printf("%s%lf", debug ? "(f) " : "", el->data.d);
		break;
	case V_CHAR:
		printf("%s'%c'", debug ? "(c) " : "", (char)el->data.l);
		break;
	case V_STRING:
		printf("%s\"%s\"", debug ? "(s) " : "", (char *)el->data.l);
		break;
	case V_BOOL:
		printf("%s%s", debug ? "(b) " : "", el->data.l ? "true" : "false");
		break;
	case V_PTR:
		printf("%s%p", debug ? "(p) " : "", (void *)el->data.l);
		break;
	}
}

void v_print(const vector *const v)
{
	putchar('[');
	for (size_t i = 0; i < v->size; ++i)
	{
		__print_element(v->data + i, false);
		if (i < v->size - 1)
			printf(", ");
	}
	puts("]");
}

void __debug_print(const vector *const v)
{
	if (!v->size)
	{
		puts("[]");
		return;
	}

	puts("[");
	
	for (size_t i = 0; i < v->size; ++i)
	{
		printf("\t\t%ld: ", i);
		__print_element(v->data + i, true);
		if (i < v->size - 1)
			putchar(',');
		putchar('\n');
	}
	
	puts("\t]");
}

void v_debug(const vector *const v)
{
	printf("vector @ %p -> {\n\tsize: %ld\n\tcapacity: %ld\n\tdata: %p -> ", v, v->size, v->capacity, v->data);
	__debug_print(v);
	puts("}");
}
