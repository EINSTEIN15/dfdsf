
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread

testimage: image.o  png.o rgbapixel.o testimage.o
	clang++ image.o  png.o rgbapixel.o testimage.o $(LDFLAGS) -o testimage


testimage.o: testimage.cpp image.h
	 clang++ $(CXXFLAGS) testimage.cpp

image.o: image.cpp image.h png.h rgbapixel.h
	clang++ $(CXXFLAGS) image.cpp

png.o : png.cpp png.h rgbapixel.h
	clang++ $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h
	clang++ $(CXXFLAGS) rgbapixel.cpp
clean : 
	rm testimage *.o
