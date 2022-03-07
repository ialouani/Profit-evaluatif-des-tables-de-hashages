exo3_run: exo3
	valgrind ./exo3
exo3: ../exo3.c
	gcc -g ../exo3.c -o exo3
exo2_run: exo2
	valgrind ./exo2
exo2: ../exo2.c
	gcc -std=c99 -g ../exo2.c -o exo2
exo1_run: exo1
	valgrind ./exo1
exo1: ../exo1.c
	gcc ../exo1.c -o exo1
clean:
	rm -f Makefile~ *.o *.sh~ *.c~ *.h~ *.txt~ a.out exo1 exo2 exo3
