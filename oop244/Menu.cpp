/* Citation and Sources...
 * Final Project Milestone 2
 * Module: Menu
 * Filename: Menu.cpp
 * Version 1.0
 * Author	Namandeep Singh Wadhwa
 * Revision History
 * -----------------------------------------------------------
 *  Date      Reason
 *  2022/07/13  Preliminary release
 *  -----------------------------------------------------------
 *  I have done all the coding by myself and only copied the code 
 *  that my professor provided to complete my project milestones.
 *  -----------------------------------------------------------
 *  */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Menu.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	MenuItem::MenuItem()
	{
		content = nullptr;

	}
	MenuItem::MenuItem(char* content_name)
	{
		if (content_name != nullptr && strlen(content_name) != 0)
		{
			content = nullptr;
			content = new char[strlen(content_name) + 1];
			strcpy(content, content_name);
		}

		else
			content = nullptr;
	}
	MenuItem::~MenuItem()
	{
		delete[] content;
		content = nullptr;
	}
	MenuItem::operator bool() const
	{
		if (content != nullptr)
		{
			return true;

		}
		return false;
	}
	const char* MenuItem::name() const
	{
		if (content != nullptr)
		{

			return content;
		}

		else
			return "No name";
	}
	void MenuItem::display(std::ostream& os)const
	{
		if (this)
			os << this->name();
		else;
	}
	void MenuItem::setname(const char* content_name)
	{

		if (content_name != nullptr)
		{
			delete[]content;
			content = nullptr;
			content = new char[strlen(content_name) + 2];
			strcpy(content, content_name);

		}

		else
			content = nullptr;
	}
	Menu::Menu()
	{
		total_item = 0;
		menuname.setname(nullptr);

	}
	Menu::Menu(const char* name)
	{
		total_item = 0;
		menuname.setname(name);

	}
	Menu::~Menu()
	{
		int i = 0;
		for (i = 0; i < total_item; i++)
		{
			delete menu[i];
			menu[i] = nullptr;
		}
		total_item = 0;
	}
	void Menu::display_title(std::ostream& os)const
	{
		if (menuname)
		{
			os << menuname.content;

		}
		else
		{
			;
		}

	}
	void Menu::display_menu(std::ostream& os)const
	{
		if (menuname)
		{
			os << menuname.content << endl;

		}
		else
		{
			;
		}


		int i = 0;
		for (i = 0; i < total_item; i++)
		{
			if (menu[i])
			{
				os << " " << i + 1 << "- " << menu[i]->content << endl;
			}
		}
		os << " " << "0- " << "Exit" << endl << "> ";

	}
	unsigned int Menu::run() const
	{
		display_menu(cout);
		return validnum(*this);

	}
	unsigned int Menu::operator ~()
	{
		this->display_menu(cout);
		return validnum(*this);
	}
	Menu& Menu::operator<<(const char* menuitemConent)
	{
		if (total_item < MAX_MENU_ITEMS)
		{
			menu[total_item] = nullptr;
			menu[total_item] = new MenuItem;
			menu[total_item]->setname(menuitemConent);

			total_item++;
		}
		return *this;
	}
	Menu::operator int() const
	{
		return total_item;
	}
	Menu::operator unsigned int() const
	{
		return total_item;
	}
	Menu::operator bool() const
	{
		if (total_item > 0 && menuname.content != nullptr)
			return true;
		return false;
	}

	const char* Menu::operator [] (int number) const
	{
		if (number < total_item)
		{
			return menu[number]->name();
		}
		else
			return menu[0]->name();
	}
	void Menu::set_title(const char* title)
	{
		menuname.setname(title);
	}
	std::ostream& operator<<(std::ostream& os, const Menu& m)
	{
		m.display_title(os);
		return os;


	}


}



