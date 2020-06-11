#include <chrono>
#include "simulate.hpp"

#include "Process.hpp"

#include "ArrayList.hpp"

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int main(int argc, char **argv){

  int numCPUBound = stoi (argv[1]);
  int numIOBound = stoi (argv[2]);
  int numCycle = stoi (argv[3]);
  
  Scheduler* aa [4];
  
  aa[0] = new RoundRobin() ;

  aa[1] = new FastRoundRobin();

  aa[2] = new CompletelyFair();

  aa[3] = new FastCompletelyFair();

  string *str = new string [2];
 
  
  for(int i =0;i<4;i++) {

    double* arr = simulate(aa[i], numCPUBound, numIOBound, numCycle);

    cout << " " << endl;
    
    cout << "Average Scheduler: " << arr[0] << endl;
    cout << "CPU Time: " << arr[1] << endl;
    cout << "CPU Wait Time: " << arr[2] << endl;
    cout << "IO Time: " << arr[3] << endl;
    cout << "IO Wait Time: " << arr[4] << endl;

    if (i == 0) {
      cout << " " << endl;
      cout << "________________________ Fast Round Robin ________________________" << endl;
    }

    if (i == 1) {
      cout << " " << endl;
      cout << "________________________  Completely Fair  ________________________" << endl;
    }

    if (i == 2) {
      cout << " " << endl;
      cout << "_____________________  Fast Completely Fair  ______________________" << endl;
    }
    
    
    delete []arr;
    }

    cout << " " << endl;

}
  
    
