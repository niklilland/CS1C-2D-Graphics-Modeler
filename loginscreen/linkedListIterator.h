//!File name: orderedLinkedList.h
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Template for Linked List Iterator Username / Password list

#pragma once


#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H

#include <iostream>
#include "nodeType.h"

using namespace std;

template <class Type>
class linkedListIterator {
public:
    linkedListIterator();
	//Default constructor
	//Postcondition: current = nullptr;
	
    linkedListIterator(nodeType<Type> *ptr);
	//Constructor with a parameter.
	//Postcondition: current = ptr;
	
    Type operator*();
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.
	
    linkedListIterator<Type> operator++();
	//Overload the pre-increment operator.
	//Postcondition: The iterator is advanced to the next
	//               node.
	
    bool operator==(const linkedListIterator<Type>& right) const;
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to 
	//               the iterator specified by right,
	//               otherwise it returns false.
	
    bool operator!=(const linkedListIterator<Type>& right) const;
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not equal
	//               to the iterator specified by right,
	//               otherwise it returns false.
	
private:
    nodeType<Type> *current; //pointer to point to the current
                             //node in the linked list 
};


//! linked list iterator - generic iterator
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = nullptr;
}

//! linked list iterator - generic iterator
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param nodeType<Type> 
template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
	current = ptr;
}

//! linked list iterator - dereferencing operator overload *
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template<class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}

//! linked list iterator - operator ++ overload
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	
	return *this;
}

//! linked list iterator - operator == overload
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param linkeListIterator<Type> - for right hand comparison
template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>&right) const{
	return (current == right.current);
}

//! linked list iterator - operator != overload
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param linkeListIterator<Type> - for right hand comparison
template <class Type> bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const {
    return (current != right.current); 
}
#endif