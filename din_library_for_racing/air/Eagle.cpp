//
// Created by Macbook on 20.09.2023.
//

#include "Eagle.h"

Eagle::Eagle(){
    speed = 8;
    coeff_less1000 = 6;
    coeff_less5000 = 6;
    coeff_less10000 = 6;
    coeff_more10000 = 6;
};

float Eagle::decide(int trip){
    return Magic_carpet::decide(trip);
}
