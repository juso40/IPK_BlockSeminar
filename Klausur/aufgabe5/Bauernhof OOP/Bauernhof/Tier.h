//Justin Sostmann
#ifndef TIER_H
#define TIER_H
#include "Terminal.h"
class Tier{

public:
    Tier();
    Tier(Terminal& term);
    virtual void draw()=0;
    virtual void move(char pressed)=0;
    virtual void draw_chosen()=0;
    Terminal& _term;

};

#endif