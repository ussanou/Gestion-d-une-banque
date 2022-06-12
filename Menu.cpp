#include "head.h"

int Demander_choix();

int menu()
{
    ///déclaration des variable de temps,entier,caractère spéciale :
    int option ;
    setlocale (LC_CTYPE,"fra");
    time_t now = time(0);
    char *temps = ctime(&now);

    do
    {
        cls;
        for (int l = 0 ; l < 9 ; l++)
        {
            switch (l)
            {
            case 0 :
                {
                    for (int i = 0 ; i < 135 ; i++)cout << "#";
                }
                break;

            case 2 :
                {
                    cout << "#";
                    for(int i = 0 ; i < 50 ; i++)cout << " ";
                    cout << temps;
                }
                break;


            case 4 :
                {
                    cout << "#      1 | GESTION CLIENT";
                    for(int i = 0 ; i < 85 ; i++)cout << " ";
                    cout << "GESTION COMPTE | 2      #";

                }
                break;

            case 6 :
                {
                    cout << "#      3 | OPERATION";
                    for(int i = 0 ; i < 97 ; i++)cout << " ";
                    cout << "QUITTER | 4      #";
                }
                break;
/*
            case 8 :
                {
                    cout << "#      5 | Chercher";
                    for(int i = 0 ; i < 98 ; i++)cout << " ";
                    cout << "Support | 6      #";
                }
                break;
*/
            case 8:
                {
                    for (int i = 0 ; i < 135 ; i++)cout << "#";
                }
                break;

            default :
                {
                    cout << "#";
                    for(int i = 0 ; i < 133 ; i++)cout << " ";
                    cout << "#";
                }
            }
        }
        option = Demander_choix();
    }while (option<1 || option > 6);
    return option;
}


