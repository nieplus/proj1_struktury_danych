CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -O2
SRCS = main.cpp Dynamic_array.cpp Linked_list.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = app

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
