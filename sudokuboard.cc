/************************************************************************
    File: sudokuboard.cc
    Author: Sam Farber
    Date: September 19, 2016
    Assignment:  Lab 3 (Sudoku)

    Implementation of a sudoku board based on a 9 X 9 array of chars.

************************************************************************/
#include <iostream>
#include "sudokuboard.h"

using namespace std;

/*** Constructor ***/
sudokuboard::sudokuboard()
{
  // Initializes a 9 X 9 sudoku board with underscores in each position
  for (size_t i = 0; i < 9; i++)
    for (size_t j = 0; j < 9; j++) {
      char num;
      cin >> num; // User inputs num
  	  _board[i][j] = num; // Num is now placed onto the board
    }
}

/*** const member functions ***/


char sudokuboard::get(size_t r, size_t c) const
{
  // Returns the numeral at position (r, c)
  return _board[r][c];
}

bool sudokuboard::canPlace(size_t r, size_t c, char n) const
{
  // Returns true iff the board would allow placing n at (r, c)
  if (get(r, c) != '_')
    return false;

  for (size_t i = 0; i < 9; i++) {
    // Makes sure n is not equal to any number in the column
    if (get(i, c) == n)
      return false;
  }

  for (size_t j = 0; j < 9; j++) {
  	// Makes sure n is not equal to any number in the row
  	if (get(r, j) == n)
  		return false;
  }

  for (size_t i = (r/3) * 3; i < (r/3 * 3) + 3; i++) {
  	for (size_t j = (c/3) * 3; j < (c/3 * 3) + 3; j++) {
  		// Checks if n is in 3 X 3 grid
  		if (get(i, j) == n)
  			return false;
  	}
  }

  return true;
}

void sudokuboard::print() const
{
  // Writes the board to cout
  for (size_t i = 0; i < 9; i++) {
  	for (size_t j = 0; j < 9; j++) {
      cout << get(i, j);
  	}
  	cout << endl;
  }
}

/*** non-const member functions ***/


void sudokuboard::place(size_t r, size_t c, char n)
{
  // Places numeral n at position (r, c)
  _board[r][c] = n;
}

void sudokuboard::remove(size_t r, size_t c)
{
  // Removes the numeral at position (r, c)
  _board[r][c] = '_';
}
