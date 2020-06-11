#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"

/*More info on Catch
Git-Page: https://github.com/philsquared/Catch
*/

//What are we testing today?
#include "Scheduler.hpp"

#include "Process.hpp"


TEST_CASE("TESTING CompletelyFair")
{
  
  

  SECTION("TEST")
    {
      
      CompletelyFair* a =new CompletelyFair();
      FastCompletelyFair* b = new FastCompletelyFair();
      
      Process* s = new CPUBoundProcess(1);
      Process* c = new IOBoundProcess(2);
      Process* d =  new CPUBoundProcess(3);
      Process* e =  new IOBoundProcess(4);
      
      a->addProcess(s);
      a->addProcess(c);
      a->addProcess(d);
      a->addProcess(c);

      b->addProcess(s);
      b->addProcess(c);
      b->addProcess(d);
      b->addProcess(c);

      a->popNext(10);
      b->popNext(10);

      //REQUIRE((b->popNext(10))->getCPUTime() == 2);
      //REQUIRE((a->popNext(10))->getCPUTime() == 2);
      
        
    }
}

