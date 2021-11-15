/** ADT priority queue: ADT sorted list implementation.
@file SL_PriorityQueue.h */
#ifndef SL_PRIORITY_QUEUE
#define SL_PRIORITY_QUEUE
#include "PriorityQueueInterface.h"
#include "LinkedSortedList.h"
#include "PrecondViolatedExcep.h"
template < class ItemType >
class SL_PriorityQueue :public PriorityQueueInterface < ItemType >
{
private:
	LinkedSortedList < ItemType >* slistPtr;	// Pointer to sorted list of
												// items in the priority queue
public:
	SL_PriorityQueue();
	//SL_PriorityQueue(const SL_PriorityQueue & pq);

	virtual ~SL_PriorityQueue();
	bool isEmpty() const;

	bool add(const ItemType& newEntry);

	bool remove();

	/** @throw PrecondViolatedExcep if priority queue is empty. */
	ItemType peek() const;// throw (PrecondViolatedExcep);
};				// end SL_PriorityQueue

#include "SL_PriorityQueue.cpp"
#endif