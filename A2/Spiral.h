#ifndef SPIRAL_H
#define SPIRAL_H
class Spiral 
{    
    // x-value of the current letter's position
    double centerX;
    // y-value of the current letter's position
    double centerY;
    // angle of the current letter's position
    double angle;
    // radius of the circle the letter is aligned with
    double radius;
    // radian of the current letter along the spiral 
    double circleRadian;
    // The angle's rate of change
    double angleROC;
    // The radius's rate of change
    double radiusROC;

public:

    Spiral(double _centerX, double _centerY, double _angle, double _radius);

    Spiral& operator++ ();   
    Spiral operator++ (int);

    double getTextX();
    double getTextY();  
    double getLetterAngle();
};
#endif