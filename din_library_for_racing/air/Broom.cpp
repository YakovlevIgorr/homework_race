//
// Created by Macbook on 20.09.2023.
//

#include "Broom.h"

Broom::Broom() {
    speed = 20;
    coeff_less1000 = 0;
    coeff_less5000 = 0;
    coeff_less10000 = 0;
    coeff_more10000 = 0;
}

float Broom::decide(int trip){
    if(trip > 1000){
        coeff_less1000 = static_cast<int>(trip / 1000);
        coeff_less5000 = static_cast<int>(trip / 1000);
        coeff_less10000 = static_cast<int>(trip / 1000);
        coeff_more10000 = static_cast<int>(trip / 1000);
    }
    return Magic_carpet::decide(trip);
}