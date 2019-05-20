#include "Vehicle.h"


void Vehicle::operator --()
{
	int size=this->vehiclePath.size();
	for (int i = 0; i < size; i++)
	{
		this->vehiclePath.pop_back();
	}
	this->pathDetermined=false;
	this->vehicleFinishedHisTravel = false;

}

bool Vehicle::operator==(const Position & x)
{
	return (this->srcPosition.xPos==x.xPos && this->srcPosition.yPos==x.yPos);
}

bool Vehicle::operator!=(const Position & x)
{
	return (this->srcPosition.xPos != x.xPos || this->srcPosition.yPos != x.yPos);
}

Vehicle & Vehicle::operator=(const Vehicle&)
{
	return *this;
}

void Vehicle::initVehiclePath(std::deque<int> &x)
{
	int tmp = 0;
	
	for (int i = 0; i < x.size(); i++)
	{
		this->vehiclePath.push_back(tmp);
	}
	this->vehiclePath.swap(x);
	this->pathDetermined = true;
}

void Vehicle::findSrcAndDstPoints(int **gameMap,int rows,int columns)
{
		//setting src position of vehicle
		//check above
		if (this->srcPosition.yPos - 1 >= 0)
		{
			if (gameMap[this->srcPosition.yPos - 1][this->srcPosition.xPos] != 0 && gameMap[this->srcPosition.yPos-1][this->srcPosition.xPos] != 12 && gameMap[this->srcPosition.yPos-1][this->srcPosition.xPos] != 13)
			{
				this->srcPosition.yPos -= 1;
			}
		}
		//check under
		if (this->srcPosition.yPos + 1 < rows)
		{
			if (gameMap[this->srcPosition.yPos + 1][this->srcPosition.xPos] != 0 && gameMap[this->srcPosition.yPos+1][this->srcPosition.xPos] != 12 && gameMap[this->srcPosition.yPos+1][this->srcPosition.xPos] != 13)
			{
				this->srcPosition.yPos += 1;
			}
		}
		//check on right
		if (this->srcPosition.xPos + 1 < columns)
		{
			if (gameMap[this->srcPosition.yPos][this->srcPosition.xPos + 1] != 0 && gameMap[this->srcPosition.yPos][this->srcPosition.xPos+1] != 12 && gameMap[this->srcPosition.yPos][this->srcPosition.xPos+1] != 13)
			{
				this->srcPosition.xPos += 1;
			}
		}
		//check on left
		if (this->srcPosition.xPos - 1 >= 0)
		{
			if (gameMap[this->srcPosition.yPos][this->srcPosition.xPos - 1] != 0 && gameMap[this->srcPosition.yPos][this->srcPosition.xPos-1] != 12 && gameMap[this->srcPosition.yPos][this->srcPosition.xPos-1] != 13)
			{
				this->srcPosition.xPos -= 1;
			}
		}

		//setting dst position of vehicle
		//check above
		if (this->dstPosition.yPos - 1 >= 0)
		{
			if (gameMap[this->dstPosition.yPos - 1][this->dstPosition.xPos] != 0 && gameMap[this->dstPosition.yPos - 1][this->dstPosition.xPos] != 12 && gameMap[this->dstPosition.yPos - 1][this->dstPosition.xPos] != 13)
			{
				this->dstPosition.yPos -= 1;
			}
		}
		//check under
		if (this->dstPosition.yPos + 1 < rows)
		{
			if (gameMap[this->dstPosition.yPos + 1][this->dstPosition.xPos] != 0 && gameMap[this->dstPosition.yPos + 1][this->dstPosition.xPos] != 12 && gameMap[this->dstPosition.yPos + 1][this->dstPosition.xPos] != 13)
			{
				this->dstPosition.yPos += 1;
			}
		}
		//check on right
		if (this->dstPosition.xPos + 1 < columns)
		{
			if (gameMap[this->dstPosition.yPos][this->dstPosition.xPos + 1] != 0 && gameMap[this->dstPosition.yPos][this->dstPosition.xPos + 1] != 12 && gameMap[this->dstPosition.yPos][this->dstPosition.xPos + 1] != 13)
			{
				this->dstPosition.xPos += 1;
			}
		}
		//check on left
		if (this->dstPosition.xPos - 1 >= 0)
		{
			if (gameMap[this->dstPosition.yPos][this->dstPosition.xPos - 1] != 0 && gameMap[this->dstPosition.yPos][this->dstPosition.xPos - 1] != 12 && gameMap[this->dstPosition.yPos][this->dstPosition.xPos - 1] != 13)
			{
				this->dstPosition.xPos -= 1;
			}
		}
}

Vehicle::Vehicle(Position src, Position dst,int num)
{
	this->srcPosition.xPos = src.xPos;
	this->srcPosition.yPos = src.yPos;
	this->dstPosition.xPos = dst.xPos;
	this->dstPosition.yPos = dst.yPos;
	this->srcPostionOriginal.xPos = src.xPos;
	this->srcPostionOriginal.yPos = src.yPos;

	this->xPos = src.xPos;
	this->yPos = src.yPos;
	
	this->vehicleNum = num;

}

Vehicle::~Vehicle(){}

std::ostream & operator<<(std::ostream & x, Vehicle &vehicle)
{
	std::cout << vehicle.vehicleNum<<" ";
	for (int i = 0; i < vehicle.vehiclePath.size();i++)
	{
		std::cout << vehicle.vehiclePath[i] << " ";
	}
	return x;
}
