CC = g++
GPPFLAGS = -std=c++11

%: %.cpp
	$(CC) $(GPPFLAGS) -o $@ $<

TESTOBJ = TestDataGenerator.h

tick: $(TESTOBJ)
	$(CC) $(GPPFLAGS) -o $@ $<
