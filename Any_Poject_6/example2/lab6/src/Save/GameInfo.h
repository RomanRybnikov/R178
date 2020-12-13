#ifndef GAMEINFO_H
#define GAMEINFO_H
#define FIELD_HEIGHT 11
#define FIELD_WIDTH 11

#include <map>
#include <vector>
#include <iostream>

class GameInfo
{
public:
	std::pair<int, int> TPEnemyPos;
	std::pair<int, int> robEnemyPos;
	std::pair<int, int> beatEnemyPos;
	int heroHealth;
	int heroOpenedChests;
	int heroKeys;
	std::pair<int, int> heroPos;
	int heartCount;
	std::vector<std::pair<int, int>> heartsPos;
	int keysCount;
	std::vector<std::pair<int, int>> keysPos;
	int chestsCount;
	std::vector<std::pair<int, int>> chestsPos;
	int openedChestsCount;
	std::vector<std::pair<int, int>> openedChestsPos;
	int field[FIELD_WIDTH][FIELD_HEIGHT];
	void print();
};

#endif