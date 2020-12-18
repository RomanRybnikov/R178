#ifndef INERATOR_H
#define INERATOR_H
#include <iostream>
#include <list>
#include "Map.h"

namespace Maps {
#define ITERATOR_CHAR 'I'

    class MapPosition {
        int m_Row;
        int m_Col;
    public:
        MapPosition() {
            m_Row = 0;
            m_Col = 0;
        }
        MapPosition(int row, int col) {
            m_Row = row;
            m_Col = col;
        }

        int GetRow() { return m_Row; }
        int GetCol() { return m_Col; }
        int SetRow(int value) { return m_Row = value; }
        int SetCol(int value) { return m_Col = value; }

        friend bool operator == (MapPosition a, MapPosition b);
        friend bool operator != (MapPosition a, MapPosition b);
    };

    class Map;
    class Iterator { // итератор, который двигается по игровому полю
    public:       
        class Listener { // интерфейс наблюдателя за итератором
            friend class Iterator;
            virtual void OnMove(Iterator* iterator) = 0; // происходит, когда двигается итератор (приватное тк оно должно быть доступно только итераторы и вызываться только когда сместился итератор и не доступен из других мест(принцип инкапсуляции))
        };
    private:
        const Maps::Map* map;       // карта, с которой работаем
        int str, col;               // координаты в карте
        std::list<Listener*> m_Listeners;// набор наблюдателей за итератором (что уведомлять после смещения)
        void InvokeListeners();     // вызвать событие что переместились
        std::ostream& Print(std::ostream& os);

    public:
        Iterator(const Maps::Map *map);
        ~Iterator();

        bool Up();
        bool Down();
        bool Left();
        bool Right();

        Iterator& MoveStart();   // встать на вход
        Iterator& MoveEnd();     // вставть на выход

        Cell& Get();
        MapPosition GetMapPos() { return MapPosition(str, col); }
        void SetMapPos(MapPosition pos) { 
            str = pos.GetRow();
            col = pos.GetCol();
        }

        void AddListener(Listener* listener);
        void RemoveListener(Listener* listener);

        friend std::ostream& operator<<(std::ostream& os, Iterator& iterator);
    };
}

#endif /* INERATOR_H */

// итератор всем сообщает о новостях
// player and logplayer слушатели итератора
// player реагирует на сообщ от итератора он берет текущ позицию игрока и тек ячейку из итератора, и применяет ячейку на самого себя(после смещ итератора)
// logplayer реагирует таким образом: итератор сместился => игрок сместился => выводим логи смещения
