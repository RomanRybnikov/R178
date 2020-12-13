#include "GameHandler.h"

void GameHandler::gameInfo() {
    std::cout << "Info:" << std::endl;
    std::cout << "You ned to take 3 coin and do not die till you don`t go to the end of the field." << std::endl;
    std::cout << "On field you can see 8 type of cell:" << std::endl;
    std::cout << "0 - free cell;" << std::endl;
    std::cout << "1 - wall;" << std::endl;
    std::cout << "S - enter of the field " << std::endl;
    std::cout << "E - exit of the field" << std::endl;
    std::cout << "5 - coin" << std::endl;
    std::cout << "6 - trap" << std::endl;
    std::cout << "7 - +1 to lives" << std::endl;
    std::cout << "9 - person" << std::endl;
    std::cout << std::endl << "To step down press: s" << std::endl;
    std::cout << "To step right press: d" << std::endl;
    std::cout << "To step left press: a" << std::endl;
    std::cout << "To step up press: w" << std::endl;
}

void GameHandler::prepareGame() {
    display = new Display;
    person = Person::Instance();
    AreaHandler::prepareArea();
    enemy1 = new TemplateEnemy <StandEnemy> (new StandEnemy(8,3));
    enemy2 = new TemplateEnemy<ProtectEnemy> (new ProtectEnemy(2, 2));
    enemy3 = new TemplateEnemy<WalkEnemy> (new WalkEnemy(5, 5));
    gameInfo();
    log();
}

void GameHandler::printCompleteGame() {
    if (person->getLives() > 0) {
        std::cout << "Winer, Winer, Chicken Dinner!!!" << std::endl;
    }
    else {
        std::cout << "YOU DIED" << std::endl;
    }
}

bool GameHandler::isCompleteGame()
{
    if (person->getLives() > 0)
    {
        return person->getCounterCoin() >= 3 && AreaHandler::getCellType(person->getX(), person->getY()) == CellType::EXIT;
    } return true;
}

void GameHandler::log() {
    logOut = new FileLogOut();
    logOut->createSubDict();
    publisher = new Publisher;
    publisher->addSub(*logOut);
    return;
}

void GameHandler::printCurrInfo()
{
    display->printArea(Area::getInstance());
    std::cout << "You collect " << person->getCounterCoin() << " coins" << std::endl;
    std::cout << "Your lives = " << person->getLives() << std::endl;
}

bool GameHandler::isWannaRestart()
{
    std::string restart;
    std::cout << "Do you wanna play again?\nIf yep - write yes\nelse - no" << std::endl;
    std::cin >> restart;
    if (restart == "yes") {
        AreaHandler::prepareArea();
        person->restart();
        return true;
    }
    else if (restart == "no") {
        return false;
    }
    else {
        this->isWannaRestart();
    }
}

void GameHandler::publishPerson()
{
    publisher->publish(AreaHandler::getCellItem(Person::Instance()->getX(), Person::Instance()->getY()));
    publisher->publish(ItemType::PERSON);
}

bool GameHandler::movePerson(char move) 
{
    switch (move) {
    case 'w':
        person->moveUp();
        publishPerson();
        return true;
    case 'a':
        person->moveLeft();
        publishPerson();
        return true;
    case 's':
        person->moveDown();
        publishPerson();
        return true;
    case 'd':
        person->moveRight();
        publishPerson();
        return true;
    default:
        return false;
    }
}

void GameHandler::moveEnemy(int type) {
    switch (type) {
    case 1:
        enemy1->moveEnemy();
        +*enemy1;
        break;
    case 2:
        enemy2->moveEnemy();
        +*enemy2;
        break;
    case 3:
        enemy3->moveEnemy();
        +*enemy3;
        break;
    default:
        break;
    }
}

