#include "GameState.h"
#include "Drawing.h"

void DestroyTextures(struct GameState *game)
{
	for (int i = 0; i <= 10; i++)
	{
		SDL_DestroyTexture(game->textures[i]);
	}
}

void LoadTextures(struct GameState *game)
{

	SDL_Surface *surface = NULL;

	//*
	//Load images, creating textures
	surface = IMG_Load("game_images/ground.png");
	if (!surface) { printf("Cannot find texture!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_FLOOR] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/ground_wth_dot.png");
	if (!surface) { printf("Cannot find texture!\n\n");  SDL_Quit(); exit(1); }
	game->textures[TEX_FLOOR_DOT] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/player_images/down.png");
	if (!surface) { printf("Cannot find texture!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_PLAYER_IDLE] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/player_images/right.png");
	if (!surface) { printf("Cannot find texture!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_PLAYER_RIGHT] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/player_images/left.png");
	if (!surface) { printf("Cannot find texture!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_PLAYER_LEFT] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/player_images/top.png");
	if (!surface) { printf("Cannot find .png!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_PLAYER_TOP] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/player_images/down.png");
	if (!surface) { printf("Cannot find .png!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_PLAYER_BOT] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/crate.png");
	if (!surface) { printf("Cannot find crate.png!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_CRATE] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/crate_ondot.png");
	if (!surface) { printf("Cannot find crate_ondot.png!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_CRATE_ONDOT] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/brick.png");
	if (!surface) { printf("Cannot find brick.png!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_WALL] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("game_images/gameover.png");
	if (!surface) { printf("Cannot find gameover.png!\n\n"); SDL_Quit(); exit(1); }
	game->textures[TEX_GAME_OVER] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

}

void doRender(struct GameState *game)
{
	SDL_RenderClear(game->renderer);
	SDL_SetRenderDrawColor(game->renderer, 128, 128, 255, 255);
	struct Crate *cratePtr = game->Crate;
	struct Assets *wallPtr = game->Wall;
	struct Assets *flootPtr = game->Floor;
	struct Assets *floor_with_dotPtr = game->Floor_with_dot;
	struct GameState *gameStatePtr = game;
	
	
	//drawing walls
	while (wallPtr != NULL)
	{
		SDL_Rect WallRect = { wallPtr->x*TexturesWidthAndHeight ,wallPtr->y*TexturesWidthAndHeight,TexturesWidthAndHeight,TexturesWidthAndHeight };
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_WALL], NULL, &WallRect);

		wallPtr = wallPtr->next;

	}  
	//drawing floor
	while (flootPtr != NULL)
	{
		SDL_Rect FloorRect = { flootPtr->x*TexturesWidthAndHeight,flootPtr->y*TexturesWidthAndHeight,TexturesWidthAndHeight,TexturesWidthAndHeight };
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_FLOOR], NULL, &FloorRect);

		flootPtr = flootPtr->next;

	}  
	//drawing floor with dot
	while (floor_with_dotPtr != NULL)
	{
		SDL_Rect Floor_with_dot_Rect = { floor_with_dotPtr->x*TexturesWidthAndHeight,floor_with_dotPtr->y*TexturesWidthAndHeight,TexturesWidthAndHeight,TexturesWidthAndHeight };
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_FLOOR_DOT], NULL, &Floor_with_dot_Rect);

		floor_with_dotPtr = floor_with_dotPtr->next;

	}


	//drawing player
	SDL_Rect destinationRect = { gameStatePtr->player.x*TexturesWidthAndHeight,gameStatePtr->player.y*TexturesWidthAndHeight,TexturesWidthAndHeight,TexturesWidthAndHeight };

	if (gameStatePtr->move_right)
	{
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_PLAYER_RIGHT], NULL, &destinationRect);
	}
	else if (gameStatePtr->move_left)
	{
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_PLAYER_LEFT], NULL, &destinationRect);
	}
	else if (gameStatePtr->move_up)
	{
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_PLAYER_TOP], NULL, &destinationRect);
	}
	else if (gameStatePtr->move_down)
	{
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_PLAYER_BOT], NULL, &destinationRect);
	}
	else
	{
		SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_PLAYER_IDLE], NULL, &destinationRect);
	}

	//drawing crate
	while (cratePtr != NULL)
	{
		SDL_Rect crateRect = { cratePtr->x*TexturesWidthAndHeight,cratePtr->y*TexturesWidthAndHeight,TexturesWidthAndHeight,TexturesWidthAndHeight };
		
		if (cratePtr->on_dot)
		{
			SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_CRATE_ONDOT], NULL, &crateRect);
		}
		else
		{
			SDL_RenderCopy(gameStatePtr->renderer, gameStatePtr->textures[TEX_CRATE], NULL, &crateRect);
		}

		cratePtr = cratePtr->next;

	}  

	

	SDL_RenderPresent(gameStatePtr->renderer);
}

void DrawGameOver(struct SDL_Renderer *renderer, struct SDL_Texture *textures[])
{

	SDL_Surface *surface = NULL;
	surface = IMG_Load("game_images/gameover.png");
	if (!surface) { printf("Cannot find gameover.png!\n\n"); SDL_Quit(); exit(1); }
	textures[TEX_GAME_OVER] = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect gameoverRect = { 108,232,600,128 };
	SDL_RenderCopy(renderer, textures[TEX_GAME_OVER], NULL, &gameoverRect);
	SDL_RenderPresent(renderer);
}

