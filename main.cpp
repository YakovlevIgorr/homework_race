#include <iostream>
#include "din_library_for_racing/ground/all_terrain_boots.h"
#include "din_library_for_racing/air/Broom.h"
bool Transport_compare_rice(int type_rice, int type_transport){
    if(type_rice == 1){
        if(type_transport == 2 || type_transport == 5 || type_transport == 7) return false;
    }else if(type_rice == 2){
        if(type_transport == 1 || type_transport == 3 || type_transport == 4 || type_transport == 6) return false;
    }
    return true;

}
void after_start(int* input_after_start1){
    std::cout << "1. Зарегистрировать транспорт\n2. Начать гонку\nВыберите действие: ";
    std::cin >> *input_after_start1;
    std::cout << "\n";
}

float result_of_dll(int choose, int trip) {
    All_terrain_boots allTerrainBoots;
    Broom broom;
    Camel camel;
    Centaur centaur;
    Eagle eagle;
    Camel_fast camelFast;
    Magic_carpet magicCarpet;
    switch (choose) {
        case 1:
            return allTerrainBoots.decide(trip);
        case 2:
            return broom.decide(trip);
        case 3:
            return camel.decide(trip);
        case 4:
            return centaur.decide(trip);
        case 5:
            return eagle.decide(trip);
        case 6:
            return camelFast.decide(trip);
        case 7:
            return magicCarpet.decide(trip);
    }
    return 0;
}

void result(int* choose_transport1, std::string* list_of_transport1, int* length_of_trip1){//void print(const int (&numbers)[5])
    std::cout << "\nРезультаты гонки:\n";
    for(int i = 1; i < 9; i++){
        if(choose_transport1[i] == 0)break;
        std::cout << i << ". " << list_of_transport1[choose_transport1[i]]
        << ". Время: " << result_of_dll(choose_transport1[i],*length_of_trip1) << "\n";
    }
    std::cout << "\n";
}

void game_over(int* end_of_game1){
    std::cout << "1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
    std::cin >> *end_of_game1;
}

int main() {

int end_of_game = 1;
    while (end_of_game == 1) {

        int type_of_rice;
        std::string *type_of_rice_string = new std::string[4]{"", "Гонка для наземного транспорта",
                                                              "Гонка для воздушного транспорта",
                                                              "Гонка для наземного и воздушного транспорта"};
        int length_of_trip;
        int choose_for_registration = 0;
        int *choose_transport = new int[8]();
        int input_after_start = 1;

        std::string *list_of_transport = new std::string[8]{"Закончить регистрацию",//1,3,4,6- наземные
                                                            "Ботинки-вездеходы", "Метла", "Верблюд", "Кентавр", "Орел",
                                                            "Верблюд-быстроход",
                                                            "Ковер-самолет"};//2,5,7 - воздушные
        while (choose_for_registration == 0) {//выбор гонки и дистанции (в цикле)
            std::cout << "Добро пожаловать в гоночный симулятор! \n1. Гонка для наземного транспорта\n"
                         "2. Гонка для воздушного транспорта\n3. Гонка для наземного и воздушного транспорта\n"
                         "Выберите тип гонки: ";
            std::cin >> type_of_rice;
            //выбор дистанции
            std::cout << "\nУкажите длину дистанции(должна быть положительна): ";
            std::cin >> length_of_trip;

            std::cout << "Должно быть зарегистрировано минимум 2 транспортных средства\n1. Зарегистрировать транспорт\n"
                         "0. Назад " << std::endl;
            std::cin >> choose_for_registration;
            std::cout << "\n";
        }

        //выбор транспорта
        for (int k = 1; k < 8; k++) {


            std::cout << type_of_rice_string[type_of_rice] << ". Расстояние: " << length_of_trip << std::endl;
            if (choose_transport[1] != 0) {
                std::cout << "Зарегестрированные транспортные средства: ";
                for (int m = 1; m < k; m++) {//
                    if (choose_transport[m] != 0)
                        std::cout << (m > 1 ? ", " : "") << list_of_transport[choose_transport[m]];
                }
                std::cout << "\n";
            }

            for (int i = 1; i < 9; i++) {
                if (i == 8) {
                    std::cout << "0. " << list_of_transport[0] << "\n";
                } else std::cout << i << ". " << list_of_transport[i] << "\n";
            }


            std::cout << "Выберите транспорт или 0 для завершения регистрации: ";
            std::cin >> choose_transport[k];
            std::cout << "\n";

            if (type_of_rice == 1 && k == 4) {
                std::cout << "Больше нет транспорта в выбранном типе гонки.\n";
                //after_start(&input_after_start);
                input_after_start = 2;
            } else if (type_of_rice == 2 && k == 3) {
                std::cout << "Больше нет транспорта в выбранном типе гонки.\n";
                //after_start(&input_after_start);
                input_after_start = 2;
            } else if (choose_transport[k] == 0) {//выход
                after_start(&input_after_start);//выход с регистрации
                k--;

            }
            if (input_after_start == 2) { // начало гонки
                result(choose_transport, list_of_transport, &length_of_trip);// н работает// не рабоатет меню

                break;
            }


            if ((!Transport_compare_rice(type_of_rice, choose_transport[k]))) {
                std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << "\n";
                k--;
            } else if(choose_transport[k] != 0) {
                for (int l = 0; l < k; l++) {
                    if (choose_transport[k] == choose_transport[l]) {
                        std::cout << list_of_transport[choose_transport[k]] << " уже зарегистрирован!\n";
                        k--;
                    } else std::cout << (l == (k - 1) ? list_of_transport[choose_transport[k]] +
                                                        " успешно зарегистрирован!\n" : "");
                }
            }

        }
        game_over(&end_of_game);//не участвуют в гонке если повторно хочешь зарегистрироваться
        if(end_of_game == 2)break;
        std::cout << "\n";



// delete Array
        delete[] list_of_transport;
        delete[] type_of_rice_string;
        delete[] choose_transport;
    }

    return 0;
}

