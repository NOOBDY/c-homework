CC = clang
CFLAGS = -g -std=c89 -pedantic -fno-builtin -Wall
LDFLAGS = -lm

build $(target).c:
	$(CC) $(target).c $(CFLAGS) $(LDFLAGS) -o $(target)

clean $(target):
	rm $(target)
