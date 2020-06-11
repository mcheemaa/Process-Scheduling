#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "LinkedList.hpp"


TEST_CASE("TESTING LinkedList Class")
{

  
  SECTION("Testing Everything With Int")
    {

      LinkedList<int> a;

      REQUIRE(a.isEmpty() == true);
     
      REQUIRE(a.getSize() == 0);

      a.pushBack(10);
      REQUIRE(a.getSize() == 1);
      REQUIRE(a.getBack() == 10);
      
      a.pushFront(12);

      REQUIRE(a.getBack() == 10);
      REQUIRE(a.getFront() == 12);

      a.popBack();
      REQUIRE(a.getBack() == 12);

      a.pushBack(14);
      a.pushBack(16);
      

      REQUIRE(a.getFront() == 12);
      a.popFront();
      REQUIRE(a.getFront() == 14);
      REQUIRE(a.getSize() == 2);
      
      a.pushBack(13);
      a.pushBack(17);
      a.pushBack(19);
      a.pushBack(15);
      
      REQUIRE(a.getSize() == 6);
      
      REQUIRE(a.getBack() == 15);
      REQUIRE(a.getItem(6) == 15);

      a.pushBack(33);
      a.pushBack(66);

      a.setItem(6,2);
      REQUIRE(a.getItem(4) == 17);
      REQUIRE(a.getSize() == 8);

      a.insert(4,63);
      REQUIRE(a.getSize() == 9);
      REQUIRE(a.getItem(4) == 63);
      
      REQUIRE(a.getItem(5) == 17);

      a.insert(5, 91);
      REQUIRE(a.getSize() == 10);
      REQUIRE(a.getItem(5) == 91);
      REQUIRE(a.getItem(6) == 17);
      REQUIRE(a.getItem(7) == 19);


      a.remove(6);
      REQUIRE(a.getSize() == 9);
      REQUIRE(a.getItem(6) == 19);
      
   
      
      

    }

}
