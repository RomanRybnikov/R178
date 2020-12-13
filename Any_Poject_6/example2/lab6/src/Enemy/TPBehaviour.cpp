#include "TPBehaviour.h"

void TPBehaviour::Action(Hero& hero)
{
	hero.ChangePosition(-hero.GetX(), -hero.GetY());
}
