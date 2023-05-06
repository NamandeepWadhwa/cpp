#include "Station.h"
#include "Utilities.h"
namespace sdds
{
 

		int Station::m_widthField = 0;
		int Station::id_generator = 1;

		
		void remove_spaces(std::string& str)
		{
			str = str.erase(0, str.find_first_not_of(" "));
			str = str.erase(str.find_last_not_of(" ") + 1);
		}
		Station::Station(const std::string& str) {
			id = id_generator;
			Utilities utility;
			size_t traveco = 0;
			bool ok = true;

			try {
				name = utility.extractToken(str, traveco, ok);
				remove_spaces(name);
				serial_number = stoi(utility.extractToken(str, traveco, ok));
				items = stoi(utility.extractToken(str, traveco, ok));
				m_widthField = utility.getFieldWidth() > m_widthField ? utility.getFieldWidth() : m_widthField;
				description = utility.extractToken(str, traveco, ok);
				remove_spaces(description);
			}
			catch (std::string& err) {
				std::cout << err;
			}
			id_generator++;
		}

		const std::string& Station::getItemName() const {
			return name;
		}

		size_t Station::getNextSerialNumber() {
			serial_number++;
			return serial_number - 1;
		}

		size_t Station::getQuantity() const {
			return items;
		}

		void Station::updateQuantity() {
			items--;
			if (items < 0) {
				items = 0;
			}
		}

		void Station::display(std::ostream& os, bool full) const {
			os << std::right  << std::setw(3) << std::setfill('0') << id << " | ";
			os << std::setw(m_widthField) << std::left << std::setfill(' ') << name;
			os << " | " << std::setw(6) << std::right << std::setfill('0') << serial_number << " | ";

			if (full) {
				os   << std::setw(4) << std::right << std::setfill(' ') << items;
				os <<" | " << description << std::endl;
			}
			else {
				os << std::endl;
			}

		}
		
	}
