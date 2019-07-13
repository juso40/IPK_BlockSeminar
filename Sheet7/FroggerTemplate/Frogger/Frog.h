#ifndef FROG_H
#define FROG_H
#include "Vec2D.h"
#include "Terminal.h"
#include "Water.h"
#include <vector>

class Frog{
private:
    std::vector<Vec2D> _body;
public:
    Frog();
    void draw_frog(Terminal& term);
    void move(char pressed);
    //retuns the hitbox of the frog
    Vec2D position(int n);
    //checks if frog crossed road
    bool check_win();
    
    bool is_on_log_left(Water& log);
    bool is_on_log_right(Water& log);
    void move_with_log(Water& log);

    //Returns bool, if fallen in water.
    bool died_in_water(Water& log);

    bool out_of_bounds();
};



#endif