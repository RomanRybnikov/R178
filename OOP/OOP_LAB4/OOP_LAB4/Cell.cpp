#include "Cell.h"

using namespace Maps;

Cell::Cell() {
    this->m_Type = REGULAR;
    this->m_Pass = true; 
    this->m_Logic = 0;
}
Cell::~Cell() {
}

CellTypes Cell::GetType() {
    return m_Type;
}
void Cell::ReType(CellTypes NewType) {
    m_Type = NewType;
}

namespace Maps {
    std::ostream& operator << (std::ostream& os, Cell& cell)
    {
        switch (cell.m_Type) {
        case CellTypes::START:
            return os << START_CELL_CHAR;
        case CellTypes::END:
            return os << END_CELL_CHAR;
        }
        if (cell.m_Logic == 0)
            return os << EMPTY_CELL_CHAR;
        return cell.m_Logic->Output(os);
    }
}

Cell::ILogic* Cell::GetLogic() {
    return m_Logic;
}
Cell::ILogic* Cell::SetLogic(ILogic* newLogic) {
    //delete m_Logic;
    m_Logic = newLogic;
    return m_Logic;
}
void Cell::ApplyPlayer(Game::Player* player) // функция взаимодействия ячейки с игроком
{
    if (m_Logic == 0) return;
    m_Logic->ApplyPlayer(player);
}
void Cell::SaveLogic(Cell& cell, std::ostream& os)
{
    auto logic = cell.GetLogic();
    if (logic) logic->Output(os);
    else os << "_";       
    os << ' ';
}

