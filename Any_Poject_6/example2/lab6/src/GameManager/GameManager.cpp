#include "GameManager.h"


void GameManager::StartGame()
{
    setlocale(0, "");
    gameField = Field::GetInstance();
    gameField->DefineField();

    itemUseObserver = new ItemUseObserver();
    itemTakeObserver = new ItemTakeObserver();
    itemSpawnObserver = new ItemSpawnObserver();
    heroDigObserver = new HeroDigObserver();
    heroGetItemObserver = new HeroGetItemObserver();
    heroMovingObserver = new HeroMovingObserver();
    enemyMovingObserver = new EnemyMovedObserver();
    enemySpawnObserver = new EnemySpawnedObserver();
    enemyHeroMeetObserver = new EnemyHeroMeetObserver();
    loadSaveObserver = new LoadSaveObserver();
    saveObserver = new SaveObserver();


    eventManager.Attach(itemSpawnObserver, Event::ItemSpawn);
    eventManager.Attach(itemUseObserver, Event::ItemUse);
    eventManager.Attach(itemTakeObserver, Event::ItemTake);
    eventManager.Attach(heroDigObserver, Event::HeroDig);
    eventManager.Attach(heroGetItemObserver, Event::HeroGetItem);
    eventManager.Attach(heroMovingObserver, Event::HeroMoving);
    eventManager.Attach(enemyMovingObserver, Event::EnemyMove);
    eventManager.Attach(enemySpawnObserver, Event::EnemySpawn);
    eventManager.Attach(enemyHeroMeetObserver, Event::EnemyHeroMeet);

    gameState = new HeroState(this);
    //gameState->SetContext(this);
    
    PlaceItems();

    displayView = new Display(gameField);
    PlaceEnemies();
}

void GameManager::GameSaved()
{
    saveObserver->Update("");
}

void GameManager::SetState(GameState* newState)
{
    if (gameState)
    {
        delete gameState;
    } 
    gameState = newState;
}

void GameManager::EnemyTurn()
{
    gameState->Move();
}

void GameManager::HeroMoving(int moveX, int moveY)
{
    if (hero.GetX() + moveX < 0 || hero.GetX() + moveX == FIELD_WIDTH || hero.GetY() + moveY < 0 || hero.GetY() + moveY == FIELD_HEIGHT) return;
    if (gameField->GetField()[hero.GetY() + moveY][hero.GetX() + moveX].GetType() == CellType::WALL) return;
    hero.ChangePosition(moveX, moveY);
    gameField->GetField()[hero.GetY() - moveY][hero.GetX() - moveX].isHeroOnCell = false;
    gameField->GetField()[hero.GetY()][hero.GetX()].isHeroOnCell = true;
    eventManager.Notify(Event::HeroMoving, "Y: " + std::to_string(hero.GetY()) + ", X: " + std::to_string(hero.GetX()));
    if (hero.GetX() == robEnemy->getX() && hero.GetY() == robEnemy->getY())
    {
        *robEnemy - hero;
        eventManager.Notify(Event::EnemyHeroMeet, "(RobEnemy)");
        LogHeroInfo();
    }
        
    if (hero.GetX() == beatEnemy->getX() && hero.GetY() == beatEnemy->getY())
    {
        *beatEnemy - hero;
        eventManager.Notify(Event::EnemyHeroMeet, "(BeatEnemy)");
        LogHeroInfo();
    }
        

    if (hero.GetX() == TPEnemy->getX() && hero.GetY() == TPEnemy->getY())
    {
        *TPEnemy - hero;
        eventManager.Notify(Event::EnemyHeroMeet, "(TPEnemy)");
        LogHeroInfo();
    }
    SetState(new EnemyState(this));
    EnemyTurn();
}

