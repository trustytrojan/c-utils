CFLAGS = -Wall -Werror -Wextra -Wno-varargs

shared:
	clear
	gcc $(CFLAGS) -shared -o lib/libvector.so src/*.c

static:
	clear
	gcc $(CFLAGS) vector_mem.c -o obj/vector_mem.o
	gcc $(CFLAGS) vector_ops.c -o obj/vector_ops.o
	gcc $(CFLAGS) vector_print.c -o obj/vector_print.o
	gcc $(CFLAGS) vector_push.c -o obj/vector_push.o
	ar rcs libvector.a obj/*

test:
	clear
	gcc $(CFLAGS) test.c -lvector -Llib
