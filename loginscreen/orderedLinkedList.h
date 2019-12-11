//!File name: orderedLinkedList.h
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Template for Ordered Linked List for Username / Password list
#pragma once

#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include "linkedListType.h"

//! ordered linked list - generic ordered linked list for sorted lists
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
	//using linkedListType<Type>::first;
	//using linkedListType<Type>::last;
	//using linkedListType<Type>::count;
public:
	bool search(const Type& searchItem, nodeType<Type>* loc) const;
	bool search(const Type& searchItem) const;
	void insert(const Type& newItem);
	void insertFirst(const Type& newItem);
	void insertLast(const Type& newItem);
	void deleteNode(const Type& deleteItem);
};

//! ordered linked list search - for searching ordered list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param searchItem - item we're looking for, loc - return location if found
//! \return bool - true if item was found, otherwise false
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem, nodeType<Type>* loc) const
{
	bool found = false;
	nodeType<Type> *current; //pointer to traverse the list

	current = this->first; //start the search at the first node

	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;
	
	if (found)
	{
		found = (current->info == searchItem); //test for equality
		loc = current;
	}
	
	return found;
}//end search

//! ordered linked list search - for searching ordered list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param searchItem - item we're looking for
//! \return bool - true if item was found, otherwise false
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
	bool found = false;
	nodeType<Type> *current; //pointer to traverse the list

	current = this->first; //start the search at the first node

	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;
	
	if (found)
		found = (current->info == searchItem); //test for equality
	
	return found;
}//end search

//! ordered linked list insert - add new item in proper location
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param newItem - item to be added on the list
template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
	nodeType<Type> *current;
	nodeType<Type> *trailCurrent = nullptr;
	
	nodeType<Type> *newNode;
	
	bool found;
	
	newNode = new nodeType<Type>; //create the node
	newNode->info = newItem; //store newItem in the node
	newNode->link = nullptr; //set the link field of the node
						     //to nullptr

	if (this->first == nullptr) //Case 1
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	}
	else
	{
		current = this->first;
		found = false;

		while (current != nullptr && !found) //search the list
			if (current->info >= newItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
	
		if (current == this->first) //Case 2
		{
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
		else //Case 3
		{
			trailCurrent->link = newNode;
			newNode->link = current;
			
			if (current == nullptr)
				this->last = newNode;
			this->count++;
		}
	}//end else
}//end insert

//! ordered linked list insertFirst - add new item to the start of the list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param newItem - item to be added
template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	insert(newItem);
}//end insertFirst

//! ordered linked list insertLast - add to the end of the list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param newItem - item to be added to the end of the list
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
	insert(newItem);
}//end insertLast

//! ordered linked list deleteNode - remove item from list
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param deleteItem - target node to be deleted
template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent = nullptr; //pointer just
										    //before current
	bool found;
	
	if (this->first == nullptr) //Case 1
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		current = this->first;
		found = false;
		while (current != nullptr && !found)//search the list
			if (current->info >= deleteItem)
				found = true;
			else
			{
				trailCurrent = current;
				current = current->link;
			}
		if (current == nullptr) //Case 4
			cout << "The item to be deleted is not in the "
				<< "list." << endl;
		else
			if (current->info == deleteItem) //the item to be
											 //deleted is in the list
			{
				if (this->first == current) //Case 2
				{
					this->first = this->first->link;
					if (this->first == nullptr)
						this->last = nullptr;
					delete current;
				}
				else //Case 3
				{
					trailCurrent->link = current->link;
					if (current == this->last)
						this->last = trailCurrent;
					delete current;
				}
				this->count--;
			}
			else //Case 4
				cout << "The item to be deleted is not in the "
					<< "list." << endl;
	}
}//end deleteNode

#endif