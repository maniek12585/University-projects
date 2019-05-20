#include "GameState.h"
#include "LoadGame.h"

bool LoadMap(struct GameState *game, char *filename) 
{
	FILE *map_file = fopen(filename, "r");
	if (!map_file) { printf("Cannot load the map file!\n\n"); return false; }

	for (int i = 0; i < LogicOuterLoopCount; i++)
	{
		char line[64];
		fgets(line, sizeof(line), map_file);

		for (int j = 0; j < LogicInnerLoopCount; j++)
		{

			if ((line[j]) == '#')
			{
				game->map[i][j] = MAP_WALL;
			}
			if ((line[j]) == '.')
			{
				game->map[i][j] = MAP_FLOOR;
			}
			if ((line[j]) == 'o')
			{
				game->map[i][j] = MAP_FLOOR_DOT;
			}
			if ((line[j]) == 'C')
			{
				game->map[i][j] = MAP_FLOOR;
				game->map[i][j] = MAP_CRATE;
			}
			if ((line[j]) == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				game->map[i][j] = MAP_FLOOR;
			}
			if ((line[j]) == ' ')
			{
				game->map[i][j] = MAP_NONE;
			}
		}

	}
	printf("map loaded");
	fclose(map_file);
	return true;
}

bool LoadNextLevel(struct GameState *game, int current_level)
{
	game->current_level = current_level;
	char file_buffor[32] = { 0 };
	snprintf(file_buffor, sizeof(file_buffor) - 1, "maps/%u.txt", game->current_level);
	return LoadMap(game, file_buffor);
}