void GameManager::EnemyMoving()
{
    gameField->GetField()[TPEnemy->getY()][TPEnemy->getX()].DeleteEnemy();
    TPEnemy->Move();
    gameField->GetField()[TPEnemy->getY()][TPEnemy->getX()].PlaceEnemy(TPEnemy);
    eventManager.Notify(Event::EnemyMove, "X: " + std::to_string(TPEnemy->getX()) + ", Y: " + std::to_string(TPEnemy->getY()) + "(TPEnemy)");
    if (hero.GetX() == TPEnemy->getX() && hero.GetY() == TPEnemy->getY())
    {
        *TPEnemy - hero;
        eventManager.Notify(Event::EnemyHeroMeet, "(TPEnemy)");
        LogHeroInfo();
    }
    gameField->GetField()[beatEnemy->getY()][beatEnemy->getX()].DeleteEnemy();
    beatEnemy->Move();
    gameField->GetField()[beatEnemy->getY()][beatEnemy->getX()].PlaceEnemy(beatEnemy);
    eventManager.Notify(Event::EnemyMove, "X: " + std::to_string(beatEnemy->getX()) + ", Y: " + std::to_string(beatEnemy->getY()) + "(BeatEnemy)");
    if (hero.GetX() == beatEnemy->getX() && hero.GetY() == beatEnemy->getY())
    {
        *beatEnemy - hero;
        eventManager.Notify(Event::EnemyHeroMeet, "(BeatEnemy)");
        LogHeroInfo();
    }
    gameField->GetField()[robEnemy->getY()][robEnemy->getX()].DeleteEnemy();
    robEnemy->Move();
    gameField->GetField()[robEnemy->getY()][robEnemy->getX()].PlaceEnemy(robEnemy);
    eventManager.Notify(Event::EnemyMove, "X: " + std::to_string(robEnemy->getX()) + ", Y: " + std::to_string(robEnemy->getY()) + "(RobEnemy)");
    if (hero.GetX() == robEnemy->getX() && hero.GetY() == robEnemy->getY())
    {
        *robEnemy - hero;
        eventManager.Notify(Event::EnemyHeroMeet, "(RobEnemy)");
        LogHeroInfo();
    }
        

}

void GameManager::DigGrass()
{
    gameField->GetField()[hero.GetY()][hero.GetX()].SetType(CellType::DIGGEDTRAIL);
    eventManager.Notify(Event::HeroDig, "Y: " + std::to_string(hero.GetY()) + " X: " + std::to_string(hero.GetX()));
    SetState(new EnemyState(this));
    EnemyTurn();
}

void GameManager::UseItem()
{
    Item* item = gameField->GetField()[hero.GetY()][hero.GetX()].GetItem();
    if (item)
    {
        if (item->GetItemName() == "Chest" && gameField->GetField()[hero.GetY()][hero.GetX()].GetType() == CellType::DIGGEDTRAIL)
        {
            itemStrategy.SetStrategy(item);
            itemStrategy.UseItem(hero);
            eventManager.Notify(Event::ItemUse, "X: " + std::to_string(hero.GetX()) + ", Y: " + std::to_string(hero.GetY()) + "(" + ")" + item->GetItemName());
            LogHeroInfo();
        }
        else if (item->GetItemName() == "Key" || item->GetItemName() == "Heart")
        {
            itemStrategy.SetStrategy(item);
            itemStrategy.UseItem(hero);
            eventManager.Notify(Event::ItemTake,"X: " + std::to_string(hero.GetX()) + ", Y: " + std::to_string(hero.GetY()) + "(" + ")" + item->GetItemName());
            eventManager.Notify(Event::HeroGetItem, item->GetItemName());
            gameField->GetField()[hero.GetY()][hero.GetX()].DeleteItem();
            LogHeroInfo();
        }

    }
    SetState(new EnemyState(this));
    EnemyTurn();
    item = nullptr;
}

void GameManager::LogHeroInfo()
{
    std::stringstream buffer;
    buffer << hero;
    LogFile* logFile = new LogFile();
    logFile->PrintLog(buffer.str());
    delete logFile;
}

void GameManager::PlaceEnemies()
{
    TPBehaviour tpBehaviour;
    BeatBehaviour beatBehaviour;
    RobBehaviour robBehaviour;
    beatEnemy = new Enemy<BeatBehaviour>(6, 0);
    gameField->GetField()[6][0].PlaceEnemy(beatEnemy);
    eventManager.Notify(Event::EnemySpawn, "X:0, Y:6(BeatEnemy)");
    robEnemy = new Enemy<RobBehaviour>(8, 4);
    gameField->GetField()[8][4].PlaceEnemy(robEnemy);
    eventManager.Notify(Event::EnemySpawn, "X:4, Y:8(RobEnemy)");
    TPEnemy = new Enemy<TPBehaviour>(2, 10);
    gameField->GetField()[2][10].PlaceEnemy(TPEnemy);
    eventManager.Notify(Event::EnemySpawn, "X:10, Y:2(TPEnemy)");

}



