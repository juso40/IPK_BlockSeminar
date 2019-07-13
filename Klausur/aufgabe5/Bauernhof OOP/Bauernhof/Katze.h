//Justin Sostmann
#ifndef KATZE_H
#define KATZE_H
#include "Tier.h"
#include "Vec2D.h"
#include <vector>

class Katze : public Tier{
private:
    std::vector<Vec2D> _segments;
  
public:
    Katze();
    virtual void draw();
    virtual void move(char pressed);
    virtual void draw_chosen();

};

#endif