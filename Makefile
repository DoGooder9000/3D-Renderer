C_SRCS = $(wildcard src/*.cpp)

SDL2_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all:
	g++ -o main main.cpp $(C_SRCS) $(SDL2_FLAGS)

clean:
	rm -f *.exe

run: all
	./main