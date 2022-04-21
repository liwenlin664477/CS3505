/*
 * << Alternative PDF Library 1.0.0 >> -- text_demo2.c
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 * Modified by David Johnson, University of Utah, 2016.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "hpdf.h"

// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char **argv)
{
    HPDF_Doc  pdf;
    HPDF_Page page;
    char fname[256];
    HPDF_Font font;
    float angle2;
    float rad1;
    float rad2;
    unsigned int i;

    const char* SAMP_TXT = "The quick brown fox jumps over the lazy dog. We need more text to test a spiral. Maybe the radians needs to increase with smaller radius. ";

    // argv are the command line arguments
    // argv[0] is the name of the executable program
    // This makes an output pdf named after the program's name
    strcpy (fname, argv[0]);
    strcat (fname, ".pdf");

    pdf = HPDF_New (NULL, NULL);
    /* add a new page object. */
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
//    print_grid  (pdf, page);
    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);

    /* text along a circle */
    angle2 = 180;

    HPDF_Page_BeginText (page);
    // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 30);
    // Place characters one at a time on the page.
    for (i = 0; i < strlen (SAMP_TXT); i++) {
        char buf[2];
        float x;
        float y;
        // rad1 determines the angle of the letter on the page. rad2 is how far
        // around the circle you are. Notice that they are perpendicular and
        // thus not independent.
        //
        // Pay careful attention to what wants radians and what is degrees
        // between haru and spiral and math functions.
        rad1 = (angle2 - 90) / 180 * 3.141592;
        rad2 = angle2 / 180 * 3.141592;

        // The position of the character depends on the center point
        // plus the angle and the radius.
        x = 210 + cos(rad2) * 150;
        y = 300 + sin(rad2) * 150;

        // This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
        HPDF_Page_SetTextMatrix(page,
                                cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                                x, y);

        // C-style strings are null-terminated. The last character must a 0.
        buf[0] = SAMP_TXT[i]; // The character to display
        buf[1] = 0;
        HPDF_Page_ShowText (page, buf);
        angle2 -= 10.0; // change the angle around the circle
    }

    HPDF_Page_EndText (page);

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    /* clean up */
    HPDF_Free (pdf);

    return 0;
}



