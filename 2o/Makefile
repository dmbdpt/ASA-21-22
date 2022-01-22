FLAGS = -std=c++11 -O3 -Wall

all: testrand

main.o: main_copy_2.cpp
	g++ $(FLAGS) main_copy_2.cpp -lm -o main.o

rand: randGeneoTree.cpp
	g++ -std=c++11 -O3 -Wall randGeneoTree.cpp -lm -o randGeneoTree.o

testrand: rand main.o
	./randGeneoTree.o 100000 0.5 > testfile
	time ./main.o < testfile > /dev/null

graph: rand main.o
	hyperfine --warmup 3 -P size 100000 1000000 -D 100000 --prepare './randGeneoTree.o {size} 0.5 > testfile' './main.o < testfile' --export-json 'results.json' 

clean:
	rm *.o
