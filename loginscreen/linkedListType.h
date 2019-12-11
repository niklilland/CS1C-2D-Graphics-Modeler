//!File name: linkedListType.h
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Template for Linked List for Username / Password list

#pragma once

#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H

#include "linkedListIterator.h"

//! linked list type - generic linked list
//!
//!
//!
//! \tparam Type - datatype used for template
template <class Type> 
class linkedListType { 
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);        
	//Overload the assignment operator.    
	
	void initializeList();       
	//Initialize the list to an empty state.     
	//Postcondition: first = nullptr, last = nullptr,      
	//               count = 0;
	
    bool isEmptyList() const;      
	//Function to determine whether the list is empty.       
	//Postcondition: Returns true if the list is empty,      
	//               otherwise it returns false.
	
    virtual void print() const;      
	//Function to output the data contained in each node.     
	//Postcondition: none
	
    int length() const;      
	//Function to return the number of nodes in the list.      
	//Postcondition: The value of count is returned.
	
    void destroyList();      
	//Function to delete all the nodes from the list.      
	//Postcondition: first = nullptr, last = nullptr,       
	//               count = 0;
	
    Type front() const;       
	//Function to return the first element of the list.      
	//Precondition: The list must exist and must not be       
	//              empty.      
	//Postcondition: If the list is empty, the program      
	//               terminates; otherwise, the first       
	//               element of the list is returned.
	
	Type back() const;
	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be
	// empty.
	//Postcondition: If the list is empty, the program
	// terminates; otherwise, the last
	// element of the list is returned.
	
	virtual bool search(const Type& searchItem) const = 0;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the
	// list, otherwise the value false is
	// returned.
	
	virtual void insertFirst(const Type& newItem) = 0;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list,
	// last points to the last node in the list,
	// and count is incremented by 1.
	
	virtual void insertLast(const Type& newItem) = 0;
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem
	// is inserted at the end of the list,
	// last points to the last node in the
	// list, and count is incremented by 1.
	
	virtual void deleteNode(const Type& deleteItem) = 0;
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing
	// deleteItem is deleted from the list.
	// first points to the first node, last
	// points to the last node of the updated
	// list, and count is decremented by 1.
	
	linkedListIterator<Type> begin();
	//Function to return an iterator at the begining of
	//the linked list.
	//Postcondition: Returns an iterator such that current
	// is set to first.
	
	linkedListIterator<Type> end();
	//Function to return an iterator one element past the
	//last element of the linked list.
	//Postcondition: Returns an iterator such that current
	// is set to nullptr.
	
	linkedListType();
	//Default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = nullptr, last = nullptr,
	// count = 0;
	
	linkedListType(const linkedListType<Type>& otherList);
	//copy constructor
	
	~linkedListType();
	//Destructor
	//Deletes all the nodes from the list
	//Postcondition: The list object is destroyed
	
protected:
	int count;
	
	nodeType<Type> *first;
	nodeType<Type> *last;
	
private:
	void copyList(const linkedListType<Type>& otherList);
	//Function to make a copy of otherlist
	//Postcondition: A copy of otherList is created and assigned to this list
};

//! isEmptyList - check if list is empty
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == nullptr);
}

//! linked list default constructor
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

//! linked list destroy list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp; //pointer to deallocate the memory
						  //occupied by the node

	while (first != nullptr) //while there are nodes in
	{ //the list
		temp = first; //set temp to the current node
		first = first->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	last = nullptr; //initialize last to nullptr; first has
				    //already been set to nullptr by the while loop
	count = 0;
}

//! linked list initialize list - same as destroyList
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

//! linked list print - print contents of linked list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list
	current = first; //set current so that it points to
	//the first node
	
	while (current != nullptr) //while more data to print
	{
		cout << current->info << " ";
		current = current->link;
	}
}//end print

//! linked list length - number of elements in list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
int linkedListType<Type>::length() const
{
	return count;
} //end length

//! linked list front - first element in list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != nullptr);
	
	return first->info; //return the info of the first node
}//end front

//! linked list back - last element in list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != nullptr);
	return last->info; //return the info of the last node
}//end back

//! linked list begin - go to start of list for iterator
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	
	return temp;
}

//! linked list end - last element of iterator (reached end)
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(nullptr);
	
	return temp;
}

//! linked list copyList - copy list to otherList
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param otherList - destination of copy
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list
	
	if (first != nullptr) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.first == nullptr) //otherList is empty
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the
		//list to be copied
		count = otherList.count;
		//copy the first node
		first = new nodeType<Type>; //create the node
		first->info = current->info; //copy the info
		first->link = nullptr; //set the link field of
		//the node to nullptr
		last = first; //make last point to the
		//first node
		
		current = current->link; //make current point to
		//the next node
		//copy the remaining list
		while (current != nullptr)
		{
			newNode = new nodeType<Type>; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = nullptr; //set the link of
			//newNode to nullptr
			last->link = newNode; //attach newNode after last
			last = newNode; //make last point to
			//the actual last node
			current = current->link; //make current point
			//to the next node
		}//end while
	}//end else
}//end copyList

//! linked list destructor - generic destructor
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
}//end destructor

//! linked list copy constructor
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param otherList - destination for copy 
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
	first = nullptr;
	copyList(otherList);
}//end copy constructor

//! linked list overload assignment operator
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param otherList - copy otherList into new instance
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
	copyList(otherList);
	}//end else
	return *this;
}

#endif