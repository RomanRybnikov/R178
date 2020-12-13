#ifndef ITEMOBSERVER_H
#define ITEMOBSERVER_H

#include "Observer.h"

class ItemUseObserver:public Observer
{
public:
	void Update(std::string log);
};

#endif