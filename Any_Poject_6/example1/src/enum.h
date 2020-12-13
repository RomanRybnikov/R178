#pragma once

enum class CellType {
    VOID,
    WALL,
    OBJECT,
    ENTRY,
    EXIT,
};

enum class ItemType {
    NONE,
    COIN,
    LIFE_BUFFER,
    TRAP,
    PERSON,
};

enum class EnemyType
{
    STAND,
    PROTECT,
    WALK,
};