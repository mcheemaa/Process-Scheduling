
# include "RBTNode.hpp" 
# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <cstdlib>
# include <vector>
# include <sstream>
# include <algorithm>
# include "BSTForwardIterator.hpp"

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>::RBTMultimap()
{
  this->sentinel= new RBTNode<key_t,val_t>(0,0,false);  
  this->root=this->sentinel;
}

template <class key_t, class val_t>
RBTMultimap<key_t, val_t>:: ~RBTMultimap()
{
  BSTMultimap<key_t,val_t>::clear();
  delete this->sentinel;
}


template <class key_t,class val_t>
void RBTMultimap <key_t,val_t>:: insert(const key_t & key, const val_t & val)   
{

          
  RBTNode<key_t,val_t> *bt= new RBTNode<key_t,val_t>(key,val,true);
  BSTMultimap<key_t,val_t>::insertNode(bt);
  
  insertFixup(bt);
  string str="aaa"+to_string(key)+".dot";
  printDOT(str);
  return;
      
}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateLeft(BSTNode <key_t,val_t> *node)
{
  
  BSTNode<key_t,val_t> *y =node->getRightChild();

  node->setRightChild(y->getLeftChild());
  
  if((y->getLeftChild())!= (this->sentinel)){
      (y->getLeftChild())->setParent(node);
   }
  
  y->setParent(node->getParent());
  
  if((node->getParent()) == (this->sentinel)){
      this->root=y;
  }

  else if(node==((node->getParent())->getLeftChild())){
  
    (node->getParent())->setLeftChild(y);
  }

else {
  (node->getParent())->setRightChild(y); 

  }

  y->setLeftChild(node);
  node->setParent(y); 
  //delete y;

}



template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::rotateRight(BSTNode <key_t,val_t> *node)
{

  //cout<<"pa   ";
  if(node->getKey()==9)
  {
    printDOT("bmw.dot");
  }

  BSTNode<key_t,val_t> *y =node->getLeftChild();
  node->setLeftChild(y->getRightChild());
  
  //cout<<"pb   ";
  if((node->getLeftChild()) != (this->sentinel)){
      (node->getLeftChild())->setParent(node);
   }
  
  //cout<<"pc  ";
  y->setParent(node->getParent());
  //cout<<"pd  ";

  if((node->getParent()) == (this->sentinel)){
    this->root=y;
  }

  else if(node==((node->getParent())->getLeftChild())){
    (node->getParent())->setLeftChild(y);
  }

  else {
  (node->getParent())->setRightChild(y); 
  }
  if(node->getKey()==9)  {
  
  //cout<<"fuck";
  printDOT("ford.dot");
  }

  //cout<<"pe  ";
  y->setRightChild(node);
  //cout<<"pf  ";
  node->setParent(y); 
//cout<<"pg  ";
//delete y;
  if(node->getKey()==9)
  {
  printDOT("benz.dot");
  }
}


template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::insertFixup(RBTNode <key_t,val_t> *insertedNode)
{
  RBTNode<key_t,val_t> *pp;
  RBTNode<key_t,val_t> *gp;
  RBTNode<key_t,val_t> *up;
  
  //cout<<"Node:  "<<insertedNode->getKey()<<"  "<<"parent: "<<insertedNode->getParent()->getKey()<<"   ";
  //cout<<"place a: "<<this->root->getKey()<<"::"<<insertedNode->getKey()<<"   ";
  
  while(insertedNode->getKey()!=(this->root)->getKey() && (insertedNode->isRed()) &&(insertedNode->getParent())->isRed())
  {
    pp=insertedNode->getParent();
    gp=(insertedNode->getParent())->getParent();
  //cout<<"place c: "<<this->root->getKey()<<"   ";

  if(pp == gp->getLeftChild())
  {
   up=gp->getRightChild();
     if(up->getKey() != (this->sentinel->getKey()) &&up->isRed())
      {
       pp->setIsRed(false);
       up->setIsRed(false);
       gp->setIsRed(true);
       insertedNode=gp;
      }
     else
     {
       if(insertedNode->getKey()==pp->getRightChild()->getKey())
       {
        rotateLeft(pp);
        insertedNode=pp;
        pp=insertedNode->getParent();
       }
       rotateRight(gp);
     if(pp->isRed() != gp->isRed())
     {
       if(pp->isRed())
       {
        pp->setIsRed(false);
        gp->setIsRed(true);
        }
       else
      {
       pp->setIsRed(true);
        gp->setIsRed(false);
       }
     }
      insertedNode=pp;
     }
   //cout<<"place d: "<<this->root->getKey()<<"   ";

  }
  else
     {
     up=gp->getLeftChild();
     if((up->getKey() != this->sentinel->getKey()) && up->isRed())
      {
      gp->setIsRed(true);
      pp->setIsRed(false);
      up->setIsRed(false);
      insertedNode=pp;
    }
    else
     {
       if(insertedNode->getKey()==pp->getLeftChild()->getKey())
       {
        rotateRight(pp);
        insertedNode=pp;
        pp=insertedNode->getParent();
      }
      rotateLeft(gp);
      
      if(pp->isRed() != gp->isRed())
     {
       if(pp->isRed())
       {
        pp->setIsRed(false);
        gp->setIsRed(true);
        }
       else
      {
       pp->setIsRed(true);
        gp->setIsRed(false);
       }
     }
     insertedNode=gp;
   }
  //cout<<"place e: "<<this->root->getKey()<<"   ";
  }


  }

  RBTNode<key_t,val_t> *ig= dynamic_cast<RBTNode<key_t,val_t>*>(this->root);
 
   ig->setIsRed(false);
  //delete pp;
  //delete gp;
  //delete up;
  //cout<<"place b: "<<this->root->getKey()<<"   ";

}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::transplant(BSTNode<key_t, val_t>* nodeToReplace, BSTNode<key_t, val_t>* replacementNode)
{

  cout << "Calls Transplant "  << endl;

  if (nodeToReplace->getParent() == this->sentinel) {

    (this->root) = replacementNode; 

  }

  else if (nodeToReplace == (nodeToReplace->getParent())->getLeftChild()) {

    nodeToReplace->getParent()->setLeftChild(replacementNode);

  }

  else {

    nodeToReplace->getParent()->setRightChild(replacementNode);

  }

  replacementNode->setParent(nodeToReplace->getParent());

}



