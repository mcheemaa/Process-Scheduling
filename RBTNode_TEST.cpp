#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "RBTNode.hpp"

TEST_CASE("TESTING ArrayList Class")
{

  
  SECTION("test rbtnode")
    {
      int x=0;
      int y=0;

      RBTNode<int,int> *a= new RBTNode<int,int>(x,y,true);
      RBTNode<int,int> *b= new RBTNode<int,int>(1,1,false);
      RBTNode<int,int> *c = new RBTNode<int,int>(2,2,false);
      a->setKey(1);
      a->setValue(6);
      b->setKey(2);
      b->setValue(7);
      c->setKey(3);
      c->setValue(8);
      a->setLeftChild(b);
      a->setRightChild(c);
      b->setParent(a);
      c->setParent(a);
      b->setIsRed(false);
      cout<<"at";
      REQUIRE(a->getKey() == 1);
      REQUIRE(a->getValue()== 6);
       REQUIRE(b->getKey() == 2);
      REQUIRE(b->getValue()== 7);
       REQUIRE(c->getKey() == 3);
      REQUIRE(c->getValue()== 8);
      cout<<"mt";
      REQUIRE(a->getLeftChild()->getKey()==2);
      REQUIRE(a->getLeftChild()->getValue() == 7);
      cout<<"gt";
      REQUIRE(a->getRightChild()->getKey()== 3);
      REQUIRE(a->getRightChild()->getValue()==8);
      cout<<"qt";
      REQUIRE(b->getParent()->getKey()== 1);
      cout<<"j";
      REQUIRE(b->getParent()->getValue()==6);
      cout<<"k";
      REQUIRE(c->getParent()->getKey()== 1);
      cout<<"ghjkl";
      REQUIRE(c->getParent()->getValue()==6);
      REQUIRE(a->isRed());
      REQUIRE(b->isRed()==false);
       REQUIRE(c->isRed()==false);
      
     
            
    }

  

  

}
