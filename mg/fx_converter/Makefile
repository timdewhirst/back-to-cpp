all: main.exe

main.exe: main.o Currency.o  ExchangeRate.o ExchangeBoard.o
	g++ -o main.exe main.o Currency.o  ExchangeRate.o ExchangeBoard.o 
	
main.o: main.cpp 
	g++ -g -c main.cpp

Currency.o: Currency.cpp Currency.hpp
	g++ -g -c Currency.cpp

ExchangeRate.o: ExchangeRate.cpp ExchangeRate.hpp 
	g++ -g -c ExchangeRate.cpp

ExchangeBoard.o: ExchangeBoard.cpp ExchangeBoard.hpp
	g++ -g -c ExchangeBoard.cpp

clean:
	rm main.exe main.o Currency.o ExchangeBoard.o ExchangeRate.o