#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <string>
#include "archer.h"
#include "base.h"
#include "catapult.h"
#include "knight.h"
#include "pikeman.h"
#include "ram.h"
#include "swordsman.h"
#include "worker.h"
#include "entity.h"

class mediator
{
public:
    mediator(const char *map, const char *status, const char *orders);
    ~mediator();

    void game_begin();

private:
    // read the status file
    void update_status();
    // checks if the given orders are valid, and if so, executes them
    void exec_orders();
    // create entity if needed
    entity *create_entity(char unitType, int x, int y);
    // checks how much damage an unit is dealing to a diffrent unit
    int fight(char attacker, char defender);
    // checks if a unit can move to the given square (is it occupied)
    bool can_move(int x, int y);
    // checks if there any new entities build by base
    void check_for_new_entities();
    // checks if the game has ended 1 - player one won, 2 - player two won, 0 - draw
    bool check_for_end_of_game();

private:
    const char *fileNames[3];
    std::fstream map;
    std::fstream status;
    std::fstream orders;
    std::unordered_map<int, entity *> playerOneUnits;
    std::unordered_map<int, entity *> playerTwoUnits;
    // squares where a unit can't stay
    std::vector<std::pair<int, int>> obstacles;
    std::pair<int, int> mapSize{0, 0};
    // gold of each player gold.first - first player's, gold.second - second player's
    std::pair<long, long> gold{2000, 2000};
    // next index for entities: 0 and 1 is reserved for players bases, which can be changed;
    int ID = 2;
    int turnNumber = 0;
    int winner = -1;
    // 1 - first player / 0 - second player
    bool turn;
};

#endif