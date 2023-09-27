//
// Created by Macbook on 20.09.2023.
//

#include "centaur.h"

Centaur::Centaur() {
    speed = 15;
    move_until_stop = 8;
    recreation_first_times = 2;
    recreation_rest_times = 2;
}

float Centaur::decide(int trip) {
    return Camel::decide(trip);
}