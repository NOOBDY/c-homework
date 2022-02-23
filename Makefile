build $(n).c:
	clang $(n).c -g -std=c11 -pedantic -lm -fno-builtin -Wall -o $(n)

clean $(n):
	rm $(n)
