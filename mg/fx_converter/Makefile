all: app.exe

app.exe: app.o mainv2.o
	g++ -o app.exe app.o complex.o

app.o: app.cpp
	g++ -g -c app.cpp

mainv2.o: mainv2.cpp Currency.hpp CurrencyContainer.hpp ExchangeRate.hpp ExchangeBoard.hpp
	g++ -g -c mainv2.cpp

clean:
	rm app.exe app.o mainv2.o