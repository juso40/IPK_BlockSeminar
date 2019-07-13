TARGET = bhof
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11 -fsanitize=leak

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = Bauernhof/main.cpp Bauernhof/Terminal.cpp Bauernhof/Tier.cpp Bauernhof/Katze.cpp Bauernhof/Schwein.cpp Bauernhof/Bauernhof.cpp
HEADERS = Bauernhof/Terminal.h Bauernhof/Katze.h Bauernhof/Tier.h Bauernhof/Vec2D.h Bauernhof/Bauernhof.h Bauernhof/Schwein.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)
	
clean:
	-rm -f $(TARGET)
	
