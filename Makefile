#Makefile
all: sum-nbo

sum-nbo: main.o nbo.o
	g++ -o sum-nbo main.o nbo.o

main.o : main.h main.cpp 
	g++ -c -o main.o main.cpp

nbo.o : main.h nbo.cpp
	g++ -c -o nbo.o nbo.cpp
	
clean:
	rm -f sum-nbo
	rm -f *.o
