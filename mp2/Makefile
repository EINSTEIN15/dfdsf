
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi -lpthread
all: testimage testscene
testimage: image.o  png.o rgbapixel.o testimage.o
	clang++ image.o  png.o rgbapixel.o testimage.o $(LDFLAGS) -o testimage
testscene: testscene.o scene.o image.o png.o rgbapixel.o  
	clang++ testscene.o scene.o image.o png.o rgbapixel.o  $(LDFLAGS) -o testscene

testscene.o :testscene.cpp scene.h png.h rgbapixel.h image.h
	clang++ $(CXXFLAGS) testscene.cpp
testimage.o: testimage.cpp image.h
	clang++ $(CXXFLAGS) testimage.cpp

image.o: image.cpp image.h png.h rgbapixel.h
	clang++ $(CXXFLAGS) image.cpp

png.o : png.cpp png.h rgbapixel.h
	clang++ $(CXXFLAGS) png.cpp

rgbapixel.o : rgbapixel.cpp rgbapixel.h png.h
	clang++ $(CXXFLAGS) rgbapixel.cpp
scene.o: scene.cpp scene.h image.h rgbapixel.h png.h
	clang++ $(CXXFLAGS) scene.cpp
clean : 
	rm testimage testscene *.o
