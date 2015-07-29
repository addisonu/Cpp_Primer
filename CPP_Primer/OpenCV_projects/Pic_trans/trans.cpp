// DATE : 07/28/15
// FILE : trans.cpp
// DESC : Use OpenCV library to apply artistic transformations to image

// Standard header files
#include <iostream>
#include <string>
#include <vector>

// OpenCV header files
#include "opencv2/highgui/highgui.hpp"
#include "opencv/cv.h"

using namespace cv;

int main(int argc, char **argv)
{

// Create Mat object to hold image copy
    cv::Mat img;
    if(argc >= 2){
        img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

// Print original image
        if(img.data){
            cv::namedWindow("Original image", cv::WINDOW_OPENGL);
            cv::resizeWindow("Original image", 1, 1);// doesn't work, remove or fix
            cv::imshow("Display Original image", img);
            cv::waitKey(0);
        }
        else{
            std::cerr << "Image not loaded." << std::endl;
            return 1;
        }
    // Divide image into four equal quandrants
        cv::Mat img_q1 = img(Range(0, img.size().height / 2), Range(0, img.size().width / 2));
        cv::Mat img_q2 = img(Range(0, img.size().height / 2), Range(img.size().width / 2, img.cols));

        cv::Mat img_q3 = img(Range(img.size().height / 2, img.rows), Range(0, img.size().width / 2));

        cv::Mat img_q4 = img(Range(img.size().height / 2, img.rows), Range(img.size().width / 2, img.cols));


// Print quandrant images
        if(img_q1.data){
            cv::namedWindow("Q1 image", cv::WINDOW_OPENGL);
            cv::imshow("Display Q1 image", img_q1);
            cv::waitKey(0);

        }
        else{
            std::cerr << "Q1 image not loaded." << std::endl;
            return 1;
        }

        if(img_q2.data){
            cv::namedWindow("Q2 image", cv::WINDOW_OPENGL);
            cv::imshow("Display Q2 image", img_q2);
            cv::waitKey(0);

        }
        else{
            std::cerr << "Q2 image not loaded." << std::endl;
            return 1;
        }

        if(img_q3.data){
            cv::namedWindow("Q3 image", cv::WINDOW_OPENGL);
            cv::imshow("Display Q3 image", img_q3);
            cv::waitKey(0);

        }
        else{
            std::cerr << "Q3 image not loaded." << std::endl;
            return 1;
        }

       if(img_q4.data){
            cv::namedWindow("Q4 image", cv::WINDOW_OPENGL);
            cv::imshow("Display Q4 image", img_q4);
            cv::waitKey(0);
        }
        else{
            std::cerr << "Q4 image not loaded." << std::endl;
            return 1;
        }
    }
    return 0;
}
