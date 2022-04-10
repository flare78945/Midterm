#include "address.h"
#include "addressbook.h"
#include "functions.h"
#include "iterator.h"

std::string query()
{
	std::cout << "1 = Yes" << std::endl;
	std::cout << "2 = No" << std::endl;
	std::string hold;
	std::cin >> hold;
	std::cin.ignore(1);
	return hold;
}

std::string get_name()
{
	std::cout << "What is the name to be added? ";
	std::string name;
	clear();
	std::getline(std::cin, name);
	return name;
}

std::string get_address()
{
	std::cout << "What is their address? ";
	std::string address;
	clear();
	std::getline(std::cin, address);
	return address;
}

std::string replace_name()
{
	std::cout << "Replacement name: ";
	std::string replace;
	clear();
	std::cin >> replace;
	return replace;
}

std::string replace_address()
{
	std::cout << "Replacement Address: ";
	std::string replace;
	clear();
	std::cin >> replace;
	return replace;
}

void clear()
{
	if(std::cin.peek() == '\n')
	{
		std::cin.clear();
		std::cin.ignore(1);
	}	
}

void menu(Addressbook* a)
{
	std::cout << "Would you like to:" << std::endl;
	std::cout << "1 = View the Address Book? " << std::endl;
	std::cout << "2 = Search the Address Book for a specific name? Name is case sensitive. " << std::endl;
	std::cout << "3 = Add an entry? " << std::endl;
	std::cout << "4 = Edit an entry? " << std::endl;
	std::cout << "5 = Erase an entry? " << std::endl;
	std::cout << "6 = Exit to save options? " << std::endl;
	std::string get = "";
	std::cin >> get;

	if(get == "1") // Prints the whole Addressbook along with corresponding entry numbers and returns to menu.
	{
		a->print();
		menu(a);
	}
	else if(get == "2") // See lookup function
	{
		lookup(a);
	}
	else if(get == "3") // Adds a new entry
	{
		Iterator pos;
		pos = a->end();
		std::string hold = get_name();
		std::string hold2 = get_address();
		pos.add(hold, hold2);
		menu(a);
	}
	else if(get == "4") // See edits function; Returns to menu
	{
		std::cout << "Entry number to be edited: ";
		int entry;
		std::cin >> entry;
		edits(a, entry);
		menu(a);
	}
	else if(get == "5") // See save function
	{
		std::cout << "Entry number to be erased: ";
		int entry;
		std::cin >> entry;
		erase(a, entry);
		menu(a);
	}
	else if(get == "6") // See save function
	{
		save(a);
	}
	else menu(a); // Executes if user inputs anything but an option digit
}

void lookup(Addressbook* a)
{
	std::cout << "What is the name to be searched for: ";
	std::string search;
	clear();
	std::getline(std::cin, search, '\n');
	a->print_specific(search);
	menu(a);
}

void edits(Addressbook* a, int index)
{
	std::cout << "What kind of edit: " << std::endl;
	std::cout << "1 = Name" << std::endl;
	std::cout << "2 = Address" << std::endl;
	std::cout << "3 = Both" << std::endl;
	char get;
	while (get != '1' && get != '2' && get != '3')
	{
		get = std::cin.get();
	}
	Iterator pos;
	pos = a->begin();
	for (int i = 0; i < index; i++)
	{
		pos.next();
	}
	if(get == '1')
	{
		pos.edit_name(replace_name());
	}
	else if(get == '2')
	{
		pos.edit_add(replace_address());
	}
	else if(get == '3')
	{
		pos.edit(replace_name(), replace_address());
	}
}

void erase(Addressbook* a, int index)
{
	Iterator pos;
	pos = a->begin();
	for (int i = 0; i < index; i++)
	{
		pos.next();
	}
	pos = a->erase(pos);
}

void save(Addressbook* a)
{
	std::cout << "Write the addressbook to output.txt?" << std::endl;
	std::string hold;
	while (hold != "1" && hold != "2")
	{
		hold = query();
	}

	if(hold == "1")
	{
		a->write();
	}

	if(hold == "2")
	{
		std::cout << "What will the file name be? Exclude the file extension. ";
		std::string name_out;
		std::cin >> name_out;
		a->writeto(name_out);
	}
}
