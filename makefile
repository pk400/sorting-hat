all: sorting

sorting: main.o
	g++ main.o -o run -lsfml-audio -lsfml-window -lsfml-system
	rm main.o

main.o: main.cpp
	g++ -c main.cpp
