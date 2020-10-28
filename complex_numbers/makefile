all: app.exe

app.exe: app.o complex.o
	g++ -o app.exe app.o complex.o

app.o: app.cpp
	g++ -g -c app.cpp

complex.o: complex.cpp complex.hpp
	g++ -g -c complex.cpp

clean:
	rm app.exe app.o complex.o