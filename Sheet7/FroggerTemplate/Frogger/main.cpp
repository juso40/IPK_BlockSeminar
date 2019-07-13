#include "Terminal.h"
#include "Game.h"
#include "Frog.h"
#include "Car.h"
#include <iostream>

int main()
{
	
	Terminal term(80, 30);
	Game game(term);
	game.initialize_left_cars();
	game.initialize_right_cars();
	game.initialize_logs();
	while (!game.is_done()) {
      
        game.update();
        game.draw();
	}
	term.close();
	return 0;
}
