#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
	private:
		std::string Name;
		std::string address;
		Address* Next;
		Address* Previous;
	public:
		/*
		Constructs an empty Address;
		*/
		Address();
		/*
		Constructs an Address with the given parameters
		*/
		Address(std::string name, std::string add);
		/*
		Updates Name with
		@param name
		*/
		void change_name(std::string name);
		/*
		Updates address with
		@param add
		*/
		void change_address(std::string add);
	friend class Addressbook;
	friend class Iterator;
};

#endif
