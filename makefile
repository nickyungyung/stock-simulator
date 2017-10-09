CC = g++
GPPFLAGS = -std=c++11

tick: *.cpp
	$(CC) $(GPPFLAGS) -o $@ ./*.cpp

month: *.cpp
	$(CC) $(GPPFLAGS) -o $@ ./*.cpp

mean: *.cpp
	$(CC) $(GPPFLAGS) -o $@ ./*.cpp
