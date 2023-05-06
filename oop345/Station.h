// Name:
// Seneca Student ID:146466214
// Seneca email:nwadhwa2@mysenec.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef STATION_H
#define STATION_H
#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
namespace sdds
{
	class Station
	{
		int id;
		std::string name;
		std::string description;
		signed int serial_number;
		unsigned int items;
		static int m_widthField;
		static int id_generator;
	public:
		Station(const std::string& str);
		const std::string& getItemName()const;
		size_t getNextSerialNumber();
		size_t getQuantity()const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !STATION_H

