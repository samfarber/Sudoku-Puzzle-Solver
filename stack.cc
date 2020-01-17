/************************************************************************
    File: stack.cc
    Author: Sam Farber
    Date: September 19, 2016
    Assignment:  Lab 3 (Sudoku)

    Implementation of a stack class.

************************************************************************/
#include <iostream>
#include "stack.h"
#include "assert.h"

using namespace std;

void stack::_create()
{
  _top = NULL;
}

void stack::_destroy()
{
  // Destroys stack essentially
  node *next;
  for (node *curr = _top; curr != NULL; curr = next) {
    next = curr -> next;
    delete curr;
  }
}

/*** Constructor ***/
stack::stack()
{
 _create();
}

/*** Destructor ***/
stack::~stack()
{
  _destroy();
}

/*** const member functions ***/


bool stack::empty() const
{
  // Checks if there is 0 items on stack
	return _top == NULL;
}

char stack::top() const
{
  // Returns top item
  assert (!empty());
  return _top -> data;
}


 /*** non-const member functions ***/


void stack::push(const char & item)
{
  // Puts item on stack
  _top = new node(item, _top);
}


void stack::pop()
{
  // Removes item at the top
	node *dead = _top;
	_top = _top -> next;
	delete dead;
} 
