#include "Game.h"
#include <iostream>

Game::Game (int str, int col){
    Maps::Map map = *Map::GetInstance(str, col);
    
     Iterator m_Iterator(&map);   // итератор позиции игрока
     Player m_Player(&m_Iterator);       // игрок (игровая ситуация)
     LogPlayer playerLog(&m_Player);
     
}


void Game::Game::Update(){
    // очистка экрана //
    std::cout << *m_Player << std::endl;
    
    if (m_Iterator->Get().GetType() == Maps::CellTypes::END)
        m_Player->TellAboutEndCell();
    if (m_Player->GetState() == States::WIN) {
        std::cout << "WIN!" << std::endl;
        return;
    }
    else if (m_Player->GetState() == States::DEAD) {
        std::cout << "YOU DEAD!" << std::endl;
        return;
    }
    
    if(!m_InGame){
        std::cout << "GAME OVER" << std::endl;
    }
    
    void Game::Game::Up() {
        if(!m_InGame) return;
        m_Iterator->Up();
    }
    
    void Game::Game::Down() {
        if(!m_InGame) return;
        m_Iterator->Down();
    }
    
    void Game::Game::Left() {
        if(!m_InGame) return;
        m_Iterator->Left();
    }
    
    void Game::Game::Right() {
        if(!m_InGame) return;
        m_Iterator->Right();
    }


}
