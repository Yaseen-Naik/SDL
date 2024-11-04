CC=gcc
CFLAGS=-I"C:/SdlUsingC/include"
LDFLAGS=-L"C:/SdlUsingC/lib" -lmingw32 -lSDL2main -lSDL2
SRC=main.c
TARGET=main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)
