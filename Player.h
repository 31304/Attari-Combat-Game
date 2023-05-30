#pragma once
//this class composite with the menue class
#include "util.h"
#include <fstream>
class Player
{
private:
	string name;
	string password;
	fstream myfile;
	string email;
public:
	void setname(string Name)
	{
		name = Name;
	}
	void setpassword(string Password)
	{
		password = Password;
	}
	string getname()
	{
		return name;
	}
	string getpassword()
	{
		return password;
	}
	void setemail(string Email)
	{
		email = Email;
	}
	string getEmail()
	{
		return email;
	}
	bool valideplayer()
	{
		myfile.open("User.txt", ios::in);
		string line;
		int i = 0;
		bool check1=false;
		bool check2=false;
		while (getline(myfile, line))
		{
			if (i % 2 == 1)
			{
				if (line == password)
				{
					
					check1 = true;
				}
			}
			if (i % 2 == 0)
			{
				if (line == email)
				{
					check2 = true;
				}
			}
			i++;
		}
		if (check1 == true && check2 == true)
		{
			myfile.close();
			return true;
		}
		myfile.close();
		return false;
	}
	void registerplayer()
	{
		myfile.open("User.txt", ios::app);
		myfile << email << endl;
		myfile << password << endl;
		myfile.close();
		string file = email + ".txt";
		cout << file << endl;
		myfile.open(file, ios::out);
		myfile << name<<endl;
		myfile << email<<endl;
		myfile << password<<endl;
		myfile.close();
	}

};