#include "Iterator.h"
#include "Map.h"
#include <iostream>

using namespace Maps;

bool Maps::operator == (MapPosition& a, MapPosition& b) {
    return a.m_Row == b.m_Row && a.m_Col == b.m_Col;
}
bool Maps::operator != (MapPosition& a, MapPosition& b) {
    return !(a == b);
}

Iterator::Iterator(const Map* map) {
    this->map = map;
    this->str = 0;
    this->col = 0;
}

Iterator::~Iterator() {
}

Cell& Iterator::Get() {
    return map->ArrMap[str][col];
}

Iterator& Iterator::MoveStart()        // итератор на вход карты
{
    str = 0;
    col = 0;
    return *this;
}

bool Iterator::Up() {
    if (str <= 0){
        return false;
    }
    --str;
    InvokeListeners();
    return true;
}
bool Iterator::Down() {
    if (str >= map->width-1) {
        return false;
    }
    ++str;
    InvokeListeners();
    return true;
}
bool Iterator::Left() {
    if (col <= 0) {
        return false;
    }
    --col;
    InvokeListeners();
    return true;
}
bool Iterator::Right() {
    if (col >= map->height-1){
        return false;
    }
    ++col;
    InvokeListeners();
    return true;
}

std::ostream& Iterator::Print(std::ostream& os)
{
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            if (i == str && j == col){
                os << ITERATOR_CHAR;
            }
            else {
                os << map->ArrMap[i][j];
            }
            os << " ";
        }
        os << std::endl;
    }

    return os;
}

namespace Maps {
    std::ostream& operator<<(std::ostream& os, Iterator& iterator)
    {
        return iterator.Print(os);
    }
}

void Iterator::InvokeListeners()     // вызвать событие что переместились (уведомление всех наблюдателе о том, что мы переместились)
{
    for (std::list<Listener*>::iterator i = m_Listeners.begin(); i != m_Listeners.end(); ++i) {
        (*i)->OnMove(this);
    }
}

void Iterator::AddListener(Listener* listener)
{
    m_Listeners.push_back(listener);
}
void Iterator::RemoveListener(Listener* listener)
{
    m_Listeners.remove(listener);
}