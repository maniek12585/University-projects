#pragma once
#include "Textures.h"
#include <iostream>
#include <string>
class display : public Textures
{
	 const int windowWidth = 1496;
	 const int windowHeight = 920;
	 const int GUIposX = windowWidth - 112;
	 const int GUIposY = 15;
	 int textHeight = 0;
	 int textWidth = 0;

	SDL_Window	*window ;
	SDL_Rect objToRender;
	SDL_Rect txtRect;

	SDL_Surface *txtSurface;
	TTF_Font * font;
	std::string txtToDisplay;
	const char *x;
	SDL_Texture * textTexture;
	bool displayText;
public:

	int getWindowWidth()const { return this->windowWidth; }
	int getWindowHeight()const { return this->windowHeight; }
	int getGUIposX()const { return this->GUIposX; }
	int getGUIposY()const { return this->GUIposY; }
	int getDisplayText() { return displayText; }
	void setDisplayText(bool var) { displayText = var; }

	bool initSDL();
	void initWindow();

	void renderObj(int texture, int positionX, int positionY);
	void renderMap(int rows ,int columns);
	void renderGUI();
	void renderUpdate(int rows, int columns, int **gameMap,  int vehicleContamination);
	void renderVehicles(int positionX, int positionY);
	void renderText(int vehicleContamination);
	void renderClear();
	void renderPresent();
	void clean();

	display() {};

	~display() {}
};

