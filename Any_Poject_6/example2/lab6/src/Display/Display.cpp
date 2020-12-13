#include "Display.h"
#include "windows.h"
#include "stdio.h"


Display::Display(Field* gameField)
{
	field = gameField->GetField();
	heroTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/hero.png");
	heroSprite.setTexture(heroTexture);
}

void Display::DisplayField(sf::RenderWindow &window)
{
	for (int j = 0; j < FIELD_HEIGHT; j++)
	{
		for (int i = 0; i < FIELD_WIDTH; i++)
		{
			cellView.SetCellType(field[i][j].GetType());
			sf::RectangleShape rectangle = cellView.SetRectangleTexture();
			rectangle.setPosition(j * CELL_SIZE, i * CELL_SIZE);
			window.draw(rectangle);
		}
	}
}

void Display::DisplayHero(sf::RenderWindow& window, Hero& hero)
{
	heroSprite.setPosition(hero.GetX() * CELL_SIZE, hero.GetY() * CELL_SIZE);
	window.draw(heroSprite);
}

void Display::DisplayItemsAndEnemies(sf::RenderWindow& window)
{
	for (int j = 0; j < FIELD_HEIGHT; j++)
	{
		for (int i = 0; i < FIELD_WIDTH; i++)
		{
			if (field[i][j].GetItem())
			{
				//std::cout << (int)(field[i][j].GetItem());
				if (field[i][j].GetItem()->GetItemName() == "Chest" && field[i][j].GetType() != CellType::DIGGEDTRAIL)
				{
				}
				else 
				{
					itemView.SetItemType(field[i][j].GetItem()->GetItemName());
					sf::Sprite sprite = itemView.SetItemTexture();
					sprite.setPosition(j * CELL_SIZE, i * CELL_SIZE);
					window.draw(sprite);
				}
				
			}
			if (field[i][j].GetRobEnemy())
			{
				enemyView.SetEnemyType("Rob");
				sf::Sprite sprite = enemyView.SetEnemyTexture();
				sprite.setPosition(j * CELL_SIZE, i * CELL_SIZE);
				window.draw(sprite);
			}
			if (field[i][j].GetBeatEnemy())
			{
				enemyView.SetEnemyType("Beat");
				sf::Sprite sprite = enemyView.SetEnemyTexture();
				sprite.setPosition(j * CELL_SIZE, i * CELL_SIZE);
				window.draw(sprite);
			}
			if (field[i][j].GetTPEnemy())
			{
				enemyView.SetEnemyType("TP");
				sf::Sprite sprite = enemyView.SetEnemyTexture();
				sprite.setPosition(j * CELL_SIZE, i * CELL_SIZE);
				window.draw(sprite);
			}
		}
	}

}

void Display::DisplayHeroInformation(sf::RenderWindow& window, Hero &hero)
{
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(550, 70));
	background.setFillColor(sf::Color(41, 54, 117));
	background.setPosition(0, 550);
	window.draw(background);


	sf::Text text;
	sf::Font font;

	font.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/font.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color(239, 100, 54));

	text.setPosition(10, 570);
	text.setString("Health:" + std::to_string(hero.GetHealthPoints()));
	window.draw(text);

	text.setPosition(180, 570);
	text.setString("Opened Chests:" + std::to_string(hero.GetOpenedChestCounter()));
	window.draw(text);	

	text.setPosition(450, 570);
	text.setString("Keys:" + std::to_string(hero.GetKeyCounter()));
	window.draw(text);
}

void Display::DisplayWinWindow(sf::RenderWindow& window)
{
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(550, 620));
	background.setPosition(sf::Vector2f(0, 0));
	background.setFillColor(sf::Color(41, 54, 117));
	window.draw(background);


	sf::Text text;
	sf::Font font;

	font.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/font.ttf");
	text.setFont(font);
	text.setCharacterSize(62);
	text.setFillColor(sf::Color(239, 100, 54));

	text.setPosition(155, 240);
	text.setString("YOU WIN!");
	window.draw(text);
}

void Display::DisplayStartWindow(sf::RenderWindow& window)
{
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(550, 620));
	background.setPosition(sf::Vector2f(0, 0));
	background.setFillColor(sf::Color(41, 54, 117));
	window.draw(background);


	sf::Text text;
	sf::Text text1;
	sf::Font font;

	font.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/font.ttf");
	text.setFont(font);
	text.setCharacterSize(62);
	text.setFillColor(sf::Color(239, 100, 54));

	text1.setFont(font);
	text1.setCharacterSize(25);
	text1.setFillColor(sf::Color(255, 30, 24));

	text1.setPosition(15, 15);
	text1.setString("RULES:\n\nLeft Arrow - Go Left\nRight Arrow - Go Right\nDown Arrow - Go Down\nUp Arrow - Go Up\n\E - Use\Take Item\n\Space - Dig Grass\nEsc - Close Game\n \
	Find all the Keys and open the Door or dig up and open all\n the Chests to win!");
	text.setPosition(120, 350);
	text.setString("Press \"Enter\" \n to start game!");
	window.draw(text);
	window.draw(text1);
}

void Display::DisplayLostWindow(sf::RenderWindow& window)
{
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(550, 620));
	background.setPosition(sf::Vector2f(0, 0));
	background.setFillColor(sf::Color(41, 54, 117));
	window.draw(background);


	sf::Text text;
	sf::Font font;

	font.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/font.ttf");
	text.setFont(font);
	text.setCharacterSize(62);
	text.setFillColor(sf::Color(239, 100, 54));

	text.setPosition(120, 240);
	text.setString("YOU LOST...");
	window.draw(text);
}