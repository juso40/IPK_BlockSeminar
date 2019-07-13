TARGET = list
CC = g++
CFLAGS = -g -Wall -std=c++11 -fsanitize=leak

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = main.cpp List.cpp
HEADERS = List.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)

clean:
	-rm -f $(TARGET)
