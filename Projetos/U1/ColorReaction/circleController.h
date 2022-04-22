#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using std::pair;


class circleController{
private:
    struct circle {
        pair <int, int> position;
        float time;
        bool alive;
    };
    circle *objects;
public:
    int n_circles, seed;
    float time_step;
        circleController(unsigned n_circles = 4, int seed = 777, float time_step = 0.002);
       ~circleController();

       inline bool getAlive(unsigned i) { return this->objects[i].alive; }
       inline pair<int, int> getPosition(unsigned i) { return this->objects[i].position; }
       inline float getTimeLive(unsigned i) { return this->objects[i].time; }

       bool intersectionWithSomeObj(pair<int, int> pos, unsigned id);
       void killObject(unsigned i);
       void initObject(unsigned i, unsigned win_width, unsigned win_height); // traz um objeto a vida
       unsigned run(); // roda o circleHandler por um instante de tempo e retorna o numero de objetos expirados no tempo

};





















#endif // CIRCLE_H
