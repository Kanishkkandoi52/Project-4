/**
 * Rectangle.cpp
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

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// TODO: implement three constructors, setStart, getStart, setEnd, getEnd,
//       setColor, setColorTopLeft, getColorTopLeft, setColorTopRight,
//       getColorTopRight, setColorBottomRight, getColorBottomRight,
//       setColorBottomLeft, getColorBottomLeft, read, write.

/* Implementing the constructors for Rectangle */

Rectangle::Rectangle() {

}

Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft,
                     Color cTopRight, Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

/* Implementing the setters and getters */

void Rectangle::setStart(Point pt) {
    start = pt;
}

Point Rectangle::getStart() {
    return start;
}

void Rectangle::setEnd(Point pt) {
    end = pt;
}

Point Rectangle::getEnd() {
    return end;
}

void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

/* Different color setter and getter */

void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

/* We take in one color and check for second color
   If second color fails then we set all colors to first color
   If does not fail, then we continue to input other values */

void Rectangle::read(std::istream& ins) {
    ins >> start >> end >> colorTopLeft;

    if (!ins.fail()) {
        ins >> colorTopRight;

        if (!ins.fail()) {
            ins >> colorBottomRight;

            if (!ins.fail()) {
                ins >> colorBottomLeft;

                if (ins.fail()) {
                    ins.clear();
                    colorBottomLeft = colorBottomRight;
                }
            } else {
                ins.clear();
                colorBottomRight = colorTopRight;
                colorBottomLeft = colorBottomRight;
            }
        } else {
            ins.clear();
            colorTopRight = colorTopLeft;
            colorBottomRight = colorTopRight;
            colorBottomLeft = colorTopRight;
        }
    } else {
        ins.clear();
        colorTopLeft = Color(0, 255, 255);
        colorTopRight = colorTopLeft;
        colorBottomRight = colorTopLeft;
        colorBottomLeft = colorTopLeft;
    }

}

/* Writing the colors in file taken from read */

void Rectangle::write(ostream& outs) {
    outs << start << " " << end << " " << colorTopLeft << " "
    << colorTopRight << " " << colorBottomRight << " " << colorBottomLeft;
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
