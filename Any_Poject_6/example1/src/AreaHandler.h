#pragma once
#include "enum.h"
#include "Area.h"

class AreaHandler {
public:
    static ItemType getCellItem(int x, int y);
    static CellType getCellType(int x, int y);
    static void addPersone(int x, int y);
    static void addEnemy(int x, int y);
    static void clearCell(int x, int y);
    static int getHeight();
    static int getWidth();
    static void prepareArea();
    static void setWall(int height, int width);
    static void setWallAroundArea();
    static void setEntry(int height, int width);
    static void setExit(int height, int width);
    static void setCell(int height, int width, CellType type);
    static void setItem(int height, int width, ItemType item);
};