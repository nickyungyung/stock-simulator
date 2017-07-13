CC = g++
GPPFLAGS = -std=c++11

%: %.cpp
	$(CC) $(GPPFLAGS) -o $@ $<

TARGET = tick

$(TARGET):
	$(CC) $(GPPFLAGS) -o $@ ./*.cpp