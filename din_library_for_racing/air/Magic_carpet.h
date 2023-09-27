//
// Created by Macbook on 20.09.2023.
//

#ifndef SIMULATOR_RACE_MAGIC_CARPET_H
#define SIMULATOR_RACE_MAGIC_CARPET_H

#endif //SIMULATOR_RACE_MAGIC_CARPET_H
#pragma once

class Magic_carpet{
protected:
    float all_time;
    float speed;
    float coeff_less1000;
    float coeff_less5000;
    float coeff_less10000;
    float coeff_more10000;

public:
    virtual float decide(int);
    Magic_carpet();
};
