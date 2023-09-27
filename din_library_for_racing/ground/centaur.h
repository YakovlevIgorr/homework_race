//
// Created by Macbook on 20.09.2023.
//

#ifndef SIMULATOR_RACE_CENTAUR_H
#define SIMULATOR_RACE_CENTAUR_H

#endif //SIMULATOR_RACE_CENTAUR_H
#pragma once
#include "camel_fast.h"
class Centaur:public Camel_fast{
public:
    float decide(int) override;
    Centaur();

};