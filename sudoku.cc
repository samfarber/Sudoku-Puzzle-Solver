/************************************************************************
    File: sudoku.cc
    Author: Sam Farber
    Date: September 19, 2016
    Assignment:  Lab 3 (Sudoku)

    Main sudoku class, has a function solve and two helper functions
    to complete the sudoku board.

************************************************************************/
#include <iostream>
#include <cstdlib>
#include "sudokuboard.h"
#include "stack.h"

using namespace std;

void advance(sudokuboard & board, stack & s, size_t & row,
  size_t col, char & num) {

  // Pushes row and col, increments row, and sets num back to 1
  board.place(row, col, num);
  s.push(col);
  s.push(row);
  row++;
  num = '1';
}

void backtrack(sudokuboard & board, stack & s, size_t & row,
  size_t & col, char & num) {

  if (s.empty()) {
    cout << "No solution" << endl;
    return;
  }
  // Removes the latest row and col from stack,
  // Sets row and col to the last location where num was placed
  row = s.top();
  s.pop();
  col = s.top();
  s.pop();
  num = board.get(row, col) + 1;
  board.remove(row, col);
}

void solve(sudokuboard & board) {
  stack s; // Made to keep track of backtracking
  size_t row = 0;
  size_t col = 0;
  char num = '1'; // The number that gets placed on board
  while (col < 9) {
    if (row < 9) {
      if (board.get(row, col) == '_') {
        if (num != ':') { // The colon symbol is after the numeral '9'
          if (board.canPlace(row, col, num))
            advance(board, s, row, col, num);

          else
            num++; // Couldn't place num so num is incremented
        }

        // No numbers can be placed... have to backtrack
        else
          backtrack(board, s, row, col, num);
      }

      // Board already has a number at this spot, so row is incremented
      else
        row++;
    }

    // Row is full, goes to next column at the first row
    else {
      row = 0;
      col++;
    }
  }
}

int main() {
  sudokuboard board;
  solve(board);
  board.print();

  return 0;
}
