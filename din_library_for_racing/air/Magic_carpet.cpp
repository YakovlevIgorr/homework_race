//
// Created by Macbook on 20.09.2023.
//

#include "Magic_carpet.h"

Magic_carpet::Magic_carpet(){
    speed = 10;
    coeff_less1000 = 0;
    coeff_less5000 = 3;
    coeff_less10000 = 10;
    coeff_more10000 = 5;
}

float Magic_carpet::decide(int trip){

    if(trip < 1000){
        trip *= (1 - (coeff_less1000 * 0.01));
        all_time = trip / speed;
        return all_time;
    }else if(trip < 5000){
        trip *= (1 - (coeff_less5000 * 0.01));
        all_time = trip / speed;
        return all_time;
    }else if(trip < 10000){
        trip *= (1 -(coeff_less10000 * 0.01));
        all_time = trip / speed;
        return all_time;
    }else {
        trip *= (1 - (coeff_more10000 * 0.01));
        all_time = trip / speed;
        return all_time;
    }

}
