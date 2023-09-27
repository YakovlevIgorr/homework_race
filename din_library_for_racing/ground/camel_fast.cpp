//
// Created by Macbook on 19.09.2023.
//

#include "camel_fast.h"

    Camel_fast::Camel_fast(){
        speed = 40;
        move_until_stop = 10;
        recreation_first_times = 5;
        recreation_rest_times = 8;
        recreation_second_time = 6.5;
}


float Camel_fast::decide(int trip) {
    all_trip = trip;
    move_until_stop_times = all_trip / move_until_stop;

    if(move_until_stop_times <= 1){ // без отдыха
        move_until_stop_times = 0;
        recreation_rest_times = 0;
        recreation_first_times = 0;
        recreation_second_time = 0;

    }else { //отдыхи кратные пути
        if(all_trip % static_cast<int>(move_until_stop) == 0) {
            move_until_stop_times -= 1;//отдыхи кратные пути
        }


        if(move_until_stop_times < 3){
            recreation_rest_times = 0;//*= static_cast<int>(move_until_stop_times - 1);
        }else recreation_rest_times *= static_cast<int>(move_until_stop_times - 2);

    }

    speed = all_trip / speed; // время прохождения без перерыва


    all_time = speed + recreation_first_times + recreation_second_time + recreation_rest_times;
    return all_time;
}
//
//Верблюд-быстроход	скорость-40	отдых каждые-10	Первый раз: 5////40 1+19.5= 20.5
//Второй раз: 6.5
//Все последующие разы: 8