#include "RandomWolker.h"

using namespace Game;

RandomWolker::RandomWolker() {
	m_Map = 0;
	m_Player = 0;
	m_PlayerPositionIerator = 0;
	m_Iterator = 0;
}
void RandomWolker::Initialize(Maps::Map* map, Player* player, Maps::Iterator* playerPositionIerator)
{
	m_Map = map;
	m_Player = player;
	m_PlayerPositionIerator = playerPositionIerator;
	if (m_Iterator) delete m_Iterator;
	// получаем стартовую позицию
	// инициализируем итератор в этой позиции
	m_Iterator = new Maps::Iterator(m_Map); // доработать конструктор для инициализации в уксзанной точке
}
void RandomWolker::Update() // обновление логики в основном цикле
{
	switch (rand() % 4) {
		case 0: Up(); break;
		case 1: Down(); break;
		case 2: Left(); break;
		case 3: Right(); break;
	}
}
Maps::Iterator* RandomWolker::GetIterator() // итератор позиции врага
{
	return m_Iterator;
}
bool RandomWolker::CheckPosition(Maps::MapPosition pos)
{

}
void RandomWolker::Up() {
	// ограничитель движения
	auto pos = m_Iterator->GetMapPos();
	if (!CheckPosition(pos)) return;
	// сдвигаемся
	m_Iterator->Up();
}
void RandomWolker::Down(){
	m_Iterator->Down();
}
void RandomWolker::Left(){
	m_Iterator->Left();
}
void RandomWolker::Right(){
	m_Iterator->Right();
}