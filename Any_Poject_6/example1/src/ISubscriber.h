#pragma once
#include <string>
#include <ostream>

class ISubscriber {
public:
	virtual void printInfo(std::ostream&) = 0;
	virtual ~ISubscriber() {};
};