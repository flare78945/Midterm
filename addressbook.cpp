#include "address.h"
#include "addressbook.h"
#include "iterator.h"

Addressbook::Addressbook()
{
	First = nullptr;
	Last = nullptr;
}

Addressbook::Addressbook(std::string name, std::string address)
{
	Address* temp = new Address(name, address);
	First = temp;
	Last = temp;
}

int Addressbook::size()
{
	int count = 0;
	Iterator temp;
	temp = this->begin();
	while (temp.entry != nullptr)
	{
		count++;
		temp.next();
	}
	return count;
}

void Addressbook::print()
{
	int count = 1;
	Iterator temp;
	temp = this->begin();
	while (temp.entry != nullptr)
	{
		std::cout << count << ". " << temp.get_Name() << ", " << temp.get_add() << std::endl;
		temp.next();
		count++;
	}
}

void Addressbook::print_specific(std::string name)
{
	const std::string value = name;
	bool found = false;
	int count = 1;
	
	Iterator temp;
	temp = this->begin();
	
	while (temp.entry != nullptr)
	{
		if (value == temp.get_Name())
		{
			std::cout << value << std::endl;
			std::cout << count << ". " << temp.get_Name() << ", " << temp.get_add() << std::endl;
			found = true;
		}
		temp.next();
		count++;
	}
	if (!found)
	{
		std::cout << "This name was not found." << std::endl;
	}
}

void Addressbook::read(std::string file_name)
{
	Iterator temp;
	temp = this->begin();
	std::fstream read;
	read.open(file_name);
	while (read.is_open())
	{
		int end = read.peek();
		std::string name_hold;
		std::string address_hold;

		if (end == EOF)
		{
			read.close();
			break;
		}

		std::getline(read, name_hold, '\n');
		std::getline(read, address_hold, '\n');

		temp.add(name_hold, address_hold);
	}
}

void Addressbook::write()
{
	std::ofstream alpha;
	alpha.open("output.txt");

	Iterator temp;
	temp = this->begin();
	while (temp.entry != nullptr)
	{
		alpha << temp.get_Name() << ", " << temp.get_add() << std::endl;
		temp.next();
	}
}

void Addressbook::writeto(std::string file_name)
{
	const std::string f_name = file_name + ".txt";
	std::ofstream alpha;
	alpha.open(f_name);

	Iterator* temp = new Iterator();
	temp->book = this;
	temp->entry = temp->book->First;
	while (temp->entry != nullptr)
	{
		alpha << temp->get_Name() << ", " << temp->get_add() << std::endl;
		temp->next();
	}

	std::cout << "Contents written to: " << f_name << std::endl;
}

void Addressbook::free()
{
	Address* to_delete = First;
	while(to_delete != nullptr)
	{
		Address* next_to_delete = to_delete->Next;
		delete to_delete;
		to_delete = next_to_delete;
	}
}

Iterator Addressbook::erase(Iterator pos)
{
	Iterator temp = pos;
	Address* to_delete = pos.entry;

	if (to_delete->Previous != nullptr)
	{
		if (to_delete->Next != nullptr)
		{
			to_delete->Previous->Next = to_delete->Next;
			to_delete->Next->Previous = to_delete->Previous;
			temp.entry = pos.entry->Previous;
		}
		else
		{
			to_delete->Previous->Next = nullptr;
			temp.entry = pos.entry->Previous;
			temp.book->Last = temp.entry;
		}
	}
	else
	{
		if (temp.entry->Next != nullptr)
		{
			temp.entry = pos.entry->Next;
			temp.entry->Previous = nullptr;
			temp.book->First = temp.entry;
		}
		else
		{
			temp.entry = nullptr;
			temp.book->First = nullptr;
			temp.book->Last = nullptr;
			std::cout << "You erased the last entry." << std::endl;
		}
	}
	
	delete to_delete;
	
	return temp;
}

Iterator Addressbook::begin()
{
	Iterator location;
	location.book = this;
	if (First != nullptr)
	{
		location.entry = First;
	}
	else
	{
		location.entry = nullptr;
	}
	return location;
}

Iterator Addressbook::end()
{
	Iterator location;
	location.book = this;
	if (Last != nullptr)
	{
		location.entry = Last;
	}
	else
	{
		location.entry = nullptr;
	}
	return location;
}
