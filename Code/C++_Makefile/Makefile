C = g++

SOURCES = $(shell find -type f -name "*.cpp")

OBJECTS := $(SOURCES:.cpp=.o)
HEADERS := $(SOURCES:.cpp=.h)

# What is processed before executing
output: $(OBJECTS) 
	$(C) $(OBJECTS) -o main

# Executes multiple CPP and Headers
%.o: $(SOURCES) $(HEADERS)
	$(C) -c $(SOURCES)

# Removes object and exe files
clean:
	rm *.o main