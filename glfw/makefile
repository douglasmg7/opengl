CC=g++
CFLAGS=-I.

main: win.o
	$(CC) win.o glad.o -o win -lglfw -ldl

# win.0
win:
	$(CC) -c win.cpp

glad:
	$(CC) -c glad.c -I$(HOME)/code/opengl/glfw/include

clean:
	rm *.o win
