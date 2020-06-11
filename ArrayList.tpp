
# include "ArrayList.hpp"
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
ArrayList <item_t>:: ArrayList()
{
	this->capacity = 10;
	this->items = new item_t[capacity];
	this->size = 0;
		
}


template <class item_t>
ArrayList <item_t>:: ArrayList(int capacity)
{
	this->capacity = capacity;
	this->items = new item_t[capacity];
	this->size = 0;
		
}

	
template <class item_t>
ArrayList <item_t>:: ~ArrayList()
{
	delete [] this->items;	

}


template <class item_t>
void ArrayList <item_t>:: pushBack(const item_t& item)   
{
	if ((size+1) >= capacity) {
	   resize();
	 } 
	
	this->items [size] = item; 
	size = size + 1;	
}


template <class item_t>
void ArrayList <item_t>:: popBack()   
{
	size = size - 1;	
}


template <class item_t>
const item_t& ArrayList <item_t>:: getBack() const   
{
	return this->items [size-1];

}


template <class item_t>
void ArrayList <item_t>:: pushFront(const item_t& item)   
{
	if ((size+1) >= capacity) {
	   resize();
	 }

	for (int i = size; i >= 0; i--) {

	    items[i+1] = items[i];

	       }

	items[0] = item;
	size = size + 1;	
}


template <class item_t>
void ArrayList <item_t>:: popFront()   
{

	for (int i = 0; i < size; i++) {

	    items[i] = items[i+1];

	       }

	size = size - 1;	
}


template <class item_t>
const item_t& ArrayList <item_t>:: getFront() const   
{
	return this->items [0];

}


template <class item_t>
const item_t& ArrayList <item_t>:: getItem(int index) const   
{
	return this->items [index];

}


template <class item_t>
void ArrayList <item_t>:: setItem(int index, const item_t& item)   
{
	this->items[index] = item;
}



template <class item_t>
void ArrayList <item_t>:: insert(int index, const item_t& item)   
{
	if ((size+1) >= capacity) {
	   resize();
	 }
	
	else if (index == 0) {
	   pushFront(item);
	   }
	   
	else {

	for (int i = size; i >= index; i--) {

	    items[i+1] = items[i];

	       }


	items[index] = item;
	size = size + 1;
	}
}

template <class item_t>
void ArrayList <item_t>:: remove(int index)   
{
	if (index == size) {
	   popBack();
	   }
	   
	else {
	   
	
	for (int i = index; i <= size; i++) {

	    items[i] = items[i+1];

	     }

	size = size - 1;
	}
}

template <class item_t>
int ArrayList <item_t>:: getSize() const   
{
	return size;

}


template <class item_t>
bool ArrayList <item_t>:: isEmpty() const   
{
	if (size == 0) {
	   return true;
	   }

	else {
	return false;
	}
	
}

template <class item_t>
int ArrayList <item_t>:: getCapacity() const   
{
	return capacity;

}


template <class item_t>
void ArrayList <item_t>:: resize()    
{
	
	capacity = 2 * capacity;
	item_t* newItems = new item_t[capacity];

	//cout<<"Working Until Here" <<endl;

	for (int i = 0; i < size; i++) {

	    newItems [i] = items[i];

	    }

	
	//cout << "items[1] = " << items[3] << endl;
	delete [] items;    
	//cout << "items[1] = " << items[3] << endl;
	items = newItems;
	//cout << "items[1] = " << items[1] << endl;
	
	//delete newItems;

	       
}

















