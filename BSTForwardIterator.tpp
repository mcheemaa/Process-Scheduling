
# include "BSTForwardIterator.hpp"
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>



using namespace std;


template <class key_t, class val_t>
BSTForwardIterator <key_t, val_t>:: BSTForwardIterator(BSTNode<key_t, val_t>* node, BSTNode<key_t, val_t>* sentinel)
{
	this->current = node;
	this->sentinel = sentinel;	
}

template <class key_t, class val_t>
void BSTForwardIterator <key_t, val_t>::next()
{

	if (current->getRightChild() != sentinel) {

		current = current->getRightChild();

		while (current->getRightChild() != sentinel) {

			current = current->getLeftChild();

		}

	}

	else if (current != sentinel) {

		BSTNode<key_t,val_t>* newN = current->getParent();

		while (newN != sentinel and current == newN->getRightChild()) {

			current = newN;
			newN = newN->getParent();
		}

		current = newN;

	}

}

template <class key_t, class val_t>
bool BSTForwardIterator <key_t, val_t>::isPastEnd() const
{
	if (this->current == this->sentinel) {

		return true;

	}

	else {

		return false;

	}

}


template <class key_t, class val_t>
const key_t& BSTForwardIterator <key_t, val_t>::getKey() const
{

	return current->getKey();

}


template <class key_t, class val_t>
const val_t& BSTForwardIterator <key_t, val_t>::getValue() const
{

	return current->getValue();

}


template <class key_t, class val_t>
void BSTForwardIterator <key_t, val_t>::setValue(const val_t& newVal)
{

	return current->setValue(newVal);

}

