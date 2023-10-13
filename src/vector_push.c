#include <stdarg.h>

#include "vector.h"

void v_push(vector *const v, const char *const types, ...)
{
	int num_types = 0;
	for (const char *p = types; *p != '\0'; ++p)
		if (*p == '%')
			++num_types;
	va_list args;
	va_start(args, num_types);
	v_element el;
	for (const char *p = types; *p != '\0'; ++p)
	{
		if (*p == '%')
			continue;
		switch (*p)
		{
		case 'i':
			el = (v_element){.type = V_SIGNED, .data = {.l = va_arg(args, long)}};
			break;
		case 'u':
			el = (v_element){.type = V_UNSIGNED, .data = {.l = va_arg(args, unsigned long)}};
			break;
		case 'f':
			el = (v_element){.type = V_FLOAT, .data = {.d = va_arg(args, double)}};
			break;
		case 'c':
			el = (v_element){.type = V_CHAR, .data = {.l = va_arg(args, long)}};
			break;
		case 's':
			el = (v_element){.type = V_STRING, .data = {.l = (long)va_arg(args, char *)}};
			break;
		case 'b':
			el = (v_element){.type = V_BOOL, .data = {.l = va_arg(args, long)}};
			break;
		case 'p':
			el = (v_element){.type = V_PTR, .data = {.l = (long)va_arg(args, void *)}};
			break;
		}
		v->data[v->size++] = el;
	}
}
