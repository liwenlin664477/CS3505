// CS 3505 - Elizabeth Lomheim - A2: Classes, Facades, and Makefiles

#include "Spiral.h"
#include "HaruPDF.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main (int argc, char **argv) 
{
    HaruPDF pdf;
    Spiral spin(0, 0, 0, 75);
    char* inputText;
    char currChar;
    // Math vars
    double angle;
    double letterX;
    double letterY;

    if (argc < 2) {
        std::cout << "Error: No input" << std::endl;
        return 0;
    }

    inputText = argv[1];

    for (int i = 0; inputText[i]!= 0; i++) 
    {
        currChar = inputText[i];

        angle = spin.getLetterAngle() + 180;
        letterX = spin.getTextX() + 210;
        letterY = spin.getTextY() + 300;

        pdf.PlaceLetter(currChar, letterX, letterY, angle);
        spin++;
    }
    pdf.SavePDF(argv[0]);
}