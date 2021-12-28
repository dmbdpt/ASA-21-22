FLAGS = -std=c++11 -O3 -Wall

all: main.o testrand
	./main.o < test

main.o: main.cpp
	g++ $(FLAGS) main.cpp -lm -o main.o

rand: random_k.cpp
	g++ -O3 -Wall -o random_k random_k.cpp -lm

testrand: rand
	./random_k 1 10 0.5 200 > testfile
	./main.o < testfile

clean:
	rm *.o