#include "Map.h"
#include "Iterator.h"
#include "AddCoinsCellLogic.h"
#include "HpCellLogic.h"
#include "KillCellLogic.h"
#include <math.h>
using namespace Maps;

Map* Map::p_map = 0;

Map::Map(int str, int col) {
    this->width = str;
    this->height = col;
    ArrMap = new Cell * [str];
    for (int i = 0; i < width; i++) {
        ArrMap[i] = new Cell[height];
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++) {
            ArrMap[i][j].Cell::ReType(REGULAR);
        }
    }

    ArrMap[0][0].ReType(START);
    ArrMap[width - 1][height - 1].ReType(END);

    GenerateLogic();
}

// constructor copy
Map::Map(const Map& obj) {
    this->width = obj.width;
    this->height = obj.height;
    ArrMap = new Cell * [width];
    for (int i = 0; i < width; i++) {
        ArrMap[i] = new Cell[height];
    }

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) 
            ArrMap[i][j] = obj.ArrMap[i][j];        
    }
    std::cout << "COPY" << std::endl;
}

// явно реализованный оператор перемещения(чтобы получить 1 балл *исправление*)
Map::Map(Map&& object) {
    Clear();
    this->width = object.width;
    this->height = object.height;
    this->ArrMap = object.ArrMap;
    std::cout << "MOOOVE" << std::endl;
    object.ArrMap = nullptr;
}

Map::~Map() {
    Clear();
}

void Map::GenerateLogic()               // генерирует логику ячеек
{
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // пропуск служебных ячеек
            if (ArrMap[i][j].GetType() != REGULAR) continue;
            // вставка в радиусе конца HP
            if (sqrt((width - 1 - i) * (width - 1 - i) + (height - 1 - j) * (height - 1 - j)) <= HP_RADIUS) {
                ArrMap[i][j].SetLogic(new HpCellLogic(-100 + rand() % 200));
                continue;
            }
            switch (rand() % (3 + EMPTY_CELL_P)) {
            case 0:
                ArrMap[i][j].SetLogic(new AddCoinsCellLogic(1 + rand() % 100));
                break;
            case 1:
                ArrMap[i][j].SetLogic(new HpCellLogic(-100 + rand() % 200));
                break;
            case 2:
                ArrMap[i][j].SetLogic(new KillCellLogic());
                break;
            }
        }
    }
}

void Map::Clear() {
    if (ArrMap) {
        for (int i = 0; i < width; i++) {
            delete[] ArrMap[i];
        }
    }
    delete[] ArrMap;

    ArrMap = 0;
}

Map* Map::GetInstance() {
    if (p_map == 0) {
        p_map == new Map(3,3);
    }
    return p_map;
}
Map* Map::GetInstance(int str, int col) {
    if (p_map != 0) {
        delete p_map;
        p_map = 0;
    }
    if (p_map == 0){
        p_map = new Map(str, col);
    }
    return p_map;
}

void Map::Copy(Map const& object) {             // func.copy
    this->width = object.width;
    this->height = object.height;
    ArrMap = new Cell * [width];
    for (int i = 0; i < width; i++) {
        ArrMap[i] = new Cell[height];
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            ArrMap[i][j].Cell::ReType(REGULAR);
        }
    }
}
void Map::GetMap() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            std::cout << ArrMap[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
Map& Map::operator=(const Map& map) {                 // operator copy
    std::cout << "operator=" << std::endl;
    Clear();
    Copy(map);
    return *this;
}
Map& Map::operator=(const Map&& map) {                // operator move
    std::cout << "operator move=" << std::endl;

    Clear();
    this->width = map.width;
    this->height = map.height;
    this->ArrMap = map.ArrMap;

    return *this;
}




