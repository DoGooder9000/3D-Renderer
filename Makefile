C_SRCS = $(wildcard src/*.c)

SDL2_FLAGS = -lsdl2

all:
	gcc -o main main.c $(C_SRCS) $(SDL2_FLAGS)

clean:
	rm -f *.exe

run: all
	./main