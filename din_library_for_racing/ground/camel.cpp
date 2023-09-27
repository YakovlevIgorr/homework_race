//
// Created by Macbook on 18.09.2023.
//

#include "camel.h"
#include <iostream>

    Camel::Camel(){ //100
        speed = 10;
        move_until_stop = 30;
        recreation_first_times = 5;
        recreation_rest_times = 8;
    }


     float Camel::decide(int trip) {
         all_trip = trip;
         move_until_stop_times = all_trip / move_until_stop;

         if(move_until_stop_times <= 1){ // без отдыха
             move_until_stop_times = 0;
             recreation_rest_times = 0;
             recreation_first_times = 0;

         }else { //отдыхи кратные пути
             if(all_trip % static_cast<int>(move_until_stop) == 0) {
                 move_until_stop_times -= 1;//отдыхи кратные пути
                 }


             if(move_until_stop_times >= 2){
                 recreation_rest_times *= static_cast<int>(move_until_stop_times - 1);
             }else recreation_rest_times = 0;

         }

    speed = all_trip / speed; // время прохождения без перерыва


    all_time = speed + recreation_first_times + recreation_rest_times;
         return all_time;
}


//Вид ТС	Скорость	Время движения до отдыха	Длительность отдыха
//Верблюд	    10	        30	    Первый раз: 5 Все последующие разы: 8
//int speed = 10; // 10 часов
//int move_until_stop = 30; // 3 раза
//int recreation_first_times = 5; // 1 раз х 5 = 5 часов
//int recreation_rest_times = 8; // 2 раза х 8 = 16 часов