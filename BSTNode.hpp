#ifndef BST_NODE
#define BST_NODE



template <class key_t,class val_t>
class BSTNode
{
  protected:
   key_t key;
   val_t  value;
  BSTNode<key_t,val_t> *  parent;
  BSTNode<key_t,val_t> *  rightchild;
  BSTNode<key_t,val_t> *  leftchild;
   
  public:
  
   BSTNode(const key_t & key, const val_t & val);
   
   
  
  virtual  ~BSTNode();

  
   virtual const key_t & getKey() const;
   virtual const val_t & getValue() const;
  virtual BSTNode<key_t,val_t> * getParent() const;
  virtual BSTNode<key_t,val_t> * getLeftChild() const;
  virtual BSTNode<key_t,val_t> * getRightChild() const;
   virtual void setKey(const key_t& key);
  virtual void setValue(const val_t & value);
   virtual void setParent( BSTNode * bt);
   virtual void setLeftChild( BSTNode * bt);
   virtual void setRightChild( BSTNode * bt);  

 
};

#include "BSTNode.tpp"


#endif
