//Justin Sostmann
#ifndef SCHWEIN_H
#define SCHWEIN_H
#include "Tier.h"
#include "Vec2D.h"
#include <vector>

class Schwein : public Tier{
private:
    std::vector<Vec2D> _segments;
    
public:
    Schwein ();
    virtual void draw();
    virtual void move(char pressed);
    virtual void draw_chosen();

};


#endif