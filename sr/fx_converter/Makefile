all: converter.exe

LINK_TARGET = converter.exe

OBJS = \
	converter.o \
	exchangeRate.o \
	currency.o \
	exchangeBoard.o \
	randomWalk.o

$(LINK_TARGET): $(OBJS)
	g++ -pthread -o $@ $^

%.o : %.cpp
	g++ -pthread -g -c $^

exchange_rate.o: exchangeRate.hpp
currency.o: currency.hpp
exchange_board.o: exchangeBoard.hpp
randomWalk.o: randomWalk.hpp

clean:
	rm $(LINK_TARGET) $(OBJS)