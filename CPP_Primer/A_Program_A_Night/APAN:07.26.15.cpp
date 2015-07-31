// DATE : 07/26/15
// FILE : APAN:07.26.15.cpp
// DESC : Display an image with OpenCV library

// Standard library headers
#include <iostream>
#include <string>
#include <vector>

// OpenCV headers
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv/cv.h"

using namespace cv;

// Forward declarations
int print_img(Mat img, std::string name);

int main(int argc, char **argv)
{
    if(argc >= 2){
        Mat img_0;
        img_0 = imread(argv[1], 1);
        print_img(img_0, "img_0");
    }
    else{
        std::cerr << "Invalid command line arguments." << std::endl;
        return -1;
    }
    return 0;
}

int print_img(Mat img, std::string name)
{
    if(img.data){
        namedWindow(name, WINDOW_NORMAL);
        imshow(name, img);
        waitKey(0);
    }
    else{
        std::cerr << "Image not loaded." << std::endl;
        return -1;
    }
    return 0;
}
