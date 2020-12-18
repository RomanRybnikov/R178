#ifndef MAP_H_
#define MAP_H_
#include <iostream>
#include "Cell.h"
#include "Iterator.h"

namespace Maps {
#define EMPTY_CELL_P 5
#define HP_RADIUS 2
    class Map {
        int width;
        int height;
        static Map* p_map;
        Cell** ArrMap;
        void Clear();                            // data clear
        void Copy(Map const& object);            // func copy
        void GenerateLogic();               // генерирует логику ячеек

    public:
        friend class Iterator;
        static Map* GetInstance();
        static Map* GetInstance(int str, int col);
        Map(int str, int col);
        Map& operator=(const Map& map);          // operator copy
        Map& operator=(const Map&& map);         // operator move
        Map(const Map& obj);           // constructor copy
        Map(Map&& object);             // c.move(явно описанный *исправление*)
        ~Map();
        void GetMap();
        int GetWidth() { return width; }
        int GetHeight() { return height; }
        Cell& GetCell(int row, int col) { return ArrMap[row][col]; }

        void Save(std::ostream& os);
        void Load(std::istream& os);
    };
}

#endif
