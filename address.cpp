#include "address.h"

Address::Address()
{
	Next = nullptr;
	Previous = nullptr;
}

Address::Address(std::string name, std::string add)
{
	Name = name;
	address = add;
	Next = nullptr;
	Previous = nullptr;
}

void Address::change_name(std::string name)
{
	Name = name;
}

void Address::change_address(std::string add)
{
	address = add;
}
