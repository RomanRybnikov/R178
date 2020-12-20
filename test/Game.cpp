#include "Game.h"
#include "SaveStream.h"
#include "CirclePlayerLogicFactory.h"
#include "RandomPlayerLogicFactory.h"
#define PATH "/Users/anastasiasergienkova/Desktop/test_6/test_6/test_6/save.txt"
Game::Game(Field* field, IEnemy *enemy) {
	m_Field = field;
	m_Player = 0;
	m_Enemy = enemy;
	m_PlayerLoger = 0;
	Replay();
}

Game::~Game() {
	delete m_PlayerLoger;
	delete m_Player;
}

void Game::Replay() {
	delete m_PlayerLoger;
	delete m_Player;
	m_Player = new Player(m_Field);
	m_PlayerLoger = new PlayerLoger(m_Player);
	
	if (rand() % 2) m_Field->SetLogicFactory(new CirclePlayerLogicFactory());
	else m_Field->SetLogicFactory(new RandomPlayerLogicFactory());

	m_IsPlaying = true;
	m_IsWin = false;

	// инициализация врага
	m_Enemy->Initialize(m_Field, m_Player, true);
}

void Game::Up() {
	m_Player->GetIterator().Up();
}

void Game::Down() {
	m_Player->GetIterator().Down();
}

void Game::Left() {
	m_Player->GetIterator().Left();
}

void Game::Right() {
	m_Player->GetIterator().Right();
}

bool Game::IsPlaying() {
	return m_IsPlaying;
}

void Game::Exit() {
	m_IsPlaying = false;
}

void Game::Update() {
	// обновление игрока
	m_Player->Update();
	// обновление врага
	m_Enemy->Update();

	// если дошли до конца то выход
	if (m_Player->GetIterator().Value().GetType() == CageType::OUT) {
		if (m_Player->GetScores() >= 200) {
			m_IsWin = true;
			m_IsPlaying = false;
			return;
		}
		else {
			std::cout << "NEED 200 SCORES..." << std::endl;
			system("PAUSE");
		}
	}

	// отработка смерти
	if (m_Player->GetHP() <= 0) {
		m_IsWin = false;
		m_IsPlaying = false;
		return;
	}
}

void Game::Draw() {
	// вывод параметров игрока
	std::cout << "HP:\t" << m_Player->GetHP() << std::endl;
	std::cout << "SCORES:\t" << m_Player ->GetScores() << std::endl;

	// вывод поля
	for (int i = 0; i < m_Field->GetRow(); i++) {
		for (int j = 0; j < m_Field->GetCol(); j++) {
			// выводим крест, если выводим позицию итератора, и выводим поле, в противном случае
			if (&m_Player->GetIterator().Value() == &m_Field->GetCage(i, j)) std::cout << 'X';
			else if (m_Enemy->GetRow() == i && m_Enemy->GetCol() == j) m_Enemy->Draw(std::cout);
			else std::cout << m_Field->GetCage(i, j);
			// провел в любом случае
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
}

bool Game::IsWin() {
	return m_IsWin;
}

void Game::Save(std::string fileName) {
	SaveStream ss(PATH, true);
	ss.GetOStream() << m_IsPlaying << ' ' << m_IsWin << std::endl;
	m_Player->Save(ss.GetOStream());
	m_Field->Save(ss.GetOStream());
	m_Enemy->Save(ss.GetOStream());
}

void Game::Load(std::string fileName) {
	SaveStream ss(PATH, false);
	ss.GetIStream() >> m_IsPlaying;
	ss.GetIStream() >> m_IsWin;
	m_Player->Load(ss.GetIStream());
	m_Field->Load(ss.GetIStream());
	m_Enemy = IEnemy::Load(ss.GetIStream());
	m_Enemy->Initialize(m_Field, m_Player, false);
}
