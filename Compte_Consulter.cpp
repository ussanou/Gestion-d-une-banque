#include "head.h"

int consulter (char nom_fc[50],int &n_cpt)
{
    int id_cpt,id;
    float solde = 0;
    for(int i = 0 ; i < 3 ; i++) cout << endl;
    for(int i = 0 ; i < 52 ; i++) cout << " ";
    cout << "L'id du compte a consulter : ";
    cin >> id_cpt ;
    ifstream Lire(nom_fc , ios::in);
    if(Lire)
    {
        for(int i = 0 ; i < n_cpt*4 ; i++)
        {
            if(i==0||i%4==0)
            {
                Lire >> id;
                if(id == id_cpt)
                {
                    Lire >> solde;
                    Lire >> solde;
                }
            }
        }
    }
    Lire.close();
    cout << endl;

    for(int i = 0 ; i < 55 ; i++) cout << " ";
    cout << "+----------------------+\n";
    for(int i = 0 ; i < 55 ; i++) cout << " ";

    if(solde == 0)
        cout << "|Compte introuvable.   |\n";
    else
    {
        printf("|Solde : %12.2fDH|\n",solde);

    }

    for(int i = 0 ; i < 55 ; i++) cout << " ";
    cout << "+----------------------+\n";

    cout << "      1 | retour";
    for(int i = 0 ; i < 100 ; i++)cout << " ";
    cout << "Quitter | 2      ";

    return Demander_choix ();
}
