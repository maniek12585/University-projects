#pragma once
#include "SDL.h"
#include <iostream>
#include <string>
class eventMenager
{
	int mousePosX;
	int mousePosY;

public:
	int getMousePosX()const { return mousePosX; }
	int getMousePosY()const { return mousePosY; }
	void setMousePosX(int var) { mousePosX = var; }
	void setMousePosY(int var) { mousePosY = var; }

	bool checkMouseClickOnMap(int windowHeight, int GUIposX, int mousePosX, int mousePosY);
	bool checkMouseClickOnGUI(int windowWidth, int GUIposX, int GUIposY, int GUItextureDimension, int mousePosX, int mousePosY,std::string &id, int &objType,bool &simulationIsEnable, bool &deleteButtonPushed);

	eventMenager(){}
	~eventMenager(){}

};

