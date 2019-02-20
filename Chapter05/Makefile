ex5_1.so: ex5_1.o
	gcc -shared -o libex5_1.so ex5_1.o

ex5_1.o: ex5_1.c
	gcc -c -Wall -Werror -fpic ex5_1.c

ex5_1_1.so: ex5_1_1.o
	g++ -shared -o libex5_1_1.so ex5_1_1.o

ex5_1_1.o: ex5_1_1.cpp
	g++ -std=c++11 -c -Wall -Werror -fpic ex5_1_1.cpp	

clean:
	rm -rf *.o *.pyc