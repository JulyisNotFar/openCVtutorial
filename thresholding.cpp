//
//  thresholding.cpp
//  OpenCV-test
//
//  Created by wangxiaohui on 14/9/16.
//  Copyright © 2016 wangxiaohui. All rights reserved.
//  Thresholding of Lena and demo of function createTrackbar.
//  Remember to invoke the callback function after createTrackbar.

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;

int trackBarValue=150;

Mat srcImage,dstImage;
void Threshold_Demo(int,void*);


int main(int argc, const char * argv[]) {
    srcImage=imread("/Users/TONY/Downloads/Lena.jpg",0);
        string winname="Threshold Demo";
        string trackbarname="threshold value";
        namedWindow(winname);
        createTrackbar(trackbarname, winname, &trackBarValue, 255,Threshold_Demo);
        Threshold_Demo(0, 0);
        waitKey();
    
        return 0;
    }
    
        void Threshold_Demo(int,void*){
        threshold(srcImage, dstImage, trackBarValue, 255, 3);
        imshow("Threshold Demo", dstImage);
    }
