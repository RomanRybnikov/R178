#include "CellView.h"

CellView::CellView()
{
	grassTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/Grass.jpg");
	wallTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/Wall.jpg");
	doorTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/EnterDoor.jpg");
	diggedGrassTexture.loadFromFile("C:/Users/nikei/source/repos/OOPLab/OOPLab/Assets/DiggedGrass.jpg");

	rectangle = sf::RectangleShape(sf::Vector2f(50.0, 50.0));
	rectangle.setOutlineColor(sf::Color(0, 0, 0));
	rectangle.setOutlineThickness(1);
	
}

sf::RectangleShape CellView::SetRectangleTexture()
{
	switch (cellType)
	{
	case CellType::BEGIN: rectangle.setTexture(&doorTexture);  break;
	case CellType::END: rectangle.setTexture(&doorTexture); break;
	case CellType::TRAIL: rectangle.setTexture(&grassTexture); break;
	case CellType::WALL: rectangle.setTexture(&wallTexture); break;
	case CellType::DIGGEDTRAIL: rectangle.setTexture(&diggedGrassTexture); break;
	default:
		break;
	}
	return rectangle;
}


void CellView::SetCellType(CellType tempCellType)
{
	this->cellType = tempCellType;
}