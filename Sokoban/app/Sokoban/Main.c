#include "GameState.h"
#include "LoadGame.h"
#include "Logic.h"
#include "Drawing.h"

int main(int argc, char *argv[])
{
	struct GameState gameState;
	struct GUI gui;
	static struct GameState NULLstruct;

	gui.window = NULL;                  
	SDL_Renderer *renderer = NULL;		
	bool done = false;
	bool set = true;
	
	if (argc == 2) {
		int current_level = atoi(argv[1]);

		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

			gui.window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WindowWidth, WindowHeight, 0);
			renderer = SDL_CreateRenderer(gui.window, -1, SDL_RENDERER_ACCELERATED);

			while (set)
			{
				gameState.renderer = renderer;

				if (LoadNextLevel(&gameState, current_level) == false)
				{
					set = false;
					DrawGameOver(gameState.renderer, gameState.textures);
				}
				else {

					LoadTextures(&gameState);
					InitializeGameState(&gameState);

					while (!done)
					{
						doRender(&gameState);

						done = (EventsMovementandCollisionDetection(&gameState, &(gui.window), &set));
					}

					gameState = NULLstruct;
					current_level++;
					done = false;

					DestroyTextures(&gameState);

					DestroyAsset(&gameState.Floor);
					DestroyAsset(&gameState.Floor_with_dot);
					DestroyAsset(&gameState.Wall);

					DestroyCrate(&gameState.Crate);
				}

			}

		}
		system("pause");
		
		SDL_DestroyWindow(gui.window);
		SDL_DestroyRenderer(renderer);

		SDL_Quit();
	}
	
	return 0;
}

