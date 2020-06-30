#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <dlfcn.h>

void (*hello_message)(char const*);

bool init_library() {
	void * hdl = dlopen("./libHello.so", RTLD_LAZY);
	if(hdl == NULL) {
		return false;
	}
	hello_message = (void (*)(char const*))dlsym(hdl, "hello_message");
	if(hello_message == NULL) {
		return false;
	}
	return true;
}

int main() {
	if (init_library()) {
		hello_message("Dima");
	} else {
		printf("Library was not loaded!\n");
	}
	return 0;
}
