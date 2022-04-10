#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

/*
	This function collects binary user input (Yes or No) 
	in the form of a string
*/
std::string query();

/*
	Prompts the user for a name, passes the name
	back to the calling function
*/
std::string get_name();

/*
	Prompts the user for an address, passes the
	address back to the calling function
*/
std::string get_address();

/*
	Prompts the user for a name, passes the name
	back to the calling function
*/
std::string replace_name();

/*
	Prompts the user for an address, passes the
	address back to the calling function
*/
std::string replace_address();

/*
	Clear out cin
*/
void clear();

/*
	Main menu to interact with the Address book.
	User inputs corresponding digit to do that option.
*/
void menu(Addressbook* a);

/*
	Prompts the user for a name, passes the name
	back to the Addressbook search function.
	Returns to menu function.
*/
void lookup(Addressbook* a);

/**
	Askes the user what type of edit they want to make to
	the Addressbook and calls the corresponding function.
*/
void edits(Addressbook* a, int index);

/*
	Erases the entry at the given index
*/
void erase(Addressbook* a, int index);

/*
	Askes if the user wants to save the Addressbook
	to a prenamed file called output.txt. If not askes
	what name they want the output file to be and
	writes the Addressbook to that file.
*/
void save(Addressbook* a);

#endif
