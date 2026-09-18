#include "Game.h"
#include <iostream>
#include <raylib.h>

int main ()
{

	while (true) {
		Game &game = Game::GetInstance ();
		game.Tick ();
		if (game.ShouldQuit ())
			break;
	}

	return 0;
}
