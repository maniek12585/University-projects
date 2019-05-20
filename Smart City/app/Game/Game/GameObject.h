#pragma once
#include <iostream>
#include <string>
#include "Vehicle.h"

class GameObject
{
	float positionX;
	float positionY;

	std::string gameObjectID;
	
	int amountOfCars;
public:

	std::deque<Vehicle> vehicleArray;
	std::deque<Vehicle>::iterator it;

	int numOfNodes=0;
	void setPositionX(float x) { this->positionX = x; }
	void setPositionY(float y) { this->positionY = y; }
	void setGameObjectID(std::string id) { this->gameObjectID = id; }

	float getPositionX()const { return this->positionX; }
	float getPositionY()const { return this->positionY; }
	std::string getGameObjectID() { return gameObjectID; }

	void addGameObject(int xpos, int ypos,  int **gameMap, const int &objType, Position dst);
	void destoryGameObject(int xpos, int ypos, int ** gameMap);
	
	GameObject() 
	{
		amountOfCars = 0;
	}
	~GameObject() {}

};

