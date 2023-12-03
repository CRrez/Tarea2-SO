#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>
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
                    //x:B y:G z:R
                    printf ("( %d %d %d )" , (*p)[0],(*p)[1],(*p)[2]) ;
                }
            }
             auto end_time = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(end_time - start_time);
}