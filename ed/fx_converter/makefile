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
# $< - first dependency
$(LINK_TARGET): $(OBJS)
	g++ -pthread -o $@ $^

%.o : %.cpp
	g++ -pthread -g -c $<

exchange_rate.o: exchange_rate.hpp
currency.o: currency.hpp
exchange_board.o: exchange_board.hpp

clean:
	rm $(LINK_TARGET) $(OBJS)