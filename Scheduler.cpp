#include "Scheduler.hpp"
#include "ArrayList.hpp"
#include "BSTMultimap.hpp"
#include "Process.hpp"
#include "BSTForwardIterator.hpp"
#include "LinkedList.hpp"


#include "RBTMultimap.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
  
  
RoundRobin::RoundRobin(){

  procQueue = new ArrayList <Process*>();
 
 }

RoundRobin::~RoundRobin(){
  
  delete procQueue;

}

void RoundRobin:: addProcess(Process* proc){
  
  procQueue->pushBack(proc);


}

Process* RoundRobin:: popNext(int curCycle){

  int ct=0;

  for (int i=0;i<(procQueue->getSize());i++)
    {
      if((procQueue->getFront())->isBlocked(curCycle)) {
	       procQueue->pushBack(procQueue->getFront());
	       procQueue->popFront();
	     }

      else {
	       return procQueue->getFront();
      }
    }
  return 0;
}

FastRoundRobin::FastRoundRobin()
{
  delete procQueue;
  procQueue= new LinkedList <Process *>();
}
FastRoundRobin::~FastRoundRobin()
{
  delete procQueue;
}
  

CompletelyFair::CompletelyFair(){
  procTree = new BSTMultimap <int, Process*>();
 }
CompletelyFair::~CompletelyFair(){
  delete procTree;
}
void CompletelyFair:: addProcess(Process * proc){

  //cout << "calls this function add process " << proc->getCPUTime() << endl;

  procTree->insert(proc->getCPUTime(), proc); //possible error here

}

Process* CompletelyFair:: popNext(int curCycle){

  
  BSTForwardIterator <int, Process*> now = procTree->getMin();  


  if (now.isPastEnd()){
      return 0;

      }
  
  Process *a;

  while(((now.getValue())->isBlocked(curCycle)) == false){

      now.next();

      if (now.isPastEnd()){
        return 0;

      }
  
  }

  a = now.getValue();
  procTree->remove(now);

  return (a);
    
  
  
}

FastCompletelyFair::FastCompletelyFair(){
  delete procTree;
  procTree = new RBTMultimap <int, Process*>();
 }
FastCompletelyFair::~FastCompletelyFair(){
  delete procTree;
}

  
 
