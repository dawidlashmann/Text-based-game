#ifndef WORKER_H
#define WORKER_H

#include "entity.h"

class worker : public entity
{
public:
    worker(int x, int y)
    {
        this->x = x;
        this->y = y;
        health = 20;
        speed = 2;
        cost = 100;
        attackRange = 1;
        buildTime = 2;
        unitType = 'W';
        attacked = false;
        mining = false;
    };

public:
    bool mining;
};

#endif