// Name:
// Seneca Student ID:146466214
// Seneca email:nwadhwa2@mysenec.ca
// Date of completion:nov 29,2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Station.h"

namespace sdds {

	int CustomerOrder::m_widthField = 0;
	void remove_spaces2(std::string& str)
	{
		str = str.erase(0, str.find_first_not_of(" "));
		str = str.erase(str.find_last_not_of(" ") + 1);
	}

	void CustomerOrder::safe_state(CustomerOrder& cust) {
		cust.m_name = "";
		cust.m_product = "";
		cust.m_cntItem = 0;
		cust.m_lstItem = nullptr;
	}

	CustomerOrder::CustomerOrder(std::string& str) {
		safe_state(*this);
		Utilities util;
		size_t next_pos = 0;
		bool ok = true;
		m_cntItem = 0;

		m_name = util.extractToken(str, next_pos, ok);
		remove_spaces2(m_name);
		m_product = util.extractToken(str, next_pos, ok);
		remove_spaces2(m_product);

		size_t start = next_pos;

		while (ok) {
			util.extractToken(str, next_pos, ok);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];
		ok = true;

		for (int i = 0; i < m_cntItem; i++) {
			std::string src = util.extractToken(str, start, ok);
			remove_spaces2(src);
			m_lstItem[i] = new Item(src);
		}

		if (util.getFieldWidth() > m_widthField) {
			m_widthField = util.getFieldWidth();
		}

	}

	CustomerOrder::CustomerOrder(const CustomerOrder&) {
		throw std::string("No copy operations are allowed!");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
		*this = std::move(src);
	}
	

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& cust) noexcept {
		if (this != &cust) {
			if (this->m_name == "")
			{
				this->m_lstItem = nullptr;
				m_cntItem = 0;
			}
			if (m_lstItem != nullptr) {
				for (int i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
			}

			delete[] m_lstItem;
			m_name = cust.m_name;
			m_lstItem = cust.m_lstItem;
			m_cntItem = cust.m_cntItem;
			m_product = cust.m_product;
			
			cust.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		if (m_lstItem) {
			for (int i = 0; i < m_cntItem; i++) 
				delete m_lstItem[i];
			
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isOrderFilled() const {
		bool filled = true;

		for (int i = 0; i < m_cntItem && filled; i++) {
			if (m_lstItem[i]->m_isFilled == false) 
				filled = false;
			
		}

		return filled;
	}
	

	bool CustomerOrder::isItemFilled(const std::string& Name) const {
		bool filled = true;
		std::for_each(m_lstItem, (m_lstItem + m_cntItem), [Name, &filled](const Item* item) {
			if (item->m_itemName == Name && !item->m_isFilled) filled = false;
			});
		return filled ;
	}


	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	
		for (int i = 0; i < m_cntItem; i++) {
			if (m_lstItem[i]->m_itemName == station.getItemName() && m_lstItem[i]->m_isFilled==false) {
				if (station.getQuantity() >=1) {
					
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << std::right << "    Filled ";
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				else {
					os << std::right << "    Unable to fill ";
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}

	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << std::endl;
		for (int i = 0; i < m_cntItem; i++) {
			os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
			os << std::setw(m_widthField) << std::left << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			os << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
		}
	}

}