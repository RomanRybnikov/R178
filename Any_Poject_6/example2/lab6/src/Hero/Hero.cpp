#include "Hero.h"

Hero::Hero()
{
	this->xPos = 0;
	this->yPos = 0;
	this->healthPoints = 5;
}

void Hero::Damage()
{
	if(healthPoints > 0)
		this->healthPoints--;
}

void Hero::Rob()
{
	if (keyCounter > 0)
		keyCounter--;
}

void Hero::ChangePosition(int x, int y)
{
	this->xPos += x;
	this->yPos += y;
}

void Hero::AddKey()
{
	keyCounter++;
}

void Hero::AddOpenedChest()
{
	openedChestCounter++;
}

void Hero::AddHealtPoints()
{
	healthPoints++;
}

int Hero::GetHealthPoints()
{
	return healthPoints;
}

int Hero::GetX()
{
	return xPos;
}

int Hero::GetY()
{
	return yPos;

}

void Hero::SetPos(int x, int y)
{
	this->xPos = x;
	this->yPos = y;
}

void Hero::SetHealth(int health)
{
	this->healthPoints = health;
}

void Hero::SetOpenedChestCounter(int chest)
{
	this->openedChestCounter = chest;
}

void Hero::SetKeyCounter(int key)
{
	this->keyCounter = key;
}

std::ostream& operator<<(std::ostream& out, const Hero &hero)
{
	out << "Info about hero: "
		<< hero.openedChestCounter << " OpenedChests, "
		<< hero.keyCounter << " Keys, "
		<< hero.healthPoints << " Health."
		<< "Hero position: "
		<< "X: " << hero.xPos
		<< ", Y: " << hero.yPos;
	return out;
}