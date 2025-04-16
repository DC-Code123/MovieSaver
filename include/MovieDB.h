#ifndef MOVIEDB_H
#define MOVIEDB_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to store movie information
struct M_info {
    string title;  // Movie title
    int year;      // Year of release
    double price;  // Price of the movie
};

// Function declarations
void Movie_O(const M_info &movie);  // Display movie details
void Movie_I(M_info &movie);        // Input movie details
int runMovieDB();                   // Main function to run the Movie Database

#endif