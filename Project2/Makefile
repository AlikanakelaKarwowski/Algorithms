

.PHONY: all
all : convexHull435

convexHull435 : convexHull435.o JarvisMarch.o
	g++ JarvisMarch.o convexHull435.o -o convexHull435

convexHull435.o : convexHull435.cpp JarvisMarch.hpp
	g++ -std=c++17 -c convexHull435.cpp

Graham.o : Graham.cpp
	g++ -std=c++11 -c Graham.cpp

Jarvis.o : JarvisMarch.cpp
	g++ -std=c++17 -c JarvisMarch.cpp

ConvexHull.o : ConvexHull.cpp
	g++ -std=c++17 -c ConvexHull.cpp

.PHONY: clean
clean :
	@rm -f *.o convexHull435 hull_G.txt hull_J.txt hull_Q.txt
.PHONY: run
run : convexHull435
	./convexHull435 G test.txt
	./convexHull435 J test.txt
	./convexHull435 Q test.txt

.PHONY: fake
fake : convexHull435
	./convexHull435 F test.txt
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
