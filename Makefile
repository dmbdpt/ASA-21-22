FLAGS = -std=c++11 -O3 -Wall

all: testrand1 testrand2 test graph

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

graph: rand main.o
	./random_k 1 10 0.5 100000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 200000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 300000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 400000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 500000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 600000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 700000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 800000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 900000 > testfile
	time ./main.o < testfile
	./random_k 1 10 0.5 1000000 > testfile
	time ./main.o < testfile
	
test: main.o
	time ./main.o < test

clean:
	rm *.o
