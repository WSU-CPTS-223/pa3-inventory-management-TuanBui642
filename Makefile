CXX = g++ 
CXXFLAGS = -std=c++11 -Wall -g 

OBJS = main.o MainFunc.o ProductClass.o
TARGET= main 

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(TARGET)
