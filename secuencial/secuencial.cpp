#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
// read the image file .
Mat image = imread ("imagenacolor.jpg",IMREAD_COLOR) ;

int main()
{
            for (int r =0; r<image.rows; r++) 
            {
                for (int c =0; c<image.cols; c++) 
                {
                    Vec3b *p =image.ptr<Vec3b>(r,c);
                    //x:B y:G z:R
                    printf ("( %d %d %d )" , (*p)[0],(*p)[1],(*p)[2]) ;
                }
            }
}