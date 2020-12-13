#ifndef SAVEOBSERVER_H
#define SAVEOBSERVER_H

#include "Observer.h"

class SaveObserver:public Observer
{
public:
	void Update(std::string log);
};

#endif