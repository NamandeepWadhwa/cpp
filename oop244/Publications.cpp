#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include"Publication.h"
#include"Date.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	Publication::Publication()
	{
		m_title = nullptr;
		strcpy(m_shelfid, "");
		membership = 0;
		m_libRef = -1;
		m_date = new Date;
	}
	Publication::~Publication()
	{
		delete[]m_title;
		m_title = nullptr;
	}
	void Publication::set(int member_id)
	{
		if (member_id == 0 || member_id > 9999)
		{
			membership = 0;
		}
		else
		{
			cout << "Enter a valid number";
		}
	}

	void Publication::setRef(int value)
	{
		if (value > 0)
		{
			m_libRef = value;
		}
		else
		{
			cout << "Enter a valid value";
		}

	}

	void Publication::resetDate()
	{
		delete m_date;
		m_date = nullptr;
		m_date = new Date;
	}
	char Publication::type()const
	{
		return'P';
	}
	bool Publication::onLoan()const
	{
		if (membership != 0)
		{
			return true;
		}
		return false;
	}
	Date Publication::checkoutDate()const
	{
		return *m_date;
	}
	bool Publication::operator==(const char* title)const
	{
		if (strstr(title, m_title))
			return true;
		return false;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}
	Publication::operator const char* ()const
	{
		if(m_title!=nullptr)
		return m_title;
		return "";
	}
	bool Publication::conIO(ios& io) const
	{
		std::ostream& os = std::cout;
		std::istream& is = std::cin;
		if(&io==&os || &io==&is)
			return true;
		return false;

	}
	ostream& Publication::write(ostream& os) const
	{
		if (this)
		{
			return os;
		}
		if (conIO(os))
		{
			os.setf(ios::fixed);
			os.width(8);
			os << "|" << m_shelfid << "|";
			os.fill('.');
			os.width(33);
			os << *m_title << "|";
			os.width(33);
			if (membership == 0)
				os << "N/A";
			else
				os << membership;
			os.width(14);
			os << m_date;
			os.width(8);
			os<<" ";

			return os;

		}
		os << type()<<'\t'<<m_libRef<<'\t' << m_shelfid << '\t' << m_title<<'\t'<<membership<<'\t'<<m_date;
		return os;
	}

	std::istream& Publication::read(std::istream& istr)
	{
		char title[TITLE];
		char shelf[TITLE] ;
		setTOdefault();
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr >> shelf;
			if (strlen(shelf) > SDDS_SHELF_ID_LEN)
			{
				istr.setstate(std::ios_base::failbit);
				
			}
			istr.ignore(2000, '\n');
			cout << "Title: ";
			istr.getline(title,200);
			cout << "Date: ";
			
			istr >> *m_date;
			if(m_date->errCode())
				istr.setstate(std::ios_base::failbit);

			if (!istr.fail()&& m_date->errCode() == 0)
			{
				m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
				int i = 0;
				for (i = 0; i < SDDS_SHELF_ID_LEN; i++)
				{
					m_shelfid[i] = shelf[i];
				}
			}
				
			
			return istr;
		}
		istr >> m_libRef;
		istr.ignore(2000, '\t');
		istr >> m_shelfid;
		istr.ignore(2000, '\t');
		istr >> membership;
		istr.ignore(2000, '\t');
		istr >> *m_date;
		
		
	}
	Publication::operator bool()
	{
		if (m_title == nullptr || strlen(m_title) == 0 || strlen(m_shelfid) == 0)
			return false;
		return true;
	}
	void Publication::setTOdefault()
	{
		delete[]m_title;
		m_title = nullptr;
		strcpy(m_shelfid, "");
		membership = 0;
		m_libRef = -1;
		resetDate();
	}

}
std::ostream& operator<<(std::ostream& os, Streamable& st)
{
	return st.write(os);
}
std::istream& operator>>(std::istream& in, Streamable& st)
{
	return st.read(in);
}

