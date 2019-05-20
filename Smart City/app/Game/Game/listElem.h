#pragma once
#include <iostream>
#include <string>
class listElem
{
	listElem *next;
	std::string gameObjID;
	int xPos;
	int yPos;
	int idxInArray;

public:
	listElem *getNextPtr() { return this->next; }
	void setNextPtr(listElem *ptr) { this->next = ptr; }

	std::string getGameObjID() { return this->gameObjID; }
	void setGameObjID(std::string id) { this->gameObjID = id; }

	int getXPos() { return this->xPos; }
	void setXPos(int x) { this->xPos = x; }

	int getYPos() { return this->yPos; }
	void setYPos(int y) { this->yPos = y; }

	int getIdxInArray() { return this->idxInArray; }
	void setIdxInArray(int x) { this->idxInArray = x; }

	listElem() 
	{
		this->next = nullptr; 
		gameObjID = " ";
		xPos = 0;
		yPos = 0;
		idxInArray = 0;
	};
	~listElem() {};
};