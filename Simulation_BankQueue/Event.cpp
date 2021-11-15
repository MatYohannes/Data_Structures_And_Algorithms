#include "Event.h"


// Constructors

// Constructor for class with no parameter
// @param : NONE
// @post : constructs an empty Event with type = 'A', time = 0, and length = 0
Event::Event(void) : type('A'), time(0), length(0)
{
}

// Constructor for class with two parameters, time and length
// @param : inputTime and inputLength are greater than 0
// @post : constuctor Event with type = 'A', time = inputTime, and length = inputLength
Event::Event(int inputTime, int inputLength) : type('A')
{
	if (inputTime > 0)
	{
		time = inputTime;
	}
	else
	{
		time = 0;
	}

	if (inputLength > 0)
	{
		length = inputLength;
	}
	else
	{
		length = 0;
	}

}

// Constructor for class with three parameters, type, time and length
// @param : type is either 'A' or 'D', inputTime and inputLength are greater than 0
// @post : constructor Event with type = inputType, time = inputTime, and length = inputLength
Event::Event(char inputType, int inputTime, int inputLength)
{
	if (inputType != 'A' && inputType != 'D')
	{
		inputType = 'A';
	}

	if (inputTime > 0)
	{
		time = inputTime;
	}
	else
	{
		time = 0;
	}

	if (inputLength > 0)
	{
		length = inputLength;
	}
	else
	{
		length = 0;
	}
}

// Destructor
Event::~Event()
{
}

//Getters

char Event::getType() const
{
	return type;
}

int Event::getTime() const
{
	return time;
}

int Event::getLength() const
{
	return length;
}

//Setters

int Event::setType(char inputType)
{
	if (inputType != 'A' && inputType != 'D') 
	{
		return 1; 
	}

	type = inputType;
	return 0;
}

int Event::setTime(int inputTime)
{
	if (inputTime < 0) 
	{
		return 1; 
	}
	time = inputTime;
	return 0; 
}

int Event::setLength(int inputLength)
{
	if (inputLength < 0) 
	{
		return 1;
	}
	length = inputLength;
	return 0;
}

// Operators
// Operators need for comparing Event object when sorting in the PriorityQueue
// which uses a LinkedSortedList.
// When comparing objects, the time is the only variable needed
// Including the type and the length in the operator will prevent the 
// Events from being sorted correctly.
bool Event::operator == (const Event& e) const
{
	if (time == e.getTime())
	{
		return true;
	}

	return false;
}

bool Event::operator != (const Event& e) const
{
	if (time != e.getTime())
	{
		return true;
	}

	return false;
}

bool Event::operator >= (const Event& e) const
{
	if (time >= e.getTime())
	{
		return true;
	}

	return false;
}

bool Event::operator <= (const Event& e) const
{
	if (time <= e.getTime())
	{
		return true;
	}

	return false;
}

bool Event::operator > (const Event& e) const
{
	if (time > e.getTime())
	{
		return true;
	}

	return false;
}

bool Event::operator < (const Event& e) const
{
	if (time < e.getTime())
	{
		return true;
	}

	return false;
}



