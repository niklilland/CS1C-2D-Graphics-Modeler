//File name: userList.h
//------------------------------------------------------------------------------------------------------------------------------------------
//Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//Creation Date: 11/25/2019
//Date of last modification: 12/10/2019
//------------------------------------------------------------------------------------------------------------------------------------------
//Ordered linked list for Username / Password list

#pragma once

#ifndef USERLIST_H
#define USERLIST_H

#include "orderedLinkedList.h"
#include "userType.h"
#include <string>

using namespace std;

// ordered Linked List Sorted by username (default)
class userLinkedListType: public orderedLinkedList<userType>
{
	public:
		//bool search(string username);
		void userSearch(string username, bool& found, nodeType<userType>* &current);
		
};

#endif
