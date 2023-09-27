//
// Created by Macbook on 20.09.2023.
//

#ifndef SIMULATOR_RACE_ALL_TERRAIN_BOOTS_H
#define SIMULATOR_RACE_ALL_TERRAIN_BOOTS_H

#endif //SIMULATOR_RACE_ALL_TERRAIN_BOOTS_H
#pragma once
#include "centaur.h"

class All_terrain_boots:public Centaur{
public:
    float decide(int) override;
    All_terrain_boots();
};