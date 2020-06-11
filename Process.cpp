#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}
//it return the id of process
int Process::getID() const
{
   return id;
}
//return the time CPU works
int Process::getCPUTime() const
{
   return cpuTime;
}
//rrtuen the time it wait for the CPU
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}

CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}
//take in the current cycle number and return false since the
//CPUBound process will not be blocked
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}
//take in the current cycle number and slicesize, which is
//amount of time allowed to use the CPU, return the slicesize
//since CPUBound process will just take all the time.
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;
   
   

   return sliceSize;
}
//return true for CPUBound process, help judge
//type of the Process


IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}
//take in the current cycle number and return true if current
//cycle number being smaller than the time it intended to be blocked
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}
//take in the current cycle number and slicesize, which is
//amount of time allowed to use the CPU, counting on the CPU
//use time because for IO process, it will not use up all the slice
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = random()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + random()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}

