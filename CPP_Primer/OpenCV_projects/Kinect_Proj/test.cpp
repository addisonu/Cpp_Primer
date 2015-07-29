// DATE : 07/08/15
// FILE : test.cpp
// DESC : Test out some of the facilities of the OpenCV library


#include <iostream>
#include "opencv/cv.h"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
int main()
{
    IplImage *img = cvLoadImage("image.jpeg"); // verify image path
    cvNamedWindow("MyOpenCV");
    cvShowImage("MyOpenCV", img);
    cvWaitKey(0);
    cvDestroyWindow("MyOpenCV");
    cvReleaseImage(&img);

    return 0;
}
