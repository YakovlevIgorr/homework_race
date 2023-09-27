//
// Created by Macbook on 20.09.2023.
//

#include "all_terrain_boots.h"

All_terrain_boots::All_terrain_boots(){
    speed = 6;
    move_until_stop = 60;
    recreation_first_times = 10;
    recreation_rest_times = 5;
}

float All_terrain_boots::decide(int trip) {
    return Camel::decide(trip);
}