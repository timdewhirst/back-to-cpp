all: main.exe

main.exe: main.o exchange_rate.o currency.o
	g++ -o main.exe main.o exchange_rate.o currency.o

main.o: main.cpp
	g++ -g -c main.cpp

exchange_rate.o: exchange_rate.cpp exchange_rate.hpp
	g++ -g -c exchange_rate.cpp

currency.o: currency.cpp currency.hpp
	g++ -g -c currency.cpp

clean:
	rm main.exe main.o exchange_rate.o currency.o