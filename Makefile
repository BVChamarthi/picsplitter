image.o: image.cpp image.h
	g++ -std=c++17 -c image.cpp -o object/image.o

split_in_half: split_in_half.cpp image.o
	g++ -std=c++17 split_in_half.cpp object/image.o -o split_in_half