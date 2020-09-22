bOne2bTwo: bOne2bTwo.c
	gcc -g bOne2bTwo.c -o bOne2bTwo.out

test: bOne2bTwo test.txt
	./bOne2bTwo.out < test.txt

b2d: bin2dec.c
	gcc bin2dec.c -o bin2dec.out

clean:
	- rm *.out