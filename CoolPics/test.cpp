/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Kanishk Kandoi, Abby Moomaw
 * Kanishkk, amoomaw
 *
 * Contains functions for testing classes in the project.
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();
void file_check();

void startTests() {
    test_Point();
    file_check();
    test_Line();
    test_Color();
    test_Triangle();
    test_Circle();
    test_Rectangle();
    
    return;
}

void test_Point() {
    
    cout << endl << "Now testing functions in Point: " << endl << endl;
    
    // test of default constructor
    
    Point p1;
    cout << "Expected: (0,0), actual: " << p1 << endl;
    
    // test of the non-default constructor
    
    Point p2(3, 9);
    cout << "Expected: (3,9), actual: " << p2 << endl;

    // test of member function: setX()
    
    p1.setX(5);
    
    // test of member function: setY()
    
    p1.setY(3);

    // test of member functions getX() and getY()
    
    cout << "Expected: (5,3), actual: ";
    cout << "(" << p1.getX()
         << "," << p1.getY()
         << ")" << endl;
    return;
}

void file_check() {

    // open one of the text files that are part of the starter code
    
    ifstream ins;
    ins.open("data1.txt");

    // if the file was not in the correct directory, the stream state is fail
    
    if (ins.fail()) {
        cout << "Could not open data1.txt" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    ins.close();
    
    return;
}

void test_Line(){
    
    cout << endl << "Now testing functions in Line: " << endl << endl;
    
    // Test LINE_CONSTRUCTOR
    
    Line line1;
    Point line1Start = line1.getStart();
    Point line1End = line1.getEnd();
    Color line1Color = line1.getColor();
    
    cout << "Testing Default constructor: " << endl;
    cout << "Expected Start: (0, 0), Actual Start: (" << line1Start.getX()
    << ", " << line1Start.getY() << ")" << endl;
    cout << "Expected End: (0, 0), Actual End: (" << line1End.getX() << ", "
    << line1End.getY() << ")" << endl;
    cout << "Expected Color (R, G, B): (0, 0, 0), Actual Color (R, G, B): ("
    << line1Color.getRed() << ", " << line1Color.getGreen() << ", "
    << line1Color.getBlue() << ")" << endl;
    
    Point start(1, 2);
    Point end(3, 4);
    Color color(255, 0, 0);
    
    Line line2(start, end, color);
    Point line2Start = line2.getStart();
    Point line2End = line2.getEnd();
    Color line2Color = line2.getColor();
    cout << endl << "Testing Parameterized constructor: " << endl;
    cout << "Expected Start: (1, 2), Actual Start: ("
    << line2Start.getX() << ", " << line2Start.getY() << ")" << endl;
    cout << "Expected End: (3, 4), Actual End: (" << line2End.getX()
    << ", " << line2End.getY() << ")" << endl;
    cout << "Expected Color (R, G, B): (255, 0, 0), Actual Color (R, G, B): ("
    << line2Color.getRed() << ", " << line2Color.getGreen() << ", "
    << line2Color.getBlue() << ")" << endl;
    
    // Test LINE_SET_START and LINE_GET_START
    
    Point newStart(5, 6);
    line2.setStart(newStart);
    Point startPoint = line2.getStart();
    cout << endl << "Testing setStart and getStart: " << endl;
    cout << "Expected Start: (5, 6), Actual Start: (" << startPoint.getX()
    << ", " << startPoint.getY() << ")" << endl;
    
    // Test LINE_SET_END and LINE_GET_END
    
    Point newEnd(7, 8);
    line2.setEnd(newEnd);
    Point endPoint = line2.getEnd();
    cout << endl << "Testing setEnd and getEnd: " << endl;
    cout << "Expected End: (7, 8), Actual End: (" << endPoint.getX()
    << ", " << endPoint.getY() << ")" << endl;
    
}

void test_Color() {
    cout << "Now testing functions in Color:" << endl;

    // Test Default Constructor
    
    Color color1;
    int color1Red = color1.getRed();
    int color1Green = color1.getGreen();
    int color1Blue = color1.getBlue();
    cout << "Testing Default constructor:" << endl;
    cout << "Expected Red: 0, Actual Red: " << color1Red << endl;
    cout << "Expected Green: 0, Actual Green: " << color1Green << endl;
    cout << "Expected Blue: 0, Actual Blue: " << color1Blue << endl;

    // Test Parameterized Constructor
    
    Color color2(255, 128, 64);
    int color2Red = color2.getRed();
    int color2Green = color2.getGreen();
    int color2Blue = color2.getBlue();
    cout << "\nTesting Parameterized constructor:" << endl;
    cout << "Expected Red: 255, Actual Red: " << color2Red << endl;
    cout << "Expected Green: 128, Actual Green: " << color2Green << endl;
    cout << "Expected Blue: 64, Actual Blue: " << color2Blue << endl;

    // Test setBlue and getBlue
    
    color1.setBlue(150);
    cout << "Testing setBlue and getBlue:" << endl;
    cout << "Expected Blue: 150, Actual Blue: " << color1.getBlue() << endl;
    
    color2.setBlue(-150);
    cout << "Testing setBlue and getBlue:" << endl;
    cout << "Expected Blue: 0, Actual Blue: " << color2.getBlue() << endl;

    // Test checkRange in Constructor
    
    Color color3(-10, 300, 120);
    int color3Red = color3.getRed();
    int color3Green = color3.getGreen();
    int color3Blue = color3.getBlue();
    cout << "\nTesting Check Range in Constructor:" << endl;
    cout << "Expected Red: 0, Actual Red: " << color3Red << endl;
    cout << "Expected Green: 255, Actual Green: " << color3Green << endl;
    cout << "Expected Blue: 120, Actual Blue: " << color3Blue << endl;
}


void test_Triangle() {
    cout << endl << "Now testing functions in Triangle: " << endl;

    // Test TRIANGLE_CONSTRUCTORS
    
    Triangle triangle1;
    

    cout << endl << "Expected: (0,0) 0 0 0 (0,0) 0 0 0 (0,0) 0 0 0, Actual: "
    << triangle1 << endl;

    // Testing Parameterized Constructor
    
    Point vertex1(1, 1);
    Point vertex2(2, 2);
    Point vertex3(3, 3);
    Color color1(255, 0, 0);
    Color color2(0, 255, 0);
    Color color3(0, 0, 255);

    Triangle triangle2(vertex1, color1, vertex2, color2, vertex3, color3);

    cout << endl << "Expected: (1,1) 255 0 0 (2,2) 0" <<
    "255 0 (3,3) 0 0 255, Actual: "  << triangle2 << endl;
    
    // Test TRIANGLE_SET_VERTEX
    
    Point newVertex(457, 234);
    triangle2.setVertexOne(newVertex);
    Point point2(-70,400);
    triangle2.setVertexTwo(point2);
    Point point3(700,4000);
    triangle2.setVertexThree(point3);
    
    
    // Test TRIANGLE_GET_VERTEX_COLOR
    
    Color color4(78,40,-32);
    Color color5(100,-45,39);
    Color color6(-2000,3459,3021);
    triangle1.getVertexOneColor();
    triangle1.getVertexTwoColor();
    triangle1.getVertexThreeColor();
    
    // Test TRIANGLE_WRITE
    
    cout << endl << "Testing Write: " << endl;
    cout << "Expected: (4, 4) (255, 0, 0) (2, 2)"
    << "(255, 0, 0) (3, 3) (255, 0, 0)"
    << endl << "Actual: " << triangle2 << endl;
}

void test_Circle() {
    
    cout << endl << "Now testing functions in Circle: " << endl;
    
    // Test CIRCLE_CONSTRUCTORS
    
    Circle circle1;
    cout << "Expected: (0, 0) 0 0 0 0, Actual: " << circle1;
    
    Point center(-2, 20000);
    int radius = -5;
    Color color(200, 5000, 210000);
    
    Circle circle2(center, radius, color);
    cout << "Expected: (0, 99) 0 (200 255 255), Actual: " << circle2;
    
    // Test CIRCLE_SET_CENTER
    
    Point newCenter(3, 3);
    circle2.setCenter(newCenter);
    Point updatedCenter = circle2.getCenter();
    cout << "Expected: (3,3), Actual: " << updatedCenter << endl;
    
    // Test CIRCLE_SET_RADIUS
    
    circle2.setRadius(-89);
    cout << "Expected: 6, Actual: " << circle2.getRadius() << endl;
    
}

void test_Rectangle(){
    
    cout << endl << "Now testing functions in Rectangle: " << endl;
    
    // Test RECTANGLE_CONSTRUCTORS_1
    
    Rectangle rect1;
    cout << "Expected: (0,0) (0,0) (0,0,0) (0,0,0) (0,0,0) (0,0,0), Actual: "
    << rect1 << endl;
    
    // Test RECTANGLE_CONSTRUCTORS_2
    
    Point pt1(2, 2);
    Point pt2(-5, -50);
    Color color(255, 0, -900);
    Rectangle rect2(pt1, pt2, color);
    cout << "Expected: (2,2) (5,5) (255,0,0) (255,0,0) (255,0,0) (255,0,0),"
    << "Actual: " << rect2 << endl;
    
    Point pt3(2, 2);
    Point pt4(-5, -50);
    Color color2(255, 0, -900);
    Color color3(255, 5, 900);
    Color color4(230, 0, -900);
    Rectangle rect3(pt3, pt4, color, color2, color3, color4);
    cout << "Expected: (2,2) (5,5) (255,0,0) (255,0,0) (255,5,255) (230,0,0),"
    << "Actual: " << rect3 << endl;
    
    // Test RECTANGLE_SET_COLOR
    
    Color newColor(0, 255, 0);
    rect2.setColor(newColor);
    cout << "Expected: (2,2) (5,5) (0,255,0) (0,255,0) (0,255,0) (0,255,0), "
    << "Actual: " << rect2 << endl;
    
    // Test RECTANGLE_GET_END
    Point end = rect2.getEnd();
    cout << "Expected: (5,5), Actual: " << end << endl;
    
    // Test RECTANGLE_SET_START
    
    Point newStart(1, 1);
    rect2.setStart(newStart);
    cout << "Expected: (1,1) (5,5) (0,255,0) (0,255,0) (0,255,0) (0,255,0), "
    << "Actual: " << rect2 << endl;
    
}
