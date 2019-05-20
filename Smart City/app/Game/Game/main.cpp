#include "controller.h"

int main(int argc, char* args[])
{
	controller game;
	game.gameLoop(args[1]);

	return 0; 
}
