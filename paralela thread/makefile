CXX = g++
CXXFLAGS = -std=c++11
OPENCV_LIBS = `pkg-config --cflags --libs opencv4`

SRC = thread.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(OPENCV_LIBS)

clean:
	rm -f $(TARGET)
