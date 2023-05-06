#ifndef _BOOK_H
#define _BOOK_H
#include <iostream>
#include"Publication.h"
using namespace std;
#define AUTHOR 256
namespace sdds
{
	class Book :public Publication {
		char* Author;
	public:
		Book();
		Book(const Book& B);
		~Book();
		Book& operator=(const Book& B);
		virtual char type() const;
		virtual std::ostream& write(std::ostream& os) const;
		virtual std::istream& read(std::istream& istr);
		virtual void set(int member_id);
		virtual operator bool();
	};

}
#endif
