all: exe

exe: hello.h main.c lib
	gcc main.c -fPIC -ldl -o hello

lib: hello.h hello.c
	gcc hello.c -shared -fPIC -o libHello.so

clean:
	-rm hello libHello.so 2>/dev/null