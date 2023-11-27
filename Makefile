# Makefile para compilar o programa hospital

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SOURCES = hospital.c main.c
HEADERS = hospital.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = hospital_simulation

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
