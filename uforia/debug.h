#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

#define DEBUG(x) std::cout << "\033[32m" << x << "\033[m" << endl
#define START auto start = std::chrono::high_resolution_clock::now()
#define FINISH auto finish = std::chrono::high_resolution_clock::now();
#define TIME std::chrono::duration<double, std::milli> elapsed = finish - start; string message = "Elapsed Time: " + to_string(elapsed.count()) + " seconds"; cout << colored(message, Magenta, Bold) << endl

#endif // DEBUG_H