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
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace cv;


// Global var
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
Mat src, dst, glob_img;
char window_name[] = "Test filter";
int track_pos = 100;

// Forward declarations
int display_caption(char *caption);
int display_dst(int delay);
int display_image(Mat img, std::string name);
static void track_chng(int track_pos, void *user_data);

int main(int argc, char **argv)
{
// Create Mat object to hold image copy
    cv::Mat img;
    if(argc >= 2){
        img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

// Divide image into four equal quandrants
        cv::Mat img_q1 = img(Range(0, img.size().height / 2), Range(0, img.size().width / 2));

        cv::Mat img_q2 = img(Range(0, img.size().height / 2), Range(img.size().width / 2, img.cols));

        cv::Mat img_q3 = img(Range(img.size().height / 2, img.rows), Range(0, img.size().width / 2));

        cv::Mat img_q4 = img(Range(img.size().height / 2, img.rows), Range(img.size().width / 2, img.cols));

// Print original image
        display_image(img, "Original Image");
        display_image(img_q1, "Q1");
        display_image(img_q2, "Q2");
        display_image(img_q3, "Q3");
        display_image(img_q4, "Q4");

// Apply blur to quadrants of image
        int i = MAX_KERNEL_LENGTH;
        src = img_q1.clone();
        bilateralFilter(src, img_q1, i, i * 2, i / 2);
        src = img_q2.clone();
        blur(src, img_q2, Size(i - 15, i - 15), Point(-1, -1));
        src = img_q3.clone();
        GaussianBlur(src, img_q3, Size(i - 10, i), 0, 0);
        src = img_q4.clone();
        medianBlur(src, img_q4, i - 20);
        display_image(img, "Original Image");

// Add trackbar
    imwrite("trans_img.jpg", img);
    glob_img = imread("trans_img.jpg", 0);
    namedWindow("Trans Image", 1);
    if(glob_img.empty()){
        std::cerr << "Image not loaded for trackbar." << std::endl;
        return -1;
    }
    createTrackbar("Hue", "Trans Image", &track_pos, 255, track_chng);
    track_chng(track_pos, 0);
    waitKey(0);
    }
    return 0;
}

// AUXILLARY FUNCTIONS //
int display_caption(char *caption)
{
    dst = Mat::zeros(src.size(), src.type());
    putText(dst, caption, Point(src.cols / 4, src.rows / 2), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

    imshow(window_name, dst);
    int c = waitKey(DELAY_CAPTION);
    if(c >=0 ) { return -1; }
    return 0;
}

int display_dst(int delay)
{
    imshow(window_name, dst);
    int c = waitKey(delay);
    if(c >= 0) { return -1; }
    return 0;
}

int display_image(Mat img, std::string name)
{
    if(img.data){
        cv::namedWindow(name, CV_WINDOW_NORMAL);
        cv::imshow(name, img);
        cv::waitKey(0);
    }
    else{
        std::cerr << "Image not loaded." << std::endl;
        return 1;
    }
    return 0;
}

static void track_chng(int track_pos, void *user_data)
{
    Mat bw = track_pos < 128 ? (glob_img < track_pos) : (glob_img > track_pos);
    Mat labelImage(glob_img.size(), CV_32S);
    int nLabels = connectedComponents(bw, labelImage, 8);
    std::vector<Vec3b> colors(nLabels);
    colors[0] = Vec3b(0, 0, 0);
    for(int label = 1; label < nLabels; ++label){
        colors[label] = Vec3b((rand()&2), (rand()&255), (rand()&1));
    }
    Mat glob_dst(glob_img.size(), CV_8UC3);
    for(int r = 0; r < glob_dst.rows; ++r){
        for(int c = 0; c < glob_dst.cols; ++c){
            int label = labelImage.at<int>(r, c);
            Vec3b &pixel = glob_dst.at<Vec3b>(r, c);
            pixel = colors[label];
        }
    }
    imshow("Trans Image", glob_dst);
}
