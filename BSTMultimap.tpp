
# include "BSTNode.hpp" 
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>
# include <queue>
#include "BSTForwardIterator.hpp"


using namespace std;


template <class key_t,class val_t>
BSTMultimap <key_t,val_t>:: BSTMultimap()
{
  
  this->sentinel = new BSTNode<key_t,val_t>(0,0);
  this-> numItems = 0;
  this->root=this->sentinel;  
}




  
template <class key_t,class val_t>
BSTMultimap <key_t,val_t>:: ~BSTMultimap()
{
  clear();
}

template <class key_t,class val_t>
void BSTMultimap <key_t,val_t>:: insertNode(BSTNode<key_t,val_t> * bt)
   
{

 if((this->root)->getKey()==(this->sentinel)->getKey()){
              
             this->root=bt;
             bt->setParent(this->sentinel);
             bt->setLeftChild(this->sentinel); 
             bt->setRightChild(this->sentinel);
              this->numItems+=1;

              return;
        }
         
        BSTNode<key_t,val_t> *now = this->root;
      
        while(true)
        {
         
       if((now->getLeftChild())->getKey() != (this->sentinel)->getKey() ||  (now->getRightChild())->getKey() != (this->sentinel)->getKey())
       {
    
        if(bt->getKey()< now->getKey()){
              if ((now->getLeftChild())->getKey() == (this->sentinel)->getKey()){
                  now->setLeftChild(bt);
                  bt->setParent(now);
                  break;
               }
               else{
                 now=now->getLeftChild();
               }
          }
        else{
              if ((now->getRightChild())->getKey() == (this->sentinel)->getKey()){
                  now->setRightChild(bt);
                  bt->setParent(now);
                   break;
               }
               else{
                 now=now->getRightChild();
               }
         }
      }
     else{
          
         if(bt->getKey()< now->getKey()){
              
                  now->setLeftChild(bt);
                  bt->setParent(now);
                   break;
                 }
         else
        {
        now->setRightChild(bt);
        bt->setParent(now);
         break;
        }
    }
  }
  
  bt->setLeftChild(this->sentinel);
   bt->setRightChild(this->sentinel);
  this->numItems+=1;
     
  return;
}
  

template <class key_t,class val_t>
void BSTMultimap <key_t,val_t>:: insert(const key_t & key, const val_t & val)
   
{
          
  BSTNode<key_t,val_t> *bt= new BSTNode<key_t,val_t>(key,val);
  insertNode(bt);

  return;
       
      
}


template <class key_t,class val_t>
int BSTMultimap <key_t,val_t>:: getSize()   
{
  return numItems;  
}


template <class key_t,class val_t>
bool BSTMultimap <key_t,val_t>:: isEmpty() const   
{
  return this->numItems==0;

}


template <class key_t,class val_t>
bool BSTMultimap <key_t,val_t>:: helpcontains(const key_t& key, BSTNode<key_t,val_t> * bt)   
{
//cout<<" i am node: "<<bt->getKey()<<"   ";
//cout<<" i am key: "<<key<<"   ";

if (bt->getKey()==(this->sentinel)->getKey()){

     return false;
}
else if(bt->getKey()==key)
{
 //cout<<" i good";
 return true;
}
else{
  
  bool n1= helpcontains(key,bt->getLeftChild());
  //cout<<" i am n1: "<<boolalpha<<n1<<"   ";
  
   bool n2=helpcontains(key,bt->getRightChild());
   //cout<<" i am n2: "<<boolalpha<<n2<<"   ";
  if(n1==true || n2== true){
   // cout<<" i am done 1   ";
    return true;
   }
   else{
   
    return false;
   }
   }
}
  


  

template <class key_t,class val_t>
bool BSTMultimap <key_t,val_t>:: contains(const key_t& key)   
{

 
 //cout<<" is key : " << key << "is root: "<< this->root->getKey();
  return helpcontains(key,this->root);
}


