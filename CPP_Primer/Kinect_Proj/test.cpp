// DATE : 07/08/15
// FILE : test.cpp
// DESC : Test out some of the facilities of the OpenCV library

#include <iostream>
#include "opencv/cv.h"
#include "opencv/highgui.h"

int main()
{
    IplImage *img = cvLoadImage("/Users/Downloads/images.jpeg"); // verify image path
    cvNamedWindow("MyOpenCV");
    cvShowImage("MyOpenCV", img);
    cvWaitKey(0);
    cvDestroyWindow("MyOpenCV");
    cvReleaseImage(&img);

    return 0;
}
