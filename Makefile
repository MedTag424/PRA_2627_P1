all: bin/testListArray bin/testNode bin/testListLinked bin/testPoint2D

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

clean:
	rm -f *.o *.gch *.pch
	rm -rf bin

bin/testNode: testNode.cpp Node.h
	mkdir -p bin
	g++ -o bin/testNode testNode.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h Node.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

Point2D.o: Point2D.cpp Point2D.h
	g++ -c Point2D.cpp

testPoint2D.o: testPoint2D.cpp Point2D.h
	g++ -c testPoint2D.cpp

bin/testPoint2D: testPoint2D.o Point2D.o
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o
Shape.o: Shape.cpp Shape.h Point2D.h
	g++ -c Shape.cpp
Circle.o: Circle.cpp Circle.h Shape.h Point2D.h
	g++ -c Circle.cpp

testCircle.o: testCircle.cpp Circle.h
	g++ -c testCircle.cpp

bin/testCircle: testCircle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o
Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Rectangle.cpp

testRectangle.o: testRectangle.cpp Rectangle.h
	g++ -c testRectangle.cpp

bin/testRectangle: testRectangle.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o
Square.o: Square.cpp Square.h Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp

testSquare.o: testSquare.cpp Square.h
	g++ -c testSquare.cpp

bin/testSquare: testSquare.o Square.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o
Drawing.o: Drawing.cpp Drawing.h ListLinked.h Shape.h Circle.h Square.h
	g++ -c Drawing.cpp

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -c testDrawing.cpp
	g++ -o bin/testDrawing testDrawing.o Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
