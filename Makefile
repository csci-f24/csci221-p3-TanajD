.PHONY: all clean

all: CaeserCipher

CaeserCipher: main.o caesar.o
	g++ main.o caesar.o -o CaesarCipher

main.o: main.cpp caesar.h
	g++ -c main.cpp

caesar.o: caesar.cpp caesar.h
	g++ -c caesar.cpp

clean:
	rm -f *.o CaesarCipher

