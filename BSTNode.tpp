
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>

using namespace std;


template <class key_t,class val_t>
BSTNode < key_t,val_t>:: BSTNode(const key_t & key, const val_t & value)
{
      
	this->parent = 0 ;
    this-> key=key;
    this-> value=value;
    this->leftchild=0;
    this->rightchild= 0;
	
		
}



	
template <class key_t,class val_t>
BSTNode <key_t,val_t>:: ~BSTNode()
{
	delete this->parent;	  
    delete this->leftchild;
    delete this->rightchild;

}


template <class key_t,class val_t>
void BSTNode <key_t,val_t>:: setKey(const key_t& key)   
{
	this->key=key;
}
template <class key_t,class val_t>
void BSTNode <key_t,val_t>:: setValue(const val_t& value)   
{
	this->value=value;
}
template <class key_t,class val_t>
void BSTNode <key_t,val_t>:: setParent(BSTNode<key_t,val_t> * bt)   
{
	this->parent=bt;
}
template <class key_t,class val_t>
void BSTNode <key_t,val_t>:: setLeftChild( BSTNode<key_t,val_t> * bt)   
{
	this->leftchild=bt;
}
template <class key_t,class val_t>
void BSTNode <key_t,val_t>:: setRightChild( BSTNode<key_t,val_t> * bt)   
{
	this->rightchild=bt;
}

template <class key_t,class val_t>
const key_t & BSTNode <key_t,val_t>:: getKey() const  
{
	return this->key;
}
template <class key_t,class val_t>
const val_t & BSTNode <key_t,val_t>:: getValue() const   
{
	return this->value;
}
template <class key_t,class val_t>
BSTNode<key_t,val_t> * BSTNode <key_t,val_t>:: getParent() const
{
	return this->parent;
}
template <class key_t,class val_t>
BSTNode<key_t,val_t>* BSTNode <key_t,val_t>:: getLeftChild() const  
{
	return this->leftchild;
}
template <class key_t, class val_t>
BSTNode<key_t,val_t> * BSTNode <key_t,val_t>:: getRightChild() const  
{
	return this->rightchild;
}
