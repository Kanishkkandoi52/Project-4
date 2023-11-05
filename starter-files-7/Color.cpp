/**
 * Color.cpp
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

#include "Color.h"

// TODO: implement first checkRange, then two constructors, setRed, getRed,
//       setGreen, getGreen, setBlue, getBlue, read, write.

/* Implementing the constructors for Color */

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

/* Implementing the setters and getters for Color */

void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

int Color::getRed() {
    return red;
}

void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

int Color::getGreen() {
    return green;
}

void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

int Color::getBlue() {
    return blue;
}

/* Implement the read and write for color */

void Color::read(istream& ins) {
    ins >> red >> green >> blue;
    red = checkRange(red);
    blue = checkRange(blue);
    green = checkRange(green);
}

void Color::write(ostream& outs) {
    outs << red << ' ' << green << ' ' << blue;
}

/* 255 is the maximum color value we can use and 0 is the minimum */

int Color::checkRange(int val) {
    if (val < 0) {
        return 0;
    } else if (val > 255) {
        return 255;
    } else {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