Memento* GameHandler::Save()
{
    using namespace std;
    ofstream fout;
    fout.open("save.txt");

    state_ = "";
    // Saving Area
    int heightArea = AreaHandler::getHeight();
    int widthArea = AreaHandler::getWidth();
    state_.append(to_string(heightArea));
    state_.append(" ");
    state_.append(to_string(widthArea));
    state_.append(" ");
    for (int i = 0; i < heightArea; i++)
    {
        for (int j = 0; j < widthArea; j++)
        {
            CellType typeCell = AreaHandler::getCellType(j, i);
            ItemType typeItem = AreaHandler::getCellItem(j, i);
            state_.append(to_string(int(typeCell)));
            state_.append(" ");
            state_.append(to_string(int(typeItem)));
            state_.append(" ");
        }
    }

    // Saving Person
    state_.append(to_string(person->getX()));
    state_.append(" ");
    state_.append(to_string(person->getY()));
    state_.append(" ");
    state_.append(to_string(person->getCounterCoin()));
    state_.append(" ");
    state_.append(to_string(person->getLives()));
    state_.append(" ");

    // Saving Enemy
    state_.append(to_string(enemy1->getX()));
    state_.append(" ");
    state_.append(to_string(enemy1->getY()));
    state_.append(" ");
    state_.append(to_string(enemy2->getX()));
    state_.append(" ");
    state_.append(to_string(enemy2->getY()));
    state_.append(" ");
    state_.append(to_string(enemy3->getX()));
    state_.append(" ");
    state_.append(to_string(enemy3->getY()));

    //hash string
    hash<std::string> str_hash;
    string hashed = std::to_string(str_hash(state_)) + " ";
    state_.insert(0, hashed);
    //cout << state_ << endl << endl;

    fout << state_;
    fout.close();
    return new GameMemento(this->state_);
}

void GameHandler::Restore(Memento* momento)
{
    using namespace std;
    state_ = momento->state();
    // Hash check
    hash<std::string> str_hash;
    string hash1 = state_.substr(0, state_.find(' '));
    string hash2 = to_string(str_hash(state_.substr(hash1.length() + 1, state_.size() - hash1.length())));
    if (hash1.length() == hash2.length())
    {
        for (auto i = 0; i < hash1.length(); i++)
        {
            if (hash1[i] != hash2[i]) 
            {
                cout << "The data is corrupted. Restore save failed" << endl;
                return;
            }
        }
    }
    else
    {
        cout << "The data is corrupted. Restore save failed" << endl;
        return;
    }
    
    // Move data to vector
    state_ = state_.substr(hash1.length() + 1, state_.size() - hash1.length());
    vector<int> vect_data;
    char* s = new char[state_.size() + 1];
    strcpy(s, state_.c_str());
    char* p = strtok(s, " ");
    while (p!= NULL) {
        vect_data.push_back(atoi(p));
        p = strtok(NULL, " ");
    }
    
    // Recovery data
    int ind = 0;
    int heightArea = vect_data[ind++];
    int widthArea = vect_data[ind++];
    Area::getInstance();
    for (int i = 0; i < heightArea; i++)
    {
        for (int j = 0; j < widthArea; j++)
        {
            CellType type = (CellType)vect_data[ind++];
            ItemType item = (ItemType)vect_data[ind++];    
            AreaHandler::setCell(j, i, type);
            if (type == CellType::OBJECT)
            {
                AreaHandler::setItem(j, i, item);
            }
        }
    }

    person->Instance();
    person->setX(vect_data[ind++]);
    person->setY(vect_data[ind++]);
    person->setCoin(vect_data[ind++]);
    person->setLives(vect_data[ind++]);
    
    enemy1->setX(vect_data[ind++]);
    enemy1->setY(vect_data[ind++]);
    enemy2->setX(vect_data[ind++]);
    enemy2->setY(vect_data[ind++]);
    enemy3->setX(vect_data[ind++]);
    enemy3->setY(vect_data[ind++]);

}

GameHandler::~GameHandler() {
    delete display;
    delete logOut;
    delete publisher;
}