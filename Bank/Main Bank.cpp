#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include "clsPerson.h"

using namespace std;


#include "clsLoginScreen.h"

int main()

{
    

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }

    system("pause>0");
    return 0;
}
