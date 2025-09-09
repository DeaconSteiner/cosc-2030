CXX = g++
CFLAGS = -Wall 
SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
TARGET = $(notdir $(CURDIR))

.SILENT: all $(TARGET) run clean 

.PHONY: all run clean debug

all: $(TARGET)
	
$(TARGET): $(OBJ)
	@$(CXX) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	@$(CXX) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

debug: CFLAGS += -ggdb -O0
debug: clean all
