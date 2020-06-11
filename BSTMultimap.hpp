#ifndef BST_MULTIMAP
#define BST_MULTIMAP
#include "BSTNode.hpp"
#include "BSTForwardIterator.hpp"



template <class key_t,class val_t>
class BSTMultimap
{
  protected:
   BSTNode<key_t,val_t> * root;
  BSTNode<key_t,val_t> * sentinel;
  
  
  
  int   numItems;
  
  virtual void  helpclear(BSTNode<key_t,val_t> * bt);
  virtual bool helpcontains(const key_t& key, BSTNode<key_t,val_t> * bt); 
  virtual void insertNode(BSTNode<key_t,val_t>* bt); 
  public:
  
  BSTMultimap();
   
   
  
  virtual  ~BSTMultimap();

  
  virtual void  insert(const key_t & key, const val_t & val);
  virtual int  getSize() ;
  virtual bool  isEmpty() const;   
  virtual bool  contains(const key_t& key);  
  virtual void  clear();

  virtual void  transplant(BSTNode<key_t,val_t> * a, BSTNode<key_t,val_t> * b) ;


  virtual BSTForwardIterator<key_t, val_t> getMin() const;

  virtual BSTForwardIterator<key_t, val_t> getMax() const;

  virtual BSTForwardIterator<key_t, val_t> findFirst(const key_t& key) const;
  

  virtual BSTForwardIterator<key_t, val_t> findLast(const key_t& key) const;

  virtual BSTForwardIterator<key_t, val_t> remove(const BSTForwardIterator<key_t, val_t>& pos);
  
  virtual void toString();
 
};

#include "BSTMultimap.tpp"


#endif
