all: exe

exe: lib solution.c
	gcc solution.c -fPIC -Wl,-rpath,. -ldl -o solution

lib: shared.c shared.h
	gcc shared.c -shared -fPIC -o libShared.so

test: all
	./solution libShared.so secretFunction 8

clean:
	-rm solution libLib.so 2>/dev/null
