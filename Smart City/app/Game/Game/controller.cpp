#include "Controller.h"
void controller::gameLoop(char* filename)
{
	this->simulationIsEnable = false;
	this->eventVar = false;
	this->vehiclePathsSet = false;
	this->deleteButtonPushed = false;
	this->vehicleStepsCounter = 0;
	this->vehicleContamination = 0;
	this->vehiclesFinishedHisTravel = false;
	this->gameMenagerObj.setIsRunning(this->displayObj.initSDL());
	
	this->displayObj.initWindow();
	
	this->displayObj.loadTextures("textures/ground.png");
	this->displayObj.loadTextures("textures/horizontalRoad.png");
	this->displayObj.loadTextures("textures/verticalRoad.png");
	this->displayObj.loadTextures("textures/turning1.png");
	this->displayObj.loadTextures("textures/turning2.png");
	this->displayObj.loadTextures("textures/turning3.png");
	this->displayObj.loadTextures("textures/turning4.png");
	this->displayObj.loadTextures("textures/SimpleCrossing1.png");
	this->displayObj.loadTextures("textures/SimpleCrossing2.png");
	this->displayObj.loadTextures("textures/SimpleCrossing3.png");
	this->displayObj.loadTextures("textures/SimpleCrossing4.png");
	this->displayObj.loadTextures("textures/crossing.png");
	this->displayObj.loadTextures("textures/PrivateBuilding.png");
	this->displayObj.loadTextures("textures/PublicBuilding.png");
	this->displayObj.loadTextures("textures/simulateButton.png");
	this->displayObj.loadTextures("textures/Cross.png");
	this->displayObj.loadTextures("textures/car.png");


	if (!(this->gameMenagerObj.getIsRunning()))
	{
		this->displayObj.clean();
	}
	else
	{
		this->mapObj.loadMap(filename, this->displayObj.getMapGround());
		this->mapObj.initIndexArray();
		this->displayObj.renderMap(this->mapObj.getRows(), this->mapObj.getColumns());
	}

	while (this->gameMenagerObj.getIsRunning())
	{
		this->handleEvents();

		if (!this->gameMenagerObj.getIsRunning())
		{
			break;
		}
		else {

			if (this->simulationIsEnable)
			{
				if (!this->vehiclePathsSet)
				{
					if (!this->graphObj.getGraphInitialised())
					{
						this->graphObj.initGraph(273);
					}
					this->graphObj.matrixToGraph(this->mapObj.getMap(), this->mapObj.getIndexArray(), this->mapObj.getColumns(), this->mapObj.getRows());
					this->simulateVehiclesPaths();
				}
				if (!this->checkIfAllVehiclesEndTravel())
				{		
					this->updateInSimulation();
				}
				this->displayObj.renderUpdate(this->mapObj.getRows(), this->mapObj.getColumns(), this->mapObj.getMap(),vehicleContamination);

				for (int i = 0; i < (this->gameObject.vehicleArray.size()); i++)
				{
					if (this->gameObject.vehicleArray[i].getVehicleFinishedHisTravel() == false)
					{
						this->displayObj.renderVehicles(this->gameObject.vehicleArray[i].getXPos(), this->gameObject.vehicleArray[i].getYPos());
					}
				}
				Sleep(600);
			}
			else 
			{
				this->displayObj.renderUpdate(this->mapObj.getRows(), this->mapObj.getColumns(), this->mapObj.getMap(),vehicleContamination);
				this->displayObj.renderPresent();
			}
		}
	}
	this->displayObj.clean();
}

void controller::handleEvents()
{
	int mousePosX;
	int mousePosY;
	int objTypeTmp;
	bool tmp = false;
	bool deleteVar = false;
	SDL_Event evnt;
	std::string id;
	while (SDL_PollEvent(&evnt))
	{

		switch (evnt.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
			break;
		case SDL_QUIT:
			break;
		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				this->gameMenagerObj.setIsRunning(false);
				break;

			case SDLK_s:
				this->resetSimulation();
				std::cout << "Simulation finished" << std::endl;
				this->vehicleContamination = 0;
				this->displayObj.setDisplayText(false);

				for (int i = 0; i < gameObject.vehicleArray.size(); i++)
				{
					std::cout << this->gameObject.vehicleArray[i] << std::endl;
				}
			}
			break;

		case SDL_MOUSEBUTTONDOWN:

			SDL_GetMouseState(&mousePosX, &mousePosY);
			this->eventMenagerObj.setMousePosX(mousePosX);
			this->eventMenagerObj.setMousePosY(mousePosY);

			if (this->eventMenagerObj.checkMouseClickOnGUI(this->displayObj.getWindowWidth(), this->displayObj.getGUIposX(), this->displayObj.getGUIposY(), this->displayObj.getGUItextureDimension(), this->eventMenagerObj.getMousePosX(), this->eventMenagerObj.getMousePosY(), id, objTypeTmp, tmp, deleteVar))
			{
				if (tmp)
				{
					this->simulationIsEnable = tmp;
					this->displayObj.setDisplayText(true);
				}
				else if (deleteVar)
				{
					this->deleteButtonPushed = deleteVar;
				}
				else {
					this->setObjType(objTypeTmp);
					this->gameObject.setGameObjectID(id);
					this->setEventVar(true);
					
				}
			}
			break;

		case SDL_MOUSEBUTTONUP:

			SDL_GetMouseState(&mousePosX, &mousePosY);

			this->eventMenagerObj.setMousePosX(mousePosX);
			this->eventMenagerObj.setMousePosY(mousePosY);

			if (this->simulationIsEnable)
			{
				break;
			}
			else if (this->deleteButtonPushed)
			{
				if (this->getEventVar() && this->eventMenagerObj.checkMouseClickOnMap(this->displayObj.getWindowHeight(), this->displayObj.getGUIposX(), this->eventMenagerObj.getMousePosX(), this->eventMenagerObj.getMousePosY()))
				{
					objTypeTmp = this->getObjType();
					this->gameObjectsList.operator--(this->mapObj.getIndexArray()[mousePosY / (this->displayObj.getTextureDimension())][ mousePosX / (this->displayObj.getTextureDimension())]);
					this->gameObject.destoryGameObject(mousePosX / (this->displayObj.getTextureDimension()), mousePosY / (this->displayObj.getTextureDimension()), this->mapObj.getMap());
					this->deleteButtonPushed = false;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (this->getEventVar() && this->eventMenagerObj.checkMouseClickOnMap(this->displayObj.getWindowHeight(), this->displayObj.getGUIposX(), this->eventMenagerObj.getMousePosX(), this->eventMenagerObj.getMousePosY()))
				{
					objTypeTmp = this->getObjType();
					this->gameObjectsList.add(this->gameObject.getGameObjectID(), mousePosX / (this->displayObj.getTextureDimension()), mousePosY / (this->displayObj.getTextureDimension()), this->mapObj.getIndexArray());
					this->gameObject.addGameObject(mousePosX / (this->displayObj.getTextureDimension()), mousePosY / (this->displayObj.getTextureDimension()), this->mapObj.getMap(), objTypeTmp, this->findNearestPublicBuildingPos());
				}
				else
				{
					break;
				}
			}
		}
		break;
	}
}

