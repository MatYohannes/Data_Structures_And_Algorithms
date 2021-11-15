//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** @file LinkedQueue.cpp */

#ifndef LINKEDQUEUE_CPP
#define LINKEDQUEUE_CPP

#include "LinkedQueue.h"  
#include <cassert>
#include <memory>

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{     }  // end default constructor

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{  // Implementation left as an exercise (Exercise 1).
    auto origChainPtr = aQueue.frontPtr;  // Points to nodes in original chain

    // Using shared pointers initializes frontPtr/backPtr to nullPtr
    if (origChainPtr != nullptr)
    {
        // Copy first node
        frontPtr = std::make_shared<Node<ItemType>>();
        frontPtr->setItem(origChainPtr->getItem());

        // Advance original-chain pointer
        origChainPtr = origChainPtr->getNext();

        // Copy remaining nodes
        auto newChainTailPtr = frontPtr;        // Points to last node in new chain
        while (origChainPtr != nullptr)
        {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            // Create a new node containing the next item 
            auto newNodePtr = std::make_shared<Node<ItemType>>(nextItem);

            // Link new node to end of new chain
            newChainTailPtr->setNext(newNodePtr);

            // Advance pointers       
            newChainTailPtr = newChainTailPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }  // end while

        newChainTailPtr->setNext(nullptr);               // Flag end of chain
        backPtr = newChainTailPtr;
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
    //smart pointers will clean-up
    backPtr == nullptr;
    frontPtr == nullptr;
}  // end destructor

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    return backPtr == nullptr;
}  // end isEmpty

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

    // Insert the new node
    if (isEmpty())
        frontPtr = newNodePtr;        // Insertion into empty queue
    else
        backPtr->setNext(newNodePtr); // Insertion into nonempty queue

    backPtr = newNodePtr;            // New node is at back

    return true;
}  // end enqueue

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
    bool result = false;
    if (!isEmpty())
    {
        // Queue is not empty; delete front
        auto nodeToDeletePtr = frontPtr;
        if (frontPtr == backPtr)
        {  // Special case: one node in queue
            backPtr = nullptr;
            frontPtr = nullptr;
        }
        else
        {
            frontPtr = frontPtr->getNext();
        }

        result = true;
    }  // end if

    return result;
}  // end dequeue

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
    if (isEmpty())
        throw PrecondViolatedExcep("getFront() called with empty queue.");

    // Queue is not empty; return front
    return frontPtr->getItem();
}  // end peekFront
#endif
// End of implementation file.