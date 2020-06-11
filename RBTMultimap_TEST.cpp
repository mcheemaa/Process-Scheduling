#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "BSTMultimap.hpp"
#include "RBTMultimap.hpp"

TEST_CASE("TESTING RBTMultimap Class")
{

  
  SECTION("Test RBTMultiMap")
    {
      //cout<<"p1";
      RBTNode<int, int> *a= new RBTNode<int,int>(0,0,false);
      RBTNode<int,int> *b= new RBTNode<int,int>(1,1,false);
      RBTNode<int, int> *c=new RBTNode<int,int>(2,2,false);
      RBTNode<int, int> *d=new RBTNode<int,int>(3,3,false);
      RBTNode <int, int>*e=new RBTNode<int,int>(4,4,false);
       //cout<<"p2";
      RBTMultimap <int,int> *kb=new RBTMultimap<int, int>();
       //cout<<"p3";
      a->setKey(1);
      a->setValue(6);
      b->setKey(2);
      b->setValue(7);
      c->setKey(3);
      c->setValue(8);
      d->setKey(4);
      d->setValue(2);
      e->setKey(5);
      e->setValue(10);
      
     
      kb->insert(2,6);
      kb->insert(9,7);
      kb->insert(6,8);
      kb->insert(3,2);
      kb->insert(4,10);
      //kb->insert(5,11);
      //kb->insert(6,12);
      
      //kb->printDOT("ahh.txt");

      BSTForwardIterator <int, int> first = kb->findFirst(4) ;
      BSTForwardIterator <int, int> last = kb->findLast(4) ;

      REQUIRE((dynamic_cast<RBTNode<int,int>*>(first.current))->isRed());


      REQUIRE(first.getValue() == 10);
      REQUIRE(first.isPastEnd() == false);


      REQUIRE(last.getValue() == 10);
      REQUIRE(first.isPastEnd() == false);
      
      


      REQUIRE(kb->getSize() == 5);
      REQUIRE(kb->contains(4)== true);
      REQUIRE(kb->contains(4)== true);
       
      REQUIRE(kb->contains(9)== true);
      REQUIRE(kb->contains(7)== false);
	    REQUIRE(kb->contains(2)== true);
      REQUIRE(kb->isEmpty() == false);
      kb->clear();
      REQUIRE(kb->isEmpty() == true);
    
     
    }

     SECTION("Test RBTMultiMap Find First & Last")
    {
      RBTMultimap <int,int> *a = new RBTMultimap<int, int>();
      
     
      a->insert(8,3);
      a->insert(5,1);
      a->insert(15,5);
      a->insert(12,2);
      a->insert(19,4);
      a->insert(9,4);
      a->insert(13,4);
      a->insert(23,4);


      BSTForwardIterator <int, int> first = a->findFirst(5) ;
      BSTForwardIterator <int, int> last = a->findLast(13) ;

      REQUIRE((dynamic_cast<RBTNode<int,int>*>(first.current))->isRed() == false);


      REQUIRE(first.getValue() == 1);
      REQUIRE(first.isPastEnd() == false);


      REQUIRE(last.getValue() == 4);
      REQUIRE(first.isPastEnd() == false);
      
      REQUIRE(a->getSize() == 8);
      REQUIRE(a->contains(23)== true);


      BSTForwardIterator <int, int> c = a->findFirst(15) ;
      BSTForwardIterator <int, int> d = a->findLast(13) ;

      REQUIRE((dynamic_cast<RBTNode<int,int>*>(c.current))->isRed());
      REQUIRE((dynamic_cast<RBTNode<int,int>*>(d.current))->isRed());

      
     
    }

    SECTION("Test RBTMultiMap Insertion")
    {
      RBTMultimap <int,int> *a = new RBTMultimap<int, int>();
      
     
    
      a->insert(8,3);
      a->insert(5,1);
      a->insert(15,5);
      a->insert(12,2);
      a->insert(19,4);
      a->insert(9,4);
      a->insert(13,4);
      a->insert(23,4);

      a->insert(10,4);
      

      
      BSTForwardIterator <int, int> first = a->findFirst(5) ;
      BSTForwardIterator <int, int> last = a->findLast(13) ;

      REQUIRE((dynamic_cast<RBTNode<int,int>*>(first.current))->isRed() == false);


      REQUIRE(first.getValue() == 1);
      REQUIRE(first.isPastEnd() == false);


      REQUIRE(last.getValue() == 4);
      REQUIRE(first.isPastEnd() == false);
      
      REQUIRE(a->getSize() == 9);
      REQUIRE(a->contains(23)== true);


      BSTForwardIterator <int, int> c = a->findFirst(15) ;
      BSTForwardIterator <int, int> d = a->findLast(13) ;

      REQUIRE(a->getSize() == 9);


      //a->remove(c);


      REQUIRE(a->getSize() == 9);


      REQUIRE((dynamic_cast<RBTNode<int,int>*>(c.current))->isRed());
      REQUIRE((dynamic_cast<RBTNode<int,int>*>(d.current))->isRed() == false);
      
     
    }

    SECTION("Test Remove")
    {
      RBTMultimap <int,int> *a = new RBTMultimap<int, int>();
      
     
    
      a->insert(8,3);
      a->insert(5,1);
      a->insert(15,5);
      a->insert(12,2);
      a->insert(19,4);
      a->insert(9,4);
      a->insert(13,4);
      a->insert(23,4);

      a->insert(10,4);
      

      
      BSTForwardIterator <int, int> first = a->findFirst(5) ;
      BSTForwardIterator <int, int> last = a->findLast(13) ;

      REQUIRE((dynamic_cast<RBTNode<int,int>*>(first.current))->isRed() == false);


      REQUIRE(first.getValue() == 1);
      REQUIRE(first.isPastEnd() == false);


      REQUIRE(last.getValue() == 4);
      REQUIRE(first.isPastEnd() == false);
      
      REQUIRE(a->getSize() == 9);
      REQUIRE(a->contains(23)== true);


      REQUIRE(a->getSize() == 9);

      BSTForwardIterator <int, int> c = a->findFirst(15) ;


      REQUIRE(a->contains(15)== true);
        
      a->remove(c);

      REQUIRE(a->getSize() == 8);


      //REQUIRE(a->contains(15)== true);
      

      


      
    }


    SECTION("Test Remove")
    {
      RBTMultimap <int,int> *a = new RBTMultimap<int, int>();
      
     
    
      a->insert(8,3);
      a->insert(5,1);
      a->insert(11,5);
      a->insert(3,2);
      a->insert(9,4);
      a->insert(7,4);
      a->insert(14,4);
      a->insert(2,4);
      a->insert(6,4);
      
      a->printDOT("befrem.dot");

      BSTForwardIterator <int, int> c = a->findFirst(3) ;

      REQUIRE(a->contains(7)== true);
        
      a->remove(c);

      a->printDOT("aftrem.dot");

      REQUIRE(a->getSize() == 8);

      BSTForwardIterator <int, int> d = a->findFirst(8) ;
      
      a->remove(d);

      a->printDOT("aftre.dot");




      //REQUIRE(a->contains(15)== true);
      

      


      
    }


    SECTION("Test Remove Case 2")
    {
      RBTMultimap <int,int> *a = new RBTMultimap<int, int>();
      
     
    
      a->insert(31,3);
      a->insert(23,1);
      a->insert(45,5);
      a->insert(11,2);
      a->insert(28,4);
      a->insert(33,12);
      a->insert(49,11);
      a->insert(24,10);
      a->insert(47,9);
      a->insert(56,8);
      a->insert(46,6);
      
      a->printDOT("before.dot");

      BSTForwardIterator <int, int> c = a->findFirst(33) ;


      //BSTForwardIterator <int, int> d = a->findFirst(46) ;

      REQUIRE(a->contains(7)== false);
        
      a->remove(c);
      //a->remove(d);

      a->printDOT("after.dot");

      REQUIRE(a->getSize() == 10);

      /**BSTForwardIterator <int, int> d = a->findFirst(8) ;
      
      a->remove(d);

      a->printDOT("aft.dot");**/




      //REQUIRE(a->contains(15)== true);
      

      


      
    }









  

}
