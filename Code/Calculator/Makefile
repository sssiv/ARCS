# Compiler type
C = g++

# Bash command that searched for CPP files
SOURCES = $(shell find -type f -name "*.cpp")

# Variables that take the set of CPP files 
# and replaces .cpp with .o and .h
OBJECTS := $(SOURCES:.cpp=.o)
HEADERS := $(SOURCES:.cpp=.h)

# What is processed before executing
# Naming the executable name
output: $(OBJECTS) 
	$(C) $(OBJECTS) -o main

# Executes multiple CPP and Headers
%.o: $(SOURCES) $(HEADERS)
	$(C) -c $(SOURCES)

# Removes object and exe files
clean:
	rm -rf *.o main