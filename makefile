CC = g++
GPPFLAGS = -std=c++11

%: %.cpp
	$(CC) $(GPPFLAGS) -o $@ $<

TARGET = tick

$(TARGET): *.cpp
	$(CC) $(GPPFLAGS) -o $@ ./*.cpp