template <class key_t, class val_t>
BSTForwardIterator<key_t, val_t> RBTMultimap<key_t, val_t>::remove(const BSTForwardIterator<key_t, val_t>& pos)
{

  BSTForwardIterator  <key_t, val_t> fin (pos.current, this->sentinel); 

  RBTNode <key_t, val_t>*  tempo = (dynamic_cast<RBTNode<key_t, val_t>*>(pos.current));
  
  RBTNode <key_t, val_t>*  y = tempo->getRightChild();

  RBTNode <key_t, val_t>*  x;

  bool color = tempo->isRed() ;

  if (tempo->getLeftChild() == this->sentinel) {

    x = tempo->getRightChild();

    transplant(tempo, tempo->getRightChild());

  }

else if (tempo->getRightChild() == this->sentinel) {

    x = tempo->getLeftChild();

    transplant(tempo, tempo->getLeftChild());

  }

else {

    while (y != this->sentinel and y->getLeftChild() != this->sentinel) {

      y = y->getLeftChild();
    }

    cout << "Y's Key : " << y->getKey() <<endl;

    color = y->isRed() ;

    x = y->getRightChild();

    if (y->getParent() == tempo) {

      x->setParent(y);

    }

    else {

      transplant(y, y->getRightChild());

      y->setRightChild(tempo->getRightChild());

      (y->getRightChild())->setParent(y);

    }

    cout << "Z's Key : " << tempo->getKey() <<endl;


    transplant(tempo, y);

    y->setLeftChild(tempo->getLeftChild());
    (y->getLeftChild())->setParent(y);
    y->setIsRed(tempo->isRed());

  
  }


  if (color == false ) {

    cout << "Calls Delete Fixup "  << endl;

    
    deleteFixup(x);

  }

  this->numItems --;
  //delete tempo;
  return fin;
}

template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::deleteFixup(RBTNode<key_t, val_t>* replacementNode)
{

  RBTNode <key_t, val_t>*  x = replacementNode;
  RBTNode <key_t, val_t>*  w;

  while (x != this->root and x->isRed() == false) {

    if (x == (x->getParent())->getLeftChild()) {

      cout << "Goes Into 'If' Statement "  << endl;


      w = (x->getParent())->getRightChild();

      if (w->isRed()) {

        cout << "Goes Into 'First If inside If' Statement "  << endl;


        w->setIsRed(false);
        (x->getParent())->setIsRed(true);
        rotateLeft(x->getParent());

        w = (x->getParent())->getRightChild();

      }



      if ((w->getLeftChild())->isRed() == false and (w->getRightChild())->isRed() == false ){

        cout << "Goes Into 'Second If inside If' Statement "  << endl;


        w->setIsRed(true);

        x = x->getParent();

      }

      else { 

        cout << "Goes Into 'Else inside If' Statement "  << endl;


        if ((w->getRightChild())->isRed() == false) {

          cout << "Goes Into 'If inside Else inside If' Statement "  << endl;


          (w->getLeftChild())->setIsRed(false);

          w->setIsRed(true);

          rotateRight(w);

          w = (dynamic_cast<RBTNode<key_t, val_t>*>((x->getParent())->getRightChild()));

      }

      w->setIsRed(dynamic_cast<RBTNode<key_t, val_t>*>(x->getParent())->isRed());

      (dynamic_cast<RBTNode<key_t, val_t>*>(x)->getParent())->setIsRed(false);
      (w->getRightChild())->setIsRed(false);

      rotateLeft(x->getParent());

      x = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);

      }
    }


    else {



      cout << "Goes Into 'Else' Statement "  << endl;


      w = (x->getParent())->getLeftChild();

      if (w->isRed()) {

        w->setIsRed(false);
        (x->getParent())->setIsRed(true);
        rotateRight(x->getParent());

        w = (x->getParent())->getLeftChild();

      }

      if ((w->getRightChild())->isRed() == false and (w->getLeftChild())->isRed() == false ){

        w->setIsRed(true);

        x = x->getParent();

      }

      else { 

        if ((w->getLeftChild())->isRed() == false) {

        (w->getRightChild())->setIsRed(false);

        w->setIsRed(true);

        rotateLeft(w);

        w = (dynamic_cast<RBTNode<key_t, val_t>*>((x->getParent())->getLeftChild()));

      }

      w->setIsRed(dynamic_cast<RBTNode<key_t, val_t>*>(x->getParent())->isRed());

      (dynamic_cast<RBTNode<key_t, val_t>*>(x)->getParent())->setIsRed(false);
      (w->getLeftChild())->setIsRed(false);

      rotateRight(x->getParent());

      x = dynamic_cast<RBTNode<key_t, val_t>*>(this->root);
      }

    }
  }

  x->setIsRed(false);

}

    











