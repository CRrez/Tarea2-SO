CXX = g++
CXXFLAGS = -std=c++11
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs
OPENCV_INCLUDE = -I/usr/local/include/opencv4

TARGET = thread
SRC = thread.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(OPENCV_INCLUDE) $(SRC) -o $(TARGET) $(NUM_THREADS) $(OPENCV_LIBS)
	
clean:
	rm -f $(TARGET)
