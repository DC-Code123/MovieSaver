// main.cpp
#include "MovieDB.h"
#include <iostream>

int main() {
    std::cout << "=== Movie Database Management System ===" << std::endl;
    
    try {
        int result = runMovieDB();
        if (result != 0) {
            std::cerr << "Program ended with error code: " << result << std::endl;
            return result;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}