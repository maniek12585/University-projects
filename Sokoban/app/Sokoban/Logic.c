#include "GameState.h"
#include "Logic.h"
#include"GUI.h"

void InitializeGameState(struct GameState *game)
{
	game->player.dx = 0;
	game->player.dy = 0;
	

	game->Wall = NULL;
	game->Floor = NULL;
	game->Floor_with_dot = NULL;
	game->Crate = NULL;
	
	for (int i = 0; i < LogicOuterLoopCount; i++) {
		for (int j = 0; j < LogicInnerLoopCount; j++) {
			if (game->map[i][j] == MAP_WALL) {		
				AddAsset(&(game->Wall), j, i, 0, 0);
			}
			else if (game->map[i][j] == MAP_FLOOR) {		
				AddAsset(&(game->Floor), j, i, 0, 0);
			}
			else if (game->map[i][j] == MAP_FLOOR_DOT) {

				AddAsset(&(game->Floor_with_dot), j, i, 0, 0);
			}
			else if (game->map[i][j] == MAP_CRATE) {

				AddAsset(&(game->Floor), j, i, 0, 0);
				AddCrate(&(game->Crate), j, i, 0, 0);
			}
		}
	}
}

struct Crate *GetCrateIdx(int x, int y, struct Crate *head)
{
	struct Crate *tmp = head;

	while (tmp !=NULL)
	{
		
		if (tmp->x == x && tmp->y == y)
		{
			return tmp;
		}
		tmp = tmp->next;
	}

	return NULL;
}

bool EventsMovementandCollisionDetection(struct GameState *game,struct GUI *window ,bool *set) {
	
	SDL_Event event;
	bool done = false;
	bool doneptr = &done;

	//Checking events
	while (SDL_PollEvent(&event))
	{

		game->move_down = false;
		game->move_up = false;
		game->move_left = false;
		game->move_right = false;


			switch (event.type)
			{
				case SDL_WINDOWEVENT_CLOSE:
				GUIWindowClose(window, set, doneptr);
				break;

				case SDL_QUIT:
				GUIQuit(set, doneptr);
				break;

				case SDL_KEYDOWN:
				{
					switch (event.key.keysym.sym)
					{
						//Movement

					case SDLK_LEFT:
						game->player.dx = -1;
						game->move_left = true;
						break;
					case SDLK_RIGHT:
						game->player.dx = 1;
						game->move_right = true;
						break;
					case SDLK_UP:
						game->player.dy = -1;
						game->move_up = true;
						break;
					case SDLK_DOWN:
						game->player.dy = 1;
						game->move_down = true;
						break;
					}
				}
				break;

			}
			break;

}


	//Collision Detection
	int player_new_x = game->player.x + game->player.dx, player_new_y = game->player.y + game->player.dy;

	bool move_ok = true;
	bool crate_move_ok = true;
	int crate_new_x, crate_new_y;

	if (game->map[player_new_y][player_new_x] == MAP_WALL || game->map[player_new_y][player_new_x] == MAP_NONE)		//checking collision with walls
	{
		move_ok = false;
	}
	else
	{
	 //checking collision with crates
		struct Crate *CrateIdx= GetCrateIdx(player_new_x, player_new_y, game->Crate);
	

		if (CrateIdx)
		{
			crate_new_x = player_new_x + game->player.dx; //crate new x,y
			crate_new_y = player_new_y + game->player.dy;

			if (game->map[crate_new_y][crate_new_x] == MAP_WALL || game->map[crate_new_y][crate_new_x] == MAP_NONE) //checking if the stone will collide with wall or another crate
			{
				crate_move_ok = false;
			}
			else if (GetCrateIdx(crate_new_x, crate_new_y, game->Crate))
			{
				crate_move_ok = false;
			}

			

			if (!crate_move_ok)
			{
				//Cannot move the crate
				move_ok = false;
			}
			else
			{
				//Can move the crate
				
				CrateIdx->x = crate_new_x;
				CrateIdx->y = crate_new_y;

				if (game->map[crate_new_y][crate_new_x] == MAP_FLOOR_DOT)
				{
					  //check if crate is on right place
					CrateIdx->on_dot = true;
				}

			}

			if (!IsLevelComplete(game->Crate)) //checking level condition
			{
				return done = true;
			}
			
			
		}

		
	}

	if (move_ok)
	{
		game->player.x = player_new_x;
		game->player.y = player_new_y;
	}


	game->player.dx = 0;
	game->player.dy = 0;

	SDL_FlushEvent(event.type);  //reset events

	return done;
	
}

bool IsLevelComplete(struct Crate *head)
{
	
	struct Crate *headptr = head;
	
	while (headptr != NULL)
	{
		
		if (!headptr->on_dot)
		{
			return true;
		}
		headptr = headptr->next;
	}

	return false;

	
}

void AddAsset(struct Assets **head, int x,int  y, int w, int h)
{
	
	//dodawanie podstawowych assetów
	
		struct Assets* ptr1 = malloc(sizeof(struct Assets));
		struct Assets* ptr2 = malloc(sizeof(struct Assets));

		ptr2->x = x;
		ptr2->y = y;
		ptr2->w = w;
		ptr2->h = h;
		ptr2->next = NULL;
		ptr1 = *head;

		if (ptr1)
		{
			while (ptr1->next)
			{
				ptr1 = ptr1->next;
			}
			ptr1->next = ptr2;
		}
		else
		{
			*head = ptr2;
		}
	

	}

void AddCrate(struct Crate **head, int x, int  y, int w, int h)
{
	struct Crate* ptr1 = malloc(sizeof(struct Crate));
	struct Crate* ptr2 = malloc(sizeof(struct Crate));

	ptr2->x = x;
	ptr2->y = y;
	ptr2->w = w;
	ptr2->h = h;
	ptr2->on_dot = false;
	ptr2->next = NULL;
	ptr1 = *head;

	if (ptr1)
	{
		while (ptr1->next)
		{
			ptr1 = ptr1->next;
		}
		ptr1->next = ptr2;
	}
	else
	{
		*head = ptr2;
	}

}

void DestroyAsset(struct Assets **head)
{
	while (*head != NULL) 
	{
		struct Assets *tmp = *head;
		(*head) = (*head)->next;
		free(tmp->x);
		tmp->x = NULL;

		free(tmp->y);
		tmp->y = NULL;

		free(tmp->w);
		tmp->w = NULL;

		free(tmp->h);
		tmp->h = NULL;

		free(tmp);
		tmp = NULL;
	}
	
}

void DestroyCrate(struct Crate **cratehead)
{
	while (*cratehead != NULL)
	{
		struct Crate *cratetmp = *cratehead;
		(*cratehead) = (*cratehead)->next;
		free(cratetmp->x);
		cratetmp->x = NULL;

		free(cratetmp->y);
		cratetmp->y = NULL;

		free(cratetmp->w);
		cratetmp->w = NULL;

		free(cratetmp->h);
		cratetmp->h = NULL;

		free(cratetmp->on_dot);
		cratetmp->on_dot = NULL;

		free(cratetmp);
		cratetmp = NULL;
	}

}
