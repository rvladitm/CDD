newton: main.o 
	g++ main.o -o newton

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o newton



