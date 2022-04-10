#include "address.h"
#include "addressbook.h"
#include "iterator.h"

Iterator::Iterator()
{
	book = nullptr;
	entry = nullptr;
}

void Iterator::add(std::string name, std::string address)
{
	Address* temp = new Address(name, address);
	if (entry == nullptr)
	{
		if (book->First == nullptr && book->Last == nullptr)
		{
			book->First = temp;
			book->Last = temp;
			entry = book->First;
		}
		else if (book->First == book->Last)
		{
			temp->Previous = book->First;
			book->First->Next = temp;
			book->Last = temp;
			entry = book->Last;
		}
		else
		{
			temp->Previous = book->Last;
			book->Last->Next = temp;
			book->Last = temp;
			entry = book->Last;
		}
	}
	else if (book->First == book->Last)
	{
		temp->Previous = book->First;
		book->First->Next = temp;
		book->Last = temp;
		entry = book->Last;
	}
	else if (entry == book->Last)
	{
		temp->Previous = book->Last;
		book->Last->Next = temp;
		book->Last = temp;
		entry = book->Last;
	}
	else
	{
		temp->Next = entry->Next;
		temp->Previous = entry;
		entry->Next = temp;
		entry = temp->Next;
		entry->Previous = temp;
		entry = temp;
	}
}

void Iterator::edit(std::string name, std::string address)
{
	entry->change_name(name);
	entry->change_address(address);
}

void Iterator::edit_name(std::string name)
{
	entry->change_name(name);
}

void Iterator::edit_add(std::string address)
{
	entry->change_address(address);
}

void Iterator::next()
{
	if (entry == nullptr)
	{
		entry = book->Last;
	}
	else
	{
		entry = entry->Next;
	}
}

void Iterator::previous()
{
	if (entry == nullptr)
	{
		entry = book->First;
	}
	else
	{
		entry = entry->Previous;
	}
}

std::string Iterator::get_Name()
{
	std::string hold;
	hold = entry->Name;
	return hold;
}

std::string Iterator::get_add()
{
	std::string hold;
	hold = entry->address;
	return hold;	
}
