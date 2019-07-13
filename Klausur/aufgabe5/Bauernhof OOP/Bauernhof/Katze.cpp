//Justin Sostmann
#include "Katze.h"

Katze::Katze() : Tier(_term)
{
    _segments ={ {10, 15} , {11,15}, {12,15}, {13,15}, {10,16}, {12,16}, {8,13}};
}
void Katze::draw(){
    for (unsigned i=0; i<_segments.size()-1; i++){
        _term.set_cell(_segments[i].x, _segments[i].y, 'K');
    }
}

void Katze::draw_chosen(){
    draw();
    _term.set_cell(_segments[6].x, _segments[6].y, '*');
}

void Katze::move(char pressed){
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