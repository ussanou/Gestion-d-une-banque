#include "head.h"

int Demander_choix();

int Demander_choix()
{
    int choix;
    cout << endl << endl;
    for (int i = 0 ; i < 57 ; i++)cout << " " ;
    cout << "Votre choix : ";
    cin >> choix;
    return choix;
}

