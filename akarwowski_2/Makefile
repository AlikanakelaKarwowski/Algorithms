

.PHONY: all
all : convexHull435

convexHull435 : convexHull435.o
	g++ convexHull435.o -o convexHull435

convexHull435.o : convexHull435.cpp
	g++ -std=c++17 -c convexHull435.cpp

.PHONY: clean
clean :
	@rm -f *.o convexHull435 hull_G* hull_J* hull_Q* *.class

.PHONY: cleanTest
cleanTest :
	@rm output/jarvisMarch/test*
	@rm output/grahamScan/test*
	@rm output/quickHull/test*

.PHONY: cleanAll
cleanAll: clean
	@rm -f *10*.txt

#generates all hull_J_*.txt files with Jarvis March.
.PHONY: runJ
runJ : 
	@echo "Running Jarvis March Algorithm"
	./convexHull435 J rectangle10.txt
	./convexHull435 J rectangle100.txt
	./convexHull435 J rectangle1000.txt
	./convexHull435 J rectangle10000.txt
	./convexHull435 J rectangle100000.txt
	./convexHull435 J rectangle1000000.txt
	./convexHull435 J circle10.txt
	./convexHull435 J circle100.txt
	./convexHull435 J circle1000.txt
	./convexHull435 J circle10000.txt
	./convexHull435 J circle100000.txt
	./convexHull435 J circle1000000.txt
	./convexHull435 J onCircle10.txt
	./convexHull435 J onCircle100.txt
	./convexHull435 J onCircle1000.txt
	./convexHull435 J onCircle10000.txt
	./convexHull435 J onCircle100000.txt
	./convexHull435 J onCircle1000000.txt
	./convexHull435 J triangle10.txt
	./convexHull435 J triangle100.txt
	./convexHull435 J triangle1000.txt
	./convexHull435 J triangle10000.txt
	./convexHull435 J triangle100000.txt
	./convexHull435 J triangle1000000.txt

#generates all hull_G_*.txt files with Jarvis March.
.PHONY: runG
runG : 
	@echo "Running Graham Scan Algorithm"
	./convexHull435 G rectangle10.txt
	./convexHull435 G rectangle100.txt
	./convexHull435 G rectangle1000.txt
	./convexHull435 G rectangle10000.txt
	./convexHull435 G rectangle100000.txt
	./convexHull435 G rectangle1000000.txt
	./convexHull435 G circle10.txt
	./convexHull435 G circle100.txt
	./convexHull435 G circle1000.txt
	./convexHull435 G circle10000.txt
	./convexHull435 G circle100000.txt
	./convexHull435 G circle1000000.txt
	./convexHull435 G onCircle10.txt
	./convexHull435 G onCircle100.txt
	./convexHull435 G onCircle1000.txt
	./convexHull435 G onCircle10000.txt
	./convexHull435 G onCircle100000.txt
	./convexHull435 G onCircle1000000.txt
	./convexHull435 G triangle10.txt
	./convexHull435 G triangle100.txt
	./convexHull435 G triangle1000.txt
	./convexHull435 G triangle10000.txt
	./convexHull435 G triangle100000.txt
	./convexHull435 G triangle1000000.txt

.PHONY: runQ
runQ : 
	@echo "Running QuickHull Algorithm"
	./convexHull435 Q rectangle10.txt
	./convexHull435 Q rectangle100.txt
	./convexHull435 Q rectangle1000.txt
	./convexHull435 Q rectangle10000.txt
	./convexHull435 Q rectangle100000.txt
	./convexHull435 Q rectangle1000000.txt
	./convexHull435 Q circle10.txt
	./convexHull435 Q circle100.txt
	./convexHull435 Q circle1000.txt
	./convexHull435 Q circle10000.txt
	./convexHull435 Q circle100000.txt
	./convexHull435 Q circle1000000.txt
	./convexHull435 Q onCircle10.txt
	./convexHull435 Q onCircle100.txt
	./convexHull435 Q onCircle1000.txt
	./convexHull435 Q onCircle10000.txt
	./convexHull435 Q onCircle100000.txt
	./convexHull435 Q onCircle1000000.txt
	./convexHull435 Q triangle10.txt
	./convexHull435 Q triangle100.txt
	./convexHull435 Q triangle1000.txt
	./convexHull435 Q triangle10000.txt
	./convexHull435 Q triangle100000.txt
	./convexHull435 Q triangle1000000.txt

.PHONY: runAll
runAll: convexHull435 runJ runG runQ

.PHONY: generate
generate:
	javac ConvexHull_GUI.java
	java ConvexHull_GUI 1

.PHONY: testJ
testJ: convexHull435 generate
	make runJ
	java ConvexHull_GUI 0 circle10.txt hull_J_
	java ConvexHull_GUI 0 circle100000.txt hull_J_
	java ConvexHull_GUI 0 oncircle10.txt hull_J_
	java ConvexHull_GUI 0 oncircle100000.txt hull_J_
	java ConvexHull_GUI 0 rectangle10.txt hull_J_
	java ConvexHull_GUI 0 rectangle100000.txt hull_J_
	java ConvexHull_GUI 0 triangle10.txt hull_J_
	java ConvexHull_GUI 0 triangle100000.txt hull_J_

.PHONY: testG
testG: convexHull435 generate
	make runG
	java ConvexHull_GUI 0 circle10.txt hull_G_
	java ConvexHull_GUI 0 circle100000.txt hull_G_
	java ConvexHull_GUI 0 oncircle10.txt hull_G_
	java ConvexHull_GUI 0 oncircle100000.txt hull_G_
	java ConvexHull_GUI 0 rectangle10.txt hull_G_
	java ConvexHull_GUI 0 rectangle100000.txt hull_G_
	java ConvexHull_GUI 0 triangle10.txt hull_G_
	java ConvexHull_GUI 0 triangle100000.txt hull_G_

.PHONY: testQ
testQ: convexHull435 generate
	make runQ
	java ConvexHull_GUI 0 circle10.txt hull_Q_
	java ConvexHull_GUI 0 circle100000.txt hull_Q_
	java ConvexHull_GUI 0 oncircle10.txt hull_Q_
	java ConvexHull_GUI 0 oncircle100000.txt hull_Q_
	java ConvexHull_GUI 0 rectangle10.txt hull_Q_
	java ConvexHull_GUI 0 rectangle100000.txt hull_Q_
	java ConvexHull_GUI 0 triangle10.txt hull_Q_
	java ConvexHull_GUI 0 triangle100000.txt hull_Q_
