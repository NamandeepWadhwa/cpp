// Name:
// Seneca Student ID:146466214
// Seneca email:nwadhwa2@mysenec.ca
// Date of completion:nov 16 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Utilities.h"
namespace sdds
{
	char Utilities::m_delimiter = ' ';
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	int Utilities::getFieldWidth() const {
		return m_widthField;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string token="";
		size_t demlimiter_pos = next_pos;
		next_pos = str.find(m_delimiter, demlimiter_pos);
		if (next_pos == std::string::npos)
		{
			token = str.substr(demlimiter_pos);
			more = false;
			int i = token.length();
			m_widthField = m_widthField > i ? m_widthField : token.length();
			next_pos++;

			return token;
		}
		if (next_pos == demlimiter_pos)
		{
			more = false;
			throw "No token found!";
		}
		else
		{
			token = str.substr(demlimiter_pos, next_pos - demlimiter_pos);
			more = true;
			int i = token.length();
			m_widthField = m_widthField > i ? m_widthField : token.length();

			next_pos++;
			return token;
			
		}
		
	}
}
