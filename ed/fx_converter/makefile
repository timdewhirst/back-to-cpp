all: fx_converter.exe

fx_converter.exe: fx_converter.o exchange_rate.o currency.o exchange_board.o
	g++ -o fx_converter.exe fx_converter.o exchange_rate.o currency.o exchange_board.o

fx_converter.o: fx_converter.cpp
	g++ -g -c fx_converter.cpp

exchange_rate.o: exchange_rate.cpp exchange_rate.hpp
	g++ -g -c exchange_rate.cpp

currency.o: currency.cpp currency.hpp
	g++ -g -c currency.cpp

exchange_board.o: exchange_board.cpp exchange_board.hpp
	g++ -g -c exchange_board.cpp

clean:
	rm fx_converter.exe fx_converter.o exchange_rate.o currency.o