#include "Game.h"

Game::Game(Terminal& term): _term(term),
    _death_by_accident(false), _death_by_car(false), 
        _death_by_water(false), _game_over(false), _game_won(false), _is_done(false)
{

}
void Game::initialize_left_cars(){
    for (int i = 0; i<5; i++){
        _cars_left.push_back(_car);
    } 
    for (unsigned n=0; n<_cars_left.size(); n++){
       _cars_left[n].pos_left(_cars_left[n], n);
    }
}

void Game::initialize_right_cars(){
    for (int i = 0; i<5; i++){
        _cars_right.push_back(_car);
    }
    for (unsigned n=0; n<_cars_right.size(); n++){
       _cars_right[n].pos_right(_cars_right[n], n);
    }
}

void Game::initialize_logs(){
    for (int i = 0; i<3; i++){
       _logs1.push_back(_water);
       _logs2.push_back(_water);
       _logs3.push_back(_water);
    }
    for (unsigned n=0; n < _logs1.size(); n++){
        _logs1[n].pos_logs1(_logs1[n], n);
        _logs2[n].pos_logs2(_logs2[n], n);
        _logs3[n].pos_logs3(_logs3[n], n);
    }
}


bool Game::is_done() 
{
    return _is_done;
}

void Game::update(){

    if (_game_over==false && _game_won==false){
        _onanylog.clear();
        for (unsigned i=0; i<_logs1.size(); i++){
            _onanylog.push_back(_frog.died_in_water(_logs1[i]));
            _onanylog.push_back(_frog.died_in_water(_logs2[i]));
            _onanylog.push_back(_frog.died_in_water(_logs3[i]));
        }
        _onlogs = 0;
        for (unsigned i=0; i<_onanylog.size(); i++){
            if (_onanylog[i] == false){
                _onlogs++;
            }
        }
        if (_onlogs<1){
            _death_by_water = true;
            _game_over=true;
        }
    }


    char pressed = _term.get_key();
    switch (pressed) {
    case 'r':
        _game_over = false;
        _game_won = false;
        _frog = Frog();
        _onlogs = 0;
        _death_by_accident = false;
        _death_by_car = false;
        _death_by_water = false;
        break;
    case 'q':
        _is_done=true;
        break;
    default:
        _frog.move(pressed);
        break;
    }

    if (_game_over==false && _game_won==false){
        for (unsigned i=0; i<_cars_left.size(); i++)
            _cars_left[i].update_l(_cars_left[i]);
        for (unsigned i=0; i<_cars_right.size(); i++)
            _cars_right[i].update_r(_cars_right[i]);

        //moves the logs and the frog, if he's on a log
        for (unsigned i=0; i<_logs1.size(); i++){
            _logs1[i].move_logs_left();
            _frog.move_with_log(_logs1[i]);
            _logs3[i].move_logs_left();
            _frog.move_with_log(_logs2[i]);
            _logs2[i].move_logs_right();
            _frog.move_with_log(_logs3[i]);
        }   
        
        for (unsigned i=0; i<_cars_right.size(); i++){
            if ( (_cars_right[i].check_collision(_cars_right[i], _frog) == true) ){
                _death_by_car=true;
                _game_over=true;
            }
        }
        for (unsigned i=0; i<_cars_left.size(); i++){
            if ( (_cars_left[i].check_collision(_cars_left[i], _frog) == true) ){
                _death_by_car=true;
                _game_over=true;
            }
        }

        if (_frog.out_of_bounds()==true){
            _death_by_accident=true;
            _game_over=true;
        }

        if (_frog.check_win()){
            _game_won = true;
        }
    }
}

void Game::draw(){

    _term.clear();

    _water.render_water0(_term);
    _water.render_water1(_term);
    
    for (auto logs: _logs1)
        logs.draw_logs(_term);
    for (auto logs: _logs2)
        logs.draw_logs(_term);
    for (auto logs: _logs3)
        logs.draw_logs(_term);
    
    _frog.draw_frog(_term);
    for (auto LCars: _cars_left)
        LCars.draw_car_left(_term);
    for (auto RCars: _cars_right)
        RCars.draw_car_right(_term);

    if (_game_over){
        draw_game_over();
    }
    if (_game_won){
        draw_game_won();
    }
    _term.sleep(42);
}

void Game::draw_game_over() 
{
    std::string score_text;
    if (_death_by_accident == true) 
        score_text = "Game Over! You lost controll over your frog. This wasn't supposed to happen!" ;
    if (_death_by_car == true) 
        score_text = "Game Over! Your frog got hit by a car." ;
    if (_death_by_water == true) 
        score_text = "Game Over! Your frog forgot how to swim." ;
    
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

void Game::draw_game_won() 
{
    std::string score_text = "Congratulation! You crossed the road." ;
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}