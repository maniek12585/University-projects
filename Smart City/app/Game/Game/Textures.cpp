#include "Textures.h"

bool Textures::loadTextures(const char* textureFileName)
{
			this->surface = IMG_Load(textureFileName);
			if (!(this->surface))
			{
				throw std::exception("Error cannot find texture file");
				return false;
			}
			else 
			{
				textureArr.push_back(SDL_CreateTextureFromSurface(this->renderer, this->surface));
				SDL_FreeSurface(this->surface);
			}
			return true;
}
