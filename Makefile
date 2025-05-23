all: groundrim


WARNINGS = -Wall -Weffc++ -Wextra -Wsign-conversion -pedantic-errors
DEBUG = -ggdb -fno-omit-frame-pointer
OPTIMIZE = -O2
STANDARD = -std=c++2a

taxy: Makefile main.cpp
	$(CXX) -o $@ $(WARNINGS) $(DEBUG) $(OPTIMIZE) $(STANDARD) main.cpp

clean:
	rm -f groundrim

install:
	cp groundrim /usr/local/bin/groundrim

# Builder uses this target to run your application.
run:
	./groundrim

