#include<iostream>
using namespace std;


class Streamable
{
public:
	virtual std::ostream& write(std::ostream& os) const = 0;
	virtual std::istream& read(std::istream& istr) = 0;
	virtual bool conIO(ios& io)const = 0;
	virtual operator bool() = 0;
	virtual ~Streamable() {};
	
};
ostream& operator<<(std::ostream& os,Streamable& st);
istream& operator>>(std::istream& in, Streamable& st);


