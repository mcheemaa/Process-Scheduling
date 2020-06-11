#include <chrono>
#include "simulate.hpp"
#include "Scheduler.hpp"

#include "Process.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


double* simulate (Scheduler* sched, int numCPUBound, int numIOBound,int numCycles){
 
  Process* aa ;
  
  int cputime1=0;
  int cputime2=0;
  int waitime1=0;
  int waitime2=0;
  double sch=0;
  int ct=0;
 
  double *arr = new double [5];

  ArrayList <Process*>  *cpuBound= new ArrayList <Process*>();
  ArrayList <Process*>  *IOBound= new  ArrayList <Process*> ();

  
  for (int i=0;i<numCPUBound;i++)
    {
      cpuBound->pushBack(new CPUBoundProcess(i));
      sched->addProcess(cpuBound->getBack());
      

    }
    for (int j=0;j<numIOBound;j++)
    {
      IOBound->pushBack(new IOBoundProcess(numCPUBound+j));
      sched->addProcess(IOBound->getBack());

    }
    
  //rememer delete varible release memory
  
   int cy =0;

   auto t1= chrono::system_clock::now();

   while(cy<numCycles){
      aa=sched->popNext(cy);
      sch++;
      
      if(!aa) {
	       
         cy += 10;
        
        }
      
      else {
         cy += (aa->useCPU(cy,10));
         sched->addProcess(aa);
       
        }

    }
 
    auto  t2 = chrono::system_clock::now();
    auto  dur = t2 - t1;
    auto  durNS=chrono::duration_cast<chrono::nanoseconds>(dur);
    ct = durNS.count();


    double CPUt = 0;
    double CPUWaittime = 0;

    while (!cpuBound->isEmpty()) {

      Process* temp = cpuBound->getBack();
      CPUt = CPUt + temp->getCPUTime();
      CPUWaittime = CPUWaittime + temp->getWaitTime(numCycles);
      delete temp;
      cpuBound->popBack();

    }

    double IOt = 0;
    double IOWaittime = 0;

    while (!IOBound->isEmpty()) {

      Process* te = IOBound->getBack();
      IOt = IOt + te->getCPUTime();
      IOWaittime = IOWaittime + te->getWaitTime(numCycles);
      delete te;
      IOBound->popBack();

    }

    delete cpuBound;
    delete IOBound;

    arr[0]= ct/sch;
    arr[1]=CPUt/(double)numCPUBound;
    arr[2]=CPUWaittime/(double)numCPUBound;
    arr[3]=IOt/(double)numIOBound;
    arr[4]=IOWaittime/(double)numIOBound;

    //delete sched;
    return arr;
}

