#include "Frog.h"
#include "Vec2D.h"

Frog::Frog()
{
 _body = { {40,26}, {40, 27}, {41, 27}, {39, 27}, {39, 28}, {41, 28} };
}


void Frog::move(char pressed){
    switch (pressed){
        case 'w':
            for (unsigned i=0; i<_body.size(); i++){
                _body[i].y -= 3;
            }
            break;
        case 's':
            for (unsigned i=0; i<_body.size(); i++){
                _body[i].y += 3;
            }
            break;
        case 'a':
            for (unsigned i=0; i<_body.size(); i++){
                _body[i].x -= 3;
            }
            break;
        case 'd':
             for (unsigned i=0; i<_body.size(); i++){
                _body[i].x += 3;
            }
        default:
            break;
    }
}


void Frog::draw_frog(Terminal& term){
    term.set_cell(_body[0].x, _body[0].y, 'o', 10); //Head
    term.set_cell(_body[1].x, _body[1].y, '0', 10); //Body
    term.set_cell(_body[2].x, _body[2].y, '~', 10); //Front left leg
    term.set_cell(_body[3].x, _body[3].y, '~', 10); //Front right leg
    term.set_cell(_body[4].x, _body[4].y, 'v', 10); //Back left leg
    term.set_cell(_body[5].x, _body[5].y, 'v', 10); //Back right leg
}

Vec2D Frog::position(int n){
    Vec2D current_position = _body[n];
    return current_position;
 }

bool Frog::check_win(){
    if (_body[0].y < 3)    
        return true;
    return false;
}

bool Frog::is_on_log_left(Water& log){
    if (_body[0].y==11 || _body[0].y == 5){
        for (unsigned n=11; n<=13; ++n){
           if (log.position(n).x == _body[0].x &&
                    log.position(n).y == _body[0].y){
                return true;
            }
        }
    }
    return false;
}
bool Frog::is_on_log_right(Water& log){
    for (unsigned n=10; n<=14; ++n){
           if (log.position(n).x == _body[0].x&&
                log.position(n).y == _body[0].y){
                return true;
        }
    }
    return false;
}

void Frog::move_with_log(Water& log){    
    if (is_on_log_left(log)==true){
        for (unsigned i=0; i<_body.size(); i++){
            _body[i].x-=1;
        }
    }else
    if (is_on_log_right(log)==true){
        for (unsigned i=0; i<_body.size(); i++){
            _body[i].x+=1;
        }
    }
}

//returns false either if frog is not in water area
//or if his head is on a log
bool Frog::died_in_water(Water& log){
    if (_body[0].y <13 && _body[0].y > 4){
        for (unsigned n=0; n<=14; ++n){
            if (log.position(n).x == _body[0].x&&
                    log.position(n).y == _body[0].y){
                    return false;
            } 
        }
    }
    if (_body[0].y <13 && _body[0].y > 4){
        return true;
    }
    return false;
}

bool Frog::out_of_bounds(){
    if (_body[0].y > 30 || _body[0].x < 0 || _body[0].x > 80)  
        return true;
    return false;
}