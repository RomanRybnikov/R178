#pragma once
#include "ICommand.h"
#include "Game.h"

class UpCommand :public ICommand {
	Game* m_Game;
public:
	UpCommand(Game* game) {
		m_Game = game;
	}

	virtual void Execute() {
		m_Game->Up();
	}
	virtual std::string ToString() {
		return "UP";
	}
};

class DownCommand :public ICommand {
	Game* m_Game;
public:
	DownCommand(Game* game) {
		m_Game = game;
	}

	virtual void Execute() {
		m_Game->Down();
	}
	virtual std::string ToString() {
		return "DOWN";
	}
};

class LeftCommand :public ICommand {
	Game* m_Game;
public:
	LeftCommand(Game* game) {
		m_Game = game;
	}

	virtual void Execute() {
		m_Game->Left();
	}
	virtual std::string ToString() {
		return "LEFT";
	}
};

class RightCommand :public ICommand {
	Game* m_Game;
public:
	RightCommand(Game* game) {
		m_Game = game;
	}

	virtual void Execute() {
		m_Game->Right();
	}
	virtual std::string ToString() {
		return "RIGHT";
	}
};

class ExitCommand :public ICommand {
	Game* m_Game;
public:
	ExitCommand(Game* game) {
		m_Game = game;
	}

	virtual void Execute() {
		m_Game->Exit();
	}
	virtual std::string ToString() {
		return "EXIT";
	}
};

class ReplayCommand :public ICommand {
	Game* m_Game;
public:
	ReplayCommand(Game* game) {
		m_Game = game;
	}

	virtual void Execute() {
		m_Game->Replay();
	}
	virtual std::string ToString() {
		return "REPLAY";
	}
};
