#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "BSTMultimap.hpp"


TEST_CASE("TESTING BSTMultimap Class")
{

  
  SECTION("Test BSTMultiMap")
    {
      //cout<<"p1";
      BSTNode<int, int> *a= new BSTNode<int,int>(0,0);
      BSTNode<int,int> *b= new BSTNode<int,int>(1,1);
      BSTNode<int, int> *c=new BSTNode<int,int>(2,2);
      BSTNode<int, int> *d=new BSTNode<int,int>(3,3);
      BSTNode <int, int>*e=new BSTNode<int,int>(4,4);
       //cout<<"p2";
      BSTMultimap <int,int> *kb=new BSTMultimap<int, int>();
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
      
      kb->insert(2,7);
      kb->insert(1,6);
      kb->insert(3,8);
      kb->insert(4,2);
      kb->insert(5,10);

      BSTForwardIterator <int, int> temp = kb->getMin() ;

      //temp.next();


      REQUIRE(temp.getValue() == 6); 

      REQUIRE(temp.getValue() == 6); 

      REQUIRE(kb->getSize() == 5);
      REQUIRE(kb->contains(4)== true);
      REQUIRE(kb->isEmpty() == false);
      kb->clear();
      REQUIRE(kb->isEmpty() == true);
     
    }


  SECTION("Test Get Min")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    BSTMultimap <int,int> *e =new BSTMultimap<int, int>();

    BSTForwardIterator <int, int> tempo = e->getMin() ;

    REQUIRE(tempo.getValue() == 0);




    a->insert(9,25);
    a->insert(2,10);
    a->insert(3,7);
    a->insert(1,12);
    a->insert(5,36);
    a->insert(6,27);
    a->insert(7,40);

    BSTForwardIterator <int, int> temp = a->getMin() ;

    //temp.next();

    REQUIRE(temp.getValue() == 12);

    temp.next();

    REQUIRE(temp.getValue() == 10);


  }


  SECTION("Test Get Max")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    BSTMultimap <int,int> *e =new BSTMultimap<int, int>();

    BSTForwardIterator <int, int> tempo = e->getMax() ;
    REQUIRE(tempo.getValue() == 0);


    a->insert(1,25);
    a->insert(9,12);
    a->insert(3,7);
    a->insert(4,12);
    a->insert(2,36);
    a->insert(2,27);
    a->insert(7,40);
    a->insert(2,27);
    a->insert(2,27);
    a->insert(2,27);
    a->insert(2,27);
    a->insert(2,24);

    BSTForwardIterator <int, int> temp = a->getMax() ;

    REQUIRE(temp.getValue() == 12);

    temp.next();

    BSTForwardIterator <int, int> first = a->findFirst(2) ;
    BSTForwardIterator <int, int> last = a->findLast(2) ;

    REQUIRE(first.getValue() == 36);
    REQUIRE(first.isPastEnd() == false);
    first.setValue(20);
    


    REQUIRE(last.getKey() == 2);


  }


SECTION("Test Remove")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    a->insert(1,25);
    a->insert(9,12);
    a->insert(23,12);
    a->insert(3,7);
    a->insert(4,12);
    a->insert(2,36);
    a->insert(2,27);
    a->insert(7,40);
    a->insert(2,27);
    a->insert(62,27);
    a->insert(2,27);
    a->insert(2,27);
    a->insert(2,24);

    BSTForwardIterator <int, int> temp = a->getMax() ;

    REQUIRE(temp.getValue() == 27);

    temp.next();

    BSTForwardIterator <int, int> rem = a->findFirst(9) ;
    BSTForwardIterator <int, int> remi = a->findLast(62) ;

    

    a->remove(rem);
    a->remove(remi);

    REQUIRE(a->contains(9) == false);
    REQUIRE(a->contains(62) == false);
    

  }

  SECTION("Test Remove Case 1")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    a->insert(5,1);
    a->insert(2,2);
    a->insert(18,3);
    a->insert(-4,4);
    a->insert(3,5);

    BSTForwardIterator <int, int> temp = a->getMax() ;

    REQUIRE(temp.getValue() == 3);


    BSTForwardIterator <int, int> rem = a->findFirst(-4) ;
    

    a->remove(rem);

    REQUIRE(a->contains(-4) == false);
    

  }

  SECTION("Test Remove Case 2")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    a->insert(5,1);
    a->insert(2,2);
    a->insert(18,3);
    a->insert(-4,4);
    a->insert(3,5);
    a->insert(21,6);
    a->insert(19,7);
    a->insert(25,8);
    


    BSTForwardIterator <int, int> temp = a->getMax() ;

    REQUIRE(temp.getValue() == 8);


    BSTForwardIterator <int, int> rem = a->findFirst(18) ;
    

    a->remove(rem);

    REQUIRE(a->contains(18) == false);
    

  }

SECTION("Test Remove Case 3")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    a->insert(5,1);
    a->insert(2,2);
    a->insert(12,3);
    a->insert(-4,4);
    a->insert(3,5);
    a->insert(9,6);
    a->insert(21,7);
    a->insert(19,8);
    a->insert(25,9);
    


    BSTForwardIterator <int, int> temp = a->getMax() ;

    REQUIRE(temp.getValue() == 9);


    BSTForwardIterator <int, int> rem = a->findFirst(12) ;
    

    a->remove(rem);

    REQUIRE(a->contains(12) == false);
    

  }

  SECTION("Testing Inroder Traversal")
  {

    BSTMultimap <int,int> *a =new BSTMultimap<int, int>();

    BSTForwardIterator <int, int> tempo = a->getMin() ;

    REQUIRE(tempo.getValue() == 0);

    a->insert(5,0);
    a->insert(10,1);
    a->insert(3,2);
    a->insert(4,3);
    a->insert(1,4);

    BSTForwardIterator <int, int> temp = a->findFirst(1)  ;
    REQUIRE(temp.getKey() == 1);


    //cout << "string rep : " << toString() << endl;

  
    temp.next();
    REQUIRE(temp.getKey() == 3);


    temp.next();
    REQUIRE(temp.getKey() == 4);


    temp.next();
    REQUIRE(temp.getKey() == 5);


    temp.next();
    REQUIRE(temp.getKey() == 10);
    //cout << "string rep : " << toString() << endl;

    //temp.next();



  }



  

}
