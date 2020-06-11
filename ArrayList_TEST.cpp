
#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "ArrayList.hpp"


TEST_CASE("TESTING ArrayList Class")
{

  
  SECTION("Testing Everything With Int")
    {

      ArrayList<int> a;

      REQUIRE(a.isEmpty() == true);
      REQUIRE(a.getCapacity() == 10);
      REQUIRE(a.getSize() == 0);

      a.pushBack(10);
      REQUIRE(a.isEmpty() == false);
      REQUIRE(a.getBack() == 10);

      a.pushBack(8);
      a.pushBack(6);
      REQUIRE(a.getSize() == 3);

      a.popBack();
      REQUIRE(a.getBack() == 8);
      REQUIRE(a.getSize() == 2);

      a.pushFront(4);
      REQUIRE(a.getSize() == 3);
      REQUIRE(a.getFront() == 4);
      REQUIRE(a.getBack() == 8);

      a.popFront();
      REQUIRE(a.getFront() == 10);
      REQUIRE(a.getBack() == 8);
      REQUIRE(a.getItem(1) == 8);

      a.pushBack(6);
      a.pushBack(5);
      REQUIRE(a.getSize() == 4);

      a.setItem(3, 18);
      REQUIRE(a.getSize() == 4);
      REQUIRE(a.getItem(3) == 18);
      REQUIRE(a.getBack() == 18);

      a.insert(2, 16);
      REQUIRE(a.getSize() == 5);
      REQUIRE(a.getItem(3) == 6);
      REQUIRE(a.getBack() == 18);
      REQUIRE(a.getCapacity() == 10);

      //a.resize();

      REQUIRE(a.getSize() == 5);
      REQUIRE(a.getItem(3) == 6);
      REQUIRE(a.getBack() == 18);
      //REQUIRE(a.getCapacity() == 10);
      
      a.pushBack(6);
      a.pushBack(6);	
      REQUIRE(a.getSize() == 7);

      a.pushBack(6);
      a.pushBack(26);
      a.pushFront(12);
      a.insert(2,2);
      
      REQUIRE(a.getSize() == 11);
      REQUIRE(a.getBack() == 26);
      REQUIRE(a.getCapacity() == 20);

      a.remove(2);
      REQUIRE(a.getSize() == 10);
	

    }

  SECTION("Testing Everything With Strings")
    {

      ArrayList<string> a;

      REQUIRE(a.isEmpty() == true);
      REQUIRE(a.getCapacity() == 10);
      REQUIRE(a.getSize() == 0);

      a.pushBack("10");
      REQUIRE(a.isEmpty() == false);
      REQUIRE(a.getBack() == "10");

      a.pushBack("8");
      a.pushBack("6");
      REQUIRE(a.getSize() == 3);

      a.popBack();
      REQUIRE(a.getBack() == "8");
      REQUIRE(a.getSize() == 2);

      a.pushFront("4");
      REQUIRE(a.getSize() == 3);
      REQUIRE(a.getFront() == "4");
      REQUIRE(a.getBack() == "8");

      a.popFront();
      REQUIRE(a.getFront() == "10");
      REQUIRE(a.getBack() == "8");
      REQUIRE(a.getItem(1) == "8");

      a.pushBack("6");
      a.pushBack("5");
      REQUIRE(a.getSize() == 4);

      a.setItem(3, "18");
      REQUIRE(a.getSize() == 4);
      REQUIRE(a.getItem(3) == "18");
      REQUIRE(a.getBack() == "18");

      a.insert(2, "16");
      REQUIRE(a.getSize() == 5);
      REQUIRE(a.getItem(3) == "6");
      REQUIRE(a.getBack() == "18");
      REQUIRE(a.getCapacity() == 10);

      
      REQUIRE(a.getSize() == 5);
      REQUIRE(a.getItem(3) == "6");
      REQUIRE(a.getBack() == "18");
      REQUIRE(a.getCapacity() == 10);
      
            
    }

  

  

}
