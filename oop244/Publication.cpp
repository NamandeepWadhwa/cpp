// Final Project Milestone 3
// File	ms3_tester.cpp
// Version 1.0
// Author	Namandeep Singh Wadhwa
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
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
		resetDate();
	}
	void Publication::set(int member_id)
	{
		if (member_id == 0 || member_id > 99999)
		{
			membership = 0;
		}
		else
		{
			membership = member_id;
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
		
		m_date.reset_date();
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
		return m_date;
	}
	bool Publication::operator==(const char* title)const
	{
		if (strstr(m_title, title))
		{
			return true;
		}

		return false;
	}

	int Publication::getRef()const
	{
		return m_libRef;
	}
	Publication::operator const char* ()const
	{

		return m_title;

	}
	bool Publication::conIO(ios& io) const
	{
		std::ostream& os = std::cout;
		std::istream& is = std::cin;
		if (&io == &os || &io == &is)
			return true;
		return false;

	}
	ostream& Publication::write(ostream& os) const
	{
		
		if (conIO(os))
		{
			char title[(SDDS_TITLE_WIDTH)+1];
			if (strlen(m_title) >= SDDS_TITLE_WIDTH)
			{
				int i = 0;
				for (i = 0; i < SDDS_TITLE_WIDTH; i++)
				{
					title[i] = m_title[i];
				}
				title[i] = '\0';
			}
			else
			{
				strcpy(title, m_title);
			}
			
			os << "| ";
			os << m_shelfid;
			
		    os<< " | ";
			
			
			
			
			os.width(SDDS_TITLE_WIDTH);
			os.setf(ios::fixed);
			os.fill('.');
			os << title;
		    os<< " | ";
			if (membership == 0)
			{
				os.width(4);
				os.fill(' ');
				os << " N/A";
				os << "  | ";
			}

			else
			{
				os.width(5);
				os.fill(' ');
				os << membership;
				
				os << " | ";
			}
			os << m_date;
			os<< " |";
			
			

			return os;

		}
		os << type() << '\t' << m_libRef << '\t' << m_shelfid << '\t' << m_title << '\t' << membership << '\t' << m_date;
		return os;
	}

	std::istream& Publication::read(std::istream& istr)
	{
		char title[TITLE];
		char shelf[TITLE];
		setTOdefault();
		if (conIO(istr))
		{
			cout << "Shelf No: ";
			istr>>shelf;
			if (strlen(shelf) > SDDS_SHELF_ID_LEN-1)
			{
				istr.setstate(std::ios_base::failbit);

			}
			
			istr.ignore();
			cout << "Title: ";
			istr.getline(title, 200);
			cout << "Date: ";

			istr >> m_date;
			if (m_date.errCode())
				istr.setstate(std::ios_base::failbit);

			if (!istr.fail() && m_date.errCode() == 0)
			{
				
				delete[]m_title;
					m_title = new char[strlen(title) + 1];
				strcpy(m_title, title);
				int i = 0;
				for (i = 0; shelf[i] != '\0'; i++)
				{
					m_shelfid[i] = shelf[i];
					
				}
					
				m_shelfid[i] = '\0';
				

				return istr;
			}


			return istr;
		}
		int lib, memb;
		istr >>lib;
		
		istr.ignore();
		istr.getline(shelf,200,'\t');
		
		
		istr.getline(title,TITLE, '\t');
		
		
		istr >> memb;

		istr.ignore();
		istr >> m_date;
		if (strlen(shelf) > SDDS_SHELF_ID_LEN-1)
		{
			cout << strlen(shelf);
			istr.setstate(std::ios_base::failbit);

		}

		if (!istr.fail() && m_date.errCode() == 0 && lib<100000)
		{
			delete[]m_title;
			m_title = new char[strlen(title) + 1];

			strcpy(m_title, title);
			
			int i = 0;
			for (i = 0; shelf[i] != '\0'; i++)
			{
				m_shelfid[i] = shelf[i];

			}
			m_shelfid[i] = '\0';
			
			m_libRef = lib;
			membership = memb;

		}
		return istr;

	}
	Publication::operator bool()
	{

		if (m_title==nullptr||strlen(m_title) == 0 || strlen(m_shelfid) == 0)
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
	
	Publication& Publication::operator=(const Publication& p)
	{
		if (this!=&p && p)
		{

			delete[]m_title;
			m_title = new char[strlen(p.m_title) + 1];
			strcpy(this->m_title, p.m_title);
			int i = 0;
			for (i = 0; p.m_shelfid[i] != '\0'; i++)
			{
				m_shelfid[i] = p.m_shelfid[i];
				
			}
				
			m_shelfid[i] = '\0';
			
			this->membership = p.membership;
			this->m_libRef = p.m_libRef;
			this->m_date = p.m_date;
			return *this;
		}
		this->setTOdefault();
		return *this;
	}
	Publication::~Publication()
	{
		
		delete[]m_title;
		
	}
	Publication::Publication(const Publication& p)
	{
		m_title = nullptr;
		*this = p;
	}

}




