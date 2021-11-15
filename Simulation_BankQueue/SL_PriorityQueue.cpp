/** ADT priority queue: ADT sorted list implementation.
@file SL_PriorityQueue.cpp */
#ifndef _PRIORITY_QUEUE_CPP
#define _PRIORITY_QUEUE_CPP
#include "SL_PriorityQueue.h"

//  LinkedSortedList < ItemType > *slistPtr;	// Pointer to sorted list of
							// items in the priority queue
template < class ItemType >
SL_PriorityQueue<ItemType>::SL_PriorityQueue()
{
	slistPtr = new LinkedSortedList<ItemType>();
}
//SL_PriorityQueue::SL_PriorityQueue (const SL_PriorityQueue & pq);

template < class ItemType >
SL_PriorityQueue<ItemType>::~SL_PriorityQueue()
{
	delete slistPtr;
	slistPtr = nullptr;
}

template < class ItemType >
bool SL_PriorityQueue<ItemType>::isEmpty() const
{
	return slistPtr->isEmpty();
}

template < class ItemType >
bool SL_PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
	slistPtr->insertSorted(newEntry);
	return true;
}

template < class ItemType >
bool SL_PriorityQueue<ItemType>::remove()
{
	return slistPtr->remove(1);
}

/** @throw PrecondViolatedExcep if priority queue is empty. */
template < class ItemType >
ItemType SL_PriorityQueue<ItemType>::peek() const // throw (PrecondViolatedExcep)
{
	return slistPtr->getEntry(1);
}


#endif