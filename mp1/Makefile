CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

mp1: main.o png.o rgbapixel.o
	clang++ main.o png.o rgbapixel.o $(LDFLAGS) -o mp1
main.o : main.cpp png.h rgbapixel.h
	clang++ $(CXXFLAGS) main.cpp

png.o : png.cpp png.h rgbapixel.h
	clang++ $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	clang++ $(CXXFLAGS) rgbapixel.cpp




