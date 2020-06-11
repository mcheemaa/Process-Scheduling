# include "LinkedList.hpp"
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>

using namespace std;


template <class item_t>
LinkedList <item_t>:: LinkedList()
{
	head = 0;
	tail = 0;
	size = 0;
	     		
}

	
template <class item_t>	
LinkedList <item_t>:: ~LinkedList()
{
	LinkedListNode<item_t>* node = head;

	while(node != 0) {
	
		LinkedListNode<item_t>* no = node->getNext();
		delete node;
		node = no;

		}
	head = 0;
}


template <class item_t>
void LinkedList <item_t>:: pushBack(const item_t& item)   
{
	LinkedListNode<item_t>* node = new LinkedListNode<item_t> (0, item);
	
	if (size == 0) {

	   head = node;
	   tail =  node;
	   size = size + 1;
	   }

	 else {

	      tail->setNext(node);
	      size = size + 1;
	   }

	   tail = node;
}


template <class item_t>
void LinkedList <item_t>:: popBack()   
{
	LinkedListNode<item_t>* node = head;
	LinkedListNode<item_t>* previous;
	
	if (size == 1) {

	   head = 0;
	   tail = head;
	   size = 0;

	   }
	else {

	while (node != tail) {

	    previous = node;
	    node = node->getNext();
	   }
	 }
	tail = previous;
	tail->setNext(nullptr);
	size = size - 1;	
}


template <class item_t>
const item_t& LinkedList <item_t>:: getBack() const   
{
	LinkedListNode<item_t>* node = head;

	if (size == 1) {

	   return node->getItem();

	   }
	else {

	while (node != tail) {

	    
	    node = node->getNext();
	   }
	 }

	 return node->getItem();	
	
}


template <class item_t>
void LinkedList <item_t>:: pushFront(const item_t& item)   
{
	if (size == 0) {
	   LinkedListNode<item_t>* nod = new LinkedListNode<item_t> (0, item);

	   head = nod;
	   tail = head;
	   size =  1;
	}	

	else {

	LinkedListNode<item_t>* node = new LinkedListNode<item_t> (head, item);
	head = node;
	size = size + 1;
	}
}


template <class item_t>
void LinkedList <item_t>:: popFront()   
{
	if (size != 0) {

	//cout << " Head Item " << head->getItem() << endl;
	   
	   if (size == 1){
	      head = 0;
	      tail = 0;
	      size =  0;
	}

	

	else {
	
		head = head->getNext();
		//cout << " Head Item After " << head->getItem() << endl;
		size = size - 1;
	}
	}
}

template <class item_t>
const item_t& LinkedList <item_t>:: getFront() const   
{
	   return head->getItem();
}


template <class item_t>
const item_t& LinkedList <item_t>:: getItem(int index) const   
{
	//cout << " Index Is " << index << endl;
	LinkedListNode<item_t>* node = head;

	int cur = 1;

	while (cur != index) {
	     node = node->getNext();
	     cur++;
	      }

	return node->getItem();

}


template <class item_t>
void LinkedList <item_t>:: setItem(int index, const item_t& item)   
{

	LinkedListNode<item_t>* node = head;

	int cur = 1;

	while (cur != index) {
	     node = node->getNext();
	     cur++;
	      }

	 node->setItem(item);

}



template <class item_t>
void LinkedList <item_t>:: insert(int index, const item_t& item)   
{
	LinkedListNode<item_t>* add = new LinkedListNode<item_t> (0, item);
	LinkedListNode<item_t>* node = head;
	LinkedListNode<item_t>* temp;

	int cur = 1;

	while (cur != index-1) {
	     node = node->getNext();
	     cur++;
	      }

	add->setNext(node->getNext());
	node->setNext(add);
	size = size + 1;
	
}


template <class item_t>
void LinkedList <item_t>:: remove(int index)   
{

	LinkedListNode<item_t>* node = head;
	

	int cur = 1;

	while (cur != index-1) {
	     node = node->getNext();
	     cur++;
	      }
	//cout << " node value " << node->getItem() <<endl;      
	
	node->setNext(node->getNext()->getNext());

	size = size - 1;
	
}

template <class item_t>
int LinkedList <item_t>:: getSize() const   
{
	return size;

}


template <class item_t>
bool LinkedList <item_t>:: isEmpty() const   
{
	if (size == 0) {
	   return true;
	   }

	else {
	return false;
	}
	
}


