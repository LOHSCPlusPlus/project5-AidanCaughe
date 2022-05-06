InventorDB : InventorDB.o Inventor.o ReadUtils.o InventorMain.o Node.o
	g++ -g InventorDB.o Inventor.o ReadUtils.o InventorMain.o Node.o -o InventorDB

clean: 
	rm InventorDB.o Inventor.o ReadUtils.o InventorMain.o Node.o InventorDB

InventorDB.o : InventorDB.cpp InventorDB.h ReadUtils.h Inventor.h 
	g++ -g -Wall -c InventorDB.cpp  -o InventorDB.o

Node.o : Node.cpp Node.h
	g++ -g -Wall -c Node.cpp  -o Node.o

Inventor.o : Inventor.cpp ReadUtils.h Inventor.h 
	g++ -g -Wall -c Inventor.cpp  -o Inventor.o

ReadUtils.o : ReadUtils.cpp ReadUtils.h 
	g++ -g -Wall -c ReadUtils.cpp  -o ReadUtils.o

InventorMain.o : InventorMain.cpp ReadUtils.h Inventor.h InventorDB.h 
	g++ -g -Wall -c InventorMain.cpp  -o InventorMain.o

