CC = gcc
CFLAGS = -Wall -Wextra -I./src -std=c99
TARGET = program
SRCDIR = src

SERVER_SRCS = $(SRCDIR)/airplane.c
CLIENT_SRCS = $(SRCDIR)/main.c
ALL_SRCS = $(SERVER_SRCS) $(CLIENT_SRCS)
ALL_OBJS = $(ALL_SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(ALL_OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

