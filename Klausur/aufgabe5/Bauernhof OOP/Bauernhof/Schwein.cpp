//Justin Sostmann

#include "Schwein.h"

Schwein::Schwein() : Tier(_term)
{

    _segments ={ {10, 5} , {11,5}, {12,5}, {13,5}, {10,6}, {12,6}, {8, 3}};
}

void Schwein::draw(){
    for (unsigned i=0; i<_segments.size()-1; i++){
        _term.set_cell(_segments[i].x, _segments[i].y, 'S');
    }
}

void Schwein::draw_chosen(){
    draw();
    _term.set_cell(_segments[6].x, _segments[6].y, '*');
    
}

void Schwein::move(char pressed){
 switch (pressed)
    {
    case 'w':
        for (unsigned i=0; i<_segments.size(); i++)
            _segments[i].y--;
        break;
    case 's':
        for (unsigned i=0; i<_segments.size(); i++)
            _segments[i].y++;
        break;
    case 'a':
        for (unsigned i=0; i<_segments.size(); i++)
            _segments[i].x--;
        break;
    case 'd':
        for (unsigned i=0; i<_segments.size(); i++)
            _segments[i].x++;
        break;

    default:
        break;
    }
}