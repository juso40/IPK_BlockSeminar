#ifndef GAME_H
#define GAME_H
#include "Terminal.h"
#include "Frog.h"
#include "Car.h"
#include "Vec2D.h"
#include "Water.h"

class Game{
private:
    void draw_game_over();
    void draw_game_won();
   
    Terminal& _term;
    Frog _frog;
    Car _car;
    Water _water;
    std::vector<Car> _cars_left;
    std::vector<Car> _cars_right;
    std::vector<Water> _logs1;
    std::vector<Water> _logs2;
    std::vector<Water> _logs3;
    std::vector<bool> _onanylog;
    int _onlogs;
    bool _death_by_accident;
    bool _death_by_car;
    bool _death_by_water;
    bool _game_over;
    bool _game_won;
    bool _is_done;

public:
    //Spawns more cars facing left
    void initialize_left_cars();
    //Spawns more cars facing right
    void initialize_right_cars();
    //Spawns the logs
    void initialize_logs();
    //returns the quit condition.
     bool is_done();
    //Initializes a new Game
    Game(Terminal& term);   
    //Updates the game/window
    void update();
    //draws all objects/actors
    void draw();



};



#endif