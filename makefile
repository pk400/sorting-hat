all: sorting

sorting: main.o
	g++ main.o -o run -lsfml-audio -lsfml-system
	rm main.o
	./run

main.o: main.cpp
	g++ -c main.cpp
