/************************************************************************
    File: sudokuboard.h
    Author: Sam Farber
    Date: September 19, 2016
    Assignment: Lab 3 (Sudoku)

    Declaration of a sudoku board based on a 9 X 9 array of chars.

    Make no changes to this file.
************************************************************************/
#include <cstdlib>

class sudokuboard {

 private:

  /*** Member data ***/

  char _board[9][9];  // a 2D array with 9 rows and 9 columns

 public:

  /*** Constructor ***/
  sudokuboard();
  // Initializes a 9 X 9 sudoku board with empty quotes in each position


  /*** const member functions ***/


  char get(size_t r, size_t c) const;
  // Returns the numeral at position (r, c)

  bool canPlace(size_t r, size_t c, char n) const;
  // Returns true iff the board would allow placing n at (r, c)

  void print() const;
  // Writes the board to cout


   /*** non-const member functions ***/


  void place(size_t r, size_t c, char n);
  // Places numeral n at position (r, c)

  void remove(size_t r, size_t c);
  // Removes the numeral at position (r, c)

};