template <class key_t, class val_t>
void RBTMultimap<key_t, val_t>::printDOT(std::string filename)
{
   using namespace std;
   ofstream fout(filename.c_str());

   long long counter = 1;
   map<RBTNode<key_t, val_t>*, long long> nodeToCounter;
   nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] = counter;
   counter++;

   fout << "digraph RBTMultimap {" << endl;

   fout << "\t node" << nodeToCounter[dynamic_cast<RBTNode<key_t, val_t>* >(this->sentinel)] << " [label=\"nil\", style=filled, color=grey, fontcolor=white];" << endl;

   if(this->root != this->sentinel)
   {
      RBTNode<key_t, val_t>* rt = dynamic_cast<RBTNode<key_t, val_t>* >(this->root);
      if(!nodeToCounter[rt])
      {
	 nodeToCounter[rt] = counter;
	 counter++;
      }
      if(!nodeToCounter[rt->getParent()])
      {
	 nodeToCounter[rt->getParent()] = counter;
	 counter++;
      }
      fout << "\t node" << nodeToCounter[rt] << " -> node" << nodeToCounter[rt->getParent()] << " [constraint=false, tailport=n, headport=s";
      if(rt->getParent() == this->sentinel)
      {
	 fout << ", color=grey];" << endl;
      }
      else
      {
	 //The root's parent is something weird!! Make the arrow orange so it sticks out
	 fout << ", color=orange];" << endl;
      }

      map<RBTNode<key_t, val_t>*, bool> printed;
   
      queue<RBTNode<key_t, val_t>* > q;
      q.push(rt);
      while(!q.empty())
      {
	 RBTNode<key_t, val_t>* node = q.front();
	 q.pop();

	 printed[node] = true;
      
	 //Set up node's appearance
	 if(!nodeToCounter[node])
	 {
	    nodeToCounter[node] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " [label=\"k: " << node->getKey() << "\", style=filled, color=";
	 if(node->isRed())
	 {
	    fout << "red";
	 }
	 else
	 {
	    fout << "black, fontcolor=white";
	 }
	 fout << "];" << endl;

	 //Set up child links
	 //First the left node
	 if(!nodeToCounter[node->getLeftChild()])
	 {
	    nodeToCounter[node->getLeftChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getLeftChild()] << " [tailport=sw";    
	 if(node->getLeftChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getLeftChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getLeftChild());
	 }

	 if(node->getLeftChild() != this->sentinel)
	 {
	    if(node->getLeftChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getLeftChild()->getParent()])
	       {
		  nodeToCounter[node->getLeftChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getLeftChild()] << " -> node" << nodeToCounter[node->getLeftChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }

	 //Now the right node
	 if(!nodeToCounter[node->getRightChild()])
	 {
	    nodeToCounter[node->getRightChild()] = counter;
	    counter++;
	 }
	 fout << "\t node" << nodeToCounter[node] << " -> node" << nodeToCounter[node->getRightChild()] << " [tailport=se";    
	 if(node->getRightChild() == this->sentinel)
	 {
	    fout << ", color=grey";
	 }
	 else if(printed[node->getRightChild()])
	 {
	    fout << ", color=orange";
	 }
	 else
	 {
	    q.push(node->getRightChild());
	 }

	 if(node->getRightChild() != this->sentinel)
	 {
	    if(node->getRightChild()->getParent() == node)
	    {
	       //The child's parent pointer points right back,
	       //so draw the second arrow
	       fout << ", dir=both];" << endl;
	    }
	    else
	    {
	       //The child node's parent pointer is not correct!
	       //Draw it in orange so it sticks out
	       fout << "];" << endl;
	       if(!nodeToCounter[node->getRightChild()->getParent()])
	       {
		  nodeToCounter[node->getRightChild()->getParent()] = counter;
		  counter++;
	       }
	       fout << "\t node" << nodeToCounter[node->getRightChild()] << " -> node" << nodeToCounter[node->getRightChild()->getParent()] << " [tailport=n, color=orange];" << endl;
	    }
	 }
	 else
	 {
	    fout << "];" << endl;
	 }
      }
   }
   fout << "}" << endl;
}

