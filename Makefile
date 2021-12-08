FLAGS = -std=c++11 -O3 -Wall

all: main.o
	./main.o < test

main.o: main2.cpp
	g++ $(FLAGS) main2.cpp -lm -o main.o

clean:
	rm *.o