#include<iostream>
#include"Streamable.h"
using namespace std;
ostream& operator<<(std::ostream& os, Streamable& st)
{
	if (st)
		return st.write(os);
	return os;
}
istream& operator>>(std::istream& in, Streamable& st)
{
	return st.read(in);

}