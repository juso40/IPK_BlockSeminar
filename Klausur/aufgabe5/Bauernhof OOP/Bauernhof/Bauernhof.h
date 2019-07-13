//Justin Sostmann
#ifndef BAUERNHOF_H
#define BAUERNHOF_H

#include <vector>
#include "Terminal.h"
#include "Tier.h"
#include "Schwein.h"
#include "Katze.h"


class Bauernhof
{
public:
	/**
	* Initializes a new game
	*
	* @param term The terminal to draw our game on
	*/
    Bauernhof(Terminal& term);

	/**
	* Checks whether we are done with our game and should
	* end the game loop.
	*
	* @return True if the game loop is done
	*/
    bool is_done();
	//decides which animal is conrolled
	void controll();
	void last_controll();
	void next_controll();
	/**
	* Advances the game by one step (also called frame)
	*
	* @param dt The time elapsed since the last step in seconds.
	*/
    void update();

	/**
	* Draw the game.
	*/
    void draw();
	

private:
 
    bool _is_done;
    Terminal& _term;
	Katze* _katze;
	Schwein* _schwein;
	std::vector<Tier*> _tiere;
  	int _controlled_animal;
   
};

#endif
