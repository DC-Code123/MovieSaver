# Movie Database

## Features
- **Add Movies**: Input movie details (title, year, price).
- **Display Movies**: View all stored movies with formatted output.
- **Dynamic Storage**: Uses a vector to store an unlimited number of movies.

## How to Compile
```bash
g++ src/main.cpp src/MovieFuncs.cpp -o movieDB -Iinclude


---

### **Key Improvements**
1. **Modular Design** (like the Calculator program):
   - Header file (`MovieDB.h`) for declarations.
   - Implementation file (`MovieFuncs.cpp`) for logic.
   - Clean `main.cpp` for execution.

2. **Better Readability**:
   - Proper separation of concerns.
   - Comments for clarity.

3. **Scalable**:
   - Easy to add more functions (e.g., search, delete movies).

4. **Compilation Ready**:
   - Follows standard C++ project structure.

---

### **How to Compile & Run**
1. Save the files in the correct directories.
2. Compile:
   ```bash
   g++ src/main.cpp src/MovieFuncs.cpp -o movieDB -Iinclude