void GameManager::PlaceItems()
{
    ItemChestFactory chest;
    ItemHeartFactory heart;
    ItemKeyFactory key;

    gameField->GetField()[10][1].PlaceItem(key.createItem());
    eventManager.Notify(Event::ItemSpawn, "X: 1, Y: 10(KeyItem)");
    gameField->GetField()[10][5].PlaceItem(key.createItem());
    eventManager.Notify(Event::ItemSpawn, "X: 5, Y: 10(KeyItem)");
    gameField->GetField()[0][10].PlaceItem(key.createItem());
    eventManager.Notify(Event::ItemSpawn, "X: 10, Y: 0(KeyItem)");

    gameField->GetField()[7][1].PlaceItem(heart.createItem());
    eventManager.Notify(Event::ItemSpawn, "X: 1, Y: 7(HeartItem)");
    gameField->GetField()[0][3].PlaceItem(heart.createItem());
    eventManager.Notify(Event::ItemSpawn, "X: 3, Y: 0(HeartItem)");
    gameField->GetField()[3][8].PlaceItem(heart.createItem());
    eventManager.Notify(Event::ItemSpawn, "X: 8, Y: 3(HeartItem)");

    std::srand(time(NULL));
    int counter = 0;
    int x, y;
    while (counter != 4)
    {
        x = std::rand() % 9 + 1;
        y = std::rand() % 9 + 1;
        if (gameField->GetField()[y][x].GetType() == CellType::WALL || gameField->GetField()[y][x].GetItem()) continue;
        gameField->GetField()[y][x].PlaceItem(chest.createItem());
        eventManager.Notify(Event::ItemSpawn, "X: " + std::to_string(x) + ", Y: " + std::to_string(y) + "(ChestItem)");
        counter++;
    }
}

void GameManager::EndGame()
{
    closeGame = true;
}

GameState* GameManager::getState()
{
    return gameState;
}

GameManager::~GameManager()
{
    if (displayView)
        delete displayView;
    if (gameState)
        delete gameState;
}

bool GameManager::CheckPath(int moveX, int moveY)
{
    if (hero.GetX() + moveX < 0 || hero.GetX() + moveX == FIELD_WIDTH || hero.GetY() + moveY < 0 || hero.GetY() + moveY == FIELD_HEIGHT) return false;
    if (gameField->GetField()[hero.GetY() + moveY][hero.GetX() + moveX].GetType() == CellType::WALL) return false;
    return true;
}

bool GameManager::CheckGrass()
{
    if ((hero.GetX() == 0 && hero.GetY() == 0) || (hero.GetX() == FIELD_WIDTH - 1 && hero.GetY() == FIELD_HEIGHT - 1)) return false;
    if (gameField->GetField()[hero.GetY()][hero.GetX()].GetType() == CellType::DIGGEDTRAIL) return false;
    return true;
}

bool GameManager::CheckItem()
{
    Item* item = gameField->GetField()[hero.GetY()][hero.GetX()].GetItem();
    return item;
}

Memento* GameManager::Save()
{
    GameInfo gameInfo;
    gameInfo.heartsPos.clear();
    gameInfo.chestsPos.clear();
    gameInfo.keysPos.clear();
    gameInfo.openedChestsPos.clear();

    int keysCount = 0;
    int heartsCount = 0;
    int chestsCount = 0;
    int openedChestsCount = 0;

    gameInfo.beatEnemyPos = std::pair<int, int>(beatEnemy->getX(), beatEnemy->getY());
    gameInfo.robEnemyPos = std::pair<int, int>(robEnemy->getX(), robEnemy->getY());
    gameInfo.TPEnemyPos = std::pair<int, int>(TPEnemy->getX(), TPEnemy->getY());
    gameInfo.heroPos = std::pair<int, int>(hero.GetX(), hero.GetY());
    gameInfo.heroHealth = hero.GetHealthPoints();
    gameInfo.heroKeys = hero.GetKeyCounter();
    gameInfo.heroOpenedChests = hero.GetOpenedChestCounter();
    for (int y = 0; y < FIELD_HEIGHT; y++)
    {
        for (int x = 0; x < FIELD_WIDTH; x++)
        {
            gameInfo.field[y][x] = (int)gameField->GetField()[y][x].GetType();
            if (gameField->GetField()[y][x].GetItem() && gameField->GetField()[y][x].GetItem()->GetItemName() == "Heart")
            {
                gameInfo.heartsPos.push_back(std::pair<int, int>(x, y));
                heartsCount++;
            }
                
            if (gameField->GetField()[y][x].GetItem() && gameField->GetField()[y][x].GetItem()->GetItemName() == "Key")
            {
                gameInfo.keysPos.push_back(std::pair<int, int>(x, y));
                keysCount++;
            }
               
            if (gameField->GetField()[y][x].GetItem() && gameField->GetField()[y][x].GetItem()->GetItemName() == "Chest")
            {
                gameInfo.chestsPos.push_back(std::pair<int, int>(x, y));
                chestsCount++;
            }
               
            if (gameField->GetField()[y][x].GetItem() && gameField->GetField()[y][x].GetItem()->GetItemName() == "OpenedChest")
            {
                gameInfo.openedChestsPos.push_back(std::pair<int, int>(x, y));
                openedChestsCount++;
            }
                
        }
    }
    gameInfo.heartCount = heartsCount;
    gameInfo.keysCount = keysCount;
    gameInfo.chestsCount = chestsCount;
    gameInfo.openedChestsCount = openedChestsCount;

    return new ConcreteMemento(gameInfo);
}

