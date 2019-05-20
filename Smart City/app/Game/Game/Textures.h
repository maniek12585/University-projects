#pragma once
#include <vector>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

class Textures
{
	 const int mapGround = 0;
	 const int mapHorizontalRoad = 1;
	 const int mapVerticalRoad = 2;
	 const int mapTurning1 = 3;
	 const int mapTurning2 = 4;
	 const int mapTurning3 = 5;
	 const int mapTurning4 = 6;
	 const int mapSimpleCrossing1 = 7;
	 const int mapSimpleCrossing2 = 8;
	 const int mapSimpleCrossing3 = 9;
	 const int mapSimpleCrossing4 = 10;
	 const int mapCrossing = 11;
	 const int mapPrivateBuilding = 12;
	 const int mapPublicBuilding = 13;
	 const int simulationButton = 14;
	 const int crossButton = 15;

	 const int textureDimension = 64;
	 const int GUItextureDimnesion = 45;

	SDL_Renderer *renderer;
	SDL_Surface *surface;
	

public:

	std::vector<SDL_Texture*>textureArr;

	int getMapGround()const { return this->mapGround; }
	int getMapVerticalRoad()const { return this->mapVerticalRoad; }
	int getMapHorizontalRoad()const { return this->mapHorizontalRoad; }
	
	int getMapSimpleCrossing1()const { return this->mapSimpleCrossing1; }
	int getMapSimpleCrossing2()const { return this->mapSimpleCrossing2; }
	int getMapSimpleCrossing3()const { return this->mapSimpleCrossing3; }
	int getMapSimpleCrossing4()const { return this->mapSimpleCrossing4; }
	
	int getMapCrossing()const { return this->mapCrossing; }
	int getMapPrivateBuilding()const { return this->mapPrivateBuilding; }
	int getMapPublicBuilding()const { return this->mapPublicBuilding; }
	
	int getMapTurning1()const { return this->mapTurning1; }
	int getMapTurning2()const { return this->mapTurning2; }
	int getMapTurning3()const { return this->mapTurning3; }
	int getMapTurning4()const { return this->mapTurning4; }
	
	SDL_Renderer *getRenderer()const { return this->renderer; }
	SDL_Surface *getSurface()const { return this->surface; }
	void setRenderer(SDL_Renderer* var) { this->renderer = var; }
	void setSurface(SDL_Surface* var) { this->surface = var; }

	int getTextureDimension()const { return this->textureDimension; }
	int getGUItextureDimension()const { return this->GUItextureDimnesion; }

	bool loadTextures(const char* textureFileName);

	Textures() {}
	~Textures() {}
};

