CXX = g++
CXXFLAGS = -std=c++11
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
OPENCV_INCLUDE = -I/usr/local/include/opencv4

TARGET = secuencial
SRC = secuencial.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(OPENCV_INCLUDE) $(SRC) -o $(TARGET) $(OPENCV_LIBS)
	
run: $(TARGET)
	@echo "Ejecutando la conversión a escala de grises..."
	@./$(TARGET) $(IMG_COLOR) $(IMG_GRAY)
	@echo "Conversión a escala de grises completada."

clean:
	rm -f $(TARGET)
