#ifndef CAR_H
#define CAR_H
#include "Vec2D.h"
#include "Terminal.h"
#include "Frog.h"
#include <vector>
class Car{
private:
    std::vector<Vec2D> _segments;

public:
    Car();
    //Draws the cars hat face left
    void draw_car_left(Terminal& term);
    //Draws the cars that face right
    void draw_car_right(Terminal& term);
    //updates all cars to left.
    void update_l(Car& car);
    //updates all cars to right.
    void update_r(Car& car);
    //Changes start position of left
    void pos_left(Car& cars, int n);
    //Changes start position of right
    void pos_right(Car& cars, int n);
    //Checks collision with frog
    bool check_collision(Car& car, Frog& frog);


};

#endif