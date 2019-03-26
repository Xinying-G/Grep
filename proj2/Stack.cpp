/*
 * Stack.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for a stack class
 */

#include <cstddef>
#include <new>
#include <string>
#include "Stack.h"
using namespace std;

// Default constructor
template<class E>
Stack<E>::Stack()
{
    top_ptr = NULL;
    size = 0;
}

// Destructor
template<class E>
Stack<E>::~Stack()
{
    NodeType<E> *temp_ptr;

    while (top_ptr != NULL)
    {
        temp_ptr = top_ptr;
        top_ptr = top_ptr->next;
        delete temp_ptr;
    }
}

// Copy constructor
template<class E>
Stack<E>::Stack(const Stack &s)
{
    size = s.size;
    if (s.top_ptr == NULL)
        top_ptr = NULL;
    else
    {
        top_ptr = new NodeType<E>;
        top_ptr->info = s.top_ptr->info;
        top_ptr->next = NULL;
        NodeType<E> *curr = top_ptr;
        NodeType<E> *orig = s.top_ptr;
        while (orig->next != NULL)
        {
            curr->next = new NodeType<E>;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
}

// Assignment operator
template<class E>
Stack<E> & Stack<E>::operator = (const Stack<E> &s)
{
    size = s.size;
    NodeType<E> *temp;
    while (top_ptr != NULL)
    {
        temp = top_ptr;
        top_ptr = top_ptr->next;
        delete temp;
    }
    if (s.top_ptr == NULL)
        top_ptr = NULL;
    else
    {
        top_ptr = new NodeType<E>;
        top_ptr->info = s.top_ptr->info;
        top_ptr->next = NULL;
        NodeType<E> *curr = top_ptr;
        NodeType<E> *orig = s.top_ptr;
        while (orig->next != NULL)
        {
            curr->next = new NodeType<E>;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return (*this);
}

// Function push
// Parameters: Item to push on stack
// Returns: void
// Does: pushes item on top of stack
template<class E>
void Stack<E>::push(E item)
{
    if (is_full())
        throw FullStack();
    else
    {
        NodeType<E> *location;
        location = new NodeType<E>;
        location->info = item;
        location->next = top_ptr;
        top_ptr = location;
        size++;
    }
}

// Function pop
// Parameters: none
// Returns: void
// Does: removes item from top of stack
template<class E>
void Stack<E>::pop()
{
    if (is_empty())
        throw EmptyStack();
    else
    {
        NodeType<E> *tmp_ptr;
        tmp_ptr = top_ptr;
        top_ptr = top_ptr->next;
        delete tmp_ptr;
        size--;
    }
}

// Function top
// Parameters: none
// Returns: Item
// Does: returns item from top of stack.
//       Does not modify the stack.
template<class E>
E Stack<E>::top() const
{
    if (is_empty())
        throw EmptyStack();
    else
        return top_ptr->info;
}

// Function get_size
// Parameters: none
// Returns: int, the stack size
template<class E>
int Stack<E>::get_size() const
{
    return size;
}

// Function is_full
// Parameters: none
// Returns: bool
// Does: attempts to allocate a node,
//       returns false if possible true otherwise
template<class E>
bool Stack<E>::is_full() const
{
    NodeType<E> *location;
    try
    {
        location = new NodeType<E>;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

// Function is_empty
// Parameters: none
// Returns: bool
template<class E>
bool Stack<E>::is_empty() const
{
    return (top_ptr == NULL);
}

// Function make_empty
// Parameters: none
// Returns: void
// Does: empties out the stack, deallocates memory
template<class E>
void Stack<E>::make_empty()
{
    NodeType<E> *temp_ptr;

    while (top_ptr != NULL)
    {
        temp_ptr = top_ptr;
        top_ptr = top_ptr->next;
        delete temp_ptr;
    }

    top_ptr = NULL;
    size = 0;
}

// Template classes
template class Stack<int>;
template class Stack<char>;
template class Stack<string>;
