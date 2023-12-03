#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
using namespace cv;
using namespace std;
using namespace std::chrono;

// lee la imagen
Mat image = imread ("imagenacolor.png",IMREAD_COLOR) ;

int main()
{
        //inicia el temporizador
        auto start_time = high_resolution_clock::now();

            for (int r =0; r<image.rows; r++) 
            {
                for (int c =0; c<image.cols; c++) 
                {

                    //saca un pixel de la imagen,obteniendo su patron RGB
                    Vec3b *p =image.ptr<Vec3b>(r,c);
                    
                    //aplica la escal de grises con el formato BGR
                    int grayscaleValue = 0.3 * (*p)[2] + 0.59 * (*p)[1] + 0.11 * (*p)[0];
                    //implementa el nuevo pixel en escala de grises
                    image.at<uchar>(r, c) = static_cast<uchar>(grayscaleValue);

                }
            }

            //termina el temporizador
             auto end_time = high_resolution_clock::now();
             auto duration = duration_cast<milliseconds>(end_time - start_time);


    imwrite("imagengris.png",image);
    waitKey(0);

    return 0;
}