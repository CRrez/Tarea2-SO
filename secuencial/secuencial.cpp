#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
using namespace cv;
using namespace std;
using namespace std::chrono;

// read the image file .
Mat image = imread ("imagenacolor.jpg",IMREAD_COLOR) ;
// read each pixel (RGB pixel) .
int main()
{

        auto start_time = high_resolution_clock::now();

            for (int r =0; r<image.rows; r++) 
            {
                for (int c =0; c<image.cols; c++) 
                {
                    Vec3b *p =image.ptr<Vec3b>(r,c);
                    
                    int grayscaleValue = 0.3 * (*p)[2] + 0.59 * (*p)[1] + 0.11 * (*p)[0];
                    image.at<uchar>(r, c) = static_cast<uchar>(grayscaleValue);

                }
            }
             auto end_time = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(end_time - start_time);


    imshow("Grayscale Image",image);
    waitKey(0);

    return 0;
}