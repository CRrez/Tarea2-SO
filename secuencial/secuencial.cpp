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
    cout << "Cargando Imagen..." << endl;
    cout << "Filas (Ancho): " << image.cols << " Columnas (alto): " << image.rows << endl;

        //inicia el temporizador
        auto start_time = high_resolution_clock::now();

            for (double  r =0; r<image.rows; r++) 
            {
                for (double  c =0; c<image.cols; c++) 
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



    //impresion de la imagen en escala de grises
    imwrite("imagengris.png",image);


     cout << "FIn de la Conversion." << endl;
     cout << "El tiempo gasto en segundos fue de : " << duration.count() / 1000.0 << endl;


    return 0;
}