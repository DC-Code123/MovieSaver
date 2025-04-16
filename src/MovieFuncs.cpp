#include "../include/MovieDB.h"

// Function to display movie details
void Movie_O(const M_info &movie) {
    cout << "The title of the movie is: " << movie.title << endl;
    cout << "The year of release is: " << movie.year << endl;
    cout << "The price of the movie nowadays is: $" << movie.price + 1.0 << endl;
}

// Function to input movie details
void Movie_I(M_info &movie) {
    cout << "What is the title of the movie?: ";
    cin >> movie.title;
    cout << "What is the year of release?: ";
    cin >> movie.year;
    cout << "What is the price of the movie?: ";
    cin >> movie.price;
}

// Main function to run the Movie Database
int runMovieDB() {
    cout << "Welcome to the Movie Database!" << endl;

    vector<M_info> movies;
    char choice;

    do {
        M_info movie;
        cout << "Enter details for a new movie:" << endl;
        Movie_I(movie);
        movies.push_back(movie);

        cout << "Do you want to enter another movie? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nMovie Details:" << endl;
    for (size_t i = 0; i < movies.size(); i++) {
        cout << "Movie " << i + 1 << ":" << endl;
        Movie_O(movies[i]);
        cout << endl;
    }

    cout << "Thank you for using the Movie Database!" << endl;
    cout << "Have a nice day!" << endl;

    return 0;
}