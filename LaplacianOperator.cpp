//
//  LaplacianOperator.cpp
//  OpenCV-test
//
//  Created by wangxiaohui on 14/9/16.
//  Copyright © 2016 wangxiaohui. All rights reserved.
//  find the contour using Laplacian operator

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

int main(){
    
    Mat srcImage,blurred,dstImage,contour;
    
    //depth of one pixel is 16bits
    int ddepth=CV_16S;
    
    //load the pic
    srcImage=imread("/Users/TONY/Downloads/Lena.jpg",0);
    if (!srcImage.data) {
        return -1;
    }
    
    //GaussianBlur
    GaussianBlur(srcImage, blurred, Size(5,5), 0,0);
    
    //implement the contour finding using Laplacian operator
    Laplacian(blurred, dstImage, ddepth);
    
    //conert the result into absolute value
    convertScaleAbs(dstImage, contour);
    
    //display the contour
    namedWindow("Laplacian");
    imshow("Laplacian", contour);
    
    
    waitKey();
    return 0;
}
