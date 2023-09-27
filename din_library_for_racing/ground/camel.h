//
// Created by Macbook on 18.09.2023.
//

#ifndef SIMULATOR_RACE_CAMEL_H
#define SIMULATOR_RACE_CAMEL_H

#endif //SIMULATOR_RACE_CAMEL_H
#pragma  once

class Camel{
public:
    Camel();
    virtual float decide(int);

protected:
    int all_trip;
    float all_time;
    float speed;
    float move_until_stop;
    float move_until_stop_times = 0;
    float recreation_first_times;
    float recreation_rest_times;
    float recreation_second_time;
};