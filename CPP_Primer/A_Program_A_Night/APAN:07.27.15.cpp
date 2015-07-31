// DATE : 07/27/15
// FILE : APAN:07.27.15.cpp
// DESC : Blur an image with OpenCV library

// Standard library headers
#include <iostream>
#include <string>

// OpenCV headers
#include "opencv/cv.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"

using namespace cv;

// Forward declarations
int print_img(Mat img, std::string name, unsigned wt);

int main(int argc, char **argv)
{
// Var definitions
    unsigned MAX_KERNEL_LENGTH = 30;
    unsigned DELAY = 100;
    Mat img0, src, dest;
    img0 = imread(argv[1], CV_LOAD_IMAGE_COLOR);
    src = img0.clone();

// Print OG pic
    print_img(img0, "img0", 0);

// Bilateral blur
    for(std::size_t i = 1; i < MAX_KERNEL_LENGTH; i += 2){
        bilateralFilter(src, dest, i, i * 2, i / 2);
        print_img(dest, "Bilateral Blur", DELAY);
    }
// Gaussain blur
    for(std::size_t i = 1; i < MAX_KERNEL_LENGTH; i += 2){
        GaussianBlur(src, dest, Size(i, i), 0, 0);
        print_img(dest, "Gaussain Blur", DELAY);
    }
// Homogeneous blur
    for(std::size_t i = 1; i < MAX_KERNEL_LENGTH; i += 2){
        blur(src, dest, Size(i, i), Point(-1, -1));
        print_img(dest, "Homogeneous Blur", DELAY);
    }
// Median blur
    for(std::size_t i = 1; i < MAX_KERNEL_LENGTH; i += 2){
        medianBlur(src, dest, i);
        print_img(dest, "Median Blur", DELAY);
    }

    return 0;
}

int print_img(Mat img, std::string name, unsigned wt)
{
    if(img.data){
        namedWindow(name, WINDOW_NORMAL);
        imshow(name, img);
        waitKey(wt);
    }
    else{
        std::cout << "Image not loaded." << std::endl;
        return -1;
    }
    return 0;
}
