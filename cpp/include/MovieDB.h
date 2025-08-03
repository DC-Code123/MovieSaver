// MovieDB.h
#ifndef MOVIEDB_H
#define MOVIEDB_H

#include <vector>
#include <string>
#include <filesystem>

namespace std;
namespace fs = std::filesystem;

struct M_info {
    std::string timestamp;
    std::string title;
    int year;
    double price;
};

// Utility Functions
std::string getCurrentTimestamp();
void ensureMovieDirectoryExists();

// Movie Operations
void Movie_O(const M_info &movie);
void Movie_I(M_info &movie);

// File Operations
void saveMovies(const std::vector<M_info>& movies, const fs::path& filename = "movie_data/movies.txt");
void loadMovies(std::vector<M_info>& movies, const fs::path& filename = "movie_data/movies.txt");
void displayAllMovies(const std::vector<M_info>& movies);

// Main Interface
int runMovieDB();

#endif // MOVIEDB_H