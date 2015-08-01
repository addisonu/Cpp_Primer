// DATE : 07/28/15
// FILE : APAN:07.28.15.cpp
// DESC : Add trackbar to image using OpenCV library

// Standard library headers
#include <iostream>
#include <string>
#include <vector>

// OpenCV headers
#include "opencv/cv.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"

using namespace cv;

// Forward declarations
int print_img(Mat img, std::string name, unsigned wt); // print an image
static void track_chng(int track_pos, void *user_data); // function that changes image based on trackbar position

// Global var
Mat glob_src; // Mat used in main and track_chng functions
int track_pos = 100; // arbitrary initial trackbar value
char window_name[] = "Trackbar window";

int main(int argc, char **argv)
{
    if(argc >= 2){
        glob_src = imread(argv[1], 0);
        print_img(glob_src, "Original Image", 0); // print starting image for comparison to image changed by trackbar
        namedWindow(window_name, 1); // window trackbar will attach to

        if(glob_src.empty()){ // if Mat object is empty
          std::cerr << "Image not loaded for trackbar." << std::endl;
            return -1;
        }
        else{
            createTrackbar("Slider", window_name, &track_pos, 255, track_chng);
            track_chng(track_pos, 0);
            waitKey(0); // image will display until user presses key
        }
    }
    else{
        std::cerr << "Invalid command line arguments." << std::endl; // if image path wasn't passed at command line
        return -1;
    }
    return 0;
}

int print_img(Mat img, std::string name, unsigned wt)
{
    if(img.data){// if there is an image print it
        namedWindow(name, 0);
        imshow(name, img);
        waitKey(wt); // number of seconds to display image, or indefinitely if wt == 0
    }
    else{
        std::cerr << "Image not loaded." << std::endl;
        return -1;
    }
    return 0;
}

static void track_chng(int track_pos, void *user_data)
{
    Mat bw = track_pos < 128 ? (glob_src < track_pos) : (glob_src > track_pos);
    Mat labelImage(glob_src.size(), CV_32S);
    int nLabels = connectedComponents(bw, labelImage, 8);
    std::vector<Vec3b> colors(nLabels);
    colors[0] = Vec3b(0, 0, 0);

    for(int label = 1; label < nLabels; ++label)
        colors[label] = Vec3b((rand()&55), (rand()&43), (rand()&200)); // produces random values for 3 channel image

    Mat glob_dest(glob_src.size(), CV_8UC3);

    for(int r = 0; r < glob_dest.rows; ++r){// step through each element of Mat object
        for(int c = 0; c < glob_dest.cols; ++c){
            int label = labelImage.at<int>(r, c);
            Vec3b &pixel = glob_dest.at<Vec3b>(r, c);
            pixel = colors[label];
        }
    }
    imshow(window_name, glob_dest);
}
