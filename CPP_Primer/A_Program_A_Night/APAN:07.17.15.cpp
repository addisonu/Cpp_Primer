// DATE : 07/17/15
// FILE : APAN:07.17.15.cpp
// DESC : Using a Mat object

#include <iostream>
#include <string>
#include "opencv2/core/core.hpp"

int main()
{
// var arguments for Mat objects
// Create Mat object
    cv::Mat U;
    //U = cv::imread("image.jpeg", CV_LOAD_IMAGE_COLOR);
    cv::Mat B(U);
    cv::Mat C = U;
    cv::Mat D (U, cv::Rect(7, 7, 100, 100));
    cv::Mat E = U(cv::Range::all(), cv::Range(1,4));
    cv::Mat F(U.clone());
    cv::Mat G;
    U.copyTo(G);
    cv::Mat H(2, 2, CV_8UC3, cv::Scalar(0, 0, 255));

// Use Mat operations
    std::cout << "H : \n" << H << std::endl;
    return 0;
}
