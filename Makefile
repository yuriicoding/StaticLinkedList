all: x

x: driver.o list.o
	g++ -Wall -o x driver.o list.o 
	
driver.o: driver.c list.h
	g++ -Wall -o driver.o -c driver.c
	
list.o: list.c list.h
	g++ -Wall -o list.o -c list.c
	
clean:
	rm -f x *.o 
   
