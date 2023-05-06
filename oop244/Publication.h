#ifndef _Publication_H
#define _Publication_H
#include <iostream>
#include"Streamable.h"
#include"Lib.h"
#include"Date.h"
#define TITLE 255



namespace sdds
{
	class Publication :public Streamable
	{
		char* m_title;

		char m_shelfid[SDDS_SHELF_ID_LEN];
		int membership;
		int m_libRef;
		Date m_date;
	public:
		
		Publication();
		~Publication();
		Publication(const Publication& p);
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();
		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef()const;
		bool conIO(ios& io)const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& istr);
		void setTOdefault();
		virtual operator bool();
		Publication& operator=(const Publication& p);
		
	};


}

#endif

