#ifndef ITERATOR_H
#define ITERATOR_H

class Address;
class Addressbook;

class Iterator
{
	private:
		Addressbook* book;
		Address* entry;
	public:
		/*
		Default Constructor
		*/
		Iterator();
		/*
		Add a new Address to the Addressbook
		*/
		void add(std::string name, std::string address);
		/*
		Updates entry->Name & entry->address with
		@param name
		@param address
		*/
		void edit(std::string name, std::string address);
		/*
		Updates entry->Name with
		@param name
		*/
		void edit_name(std::string name);
		/*
		Updates entry->address with
		@param address
		*/
		void edit_add(std::string address);
		/*
		Moves Iterator to next Address
		*/
		void next();
		/*
		Moves Iterator to previous Address
		*/
		void previous();
		/*
		Prints current entry
		*/
		void print();
		/*
		Gets name from entry
		*/
		std::string get_Name();
		/*
		Gets address from entry
		*/
		std::string get_add();
	friend class Addressbook;
};

#endif
