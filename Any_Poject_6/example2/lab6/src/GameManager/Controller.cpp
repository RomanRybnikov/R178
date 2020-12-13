#include "Controller.h"

Controller::Controller()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gismos");

    gameManager = new GameManager();

    closeGameCommand = new CloseGameCommand(gameManager);
    digGrassCommand = new DigGrassCommand(gameManager);
    moveDownCommand = new MoveDownCommand(gameManager);
    moveLeftCommand = new MoveLeftCommand(gameManager);
    moveRightCommand = new MoveRightCommand(gameManager);
    moveUpCommand = new MoveUpCommand(gameManager);
    startGameCommand = new StartGameCommand(gameManager);
    takeItemCommand = new TakeItemCommand(gameManager);
    careTaker = new CareTaker(gameManager);
    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || gameManager->closeGame)
                window.close(); 
           
            if (!isGameWin && isGameStarted && !isGameLost)
            {
                if (event.type == sf::Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                    case sf::Keyboard::S: careTaker->BackUp(); break;
                    case sf::Keyboard::Left: moveLeftCommand->execute(); break;
                    case sf::Keyboard::Right: moveRightCommand->execute(); break;
                    case sf::Keyboard::Up: moveUpCommand->execute(); break;
                    case sf::Keyboard::Down: moveDownCommand->execute(); break;
                    case sf::Keyboard::Space: digGrassCommand->execute(); break;
                    case sf::Keyboard::E: takeItemCommand->execute();  break;
                    case sf::Keyboard::L: careTaker->Load(); break;
                    default: break;
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter && !isGameStarted)
            {
                startGameCommand->execute();
                isGameStarted = !isGameStarted;
                
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                closeGameCommand->execute();
            }
            
        }

        if (!isGameStarted)
        {
            gameManager->displayView->DisplayStartWindow(window);
        }
        else if (isGameWin)
        {
            gameManager->displayView->DisplayWinWindow(window);
            
        }
        else if (isGameLost)
        {
            gameManager->displayView->DisplayLostWindow(window);
        }
        else
        {
            IsGameEnd();
            gameManager->displayView->DisplayHeroInformation(window, gameManager->hero);
            gameManager->displayView->DisplayField(window);
            gameManager->displayView->DisplayItemsAndEnemies(window);
            gameManager->displayView->DisplayHero(window, gameManager->hero);
        }
        window.display();
        window.clear();
        
    }
	std::cout << "\n";
}







void Controller::IsGameEnd()
{
    if (gameManager->hero.GetHealthPoints() == 0)
    {
        isGameLost = true;
    }
    if (gameManager->hero.GetOpenedChestCounter() == 4 && gameManager->hero.GetX() == 10 && gameManager->hero.GetY() == 10)
    {
        isGameWin = true;
    }
    if (gameManager->hero.GetX() == 10 && gameManager->hero.GetY() == 10 && gameManager->hero.GetKeyCounter() == 3)
    {
        isGameWin = true;
    }
}


Controller::~Controller()
{
    if (gameManager)
        delete gameManager;
    if (closeGameCommand)
        delete closeGameCommand;
    if (digGrassCommand)
        delete digGrassCommand;
    if (moveDownCommand)
        delete moveDownCommand;
    if (moveLeftCommand)
        delete moveLeftCommand;
    if (moveRightCommand)
        delete moveRightCommand;
    if (moveUpCommand)
        delete moveUpCommand;
    if (startGameCommand)
        delete startGameCommand;
    if (takeItemCommand)
        delete takeItemCommand;
}


