#include <iostream>
#include <time.h>
#include "Game.h"
#include "CommandExecutor.h"
#include "Commands.h"
#include "Enemy.h"
#include "EnemyBehaviours.h"

using namespace std;
#define PATH "/Users/anastasiasergienkova/Desktop/test_6/test_6/test_6/save.txt"

void MainCycle(Game* g);

int main() {
	srand(time(0)); // чтоды избавиться от псевдослучайности

	// ввод размера поля
	int row, col;
	std::cout << "Ent row: ";
	std::cin >> row;
	std::cout << "Ent col: ";
	std::cin >> col;

	// выбираем тип врага
	auto enemy = new Enemy<EnemyKillBehaviour>();
	//auto enemy = new Enemy<EnemyScoresBehaviour>();
	//auto enemy = new Enemy<EnemyTeleportBehaviour>();
	// создаем игру
	Game g(Field::GetInstance(row, col), enemy);
	// запускаем игру
	MainCycle(&g);

	cout << "GAME OVER!" << endl;	
	system("PAUSE");
	return 0;
}

void MainCycle(Game* game) {
	char c; // код команды
	CommandExecutor executor;

	// предварительно рисуем ситуацию
	system("CLS");
	game->Draw();
	cout << "HISTORY: " << executor << endl;

	// основной игровой цикл
	while (game->IsPlaying()) {
		// ввод кода команды
		cout << "enter WASD commands for move..." << endl;
		// ввод кода команды
		//c = cin.get();
		//cin.clear();
		cin >> c;


		// обработка кода команды
		switch (c) {
		case 'w':	executor.Execute(new UpCommand(game));		break;
		case 's':	executor.Execute(new DownCommand(game));	break;
		case 'a':	executor.Execute(new LeftCommand(game));	break;
		case 'd':	executor.Execute(new RightCommand(game));	break;
		case 27:	executor.Execute(new ExitCommand(game));	break;
		case 'r':	executor.Execute(new ReplayCommand(game));	break;
		case 'o':	game->Save(PATH); break;
		case 'p':	
			try {
				game->Load(PATH);
			}
			catch (const char* str) {
				cout << "ERROR: " << str << std::endl;
                cin >> c;
			}
			catch (...) {
				cout << "UNKNOWN ERROR" << std::endl;
                cin >> c;
			}
			break;
		default: cout << "ERROR KEY CODE" << endl;
		}

		// обновление игрового процесса
		game->Update();

		// вывод текущей ситуации
		system("CLS");
		game->Draw();
		cout << "HISTORY: " << executor << endl;
	}

	// выводим причину конца игры
	if (game->IsWin()) cout << "WIN!" << endl;
	else  cout << "DEAD!" << endl;
}
