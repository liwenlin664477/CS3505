#ifndef HARUPDF_H
#define HARUPDF_H

#include "hpdf.h"

class HaruPDF 
{
    // PDF document
    HPDF_Doc pdf;
    // Page in the PDF document
    HPDF_Page page;
    // Font used in the PDF document
    HPDF_Font font;

public:

    HaruPDF();

    void PlaceLetter(char c, double x, double y, double angle);
    void SavePDF(char* filename);
};
#endif