#pragma once
#include <stack>
#include <deque>
#include <iostream>
//self defined type describing "source and destionation points for vehicle" 
struct Position
{
	int xPos;
	int yPos;

};
class Vehicle
{

	Position srcPosition; //starting position from private building
	Position dstPosition; // ending position to public building

	Position srcPostionOriginal;

	int xPos;
	int yPos;
	const float vehicleRange = 200;
	bool pathDetermined = false;
	bool vehicleFinishedHisTravel = false;


public:

	int vehicleNum;

	std::deque<int>vehiclePath;
	
	Position getSrcPosition() { return this->srcPosition; }
	Position getDstPosition() { return this->dstPosition; }

	Position getSrcPostionOriginal() { return this->srcPostionOriginal; }

	void operator--();
	bool operator==(const Position &x);
	bool operator!=(const Position &x);

	friend std::ostream & operator <<(std::ostream & x, Vehicle &vehicle);

	Vehicle &operator=(const Vehicle&);


	int getXPos() { return this->xPos; }
	int getYPos() { return this->yPos; }

	bool getPathDetermined() { return this->pathDetermined; }
	bool getVehicleFinishedHisTravel() { return this->vehicleFinishedHisTravel; }
	void setVehicleFinishedHisTravel(bool x) { this->vehicleFinishedHisTravel = x; }

	void setSrcPosition(Position x) { this->srcPosition = x; }
	void setDstPosition(Position x) { this->dstPosition = x; }

	void setXPos(int x) { this->xPos = x; }
	void setYPos(int x) { this->yPos = x; }

	void setPathDetermined(bool x) { this->pathDetermined = x; }

	void initVehiclePath(std::deque<int>& x);

	void findSrcAndDstPoints(int **gameMap, int rows, int columns);
	
	Vehicle(Position src, Position dst,int num);

	~Vehicle();
};
