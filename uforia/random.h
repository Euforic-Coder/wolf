#ifndef RANDOM_H
#define RANDOM_H

#include <chrono>
#include <iostream>

int true_rand(){
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    return rand();
}

#endif // RANDOM_H
