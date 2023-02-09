
all: partA partB

partB: partB.o  SmartClient.h ClientFeedback.h Lockbox.h
	g++ partB.o -o partB
	
partA: partA.o Lockbox.h
	g++ partA.o -o partA


partB.o: PartB.cpp SmartClient.h ClientFeedback.h Lockbox.h
	g++ -c PartB.cpp

partA.o: partA.cpp Lockbox.h 
	g++ -c partA.cpp
 
clean:
	rm *.o partA
	rm *.o partB
