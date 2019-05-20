#include "GameState.h"

void GUIWindowClose( SDL_Window *window, bool *set, bool *done)
{
	if (window)
	{
		SDL_DestroyWindow(window);
		window = NULL;
		*done = true;
		*set = false;
	}
}
void GUIQuit(bool *set, bool *done)
{
	*done = true;
	*set = false;

}