all: laboratorio1

laboratorio1: main.o tokenizer.o ficheros.o vectores.o
	      g++ main.o tokenizer.o ficheros.o vectores.o -o laboratorio1

main.o: main.cpp
	g++ -c main.cpp

tokenizer.o: tokenizer.cc
	     g++ -c tokenizer.cc

ficheros.o: ficheros.cpp
	    g++ -c ficheros.cpp
	    
vectores.o: vectores.cpp
	g++ -c vectores.cpp

clean:
	rm -rf *o laboratorio1
