#include "Map.h"
void Map::initIndexArray()
{
	int x = 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->indexArray[i][j] = x;
			x++;
		}
	}
}

void Map::loadMap(char* filename, int ObjType)
{
	file.open(filename, std::ios::in | std::ios::out);
	if (!file.good())
	{
		std::cerr << "Failed to open " << std::endl;
	}
	else
	{
		int num = 0;
		for (int i = 0; i < rows; i++) {
			std::getline(file, line);
			std::istringstream iss(line);
			for (int j = 0; j < columns; j++)
			{
				iss >> num;
				if (num == 0)
				{
					gameMap[i][j] = 0;
				}
				else
				{
					std::cerr << "Wrong data format" << std::endl;
				}
			}
		}
	}
	file.close();
}

