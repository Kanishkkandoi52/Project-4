/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Kanishk Kandoi, Abby Moomaw
 * Kanishkk, Amoomaw
 *
 * A projects in which we read  a description of shapes,
 * draws those shapes, and saves the result to a file.
 */

#include "Point.h"
#include "utility.h"

// TODO: implement two constructors, setX, getX, setY, getY, read, write, checkRange.

/* Implementing the constructors for Point */

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

/* Implementing the setters and getters for Point */

void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return x;
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return y;
}

/* Implementing the read and write for Point */

void Point::read(istream& ins) {
    char temp; // A junk variable temp
    ins >> temp >> x >> temp >> y >> temp;
    x = checkRange(x);
    y = checkRange(y);
}

void Point::write(ostream& outs) {
    outs << "(" << x << "," << y << ")";
}

/* Checking if the entered value is greater than 0 and less than 100 */

int Point::checkRange(int val) {
    if (val < 0) {
        return 0;
    } else if (val >= DIMENSION) {
        return DIMENSION - 1;
    } else {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
