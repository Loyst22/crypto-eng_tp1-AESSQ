CC = gcc
CFLAGS = -g -Wall
SRCS = attack.c aes-128_enc.c
HDR = aes-128_enc.h
TARGET = attack

all: $(TARGET)

$(TARGET): $(SRCS) $(HDR)
	$(CC) $(CFLAGS) $(SRCS) $(HDR) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean