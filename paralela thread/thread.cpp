#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
using namespace cv;
using namespace std;
using namespace std::chrono;

Mat image = imread("imagenacolor.png", IMREAD_COLOR);

//esta funcion es la que crea la imagen en escala de grises
void convertToGrayscale(int inicio_fila, int fin_fila) {
    for (int r = inicio_fila; r < fin_fila; ++r)
     {
        for (int c = 0; c < image.cols; ++c) 
        {
            Vec3b *p = image.ptr<Vec3b>(r, c);
            int grayscaleValue = 0.3 * (*p)[2] + 0.59 * (*p)[1] + 0.11 * (*p)[0];
            image.at<uchar>(r, c) = static_cast<uchar>(grayscaleValue);
        }
    }
}

int main() {
    //empieza el temporizador de tiempo
    auto start_time = high_resolution_clock::now();
    int num_threads = std::thread::hardware_concurrency();

    //aca van el numero de hebras
    #ifdef NUM_THREADS
         num_threads = NUM_THREADS;
    #endif

    vector<thread> threads;
    //aqui creo una cantidad de filas en base a las hebras disponibles
    int filas_por_hebra = image.rows / num_threads;
    int inicio_fila = 0;
    int fin_fila = 0;

// este for lo que hace es que crea n-1 hebras para procesar la funcion
    for (int i = 0; i < num_threads - 1; ++i) 
    {

        fin_fila = inicio_fila + filas_por_hebra;
        threads.emplace_back(convertToGrayscale, inicio_fila, fin_fila);
        inicio_fila = fin_fila;
    }

    // aca se procesa la ultima henra con los ultimos datos de la imagen para que esta
    // sepa cuando termina todo el proceso
    threads.emplace_back(convertToGrayscale, inicio_fila, image.rows);

    for (auto &t : threads) 
    {
        t.join();
    }
//termina el temporizador
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time);

    //impresion de la imagen en escala de grises
    imwrite("imagengris.png", image);


    return 0;
}
