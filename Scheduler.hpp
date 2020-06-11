#ifndef SCHEDULER
#define SCHEDULER
#include "ArrayList.hpp"

#include "Process.hpp"
#include "BSTMultimap.hpp"
#include "LinkedList.hpp"


#include "RBTMultimap.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Scheduler{
public:
  virtual void addProcess(Process * proc)=0;
  virtual Process* popNext(int curCycle)=0;
  virtual ~Scheduler() { }
};
class RoundRobin : public Scheduler
{
protected:
  List<Process*>* procQueue;
public:
  RoundRobin();
  ~RoundRobin();
  void addProcess(Process * proc);
  Process * popNext(int curCycle);
};
class FastRoundRobin : public RoundRobin
{
public:
  FastRoundRobin();
  ~FastRoundRobin();
};
class CompletelyFair : public Scheduler
{
protected:
  BSTMultimap <int,Process*> * procTree;
public:
  CompletelyFair();
  virtual ~CompletelyFair();
  virtual void addProcess(Process * proc);
  virtual Process * popNext(int curCycle);
};

class FastCompletelyFair : public CompletelyFair
{
  
public:
  FastCompletelyFair();
  virtual ~FastCompletelyFair();
};




#endif
