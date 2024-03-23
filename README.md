# libvector

Yet another "vector" (aka dynamic array) implementation in C. Holds any type of element by keeping type information along with each element.

## Usage
Include `vector.h` either from your include path or by a relative path:
```c
#include <vector.h> // must be in your compiler's include paths
#include "vector.h" // must be in the current directory
```

### Creating a new vector
Create a new vector with `v_new`. The vector structure is dynamically allocated and the internal array is initialized.
```c
vector *v = v_new();
```
You can also allocate the struct on the stack, and call `v_init` on it to initialize the internal array. This avoids an extra heap allocation that would occur in the above example.
```c
vector v;
v_init(&v);
```

### Inserting elements into the vector
Assuming we have our `vector *v` from above, we can push elements to the end of the vector using `v_push`:
```c
v_push(v, "s", "Hello world!");
```
Since our vector can hold any type of element, the second argument to `v_push` is a type specifier string, similar to the format string of `printf`. To understand its usage, read the docs.

(readme not finished)
