// CS 3505 - Elizabeth Lomheim - A2: Classes, Facades, and Makefiles

#include "HaruPDF.h"
#include <math.h>

// Generates a new PDF with a single page
HaruPDF::HaruPDF() 
{
    pdf = HPDF_New (NULL, NULL);
    // add a new page object.
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    // print_grid  (pdf, page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

     HPDF_Page_BeginText (page);
    // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 30);
}

// Adds a character to the PDF, placed based on the input values
void HaruPDF::PlaceLetter(char c, double inX, double inY, double angle) 
{
    // Haru-ifying input character
    char buf[2];
    buf[0] = c;
    buf[1] = 0;
    // Haru-ifying input math
    float x = (float)inX;
    float y = (float)inY;
    float letterRad = (float) (angle - 90) / 180 * M_PI;

    /* This ugly function defines where any following text will be placed
    on the page. The cos/sin stuff is actually defining a 2D rotation matrix. */
    HPDF_Page_SetTextMatrix(page,
        cos(letterRad), sin(letterRad), -sin(letterRad), cos(letterRad),
        x, y);

    HPDF_Page_ShowText (page, buf);
}

// Ends the page and saves the current PDF to a file
void HaruPDF::SavePDF(char* filename) {
    HPDF_Page_EndText (page);
    HPDF_SaveToFile (pdf, "spiralPDF.pdf");
    // clean up
    HPDF_Free (pdf);
}