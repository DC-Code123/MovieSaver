#include "../include/MovieDB.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream> // Needed for cout, cin, cerr

namespace fs = std::filesystem;

// Function to display movie details
void Movie_O(const M_info &movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Year: " << movie.year << std::endl;
    std::cout << "Price: $" << movie.price << std::endl;
    std::cout << "Last Updated: " << movie.timestamp << std::endl;
}

// Function to input movie details
void Movie_I(M_info &movie) {
    std::cout << "Enter movie title: ";
    std::getline(std::cin >> std::ws, movie.title);  // Allows spaces in titles
    std::cout << "Enter release year: ";
    std::cin >> movie.year;
    std::cout << "Enter current price: $";
    std::cin >> movie.price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    movie.timestamp = getCurrentTimestamp();
}

// ===== Reused/Adapted Utility Functions =====

// Gets current time (reused exactly from calculator)
std::string getCurrentTimestamp() {
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return std::string(buffer);
}

// Directory check (adapted from calculator)
void ensureMovieDirectoryExists() {
    try {
        if (!fs::exists("movie_data")) {
            fs::create_directory("movie_data");
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error creating directory: " << e.what() << std::endl;
    }
}

// Save movies (adapted from calculator's save function)
void saveMovies(const std::vector<M_info>& movies, const fs::path& filename) {
    ensureMovieDirectoryExists();
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Failed to save movies to " << filename << std::endl;
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
void loadMovies(std::vector<M_info>& movies, const fs::path& filename) {
    std::ifstream inFile(filename);
    if (!inFile) return;

    movies.clear();
    std::string line;

    while (std::getline(inFile, line)) {
        M_info movie;
        std::istringstream iss(line);
        std::getline(iss, movie.timestamp, '|');
        std::getline(iss, movie.title, '|');

        std::string yearStr, priceStr;
        std::getline(iss, yearStr, '|');
        std::getline(iss, priceStr);

        movie.year = std::stoi(yearStr);
        movie.price = std::stod(priceStr);

        movies.push_back(movie);
    }
}

// Display all movies (new function for movies)
void displayAllMovies(const std::vector<M_info>& movies) {
    if (movies.empty()) {
        std::cout << "No movies in database.\n";
        return;
    }

    std::cout << "\n=== Movie Database ===" << std::endl;
    for (const auto& movie : movies) {
        Movie_O(movie);
        std::cout << "---------------------" << std::endl;
    }
}

// ===== Main Movie DB Function =====
int runMovieDB() {
    std::vector<M_info> movies;
    loadMovies(movies);  // Load existing movies

    char choice;
    do {
        std::cout << "\nMovie Database Menu:" << std::endl;
        std::cout << "1. Add new movie\n2. View all movies\n3. Save & Exit\nChoice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        if (choice == '1') {
            M_info newMovie;
            Movie_I(newMovie);
            movies.push_back(newMovie);
        } else if (choice == '2') {
            displayAllMovies(movies);
        }

    } while (choice != '3');

    saveMovies(movies);
    std::cout << "Data saved. Goodbye!" << std::endl;
    return 0;
}