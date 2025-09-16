#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsString.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen :protected clsScreen
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

   
    static float _ReadRate()
    {

        cout << "\nEnter A New Rate:";
       float  Rate = clsInputValidate::ReadFloatNumber();

       return Rate;

    }



public:

    static void UpdateCurrencyScreen()
    {
        _DrawScreenHeader("\t Update Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease inter Currency Code? ";
        CurrencyCode = clsInputValidate::ReadString();

        if (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }
         



        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\n Are You Sure You Want To Update The Rete Of This Currency? y/n?";
        cin >> Answer;

        
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n Update Client Rate:";
            cout << "\n________________\n";

            Currency.UpdateRate(_ReadRate());
           
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
           

        }



    }



};

