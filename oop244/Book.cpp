#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include"Book.h"
using namespace std;
namespace sdds
{
	Book::Book()
	{
		Author = nullptr;
	}
	Book::Book(const Book& B)
	{
		Author = nullptr;
		*this = B;

	}
	Book::~Book()
	{
		delete[] Author;
	}
	Book& Book::operator=(const Book& B)
	{
		Publication::operator=(B);
		delete[]Author;
		Author = new char[strlen(B.Author) + 1];
		strcpy(Author, B.Author);
		return *this;
	}
	char Book::type()const
	{
		return 'B';
	}
	Book::operator bool()
	{
		if (Author != nullptr && strlen(Author) != 0 && Publication::operator bool())
			return true;
		return false;
	}
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}
	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);
		if (conIO(os))
		{
			os << " ";
			int i = 0;
			char temp[(SDDS_AUTHOR_WIDTH)+1];
			if (strlen(Author) >= SDDS_AUTHOR_WIDTH)
			{
				for (i = 0; i < SDDS_AUTHOR_WIDTH; i++)
				{

					temp[i] = Author[i];

				}
				temp[i] = '\0';
			}
			else
			{
				strcpy(temp, Author);
			}
			os << temp;
			os.setf(ios::left);
			os.width(SDDS_AUTHOR_WIDTH-strlen(temp));
			
			os.fill(' ');
			os << "";
			
			os << " |";
			return os;
		}
		os << "\t"<< Author;
		return os;

	}
	std::istream& Book::read(std::istream& istr)
	{
		Publication::read(istr);
		char Temp_Name[AUTHOR];
		delete [] Author;
		Author = nullptr;
		
		if (conIO(istr))
		{
			istr.ignore();
			cout << "Author: ";
			istr.getline(Temp_Name,AUTHOR,'\n');
			Author = new char[strlen(Temp_Name) + 1];
			strcpy(Author, Temp_Name);
			return istr;
		}
		istr.ignore();
		
		istr.get(Temp_Name, AUTHOR,'\n');
		Author = new char[strlen(Temp_Name) + 1];
		strcpy(Author, Temp_Name);
		return istr;

	}

}