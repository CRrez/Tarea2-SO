CXX = g++
CXXFLAGS = -std=c++11
OPENCV_LIBS = `pkg-config --cflags --libs opencv4`
OPENCV_INCLUDE = `pkg-config --cflags opencv`

TARGET = 
SRC = secuencial.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS)$(OPENCV_INCLUDE) -o $(SRC) $(TARGET) $(OPENCV_LIBS)
	
run: $(TARGET)
	@echo "Ejecutando la conversión a escala de grises..."
	@./$(TARGET) $(IMG_COLOR) $(IMG_GRAY)
	@echo "Conversión a escala de grises completada."

clean:
	rm -f $(TARGET)
