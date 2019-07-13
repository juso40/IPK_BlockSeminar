#ifndef WATER_H
#define WATER_H
#include "Vec2D.h"
#include <vector>
#include "Terminal.h"

class Water{
private: 
   std::vector<Vec2D> _logs;
   int _water_state;
public:
    Water();
    void move_logs_left();
    void move_logs_right();
    void render_water0(Terminal& term);
    void render_water1(Terminal& term);
    void pos_logs1(Water& logs, int n);
    void pos_logs2(Water& logs, int n);
    void pos_logs3(Water& logs, int n);
    void draw_logs(Terminal& term);
    Vec2D position(int n);


};





#endif