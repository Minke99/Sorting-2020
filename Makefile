CC=gcc
CFLAGS=-g -std=c11 -Iinclude
LIBS=-lm
TARGET=demo

SRC_DIR = .
OBJ_DIR = .
INC_DIR = .
_DEPS = main.h
_OBJS = main.o merge_sort.o pivot.o

DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)

