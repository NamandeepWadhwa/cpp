// Name:
// Seneca Student ID:146466214
// Seneca email:nwadhwa2@mysenec.ca
// Date of completion:
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef UTILITIES_H
#define UTILITIES_H
#include<string>
namespace sdds
{
	class Utilities
    {
       int m_widthField{ 1 };
        static char m_delimiter;
    public:
        void setFieldWidth(size_t newWidth);
        int getFieldWidth() const;
        std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(char newDelimiter);
        static char getDelimiter();

    };
}
#endif // !UTILITIES_H



