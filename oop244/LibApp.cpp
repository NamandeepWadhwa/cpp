/* Citation and Sources...
 * Final Project Milestone 2
 * Module: LibApp
 * Filename: LibApp.cpp
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
#include"LibApp.h"
using namespace std;
namespace sdds
{
	LibApp::LibApp()
	{
		m_changed = false;
		m_mainMenu.set_title("Seneca Library Application");
		m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" <<
			"Return publication to library";
		m_exitMenu.set_title("Changes have been made to the data, what would you like to do?");
		m_exitMenu << "Save changes and exit" <<
			"Cancel and go back to the main menu";
		this->load();
	}
	bool LibApp::confirm(const char* message)
	{
		Menu confirm(message);
		confirm << "Yes";
		int changes = confirm.run();
		if (changes)
		{
			return true;
		}
		return false;

	}
	void LibApp::load()
	{
		cout << "Loading Data" << endl;
	}
	void LibApp::save()
	{
		cout << "Saving Data" << endl;
	}
	void LibApp::search()
	{
		cout << "Searching for publication" << endl;
	}
	void LibApp::returnPub()
	{
		this->search();
		cout << "Returning publication" << endl<<"Publication returned"<<endl;
		m_changed = true;
	}
	void LibApp::newPublication()
	{
		cout << "Adding new publication to library" << endl;
		if (this->confirm("Add this publication to library?"))
		{
			m_changed = true;
			cout << "Publication added"<<endl;
		};
		
	}
	void LibApp::removePublication()
	{
		cout << "Removing publication from library" << endl;
		this->search();
		if (this->confirm("Remove this publication from the library?"))
		{
			m_changed = true;
			cout << "Publication removed" << endl;
		};
	}
	void LibApp::checkOutPub()
	{
		this->search();
		
			if (this->confirm("Check out publication?"))
			{
				m_changed = true;
				cout << "Publication checked out" << endl;
			};
	}
	void LibApp::run()
	{
		int i = 1;
		
		while (i)
		{
			i=this->m_mainMenu.run();
			if (i == 1)
			{
				this->newPublication();
				cout << endl;
			}
			if (i == 2)
			{
				this->removePublication();
				cout << endl;
			}
			if (i == 3)
			{
				this->checkOutPub();
				cout << endl;
			}
			if (i == 4)
			{
				this->returnPub();
				cout << endl;
			}

			if (m_changed && i==0)
			{
				i = m_exitMenu.run();
				if (i == 1)
				{
					this->save();
					cout << endl;
					i = 0;
				}
				else if (i == 2)
				{
					cout << endl;
				}
				else if (i == 0)
				{
					if (this->confirm("This will discard all the changes are you sure?"))
						cout << endl;
					else
					{
						cout << endl;
						i = 1;
					}

				}
			}
			if (i == 0 && m_changed == false)
			{
				cout << endl;
			}
			
		}
		cout << "-------------------------------------------" << endl
			<< "Thanks for using Seneca Library Application" << endl;;
		
	};

	
}
