all: converter.exe

converter.exe: converter.o currency.o  exchangeRate.o exchangeBoard.o
	g++ -o converter.exe converter.o currency.o  exchangeRate.o exchangeBoard.o

converter.o: converter.cpp 
	g++ -g -c converter.cpp

currency.o: currency.cpp currency.hpp
	g++ -g -c currency.cpp

ExchangeRate.o: exchangeRate.cpp exchangeRate.hpp 
	g++ -g -c exchangeRate.cpp

ExchangeBoard.o: exchangeBoard.cpp exchangeBoard.hpp
	g++ -g -c exchangeBoard.cpp

clean:
	rm converter.exe converter.o currency.o exchangeBoard.o exchangeRate.o