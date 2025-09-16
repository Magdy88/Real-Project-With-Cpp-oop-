#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsDate.h"
#include <iomanip>
#include "clsUser.h"


class clsLogInRegister :protected clsScreen
{
private:

	static void _PrintLogInRegisterScreen(clsUser::stLogInRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}


public:

	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		

		vector<clsUser::stLogInRegisterRecord> vLogInRegisterRecord = clsUser::GetLogInRegisterList();
		string Title = "\t LogIn Register Title Screen";
		string SubTitle = "\t    (" + to_string(vLogInRegisterRecord.size()) + ") Record(s)";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLogInRegisterRecord.size() == 0)
		{
			cout << "\n\t\t\t\tLogIn Register Is Not Found";
		}

		for (clsUser::stLogInRegisterRecord Record : vLogInRegisterRecord)
		{
			_PrintLogInRegisterScreen(Record);
			cout << endl;
		}


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

