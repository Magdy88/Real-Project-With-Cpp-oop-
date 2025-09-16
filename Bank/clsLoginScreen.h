#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvlaid Username/Password!\n";
                cout << "\nYou Have " << (3 - FaildLoginCount) << " Trial(s) To Login\n\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\n You Are Locked After 3 Faild Trials \n\n ";
                return false;
            }

           /* if (LoginFaild)
            {
                Trials--;
                cout << "You Have " << Trials << " Trials To Login\n\n";
                if (Trials == 0)
                {
                    cout << "\nYou Are Locked After 3 Faild Trials\n";
                    exit(0);
                    
                }
            }*/

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;

    }

    
 

    

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};

