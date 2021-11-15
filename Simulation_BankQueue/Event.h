#ifndef EVENT_H
#define EVENT_H

class Event
{
private:

	char type; // Type will be arrival A or departure D
	int time; // Time of arrival to the queue
	int length; // Length of transaction

public:

	// Constructors

	// Constructor for class with no parameter
	// @param : NONE
	// @post : constructs an empty Event with type = 'A', time = 0, and length = 0
	Event();

	// Constructor for class with two parameters, time and length
	// @param : inputTime and inputLength are greater than 0
	// @post : constuctor Event with type = 'A', time = inputTime, and length = inputLength
	Event(int inputTime, int inputLength);
	
	// Constructor for class with three parameters, type, time and length
	// @param : type is either 'A' or 'D', inputTime and inputLength are greater than 0
	// @post : constructor Event with type = inputType, time = inputTime, and length = inputLength
	Event(char inputType, int inputTime, int inputLength);
	
	// Destructor
	~Event();

	//Getters
	char getType() const; // Get type
	int getTime() const; // Get time
	int getLength() const; // Get length

	//Setters
	int setType(char inputType); // Set type
	int setTime(int inputTime); // Set time
	int setLength(int inputLength); // Set length

	// Operators
	// Operators need for comparing Event object when sorting in the PriorityQueue
	// which uses a LinkedSortedList.
	// When comparing objects, the time is the only variable needed
	// Including the type and the length in the operator will prevent the 
	// Events from being sorted correctly.
	bool operator == (const Event& e) const;
	bool operator != (const Event& e) const;
	bool operator >= (const Event& e) const;
	bool operator <= (const Event& e) const;
	bool operator > (const Event& e) const;
	bool operator < (const Event& e) const;
};

#endif //!EVENT_H