CC = g++ -std=c++11
CFLAGS = -Wall -g
DEBUG = -DDEBUG -g  #-D means to define a macro name                            
COVERAGE = --coverage

all: ArrayList_TEST LinkedList_TEST RoundRobin_TEST Robinmain schedulism BSTNode_TEST RBTNode_TEST BSTMultimap_TEST RBTMultimap_TEST CompletelyFair_TEST




ArrayList_TEST: ArrayList_TEST.cpp ArrayList.hpp ArrayList.tpp
	$(CC) $(CFLAGS) -o ArrayList_TEST ArrayList_TEST.cpp
BSTNode_TEST: BSTNode_TEST.cpp BSTNode.hpp BSTNode.tpp
	$(CC) $(CFLAGS) -o BSTNode_TEST BSTNode_TEST.cpp
RBTNode_TEST: RBTNode_TEST.cpp RBTNode.hpp RBTNode.tpp BSTNode.hpp BSTNode.tpp
	$(CC) $(CFLAGS) -o RBTNode_TEST RBTNode_TEST.cpp

coverage:  ArrayList_TEST.cpp  
	$(CC) $(CFLAGE) $(COVERAGE) ArrayList_TEST.cpp

coverageBSTNode:  BSTNode_TEST.cpp  
	$(CC) $(CFLAGE) $(COVERAGE) BSTNode_TEST.cpp

coverageBSTMulti:  BSTMultimap_TEST.cpp  
	$(CC) $(CFLAGE) $(COVERAGE) BSTMultimap_TEST.cpp

coverageComplete:  CompletelyFair_TEST.cpp  
	$(CC) $(CFLAGE) $(COVERAGE) CompletelyFair_TEST.cpp 

coverageRBT_Node:  RBTNode_TEST.cpp
	$(CC) $(CFLAGE) $(COVERAGE) RBTNode_TEST.cpp


coverageRBT:  RBTMultimap_TEST.cpp  
	$(CC) $(CFLAGE) $(COVERAGE) RBTMultimap_TEST.cpp 



LinkedList_TEST: LinkedList_TEST.cpp LinkedList.hpp LinkedList.tpp
	$(CC) $(CFLAGS) -o LinkedList_TEST LinkedList_TEST.cpp

coveragelink:  LinkedList_TEST.cpp  
	$(CC) $(CFLAGE) $(COVERAGE) LinkedList_TEST.cpp 
Process.o: Process.cpp
	$(CC) -g -c Process.cpp
Scheduler.o: Scheduler.cpp ArrayList.hpp ArrayList.tpp  LinkedList.hpp LinkedList.tpp BSTMultimap.hpp BSTMultimap.tpp RBTMultimap.hpp RBTMultimap.tpp
	$(CC) -g -c Scheduler.cpp
RoundRobin_Test.o: RoundRobin_TEST.cpp
	$(CC) -g -c RoundRobin_TEST.cpp
RoundRobin_TEST: RoundRobin_TEST.o Scheduler.o Process.o ArrayList.hpp ArrayList.tpp LinkedList.hpp LinkedList.tpp BSTMultimap.hpp BSTMultimap.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp 
	$(CC) $(CFLAGS) -o RoundRobin_TEST RoundRobin_TEST.o Scheduler.o Process.o
CompletelyFair_Test.o: CompletelyFair_TEST.cpp
	$(CC) -g -c CompletelyFair_TEST.cpp
CompletelyFair_TEST: CompletelyFair_TEST.o Scheduler.o Process.o ArrayList.hpp ArrayList.tpp LinkedList.hpp LinkedList.tpp BSTMultimap.hpp BSTMultimap.tpp BSTForwardIterator.hpp BSTForwardIterator.tpp 
	$(CC) $(CFLAGS) -o CompletelyFair_TEST CompletelyFair_TEST.o Scheduler.o Process.o
BSTMultimap_TEST: BSTMultimap_TEST.cpp BSTMultimap.hpp BSTMultimap.tpp BSTNode.hpp BSTNode.tpp
	$(CC) $(CFLAGS) -o BSTMultimap_TEST BSTMultimap_TEST.cpp 
RBTMultimap_TEST: RBTMultimap_TEST.cpp RBTMultimap.hpp RBTMultimap.tpp  BSTMultimap.hpp BSTMultimap.tpp RBTNode.hpp RBTNode.tpp  BSTNode.hpp BSTNode.tpp
	$(CC) $(CFLAGS) -o RBTMultimap_TEST RBTMultimap_TEST.cpp 

simulate.o: simulate.cpp
	$(CC) -g -c simulate.cpp
schedulism: schedulism.cpp simulate.o Scheduler.o Process.o
	$(CC) -o schedulism schedulism.cpp simulate.o  Scheduler.o Process.o 


Robinmain: RoundRobin_TEST.o Scheduler.o Process.o 
	$(CC) $(CFLAGS) -o Robinmain RoundRobin_TEST.o Scheduler.o Process.o  

clean:
	rm *.o;rm Robinmain;rm BSTMultimap_TEST; rm BSTNode_TEST;rm RoundRobin_TEST;rm LinkedList_TEST; rm ArrayList_TEST;rm RBTNode_TEST;rm RBTMultimap_TEST;
     