void controller::simulateVehiclesPaths()
{
	this->vehicleStepsCounter = 0;

	for (int i = 0; i < ((this->gameObject.vehicleArray).size()); i++)
	{
		if (!this->gameObject.vehicleArray[i].getPathDetermined())
		{
			if ((this->gameObject.vehicleArray[i].vehiclePath).size() == 0)
			{
				this->gameObject.vehicleArray[i].findSrcAndDstPoints(this->mapObj.getMap(), this->mapObj.getRows(), this->mapObj.getColumns());
				this->graphObj.findShortestPath((this->vehiclePositionToIndexOnMapConversion(this->gameObject.vehicleArray[i].getSrcPosition())), (this->vehiclePositionToIndexOnMapConversion(this->gameObject.vehicleArray[i].getDstPosition())));
				this->gameObject.vehicleArray[i].initVehiclePath(graphObj.shortestPath);
			}
		}
	}
	this->vehiclePathsSet = true;
}

void controller::updateInSimulation()
{
	for (int i = 0; i < (this->gameObject.vehicleArray.size()); i++)
	{
		if (this->vehicleStepsCounter >= (this->gameObject.vehicleArray[i]).vehiclePath.size())
		{
			this->gameObject.vehicleArray[i].setVehicleFinishedHisTravel(true);
		}
		else
		{
			int tmp = (this->gameObject.vehicleArray[i]).vehiclePath[this->vehicleStepsCounter];
			//setting new position for vehicle

			this->gameObject.vehicleArray[i].setXPos((this->getPosXAndYByIndex(tmp)).xPos);

			this->gameObject.vehicleArray[i].setYPos((this->getPosXAndYByIndex(tmp)).yPos);
		}
		this->vehicleContamination += (1 * 28);
		//contamination lvl calculated based on number of cells that cars are moveing by one loop iteration times const number
	}

	this->vehicleStepsCounter++;
}

int controller::vehiclePositionToIndexOnMapConversion(Position x)
{
	int tmpIdx = this->mapObj.getIndexArray()[x.yPos][x.xPos];
	return tmpIdx;
}

Position controller::getPosXAndYByIndex(int idx)
{
	Position tmp;
	for (int i = 0; i < this->mapObj.getRows(); i++)
	{
		for (int j = 0; j < this->mapObj.getColumns(); j++)
		{
			if ((this->mapObj.getIndexArray()[i][j]) == idx)
			{
				tmp.xPos = j ;
				tmp.yPos = i ;
				return tmp;
			}
		}
	}
}

int controller::getIdxByPos(int xPos, int yPos)
{
	return this->mapObj.getIndexArray()[yPos][xPos];
}

Position controller::findNearestPublicBuildingPos()
{
	
	Position foundDstPos;
	foundDstPos.xPos = 0;
	foundDstPos.yPos = 0;

	listElem *tmp = this->gameObjectsList.head;
	while (tmp)
	{
		if (tmp->getGameObjID() == "publicBuilding")
		{
			foundDstPos.xPos = tmp->getXPos();
			foundDstPos.yPos = tmp->getYPos();
			return  foundDstPos;
		}
		tmp = tmp->getNextPtr();
	}
	return foundDstPos;
}

bool controller::checkIfAllVehiclesEndTravel()
{
	for (int i = 0; i < (this->gameObject.vehicleArray.size()); i++)
	{
		if (this->gameObject.vehicleArray[i].getVehicleFinishedHisTravel() == false) 
		{
		return false;
		}
	}
	return true;
}

void controller::resetSimulation()
{
	this->simulationIsEnable = false;
	this->graphObj.setGraphInitialised(false);
	this->vehiclePathsSet = false;
	for (int i = 0; i < ((this->gameObject.vehicleArray).size()); i++)
	{
		this->gameObject.vehicleArray[i].operator--();
	}
}


