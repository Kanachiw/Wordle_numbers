
partB: partB.o  SmartClient.h 
	g++ partB.o -o partB
	
partA: partA.o Lockbox.h
	g++ partA.o -o partA


partB.o: partB.cpp SmartClient.h 
	g++ -c partB.cpp

partA.o: partA.cpp Lockbox.h 
	g++ -c partA.cpp
 
clean:
	rm *.o partA
	rm *.o partB
