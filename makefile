CC = g++
GPPFLAGS = -std=c++11 -Wall

%: %.cpp
    $(CC) $(GPPFLAGS) -o $@ $<