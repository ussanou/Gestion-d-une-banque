#include "head.h"

int Demander_choix();

int accueil()
{
    ///déclaration des variables tel que temps,entier,caractère spéciale :
    int choix ;
    ///time_t is an object declared already in the ctime library :
    time_t now = time(0);//the time from 1970 to now.
    ///ctime returns a string represent the local time based on the variable now
    char *temps = ctime(&now);

    setlocale(LC_CTYPE,"fra");
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
                    cout << "#";
                    for(int i = 0 ; i < 38 ; i++)cout << " ";
                    cout << "bienvenu sur le logiciel de la gestion banquaire !";
                    for(int i = 0 ; i < 45 ; i++)cout << " ";
                    cout << "#";

                }
                break;

            case 6 :
                {
                    cout << "#      1 | Commencer";
                    for(int i = 0 ; i < 97 ; i++)cout << " ";
                    cout << "Quitter | 2      #";
                }
                break;

            case 8 :
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
        choix = Demander_choix();
    }while (choix!=1 && choix!=2);
    return choix;
}
