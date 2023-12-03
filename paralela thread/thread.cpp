#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv ;
using namespace s t d ;
// read the image file .
Mat image = imread ( ”imagenacolor.jpg”,IMREAD COLOR) ;
// read each pixel (RGB pixel) .
for (int r =0; r<image.rows; r++) {
for (int c =0; c<image.cols; c++) {
Point3 <uchar >∗p =image.ptr<Point3 <uchar> >(r,c) ;
//x:B y:G z:R
printf ("( %d %d %d )" ,p−>x,p−>y,p−>z) ;
}