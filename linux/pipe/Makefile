all: exe

exe: solution.c
	gcc solution.c -o solution

test: exe
	./solution ./test.py 100

clean:
	-rm solution