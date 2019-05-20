#pragma once
#include <iostream>
#include <fstream>
#include <sstream> 
class Map
{
	const int rows = 13;
	const int columns = 21;
	int **gameMap = new int *[columns];
	int **indexArray = new int *[columns];
	
public:
	std::ifstream file;
	std::string line;

	int getRows()const { return rows; }
	int getColumns()const { return columns; }
	
	int **getMap() { return this->gameMap; }
	int **getIndexArray() { return this->indexArray; }
	void initIndexArray();

	void loadMap(char * filename, int ObjType);

	Map()
	{
		for (int i = 0; i < columns; i++)
		{
			this->gameMap[i] = new int[rows];
			this->indexArray[i] = new int[rows];
		}

	}

	~Map()
	{
		for (int i = 0; i < columns; i++)
		{
			delete this->gameMap[i];
			delete this->indexArray[i];
		}
		delete[] this->gameMap;
		delete[] this->indexArray;
	}
};



