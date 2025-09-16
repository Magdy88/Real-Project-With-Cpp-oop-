#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsString.h"
#include "clsInputValidate.h"

class clsCurrencyCalculator:protected clsScreen
{
private:

    static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currency Card")
    {
        cout << "\n"<<Title<<"\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _PrintCalculationResult(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        
        _PrintCurrencyCard(Currency1, "Convert From");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _PrintCurrencyCard(Currency2, "Convert To");

        float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();



    }

    static clsCurrency _GetCurrency(string Message)
    {
        string Currency1Code;

        cout << Message;
        Currency1Code = clsInputValidate::ReadString();

        if (!clsCurrency::IsCurrencyExist(Currency1Code))
        {
            cout << "\nCurrency is not found, choose another one: ";
            Currency1Code = clsInputValidate::ReadString();

        }
        clsCurrency Currency = clsCurrency::FindByCode(Currency1Code);

        return Currency;
        
    }

    

    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;

        Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }


    



 public:

    static void ShowCurrencyCalculator()
    {

        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {

            system("cls");
           _DrawScreenHeader("\t Currency Calculator");
          
           
          
           clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code:");
           clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code:");
          
           float Amount = _ReadAmount();

           _PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

           cout << "\n\nDo you want to perform another calculation? y/n ? ";
           cin >> Continue;
          
        }




        




        



    }

};

