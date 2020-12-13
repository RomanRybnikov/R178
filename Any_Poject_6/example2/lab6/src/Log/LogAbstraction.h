#ifndef LOGABSTRACTION_H
#define LOGABSTRACTION_H

#include "Observers/HeroDigObserver.h"
#include "Observers/HeroGetItemObserver.h"
#include "Observers/HeroMovingObserver.h"
#include "Observers/ItemTakeObserver.h"
#include "Observers/ItemUseObserver.h"
#include "Observers/ItemSpawnObserver.h"
#include "Observers/EnemyMovedObserver.h"
#include "Observers/EnemySpawnedObserver.h"
#include "Observers/EnemyHeroMeetObserver.h"
#include "Observers//SaveObserver.h"
#include "Observers/LoadSaveObserver.h"

class LogAbstraction
{
private:
	Observer* currentObserver;

public:
	LogAbstraction(Observer* observer) : currentObserver(observer){}
	virtual void PrintLog(std::string log) const;
	virtual ~LogAbstraction() {}
};

#endif