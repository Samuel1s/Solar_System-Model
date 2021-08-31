CC=gcc
OPCOES_COMPILADOR=-I.-ISOIL -lglut -lGLU -lSOIL -lGLEW -lGL -w -lm `sdl-config --cflags --libs` -ISDL -lSDL_mixer
TODOS_ARQUIVOS_PONTOH = 
TODOS_ARQUIVOS_OBJ = main.o 

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o main $^ $(OPCOES_COMPILADOR)

run: all
	./main

clean:
	rm *.o main
