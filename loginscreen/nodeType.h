//!File name: orderedLinkedList.h
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Template for Node Type for Linked and Ordered list

#pragma once

#ifndef NODETYPE_H
#define NODETYPE_H

#include <iostream>
#include <string>
using namespace std;

//! nodeType - generic nodetype for template datastructures
//!
//!
//!
//! \tparam Type - datatype used for template
//! \param none
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

#endif