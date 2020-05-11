.PHONY: all
all : main

main : main.o seamCarve.o
	g++ -std=c++17 main.o seamCarve.o -o carve

main.o : main.cpp seamCarve.hpp
	g++ -std=c++17 -c main.cpp

seamCarve.o : seamCarve.cpp
	g++ -std=c++17 -c seamCarve.cpp
.PHONY: clean
clean :
	@rm -f carve *.o
