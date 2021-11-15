/** ADT priority queue: ADT sorted list implementation.
@file PriorityQueueInterface.h */
#ifndef _PRIORITY_QUEUE_INTERFACE
#define _PRIORITY_QUEUE_INTERFACE
//#include "PrecondViolatedExcep.h"
template < class ItemType >
class PriorityQueueInterface
{
public:
	virtual bool isEmpty() const = 0;

	virtual bool add(const ItemType& newEntry) = 0;

	virtual bool remove() = 0;

	/** @throw PrecondViolatedExcep if priority queue is empty. */
	virtual ItemType peek() const = 0;
};				// end PriorityQueueInterface

#endif