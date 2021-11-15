#include <iostream>
#include <fstream>
#include "SL_PriorityQueue.h"

#include "LinkedQueue.h"
#include "Event.h"

class Simulation
{
private:
	bool tellerAvailable = true;
	int currentTime = 0;
	string newArrivalEvent;
	QueueInterface<Event>* bankQueue = new LinkedQueue<Event>(); // queue created when customer approaches teller
	PriorityQueueInterface<Event>* eventListPQueue = new SL_PriorityQueue<Event>(); // store uncoming events from file

	// variables below are to calculate the average wait time
	// Formula : (sumDepartureTime - sumProcessingTime - sumArrivalTime) / eventCount
	int sumDepartureTime = 0;
	int sumProcessingTime = 0;
	int sumArrivalTime = 0;
	int eventCount = 0;
	float waitTime;

public:

	// Creates a simulation by following steps :
	// 1. Read file parameter and store data in a Priority Queue. Priority Queue is used to maintain order of the
	//	  data type, Event (object class) in a queue.
	// 2. String that is read will be parsed and have the data stored as integers in the Event object.
	// 	  Sring will be expected to be in the following format
	// 3. While the Priority Queue is not empty, the Events will be run through the processArrival function if the
	//    Event data type 'Type' meets the condition.
	// 4. If the condition is not meet, the Events will be run through the processDepature function.
	// @param : string of filename
	// @post : return print of order of arrival, departure, individual waittime with Event occurs after expected time,
	//         and average waitime
	void simulate(string filename)
	{
		ifstream file(filename); // reading string of filename
		int time; // to 
		int duration; 

		while (file.peek() != EOF) // reading file from parameter 
		{
			getline(file, newArrivalEvent);

			// Use a delimiter to separate the the arrivalTime and the durationLength
			string spaceDelimiter = " ";
			// parse string upto the delimiter to get the arrivalTime
			time = stoi(newArrivalEvent.substr(0, newArrivalEvent.find(spaceDelimiter))); // stores arrivalTime as an integer from string
			// find the position of the delimiter and add 1 to get the start of the durationLength
			duration = stoi(newArrivalEvent.substr(newArrivalEvent.find(spaceDelimiter) + 1)); // stores wait as an integer from string

			Event curentEvent(time, duration); // store arrivalTime and wait duartion in class
			eventListPQueue->add(curentEvent); // adding Event to the event queue
		}

		while (!eventListPQueue->isEmpty())
		{
			Event newEvent = eventListPQueue->peek();
			currentTime = newEvent.getTime();
			
			if (newEvent.getType() == 'A')
			{
				processArrival(newEvent, eventListPQueue, bankQueue);
			}
			else
			{
				processDeparture(newEvent, eventListPQueue, bankQueue);
			}
		}

		cout << "new event D " << currentTime << endl;

		waitTime = (float)(sumDepartureTime - sumProcessingTime - sumArrivalTime) / eventCount; // averaging the wait time
		cout << "Average wait time was " << waitTime << endl;
	}

	// Processes the Event that is in the parameter
	// If the bankQueue is empty and the teller is available, take the currentTime and add the Event length/duration to find
	// when the Event ends.
	// Update the Event type from 'A' (Arrival), to 'D' (Depature) to indict the Event has been processed.
	// Update the status of teller to not available.
	// If the bankQueue is not empty and the teller is not available, then have Event added to bankQueue.
	// @param : arrivalEvent is event to prcoess, eventListPQueue stores the events, bankQueue stores the wait queue
	// @post : display the addition of the Event to screen, showing Event member variables. Collect the arrivalTime, ProcessingTime,
	//         and the count of number of Events that occur for calculating the average waitTime
	void processArrival(Event arrivalEvent, PriorityQueueInterface<Event>* eventListPQueue, QueueInterface<Event>* bankQueue)
	{
		eventListPQueue->remove();
		Event customer = arrivalEvent;

		if (bankQueue->isEmpty() && tellerAvailable)
		{
			int departureTime = currentTime + customer.getLength();
			Event newDepartureEvent('D', departureTime, 0);
			eventListPQueue->add(newDepartureEvent);
			tellerAvailable = false;
		}
		else
		{
			bankQueue->enqueue(customer);
		}
		cout << "new event : "<< customer.getType() << " " << customer.getTime() << " " << customer.getLength() << endl;

		eventCount++; // count how many customers arrived. Will be used for averaging the wait time
		sumArrivalTime += customer.getTime(); // summing to calculate the average wait time
		sumProcessingTime += customer.getLength(); // summing to calculate the average wait time
	}

	// Processes the Event that is in the parameter
	// If the bankQueue is not empty, look at the front and remove from the queue to update the 'Type' status from 'A' (Arrival) to
	// to 'D' (Depature).
	// When updating, new Event is created from the depature, the 'Type' is changed to 'D', the duartion/length is added to the currentTime
	// , and the duration is changed to 0. The Event is added back to the event Priority Queue.
	// When it is time for Event to depart, the Event is displayed on screen.
	// @param : arrivalEvent is event to prcoess, eventListPQueue stores the events, bankQueue stores the wait queue
	// @post : If the currentTime (which runs and takes into account the wait time of the Events ahead in the queue) is greater than the Events 'Time'
	//         then a comment that the Event was delayed by the difference of the arrivalTimeand the currentTime.
	void processDeparture(Event arrivalEvent, PriorityQueueInterface<Event>* eventListPQueue, QueueInterface<Event>* bankQueue)
	{
		eventListPQueue->remove();

		if (!bankQueue->isEmpty())
		{
			Event customer = bankQueue->peekFront();
			bankQueue->dequeue();
			int departureTime = currentTime + customer.getLength();
			Event newDepartureEvent('D', departureTime, 0);
			eventListPQueue->add(newDepartureEvent);

			cout << "new event D " << currentTime << endl;

			if (currentTime > customer.getTime())
			{
				cout << "Customer at time " << customer.getTime() << " had to wait " << (currentTime - customer.getTime()) << endl;
			}
		}
		else
		{
			tellerAvailable = true;
		}
		sumDepartureTime += currentTime;
	}
};

