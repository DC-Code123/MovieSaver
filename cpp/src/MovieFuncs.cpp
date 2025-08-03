#include "../include/MovieDB.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <ctime>

namespace std;
namespace fs = std::filesystem;

// Function to display movie details
void Movie_O(const M_info &movie) {
    cout << "Title: " << movie.title << endl;
    cout << "Year: " << movie.year << endl;
    cout << "Price: $" << movie.price << endl;
    cout << "Last Updated: " << movie.timestamp << endl;
}

// Function to input movie details
void Movie_I(M_info &movie) {
    cout << "Enter movie title: ";
    getline(cin >> ws, movie.title);  // Allows spaces in titles
    cout << "Enter release year: ";
    cin >> movie.year;
    cout << "Enter current price: $";
    cin >> movie.price;
    movie.timestamp = getCurrentTimestamp();
}

// ===== Reused/Adapted Utility Functions =====

// Gets current time (reused exactly from calculator)
string getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// Directory check (adapted from calculator)
void ensureMovieDirectoryExists() {
    try {
        if (!fs::exists("movie_data")) {
            fs::create_directory("movie_data");
        }
    } catch (const fs::filesystem_error& e) {
        cerr << "Error creating directory: " << e.what() << endl;
    }
}

// Save movies (adapted from calculator's save function)
void saveMovies(const vector<M_info>& movies, const fs::path& filename = "movie_data/movies.txt") {
    ensureMovieDirectoryExists();
    ofstream outFile(filename);
    
    if (!outFile) {
        cerr << "Failed to save movies to " << filename << endl;
        return;
    }

    for (const auto& movie : movies) {
        outFile << movie.timestamp << "|"
                << movie.title << "|"
                << movie.year << "|"
                << movie.price << "\n";
    }
}

// Load movies (adapted from calculator's load function)
void loadMovies(vector<M_info>& movies, const fs::path& filename = "movie_data/movies.txt") {
    ifstream inFile(filename);
    if (!inFile) return;

    movies.clear();
    string line;
    
    while (getline(inFile, line)) {
        M_info movie;
        istringstream iss(line);
        getline(iss, movie.timestamp, '|');
        getline(iss, movie.title, '|');
        
        string yearStr, priceStr;
        getline(iss, yearStr, '|');
        getline(iss, priceStr);
        
        movie.year = stoi(yearStr);
        movie.price = stod(priceStr);
        
        movies.push_back(movie);
    }
}

// Display all movies (new function for movies)
void displayAllMovies(const vector<M_info>& movies) {
    if (movies.empty()) {
        cout << "No movies in database.\n";
        return;
    }

    cout << "\n=== Movie Database ===" << endl;
    for (const auto& movie : movies) {
        Movie_O(movie);
        cout << "---------------------" << endl;
    }
}

// ===== Main Movie DB Function =====
int runMovieDB() {
    vector<M_info> movies;
    loadMovies(movies);  // Load existing movies

    char choice;
    do {
        cout << "\nMovie Database Menu:" << endl;
        cout << "1. Add new movie\n2. View all movies\n3. Save & Exit\nChoice: ";
        cin >> choice;

        if (choice == '1') {
            M_info newMovie;
            Movie_I(newMovie);
            movies.push_back(newMovie);
        } else if (choice == '2') {
            displayAllMovies(movies);
        }

    } while (choice != '3');

    saveMovies(movies);
    cout << "Data saved. Goodbye!" << endl;
    return 0;
}