EXES = joseph pointer_sort matrix_compute
CC = gcc
CFLAGS = -pedantic -Wall -Wextra -std=c11 -o $@


all: $(EXES)

circ_liste.o: circ_liste.c circ_liste.h
	$(CC) $< -c $(CFLAGS)

joseph.o: joseph.c
	$(CC) $< -c $(CFLAGS)

joseph: joseph.o circ_liste.o
	$(CC) $^ $(CFLAGS)

pointer_sort: pointer_sort.c pointer_sort.h
	$(CC) $< $(CFLAGS)

matrice.o: matrice.c matrice.h
	$(CC) $< -c $(CFLAGS)

matrix_compute.o: matrix_compute.c
	$(CC) $< -c $(CFLAGS)

matrix_compute: matrix_compute.o matrice.o
	$(CC) $^ $(CFLAGS)

clean:
	rm -f ./$(EXES) ./*.o
