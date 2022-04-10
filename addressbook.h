#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include<iostream>
#include<fstream>
#include<string>

class Address;
class Iterator;

class Addressbook
{
	private:
		Address* First;
		Address* Last;

	public:
		/**
		Constructs an empty Addressbook
		*/
		Addressbook();
		/**
		Constructs an Addressbook with the given information
		@param name is the name
		@param address is the address
		*/
		Addressbook(std::string name, std::string address);
		/**
		Returns the size of the Addressbook
		*/
		int size();
		/**
		Displays the Addressbook
		*/
		void print();
		/**
		Displays a single Addressbook entry
		@param index is the location of the entry
		*/
		void print_specific(std::string name);
		/**
		Adds to an Addressbook from a file
		@param file_name name of the file being read
		*/
		void read(std::string file_name);
		/**
		Exports the Addressbook to a file
		*/
		void write();
		/**
		Exports the Addressbook to a specified file
		@param file_name name of the file to write to
		*/
		void writeto(std::string file_name);
		/*
		Deletes all Addresses
		*/
		void free();
		/*
		Removes the Address at
		@param pos
		*/
		Iterator erase(Iterator pos);
		/*
		Returns an Iterator pointing at First
		*/
		Iterator begin();
		/*
		Returns an Iterator pointing at Last
		*/
		Iterator end();

	friend class Address;
	friend class Iterator;
};

#endif
