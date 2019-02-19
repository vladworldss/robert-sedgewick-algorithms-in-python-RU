ex5_1.so: ex5_1.o
	gcc -shared -o libex5_1.so ex5_1.o

ex5_1.o: ex5_1.c
	gcc -c -Wall -Werror -fpic ex5_1.c

clean:
	rm -rf *.o