// CS 3505 - Elizabeth Lomheim - A2: Classes, Facades, and Makefiles

#include "Spiral.h"
#include <math.h>
#include <iostream>

// Initialize variables with inputs
Spiral::Spiral(double _centerX, double _centerY, double _angle, double _radius) 
{
    centerX = _centerX;
    centerY = _centerY;
    angle = _angle;
    radius = _radius;

    angleROC = 15;
    radiusROC = 1.5;

    circleRadian = angle / 180 * M_PI;
}

// Operator overload structure used from
// https://stackoverflow.com/questions/3846296/how-to-overload-the-operator-in-two-different-ways-for-postfix-a-and-prefix

// prefix ++
Spiral& Spiral::operator++ () 
{
    // Calculate change in angle and radius
    radius = radius + radiusROC;
    angle = angle + angleROC;
    // + angleROC

    // Check if the angle rate-of-change needs to be updated
    if (radius > 250) {
        angleROC = 4;
    }
    else if (radius > 180) {
        angleROC = 6;
    }
    else if (radius > 135) {
        angleROC = 8;
    }
    else if (radius > 100) {
        angleROC = 10;
    }

    // Calculate angles as radians
    circleRadian = angle / 180 * M_PI;

    return *this;
}

// postfix ++
Spiral Spiral::operator++ (int) {
    Spiral result(*this);
    ++(*this);
    return result;
}

// Return the x-value of the letter's current position on the page.
double Spiral::getTextX() {
    centerX = cos(circleRadian) * radius;
    return centerX;
}

// Return the y-value of the letter's current position on the page.
double Spiral::getTextY() {
    centerY = sin(circleRadian) * radius;
    return centerY;
}

//  Return the angle of the letter's current position on the page, in degrees.
double Spiral::getLetterAngle() {
    return angle;
}