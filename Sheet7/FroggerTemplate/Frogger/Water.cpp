#include "Water.h"
#include "Terminal.h"

Water::Water(): _water_state(1)
{
    _logs = { {79,13}, {78, 13}, {77, 13}, {76, 13}, {75, 13},
                {79,12}, {78, 12}, {77, 12} , {76, 12}, {75, 12},
                    {79,11}, {78, 11}, {77, 11}, {76, 11}, {75, 11} };
}

void Water::move_logs_left(){
    for (unsigned i=0; i<_logs.size(); i++){
        _logs[i].x -= 1; 
        if (_logs[i].x<=0)
            _logs[i].x+=80;
    }
}
void Water::move_logs_right(){
    for (unsigned i=0; i<_logs.size(); i++){
        _logs[i].x += 1;
         if (_logs[i].x>=80)
            _logs[i].x-=80; 
    }

}

void Water::pos_logs1(Water& logs, int n){
    for (unsigned i=0; i<logs._logs.size(); i++){
        logs._logs[i].x -= 13 +n*22; 
    }
}
void Water::pos_logs2(Water& logs, int n){
    for (unsigned i=0; i<logs._logs.size(); i++){
        logs._logs[i].x = logs._logs[i].x -77 + n*14; 
        logs._logs[i].y -= 3; 
    }
}
void Water::pos_logs3(Water& logs, int n){
    for (unsigned i=0; i<logs._logs.size(); i++){
        logs._logs[i].x -= n*22; 
        logs._logs[i].y -= 6;
    }
}

void Water::draw_logs(Terminal& term){
    term.set_cell(_logs[0].x, _logs[0].y, ']', 130);
    term.set_cell(_logs[1].x, _logs[1].y, '_', 130);
    term.set_cell(_logs[2].x, _logs[2].y, '_', 130);
    term.set_cell(_logs[3].x, _logs[3].y, '_', 130);
    term.set_cell(_logs[4].x, _logs[4].y, '[', 130);
    term.set_cell(_logs[5].x, _logs[5].y, ']', 130);
    term.set_cell(_logs[6].x, _logs[6].y, '#', 130);
    term.set_cell(_logs[7].x, _logs[7].y, 'H', 130);
    term.set_cell(_logs[8].x, _logs[8].y, '#', 130);
    term.set_cell(_logs[9].x, _logs[9].y, '[', 130);
    term.set_cell(_logs[10].x, _logs[10].y, ']', 130);
    term.set_cell(_logs[11].x, _logs[11].y, 'T', 130);
    term.set_cell(_logs[12].x, _logs[12].y, 'T', 130);
    term.set_cell(_logs[13].x, _logs[13].y, 'T', 130);
    term.set_cell(_logs[14].x, _logs[14].y, '[', 130);

}

void Water::render_water0(Terminal& term){
    if (_water_state>=21){
        for (int i=0; i< 40; i++){
            term.set_cell(i*2+1, 12, '~', 4);
            term.set_cell(i*2, 10, '~', 4);
            term.set_cell(i*2+1, 8, '~', 4); 
            term.set_cell(i*2, 6, '~', 4);
            term.set_cell(i*2, 12, '~', 12);
            term.set_cell(i*2+1, 10, '~', 12);
            term.set_cell(i*2, 8, '~', 12); 
            term.set_cell(i*2+1, 6, '~', 12);
        }
        _water_state--;
    }else
    if (_water_state<21){
        for (int i=0; i< 40; i++){
            term.set_cell(i*2+1, 12, '~', 12);
            term.set_cell(i*2, 10, '~', 12);
            term.set_cell(i*2+1, 8, '~', 12); 
            term.set_cell(i*2, 6, '~', 12);
            term.set_cell(i*2, 12, '~', 4);
            term.set_cell(i*2+1, 10, '~', 4);
            term.set_cell(i*2, 8, '~', 4); 
            term.set_cell(i*2+1, 6, '~', 4);
        }
        _water_state--; 
    }
    if(_water_state<1){
        _water_state=40;
    }
} 

void Water::render_water1(Terminal& term){
    if (_water_state>=21){
        for (int i=0; i< 40; i++){
            term.set_cell(i*2+1, 13, '~', 12);
            term.set_cell(i*2+1, 11, '~', 12);
            term.set_cell(i*2, 9, '~', 12);
            term.set_cell(i*2+1, 7, '~', 12); 
            term.set_cell(i*2, 5, '~', 12);
            term.set_cell(i*2, 13, '~', 4);
            term.set_cell(i*2, 11, '~', 4);
            term.set_cell(i*2+1, 9, '~', 4);
            term.set_cell(i*2, 7, '~', 4); 
            term.set_cell(i*2+1, 5, '~', 4);
        }
        _water_state--;
    }else
    if (_water_state<21){
        for (int i=0; i< 40; i++){
            term.set_cell(i*2+1, 13, '~', 4);
            term.set_cell(i*2+1, 11, '~', 4);
            term.set_cell(i*2, 9, '~', 4);
            term.set_cell(i*2+1, 7, '~', 4); 
            term.set_cell(i*2, 5, '~', 4);
            term.set_cell(i*2, 13, '~', 12);
            term.set_cell(i*2, 11, '~', 12);
            term.set_cell(i*2+1, 9, '~', 12);
            term.set_cell(i*2, 7, '~', 12); 
            term.set_cell(i*2+1, 5, '~', 12);
        }
        _water_state--; 
    }
    if(_water_state<1){
        _water_state=40;
    }
} 

Vec2D Water::position(int n){
    return _logs[n];
}
