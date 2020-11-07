#ifndef CELL_H_
#define CELL_H_

#include <string>
#include <iostream>
#include "CellTypes.h"

namespace Game {
    class Player;
}

namespace Maps {

#define EMPTY_CELL_CHAR ' '
#define START_CELL_CHAR 'S'
#define END_CELL_CHAR 'E'

    class Cell {
    public:
        class ILogic { // интерфейс логики ячейки
        public:
            virtual void ApplyPlayer(Game::Player* player) = 0;       // применить логику к игроку
            virtual std::ostream& Output(std::ostream& os) = 0; // выводит логику в поток
        };
    private:
        CellTypes m_Type;
        bool m_Pass;     
        ILogic* m_Logic;

    public:

        Cell();
        ~Cell();
        CellTypes GetType();
        void ReType(CellTypes NewType);

        ILogic* GetLogic();
        ILogic* SetLogic(ILogic* newLogic);
        void ApplyPlayer(Game::Player* player); // функция взаимодействия ячейки с игроком

        friend std::ostream& operator << (std::ostream& os, Cell& cell);
    };
}

#endif

