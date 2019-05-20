#include "GameObject.h"

void GameObject::addGameObject(int xpos, int ypos,  int ** gamemap, const int &objType,Position dst)
{
	if (gamemap[ypos][xpos] == 0)	
	{
		if (this->gameObjectID != "publicBuilding" && this->gameObjectID != "privateBuilding")
		{
			this->numOfNodes++;
		}
		
		if (objType == 12)
		{
			Position src;
			src.xPos = xpos;
			src.yPos = ypos;
			gamemap[ypos][xpos] = objType;
			//tworzenie samochodu
			amountOfCars++;
			Vehicle car(src , dst,amountOfCars);
			//dodawanie do kontenera
			this->vehicleArray.push_back(car);
		}
		else
		{
			gamemap[ypos][xpos] = objType;
		}
	}
	else
	{
		std::cout << "Cannot add obj on the same place as existing one" << std::endl;
	}
}

void GameObject::destoryGameObject(int xpos, int ypos, int ** gamemap)
{
	Position tmp;
	int x = 0;
	int size = this -> vehicleArray.size();
	for (int i=0; i < size; i++)
	{
		tmp = this->vehicleArray[i].getSrcPostionOriginal();
		
		if (tmp.xPos == xpos && tmp.yPos == ypos)
		{
			x = i;
		}
	}

	vehicleArray.erase(vehicleArray.begin()+x);

	gamemap[ypos][xpos] = 0;

}

