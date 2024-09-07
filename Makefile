# Makefile for Xlib Example

CC = gcc
CFLAGS = -Wall -O2
LDFLAGS = -lX11 -lwebkit2gtk-4.0

# Target executable
TARGET = xlib_browser

# Source files
SRCS = xlib_browser.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean


