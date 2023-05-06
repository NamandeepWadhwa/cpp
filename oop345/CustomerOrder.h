#ifndef _CUSTOMERORDER
#define _CUSTOMERORDER
#include <algorithm>
#include<string>
#include"Station.h"
namespace sdds
{
	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		};
		std::string m_name;
		std::string m_product;
		int m_cntItem;
		Item** m_lstItem;
		static int m_widthField;
	public:
		void safe_state(CustomerOrder& cust);
		CustomerOrder(std::string&);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&) noexcept;
		CustomerOrder& operator=(CustomerOrder&&) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};

}

#endif


