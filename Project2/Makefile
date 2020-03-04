

.PHONY: all
all : convexHull435

convexHull435 : convexHull435.o
	g++ convexHull435.o -o convexHull435

convexHull435.o : convexHull435.cpp
	g++ -std=c++17 -c convexHull435.cpp

Graham.o : Graham.cpp
	g++ -std=c++11 -c Graham.cpp

Jarvis.o : Jarvis.cpp
	g++ -std=c++11 -c Jarvis.cpp

ConvexHull.o : ConvexHull.cpp
	g++ -std=c++17 -c ConvexHull.cpp

.PHONY: clean
clean :
	@rm -f *.o convexHull435 hull_G.txt hull_J.txt hull_Q.txt



#.PHONY: all
#all : convexHull435

#convexHull435 : convexHull435.o Graham.o Jarvis.o ConvexHull.o
#g++ convexHull435.o Graham.o Jarvis.o ConvexHull.o -o convexHull435

#convexHull435.o : convexHull435.cc Graham.hpp Jarvis.hpp ConvexHull.hpp
#g++ -std=c++11 -c convexHull435.cc

#Graham.o : Graham.cpp
#g++ -std=c++11 -c Graham.cpp

#Jarvis.o : Jarvis.cpp
#g++ -std=c++11 -c Jarvis.cpp

#ConvexHull.o : ConvexHull.cpp
#g++ -std=c++11 -c ConvexHull.cpp

#.PHONY: clean
#clean :
#@rm -f *.o convexHull435 hull_G.txt hull_J.txt hull_Q.txt
