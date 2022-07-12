//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-4.
    @file LinkedStack.cpp */

#include <cassert>        // For assert
#include "LinkedStack.h"  // Header file

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}  // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
   // Point to nodes in original chain
   Node<ItemType>* origChainPtr = aStack.topPtr;
   
   if (origChainPtr == nullptr)
      topPtr = nullptr;  // Original stack is empty
   else
   {
      // Copy first node
      topPtr = new Node<ItemType>();
      topPtr->setItem(origChainPtr->getItem());
      
      // Point to first node in new chain
      Node<ItemType>* newChainPtr = topPtr;
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      // Copy remaining nodes
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);           // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	// Pop until stack is empty
	while (!isEmpty())
		pop();
}  // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);				
	topPtr = newNodePtr;
   newNodePtr = nullptr;
      
	return true;
}  // end push

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
      // Stack is not empty; delete top
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
		
		// Return deleted node to system
      nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
            
      result = true;
	}  // end if
   
	return result;	
}  // end pop

template<class ItemType>	
ItemType LinkedStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition during debugging
   
	// Stack is not empty; return top
	return topPtr->getItem();
}  // end getTop

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
   return topPtr == nullptr;
}  // end isEmpty

////////////////////////////////
/// Added during lab 10/26/21///
////////////////////////////////

/// function that searches the stack for a value
template<class ItemType>
bool LinkedStack<ItemType>::contains(ItemType anEntry)
{
   LinkedStack<ItemType> tempStack; // temporarily holds values
   bool contains = false; // stores a bool value for returning later

   while(this->peek()!=nullptr)
   {
      if(anEntry != this->peek())
      {
         tempStack.push(this->peek());
         this.pop();
      }
      else
         contains = true;
   }
   while(tempStack.topPtr!=nullptr)
   {
      this.push(tempStack.peek());
      tempStack.pop();
   }
   return contains; // holding the bool value
}  // end contains

/// function that tests if two stacks are identical
template<class ItemType>
bool LinkedStack<ItemType>::operator ==(LinkedStack<ItemType> comp)
{
   LinkedStack<ItemType> temp1;
   LinkedStack<ItemType> temp2;
   bool equal;

   while(this->peek()!=nullptr)
   {
      if(this->peek() == comp.peek())
      {
         temp1.push(this->peek());
         temp2.push(comp.peek());
         this.pop();
         comp.pop();
         equal = true;
      }
      else
         equal = false;
   }

   while(temp1.topPtr!=nullptr)
   {
      this.push(temp1.peek());
      comp.push(temp2.peek());
      temp1.pop();
      temp2.pop();
   }

   return equal;
}

/// function that tests if two stacks are not identical
template<class ItemType>
bool LinkedStack<ItemType>::operator !=(LinkedStack<ItemType> comp)
{
   LinkedStack<ItemType> temp1;
   LinkedStack<ItemType> temp2;
   bool notEqual;

   while(this->peek()!=nullptr)
   {
      if(this->peek() != comp.peek())
      {
         temp1.push(this->peek());
         temp2.push(comp.peek());
         this.pop();
         comp.pop();
         notEqual = true;
      }
      else
         notEqual = false;
   }

   while(temp1.topPtr!=nullptr)
   {
      this.push(temp1.peek());
      comp.push(temp2.peek());
      temp1.pop();
      temp2.pop();
   }
   
   return notEqual;
}
// End of implementation file.