void GameManager::Restore(Memento* memento)
{
    ItemChestFactory chest;
    ItemHeartFactory heart;
    ItemKeyFactory key;

    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        for (int j = 0; j < FIELD_HEIGHT; j++)
        {
            switch (memento->State().field[i][j])
            {
            case 0:  gameField->GetField()[i][j].SetType(CellType::BEGIN); break;
            case 1:  gameField->GetField()[i][j].SetType(CellType::END); break;
            case 2:  gameField->GetField()[i][j].SetType(CellType::WALL); break;
            case 3:  gameField->GetField()[i][j].SetType(CellType::TRAIL); break;
            case 4:  gameField->GetField()[i][j].SetType(CellType::DIGGEDTRAIL); break;
            }
            gameField->GetField()[i][j].DeleteItem();
            gameField->GetField()[i][j].DeleteEnemy();
        }
    }

    TPEnemy->SetPos(memento->State().TPEnemyPos.first, memento->State().TPEnemyPos.second);
    beatEnemy->SetPos(memento->State().beatEnemyPos.first, memento->State().beatEnemyPos.second);
    robEnemy->SetPos(memento->State().robEnemyPos.first, memento->State().robEnemyPos.second);
    hero.SetPos(memento->State().heroPos.first, memento->State().heroPos.second);
    hero.SetHealth(memento->State().heroHealth);
    hero.SetKeyCounter(memento->State().heroKeys);
    hero.SetOpenedChestCounter(0);
    
    
    for (int i = 0; i < memento->State().heartCount; i++)
    {
        gameField->GetField()[memento->State().heartsPos[i].second][memento->State().heartsPos[i].first].PlaceItem(heart.createItem());
        eventManager.Notify(Event::ItemSpawn, "X: " + std::to_string(memento->State().heartsPos[i].first) + ", Y: " + std::to_string(memento->State().heartsPos[i].second) + "(HeartItem)");
    }
    for (int i = 0; i < memento->State().keysCount; i++)
    {
        gameField->GetField()[memento->State().keysPos[i].second][memento->State().keysPos[i].first].PlaceItem(key.createItem());
        eventManager.Notify(Event::ItemSpawn, "X: " + std::to_string(memento->State().keysPos[i].first) +", Y: " + std::to_string(memento->State().keysPos[i].second)+ "(KeyItem)");
    }
    for (int i = 0; i < memento->State().chestsCount; i++)
    {
        gameField->GetField()[memento->State().chestsPos[i].second][memento->State().chestsPos[i].first].PlaceItem(chest.createItem());
        eventManager.Notify(Event::ItemSpawn, "X: " + std::to_string(memento->State().chestsPos[i].first) + ", Y: " + std::to_string(memento->State().chestsPos[i].second) + "(ChestItem)");
    }

    for (int i = 0; i < memento->State().openedChestsCount; i++)
    {
        gameField->GetField()[memento->State().openedChestsPos[i].second][memento->State().openedChestsPos[i].first].PlaceItem(chest.createItem());
        eventManager.Notify(Event::ItemSpawn, "X: " + std::to_string(memento->State().openedChestsPos[i].first) + ", Y: " + std::to_string(memento->State().openedChestsPos[i].second) + "(OpenedChestItem)");
        itemStrategy.SetStrategy(gameField->GetField()[memento->State().openedChestsPos[i].second][memento->State().openedChestsPos[i].first].GetItem());
        itemStrategy.UseItem(hero);
    }
    LogHeroInfo();

    gameField->GetField()[memento->State().beatEnemyPos.second][memento->State().beatEnemyPos.first].PlaceEnemy(beatEnemy);
    eventManager.Notify(Event::EnemySpawn, "X: " + std::to_string(memento->State().beatEnemyPos.first) + ", Y: " + std::to_string(memento->State().beatEnemyPos.second) + "(BeatEnemy)");
    gameField->GetField()[memento->State().TPEnemyPos.second][memento->State().TPEnemyPos.first].PlaceEnemy(TPEnemy);
    eventManager.Notify(Event::EnemySpawn, "X: " + std::to_string(memento->State().TPEnemyPos.first) + ", Y: " + std::to_string(memento->State().TPEnemyPos.second) + "(TPEnemy)");
    gameField->GetField()[memento->State().robEnemyPos.second][memento->State().robEnemyPos.first].PlaceEnemy(robEnemy);
    eventManager.Notify(Event::EnemySpawn, "X: " + std::to_string(memento->State().robEnemyPos.first) + ", Y: " + std::to_string(memento->State().robEnemyPos.second) + "(RobûEnemy)");
    loadSaveObserver->Update("");
}
