FLAGS = -std=c++11 -O3 -Wall

all: testrand1 testrand2 test

main.o: main.cpp
	g++ $(FLAGS) main.cpp -lm -o main.o

rand: random_k.cpp
	g++ -O3 -Wall -o random_k random_k.cpp -lm

testrand1: rand main.o
	./random_k 1 10 0.999 200 > testfile
	time ./main.o < testfile

testrand2: rand main.o
	./random_k 1 10 0.5 200 > testfile
	time ./main.o < testfile

test: main.o
	time ./main.o < test

clean:
	rm *.o