template <class key_t,class val_t>
void BSTMultimap <key_t,val_t>:: helpclear(BSTNode<key_t,val_t> * bt)   
{
if (bt==this->sentinel){
     return;
}
else{
   helpclear(bt->getLeftChild());
   helpclear(bt-> getRightChild());

  //delete bt;

   }

return;


  
}
template <class key_t,class val_t>
void BSTMultimap <key_t,val_t>:: clear()   
{
helpclear(this->root);
numItems=0;
root = sentinel;
  
}

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap <key_t,val_t>:: getMin() const   
{
  BSTNode <key_t, val_t>*  tempo = root; 

  if ( tempo == this->sentinel) {

    return BSTForwardIterator <key_t, val_t> (root, sentinel);

  }

  else {

    while (tempo->getLeftChild() != sentinel) {

      tempo = tempo->getLeftChild();
    }

    return BSTForwardIterator <key_t, val_t> (tempo, sentinel);

    }


  }

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap <key_t,val_t>:: getMax() const   
{
  BSTNode <key_t, val_t>*  tempo = root;

   if ( tempo == this->sentinel) {

    return BSTForwardIterator <key_t, val_t> (root, sentinel);

  }

  else {

    while (tempo->getRightChild() != sentinel) {

      tempo = tempo->getRightChild();
    }

    return BSTForwardIterator <key_t, val_t> (tempo, sentinel);

  }

}

template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap <key_t,val_t>:: findFirst(const key_t& key) const
{

  BSTNode <key_t, val_t>*  tempo = root;

  
  while(tempo != sentinel) {

   if (tempo->getKey() == key) {
        return BSTForwardIterator <key_t, val_t> (tempo, sentinel);
      }

      else if (tempo->getKey() > key) {

        tempo = tempo->getLeftChild();

      }

      else {

        tempo = tempo->getRightChild();
      }

    }

  return BSTForwardIterator <key_t, val_t> (sentinel, sentinel);


}


template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap <key_t,val_t>:: findLast(const key_t& key) const
{

  BSTForwardIterator <key_t, val_t> ans (sentinel, sentinel);

  BSTNode <key_t, val_t>*  tempo = root;
  
  while(tempo != sentinel) {

    if (tempo->getKey() == key) {

        //cout<< "DOING IF CHILD" << endl;

        ans = BSTForwardIterator <key_t, val_t> (tempo, sentinel);

        tempo = tempo->getRightChild();

      }

      else if (tempo->getKey() > key) {

        //cout<< "DOING LEFT CHILD" << endl;

        tempo = tempo->getLeftChild();

      }

      else {

        //cout<< "DOING RIGHT CHILD" << endl;


        tempo = tempo->getRightChild();
      }

    }

  

  return ans;
}  

template <class key_t,class val_t>
void BSTMultimap <key_t,val_t>:: transplant(BSTNode<key_t,val_t> * a, BSTNode<key_t,val_t> * b)   
{
  if (a->getParent() == sentinel) {

    (this->root)->setValue(b->getValue());
  }

  else if (a == (a->getParent())->getLeftChild()) {

    ((a->getParent())->setLeftChild(b));

  }

  else {

    ((a->getParent())->setRightChild(b));

  }

  if (b != sentinel) {

    ((b->getParent())->setValue((a->getParent())->getValue()));

  }
}


template <class key_t,class val_t>
BSTForwardIterator<key_t, val_t> BSTMultimap <key_t,val_t>:: remove(const BSTForwardIterator<key_t, val_t>& pos)
{

  BSTNode <key_t, val_t>*  tempo = pos.current;
  BSTNode <key_t, val_t>*  y = tempo->getRightChild();

  if (tempo == sentinel) {

      transplant(tempo, tempo->getRightChild());

  }

  else if (tempo->getRightChild() == sentinel){

    transplant(tempo, tempo->getLeftChild());

  }

  else {

    

    if ((y->getParent()) != tempo) {

      transplant(y,y->getRightChild());
      y->setRightChild((tempo->getRightChild()));
      ((y->getRightChild())->getParent())->setParent(y);

    }

    transplant (tempo, y);
    (y->getLeftChild())->setValue((tempo->getLeftChild())->getValue());
    ((y->getLeftChild())->setParent(y));      

  }

  //delete pos.current;

  return BSTForwardIterator <key_t, val_t> (y, sentinel);

}



template <class key_t,class val_t>
void BSTMultimap <key_t,val_t>:: toString()   
{
if(root->getKey()==sentinel->getKey())
   {
    return;
   }
 queue<BSTNode<key_t,val_t>*> qq;
  BSTNode<key_t,val_t> *temp;
  qq.push(root);
  while(!(qq.empty()))
  {
    temp=qq.front();
    cout<<"key: "<<to_string(temp->getKey())<<"  ";
    qq.pop();
    if(temp->getLeftChild()->getKey() != sentinel->getKey())
    {
    
    qq.push(temp->getLeftChild());
   }
   

    if(temp->getRightChild()->getKey() != sentinel->getKey())
    {
    qq.push(temp->getRightChild());
   }
   }
}



  
  
         


