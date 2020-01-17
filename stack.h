/************************************************************************
    File: stack.h
    Author: Sam Farber
    Date: September 19, 2016
    Assignment: Lab 3 (Sudoku)

    Declaration of a stack class.

    Make no changes to this file.
************************************************************************/
#include <cstdlib>

class stack {

 private:

  /*** Member data ***/

  struct node {
    char data;
    node *next;
    node(const char & item, node *after)
    {
      data = item;
      next = after;
    }
  };
  node *_top;

  void _create();
  // Sets _top equal to NULL

  void _destroy();
  // Destroys stack essentially

 public:

  stack();
  // constructor

  ~stack();
  // destructor


  /*** const member functions ***/


  bool empty() const;
  // Checks if there is 0 items on stack

  char top() const;
  // Returns top item


  /*** non-const member functions ***/


  void push(const char & item);
  // Puts item on stack

  void pop();
  // Removes item at the top
};
