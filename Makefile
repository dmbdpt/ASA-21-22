FLAGS = -std=c++11 -O3 -Wall

all: main.o
	./main.o < test

main.o: main.cpp
	g++ $(FLAGS) main.cpp -lm -o main.o

clean:
	rm *.o