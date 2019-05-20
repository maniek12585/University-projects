#include "display.h"

bool display::initSDL()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	else
	{
		TTF_Init();

		return true;
	}
}

void display::renderClear()
{
	SDL_SetRenderDrawColor(getRenderer(), 229, 228, 226, 1.0);
	SDL_RenderClear(getRenderer());
}

void display::renderPresent()
{
	SDL_RenderPresent(getRenderer());
}

void display::renderObj(int texture, int positionX, int positionY)
{
	objToRender = { positionX,positionY,getTextureDimension(),getTextureDimension() };
	SDL_RenderCopy(getRenderer(),(textureArr[texture]), nullptr, &objToRender);
}

void display::renderMap(int rows ,int columns)
{
	this->renderClear();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <columns; j++)
		{
			this->renderObj(getMapGround(), j*(getTextureDimension()), i*(getTextureDimension()));
		}
	}
	this->renderPresent();
}

void display::renderGUI() 
{
	for (int i = 0; i < (((textureArr).size())-1)-1; i++) {

		if (i != (((textureArr).size()) - 1)-1) 
		{
			objToRender = { GUIposX,(((GUIposY*(i + 1))) + (i*(getGUItextureDimension()))),getGUItextureDimension(),getGUItextureDimension() };
			SDL_RenderCopy((getRenderer()), (textureArr[i + 1]), nullptr, &objToRender);
		}
	}
	this->renderPresent();
}

void display::renderVehicles(int positionX, int positionY)
{
	objToRender = { (positionX)*(getTextureDimension()) + 16,(positionY)*(getTextureDimension()) + 16,32,32 };
	SDL_RenderCopy(getRenderer(), (textureArr[(textureArr.size()) - 1]), nullptr, &objToRender);

	this->renderPresent();

}

void display::renderText(int vehicleContamination)
{
	if (displayText) {
		std::string vehicleCont = std::to_string(vehicleContamination);
		SDL_Color color = { 0,0,0 };
		txtToDisplay = "Current contamination level : " + vehicleCont;
		x = txtToDisplay.c_str();
		font = TTF_OpenFont("arial.ttf", 25);

		txtSurface = TTF_RenderText_Solid(font, x, color);

		textTexture = SDL_CreateTextureFromSurface(getRenderer(), txtSurface);

		SDL_FreeSurface(txtSurface);

		SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
		txtRect = { getTextureDimension(), windowHeight - 55, textWidth,textHeight };
		SDL_RenderCopy(getRenderer(), textTexture, NULL, &txtRect);

	}
}

void display::renderUpdate(int rows, int columns,int **gameMap,int vehicleContamination)
{
	this->renderClear();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (gameMap[i][j] == getMapGround())
			{
				this->renderObj(getMapGround(), j*(getTextureDimension()), i*(getTextureDimension()));
			}

			//////////////////////////
			if (gameMap[i][j] == getMapVerticalRoad())
			{
				this->renderObj(getMapVerticalRoad(), j*(getTextureDimension()), i*(getTextureDimension()));
			}

			if (gameMap[i][j] == getMapHorizontalRoad())
			{
				this->renderObj(getMapHorizontalRoad(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			//////////////////////////


			if (gameMap[i][j] == getMapTurning1())
			{
				this->renderObj(getMapTurning1(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			if (gameMap[i][j] == getMapTurning2())
			{
				this->renderObj(getMapTurning2(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			if (gameMap[i][j] == getMapTurning3())
			{
				this->renderObj(getMapTurning3(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			if (gameMap[i][j] == getMapTurning4())
			{
				this->renderObj(getMapTurning4(), j*(getTextureDimension()), i*(getTextureDimension()));
			}


			///////////////////////////////
			if (gameMap[i][j] == getMapCrossing())
			{
				this->renderObj(getMapCrossing(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			//////////////////////////////

			if (gameMap[i][j] == getMapSimpleCrossing1())
			{
				this->renderObj(getMapSimpleCrossing1(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			if (gameMap[i][j] == getMapSimpleCrossing2())
			{
				this->renderObj(getMapSimpleCrossing2(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			if (gameMap[i][j] == getMapSimpleCrossing3())
			{
				this->renderObj(getMapSimpleCrossing3(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			if (gameMap[i][j] == getMapSimpleCrossing4())
			{
				this->renderObj(getMapSimpleCrossing4(), j*(getTextureDimension()), i*(getTextureDimension()));
			}

			//////////////////////////////////
			if (gameMap[i][j] == getMapPrivateBuilding())
			{
				this->renderObj(getMapPrivateBuilding(), j*(getTextureDimension()), i*(getTextureDimension()));
			}

			if (gameMap[i][j] == getMapPublicBuilding())
			{
				this->renderObj(getMapPublicBuilding(), j*(getTextureDimension()), i*(getTextureDimension()));
			}
			///////////////////////////////////
		}
	}

	this->renderText(vehicleContamination);

	this->renderGUI();
}

void display::clean()
{
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	std::cout << "Game Over" << std::endl;
}

void display::initWindow() 
{
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
	setRenderer(SDL_CreateRenderer(window, -1, 0));
	setSurface(nullptr);
	txtSurface = nullptr;
}


