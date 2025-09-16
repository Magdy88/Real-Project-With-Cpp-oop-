#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsString.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen:protected clsScreen
{

private:


	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";
	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			 cout << "\nCurrency Found :-)\n";
			 _PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}

	}


public:


	static void ShowFindCurrencyScreen()
	{

		
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";

		short Answer = 0;
		cin >> Answer;

		if (Answer == 1)
		{
			string CodeCurrency ;
			cout << "\nPlease Enter CurrencyCode: ";
			CodeCurrency = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CodeCurrency);
			_ShowResult(Currency);

		}

		else
		{
			string CountryCurrency ;
			cout << "\nPlease Enter Country Name: ";
			CountryCurrency = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CountryCurrency);
			_ShowResult(Currency);
		}

		

		


	
		
	}


};

