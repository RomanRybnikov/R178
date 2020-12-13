#include "GameInfo.h"

void GameInfo::print()
{
	std::cout << "TPEnemyPos: X: " << TPEnemyPos.first << ", Y: " << TPEnemyPos.second << '\n';
	std::cout << "robEnemyPos: X: " << robEnemyPos.first << ", Y: " << robEnemyPos.second << '\n';
	std::cout << "beatEnemyPos: X: " << beatEnemyPos.first << ", Y: " << beatEnemyPos.second << '\n';
	std::cout << "heroPos: X: " << heroPos.first << ", Y: " << heroPos.second << '\n';
	std::cout << "heroHealth: " << heroHealth << '\n';
	std::cout << "heroKeys: " << heroKeys << '\n';
	std::cout << "heroOpenedChests: " << heroOpenedChests << '\n';
	std::cout << "heartCount: " << heartCount << '\n';
	std::cout << "heartsPos: " << '\n';
	for (int i = 0; i < heartCount; i++)
		std::cout << "\tX: " << heartsPos[i].first << "Y: " << heartsPos[i].second << '\n';
	

	std::cout << "keysCount: " << keysCount << '\n';
	std::cout << "keysPos: " << '\n';
	for (int i = 0; i < keysCount; i++)
		std::cout << "\tX: " << keysPos[i].first << "Y: " << keysPos[i].second << '\n';

	std::cout << "heartCount: " << chestsCount << '\n';
	std::cout << "chestsPos: " << '\n';
	for (int i = 0; i < chestsCount; i++)
		std::cout << "\tX: " << chestsPos[i].first << "Y: " << chestsPos[i].second << '\n';

	std::cout << "heartCount: " << openedChestsCount << '\n';
	std::cout << "openedChestsPos: " << '\n';
	for (int i = 0; i < openedChestsCount; i++)
		std::cout << "\tX: " << openedChestsPos[i].first << "Y: " << openedChestsPos[i].second << '\n';
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			std::cout << field[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
