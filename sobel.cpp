//
//  sobel.cpp
//  OpenCV-test
//
//  Created by wangxiaohui on 8/9/16.
//  Copyright © 2016 wangxiaohui. All rights reserved.
//

#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

using namespace cv;
using namespace std;

int main(){
    
    Mat srcImage,srcImage2;
    int ddepth=CV_16S;
    int dx,dy;
    
    //load the gray scale picture of 'Lena'
    srcImage=imread("/Users/TONY/Downloads/Lena.jpg",0);
    namedWindow("original");
    imshow("original", srcImage);
   
    //using a 5*5 mask to do the GaussianBlur
    GaussianBlur(srcImage, srcImage2, Size(5,5), 0,0);
    
    Mat grad_x,grad_y,abs_grad_x,abs_grad_y,grad;
    
    //x-gradient
    dx=1,dy=0;
    Sobel(srcImage2, grad_x, ddepth, dx, dy);
    
    //gradient must be converted to absolution
    convertScaleAbs(grad_x, abs_grad_x);
    
    //y-gradient
    dx=0,dy=1;
    Sobel(srcImage2, grad_y, ddepth, dx, dy);
    convertScaleAbs(grad_y, abs_grad_y);
    
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
    namedWindow("grad");
    imshow("grad", grad);
    
    waitKey();
    return 0;
}