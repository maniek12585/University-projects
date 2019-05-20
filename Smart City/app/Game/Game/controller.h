#pragma once
#include "GameObject.h"
#include "display.h"
#include "eventMenager.h"
#include "Map.h"
#include "gameMenager.h"
#include "Graph.h"
#include "gameObjList.h"
#include <windows.h>

class controller
{
	eventMenager eventMenagerObj;
	Map mapObj;
	gameMenager gameMenagerObj;
	display displayObj;
	GameObject gameObject;
	gameObjList gameObjectsList;
	Graph graphObj;
	int objType;
	bool eventVar;
	bool simulationIsEnable;
	bool vehiclePathsSet;
	bool deleteButtonPushed;
	int vehicleStepsCounter;
	bool vehiclesFinishedHisTravel;
	int vehicleContamination;
public:

	display getDisplayObj() { return this->displayObj;}
	
	GameObject getGameObj() { return this->gameObject; }

	eventMenager getEventMenagerObj() { return this->eventMenagerObj; }
	gameMenager getGameMenagerObj() { return this->gameMenagerObj; }

	int getObjType() { return this->objType; }
	bool getEventVar() { return this->eventVar; }
	void setObjType(int var) { this->objType = var; }
	void setEventVar(bool var) { this->eventVar = var; }

	void handleEvents();
	void simulateVehiclesPaths();
	void updateInSimulation();
	int getIdxByPos(int xPos, int yPos);
	int vehiclePositionToIndexOnMapConversion(Position x);
	Position getPosXAndYByIndex(int idx);
	Position findNearestPublicBuildingPos();
	bool checkIfAllVehiclesEndTravel();
	void resetSimulation();
	void gameLoop(char* filename);
	
};

