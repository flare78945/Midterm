/*
* File: main.cpp
* Description: Write an address book program that will accomplish the following: Read name and address data from the user either from the keyboard or from a file. While reading the names and addresses, put the names into an appropriate data structure. After reading names and addresses, allow user to search for names and change the names or addresses in the container data structure. Allow user to write out the container data structure to a comma delimited file, this file is different from the input file.
* Author: Minhquang Phillip Tran
* Date: April 8, 2022
* Email: phillip_tran_98@yahoo.com
*/

#include <iostream>
#include <string>
#include "address.h"
#include "addressbook.h"
#include "functions.h"
#include "iterator.h"

int main() 
{
	Addressbook* One = new Addressbook();

	std::string hold;
	std::cout << "Will you be inputting data by hand?" << std::endl;
	do
	{
		hold = query();
	} while (hold != "1" && hold != "2");

	if(hold == "1")
	{
		bool repeat = true;
		Iterator pos;
		pos = One->begin();
		while (repeat)
		{
			pos.add(get_name(), get_address());
			std::cout << "Will you add another entry? " << std::endl;
			std::string temp = query();
			do
			{
				if (temp == "2")
				{
					repeat = false;
				}
				else if (temp != "1")
				{
					temp = query();
				}
			} while (temp != "1" && temp != "2");
		}
	}

	if(hold == "2")
	{
		std::cout << "What is the file name? Text files only without the extension. ";
		std::string file_name;
		std::getline(std::cin, file_name);
		file_name += ".txt";
		One->read(file_name);
	}

	menu(One);
	
	//One->print();
	
	One->free();
	
	delete One;
}
