all: exe

exe: lib test.c
	gcc test.c -fPIC -L. -lsolution -o test

lib: solution.c
	gcc solution.c -shared -fPIC -o libsolution.so 

clean:
	-rm test libsolution.so 2>/dev/null
