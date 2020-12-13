#ifndef HERO_H
#define HERO_H

#include <fstream>
#include <iostream>

class Hero
{
private:
	int healthPoints;
	int xPos, yPos;	
	int openedChestCounter = 0;
	int keyCounter = 0;
public:
	Hero();
	int GetHealthPoints();
	int GetX();
	int GetY();

	void SetPos(int x, int y);
	void SetHealth(int health);
	void SetOpenedChestCounter(int chest);
	void SetKeyCounter(int key);

	void Damage();
	void Rob();
	void ChangePosition(int x, int y);
	void AddKey();
	void AddOpenedChest();	
	int GetKeyCounter() { return keyCounter; }
	void AddHealtPoints();
	int GetOpenedChestCounter() { return openedChestCounter; }
	friend std::ostream& operator<<(std::ostream& out, const Hero &hero);
};

#endif