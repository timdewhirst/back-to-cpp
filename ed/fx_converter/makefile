all: fx_converter.exe

LINK_TARGET = fx_converter.exe

OBJS = \
	fx_converter.o \
	exchange_rate.o \
	currency.o \
	exchange_board.o \
	random_walk.o \
	board_updater.o \
	globals.o

# $@ - target
# $^ - dependencies
$(LINK_TARGET): $(OBJS)
	g++ -pthread -o $@ $^

%.o : %.cpp
	g++ -pthread -g -c $^

exchange_rate.o: exchange_rate.hpp
currency.o: currency.hpp
exchange_board.o: exchange_board.hpp

# fx_converter.o: fx_converter.cpp
# 	g++ -g -c fx_converter.cpp

# exchange_rate.o: exchange_rate.cpp exchange_rate.hpp
# 	g++ -g -c exchange_rate.cpp

# currency.o: currency.cpp currency.hpp
# 	g++ -g -c currency.cpp

# exchange_board.o: exchange_board.cpp exchange_board.hpp
# 	g++ -g -c exchange_board.cpp

clean:
	rm $(LINK_TARGET) $(OBJS)