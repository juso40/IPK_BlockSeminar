#include "Car.h"
#include "Frog.h"
#include "Vec2D.h"
#include <vector>

Car::Car()
{
    _segments = { {72,23},{75,23},{75,24},{74,24},{73,24},{72,24},{72,25},{75,25} };
  
}





void Car::update_l(Car& car){
  for (unsigned i=0; i<car._segments.size(); i++){
      car._segments[i].x -= 1;
      if (car._segments[i].x<0){
          car._segments[i].x += 80;
      }
  }
  
}
void Car::update_r(Car& car){
    for (unsigned i=0; i<car._segments.size(); i++){
      car._segments[i].x += 1;
        if (car._segments[i].x>80){
            car._segments[i].x -= 80;
        }
    }
}


void Car::draw_car_left(Terminal& term){
    term.set_cell(_segments[0].x, _segments[0].y, '-', 1);//upper tire
    term.set_cell(_segments[1].x, _segments[1].y, '-', 1);//upper tire
    term.set_cell(_segments[2].x, _segments[2].y, ']', 1);//windshield
    term.set_cell(_segments[3].x, _segments[3].y, ']', 1);//body
    term.set_cell(_segments[4].x, _segments[4].y, ']', 1);//body
    term.set_cell(_segments[5].x, _segments[5].y, '(', 1);//body
    term.set_cell(_segments[6].x, _segments[6].y, '-', 1);//lower tire
    term.set_cell(_segments[7].x, _segments[7].y, '-', 1);//lower tire
}

void Car::draw_car_right(Terminal& term){
    term.set_cell(_segments[0].x, _segments[0].y, '-', 1);//upper tire
    term.set_cell(_segments[1].x, _segments[1].y, '-', 1);//upper tire
    term.set_cell(_segments[2].x, _segments[2].y, ')', 1);//windshield
    term.set_cell(_segments[3].x, _segments[3].y, '[', 1);//body
    term.set_cell(_segments[4].x, _segments[4].y, '[', 1);//body
    term.set_cell(_segments[5].x, _segments[5].y, '[', 1);//body
    term.set_cell(_segments[6].x, _segments[6].y, '-', 1);//lower tire
    term.set_cell(_segments[7].x, _segments[7].y, '-', 1);//lower tire
}

void Car::pos_left(Car& car, int n){
    for (unsigned i=0; i<car._segments.size(); i++){
            car._segments[i].x = car._segments[i].x - n * 18;
    }
}

void Car::pos_right(Car& car, int n){
    for (unsigned i=0; i<car._segments.size(); i++){
            car._segments[i].x = car._segments[i].x - n * 18;
            car._segments[i].y -= 6;
    }
}

bool Car::check_collision(Car& car, Frog& frog){
    for (unsigned i=0; i<car._segments.size(); i++){
        for (unsigned n=0; n<5; n++){
            if (frog.position(n).x == car._segments[i].x &&
                    frog.position(n).y == car._segments[i].y){
                return true;
            }
        }
    }
    return false;
}