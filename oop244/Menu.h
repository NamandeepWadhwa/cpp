
#ifndef MENU_H
#define MENU_H
#include<iostream>
#define MAX_MENU_ITEMS 20
namespace sdds
{


	class Menu;
	class MenuItem
	{
		char* content;
		friend class Menu;
		MenuItem();
		MenuItem(char* content_name);
		~MenuItem();
		operator bool() const;
		const char* name() const;
		void display(std::ostream& os)const;
		void setname(const char* content_name);
	};
	class Menu
	{
		MenuItem menuname;
		MenuItem* menu[MAX_MENU_ITEMS];
		int total_item;
	public:
		Menu();
		Menu(const char* name);
		~Menu();
		void display_title(std::ostream&)const;
		void display_menu(std::ostream&)const;
		unsigned int run() const;
		unsigned int operator ~();
		Menu& operator<<(const char* menuitemConent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator [] (int number) const;
		void set_title(const char* title);
	};
	std::ostream& operator<<(std::ostream& os, const Menu& m);
}

#endif 





