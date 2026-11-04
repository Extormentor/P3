all: bin/test_monedas

bin/Monedas: monedas.h
	mkdir -p bin
	g++ -c monedas.h

bin/test_monedas: monedas.h test_monedas.cpp
	mkdir -p bin
	g++ monedas.h test_monedas.cpp -o bin/test_monedas

clear:
	rm -r *.o *.gch *.pch bin bin/test_monedas  
