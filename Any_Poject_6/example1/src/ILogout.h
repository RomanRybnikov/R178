#pragma once
#include "enum.h"

class ILogOut {
public:
	virtual void createSubDict() = 0;
	virtual void subscribe(ItemType) = 0;
	virtual ~ILogOut() {};
};