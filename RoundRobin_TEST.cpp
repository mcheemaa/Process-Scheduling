#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "Scheduler.hpp"


TEST_CASE("TESTING RoundRobin")
{
  RoundRobin *aa;
  RoundRobin *qq;
  Process *bb;
  Process *cc;
  Process *dd;
  Process *ee;
  
  SECTION("TEST")
    {
      

      aa = new FastRoundRobin();
      qq = new FastRoundRobin();
      bb = new CPUBoundProcess(1);
      cc = new IOBoundProcess(2);
      dd =  new CPUBoundProcess(3);
      ee =  new IOBoundProcess(4);
      aa->addProcess(dd);
      qq->addProcess(cc);
      aa->addProcess(bb);
      aa->addProcess(cc);
    
      INFO("RR") //Displayed if fails

	    REQUIRE((aa->popNext(10))->getID()==3);
      REQUIRE((qq->popNext(10))->getID()==2);
    
        
    }
}
TEST_CASE("Testing Nothing")
{
  SECTION("Nothing One")
    {
      REQUIRE(true);
    }    
  
  
}
