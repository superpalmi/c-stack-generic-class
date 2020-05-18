CXXFLAGS = -Wall -pedantic -Wextra -pedantic-errors -DNDEBUG
CXXFLAGS_DEBUG = -Wall -pedantic -Wextra -pedantic-errors -g

BASIC_FLAGS = -DNDEBUG
main.exe: main.o
	g++  main.o -o main.exe
main.o: main.cpp
	g++ -c main.cpp -o main.o




.PHONY: clean  doc debug run_valgrind

clean:
	rm -f *.exe *.o


doc: 	
	doxygen Doxyfile



debug: 
	g++ $(CXXFLAGS_DEBUG) -c main.cpp -o main.o
	g++ $(CXXFLAGS_DEBUG) main.o -o main.exe

run_valgrind: debug
	valgrind --leak-check=yes ./main.exe
