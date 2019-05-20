#include "eventMenager.h"

bool eventMenager::checkMouseClickOnGUI(int windowWidth, int GUIposX, int GUIposY, int GUItextureDimension, int mousePosX, int mousePosY,std::string &id,int &objType,bool &simulationIsEnable, bool &deleteButtonPushed)
{
	if (mousePosX > GUIposX && mousePosX < windowWidth)
	{
		/////////////////////////////////////////////////
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && (mousePosY > GUIposY && mousePosY < GUIposY + GUItextureDimension))
		{
			 id = "horizontalRoad";
			 objType = 1;
			 return true;
		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((2 * GUIposY) + GUItextureDimension)) && (mousePosY < ((2 * GUIposY) + (2 * GUItextureDimension)))))
		{
			 id = "verticalRoad";
			 objType = 2;
			 return true;

		}
		/////////////////////////////////////////////////

		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((3 * GUIposY) + (2 * GUItextureDimension))) && (mousePosY < ((3 * GUIposY) + (3 * GUItextureDimension)))))
		{
			id = "turning1";
			objType = 3;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((4 * GUIposY) + (3 * GUItextureDimension))) && (mousePosY < ((4 * GUIposY) + (4 * GUItextureDimension)))))
		{
			id = "turning2";
			objType = 4;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((5 * GUIposY) + (4 * GUItextureDimension))) && (mousePosY < ((5 * GUIposY) + (5 * GUItextureDimension)))))
		{
			id = "turning3";
			objType = 5;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((6 * GUIposY) + (5 * GUItextureDimension))) && (mousePosY < ((6 * GUIposY) + (6 * GUItextureDimension)))))
		{
			
			id = "turning4";
			objType = 6;
			return true;

		}
		/////////////////////////////////////////////////


		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((7 * GUIposY) + (6 * GUItextureDimension))) && (mousePosY < ((7 * GUIposY) + (7 * GUItextureDimension)))))
		{
			id = "simpleCrossing1";
			objType = 7;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((8 * GUIposY) + (7 * GUItextureDimension))) && (mousePosY < ((8 * GUIposY) + (8 * GUItextureDimension)))))
		{
			id = "simpleCrossing2";
			objType = 8;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((9 * GUIposY) + (8 * GUItextureDimension))) && (mousePosY < ((9 * GUIposY) + (9 * GUItextureDimension)))))
		{
			id = "simpleCrossing3";
			objType = 9;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((10 * GUIposY) + (9 * GUItextureDimension))) && (mousePosY < ((10 * GUIposY) + (10 * GUItextureDimension)))))
		{
			 id = "simpleCrossing4";
			 objType = 10;
			 return true;

		}
		/////////////////////////////////////////////////

		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((11 * GUIposY) + (10 * GUItextureDimension))) && (mousePosY < ((11 * GUIposY) + (11 * GUItextureDimension)))))
		{
			id = "crossing";
			objType = 11;
			return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((12 * GUIposY) + (11 * GUItextureDimension))) && (mousePosY < ((12 * GUIposY) + (12 * GUItextureDimension)))))
		{
			 id = "privateBuilding";
			 objType = 12;
			 return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((13 * GUIposY) + (12 * GUItextureDimension))) && (mousePosY < ((13 * GUIposY) + (13 * GUItextureDimension)))))
		{
			 id = "publicBuilding";
			 objType = 13;
			 return true;

		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((14 * GUIposY) + (13* GUItextureDimension))) && (mousePosY < ((14 * GUIposY) + (14 * GUItextureDimension)))))
		{
			id = "simulationButton";
			objType = 14;
			simulationIsEnable = true;
			return true;
		}
		if ((mousePosX > GUIposX && mousePosX < GUIposX + GUItextureDimension) && ((mousePosY > ((15 * GUIposY) + (14 * GUItextureDimension))) && (mousePosY < ((15 * GUIposY) + (15 * GUItextureDimension)))))
		{
			id = "CrossButton";
			objType = 15;
			deleteButtonPushed = true;
			return true;
		}
	}
	return false;
}

bool eventMenager::checkMouseClickOnMap(int windowHeight, int GUIposX, int mousePosX, int mousePosY)
{
	if ((mousePosX < GUIposX && mousePosX > 0) && (mousePosY < windowHeight && mousePosY>0))
	{
		return true;
	}
	return false;
}